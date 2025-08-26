/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../inc/MarlinConfig.h"

#include "../gcode.h"

#include "../../module/endstops.h"
#include "../../module/planner.h"
#include "../../module/stepper.h" // pro různé funkce

#if HAS_LEVELING
  #include "../../feature/bedlevel/bedlevel.h"
#endif

#if ENABLED(BD_SENSOR)
  #include "../../feature/bedlevel/bdl/bdl.h"
#endif

#include "../../module/probe.h"

#if ENABLED(BLTOUCH)
  #include "../../feature/bltouch.h"
#endif

#include "../../lcd/marlinui.h"

#if ENABLED(EXTENSIBLE_UI)
  #include "../../lcd/extui/ui_api.h"
#elif ENABLED(DWIN_CREALITY_LCD)
  #include "../../lcd/e3v2/creality/dwin.h"
#elif ENABLED(DWIN_LCD_PROUI)
  #include "../../lcd/e3v2/proui/dwin.h"
#endif

#define DEBUG_OUT ENABLED(DEBUG_LEVELING_FEATURE)
#include "../../core/debug_out.h"

#if ENABLED(QUICK_HOME)

  /**
   * Rychlé homing XY os - simuluje pozici 0,0 a pohybuje se diagonálně
   */
  static void quick_home_xy() {
    // AI_DEBUG: quick_home_xy začíná
    SERIAL_ECHOLNPGM("AI_DEBUG: quick_home_xy() ZAČÍNÁ");
    SERIAL_ECHOLNPGM("AI_DEBUG: quick_home_xy - aktuální pozice před resetem = ", current_position.x, ", ", current_position.y);

    // Předstíráme, že aktuální pozice je 0,0
    current_position.set(0.0, 0.0);
    SERIAL_ECHOLNPGM("AI_DEBUG: quick_home_xy - pozice resetována na = ", current_position.x, ", ", current_position.y);
    sync_plan_position();

    const int x_axis_home_dir = TOOL_X_HOME_DIR(active_extruder);
    SERIAL_ECHOLNPGM("AI_DEBUG: quick_home_xy - x_axis_home_dir = ", x_axis_home_dir);

    // Použije vyšší diagonální rychlost, aby se osy pohybovaly homing rychlostí
    const float minfr = _MIN(homing_feedrate(X_AXIS), homing_feedrate(Y_AXIS)),
                fr_mm_s = HYPOT(minfr, minfr);

    // Pohyb diagonálně k endstopům
    do_blocking_move_to_xy(1.5 * max_length(X_AXIS) * x_axis_home_dir, 1.5 * max_length(Y_AXIS) * Y_HOME_DIR, fr_mm_s);

    endstops.validate_homing_move();

    // Nastaví pozici na 0,0 po homingu
    current_position.set(0.0, 0.0);
    SERIAL_ECHOLNPGM("AI_DEBUG: quick_home_xy - pozice nastavena na = ", current_position.x, ", ", current_position.y);
    SERIAL_ECHOLNPGM("AI_DEBUG: quick_home_xy() KONČÍ");
  }

#endif // QUICK_HOME

#if ENABLED(Z_SAFE_HOMING)

  /**
   * Bezpečný Z homing - přesune trysku na bezpečné místo před homingem Z osy
   */
  inline void home_z_safely() {
    DEBUG_SECTION(log_G28, "home_z_safely", DEBUGGING(LEVELING));

    // Zakáže Z homing, pokud je potřeba X nebo Y homing
    if (homing_needed_error(_BV(X_AXIS) | _BV(Y_AXIS))) return;

    sync_plan_position();

    /**
     * Přesune Z sondu (nebo trysku) na bezpečný homing bod
     * (Z je už ve správné výšce)
     */
    constexpr xy_float_t safe_homing_xy = { Z_SAFE_HOMING_X_POINT, Z_SAFE_HOMING_Y_POINT };
    
    // AI_DEBUG: Přidávám debug výpisy pro Z_SAFE_HOMING
    SERIAL_ECHOLNPGM("AI_DEBUG: Z_SAFE_HOMING_X_POINT = ", Z_SAFE_HOMING_X_POINT);
    SERIAL_ECHOLNPGM("AI_DEBUG: Z_SAFE_HOMING_Y_POINT = ", Z_SAFE_HOMING_Y_POINT);
    SERIAL_ECHOLNPGM("AI_DEBUG: safe_homing_xy = ", safe_homing_xy.x, ", ", safe_homing_xy.y);
    
    #if HAS_HOME_OFFSET
      // Aplikuje home offset na bezpečnou homing pozici
      xy_float_t okay_homing_xy = safe_homing_xy;
      okay_homing_xy -= home_offset;
      SERIAL_ECHOLNPGM("AI_DEBUG: home_offset = ", home_offset.x, ", ", home_offset.y);
      SERIAL_ECHOLNPGM("AI_DEBUG: okay_homing_xy = ", okay_homing_xy.x, ", ", okay_homing_xy.y);
    #else
      constexpr xy_float_t okay_homing_xy = safe_homing_xy;
      SERIAL_ECHOLNPGM("AI_DEBUG: No home_offset, okay_homing_xy = ", okay_homing_xy.x, ", ", okay_homing_xy.y);
    #endif

    // Nastaví cílovou pozici pro pohyb
    destination.set(okay_homing_xy, current_position.z);
    SERIAL_ECHOLNPGM("AI_DEBUG: destination set to = ", destination.x, ", ", destination.y);

    // TERN_(HOMING_Z_WITH_PROBE, destination -= probe.offset_xy);  // AI_DEBUG: DEAKTIVOVÁNO - Neodečítá probe.offset_xy

    if (position_is_reachable(destination)) {

      if (DEBUGGING(LEVELING)) DEBUG_POS("home_z_safely", destination);

      // Uvolní aktivní extruder pro pohyb
      TERN_(DUAL_X_CARRIAGE, idex_set_parked(false));

      // Pohyb na bezpečnou pozici a homing Z osy
      do_blocking_move_to_xy(destination);
      
      // AI_DEBUG: Pozice před Z homingem
      SERIAL_ECHOLNPGM("AI_DEBUG: Před Z homingem - current_position = ", current_position.x, ", ", current_position.y);
      
      homeaxis(Z_AXIS);
      
      // AI_DEBUG: Pozice po Z homingu
      SERIAL_ECHOLNPGM("AI_DEBUG: Po Z homingu - current_position = ", current_position.x, ", ", current_position.y);
      
      // AI_DEBUG: Pozice před sync_plan_position
      SERIAL_ECHOLNPGM("AI_DEBUG: Před sync_plan_position - current_position = ", current_position.x, ", ", current_position.y);
      
      sync_plan_position();
      
      // AI_DEBUG: Pozice po sync_plan_position
      SERIAL_ECHOLNPGM("AI_DEBUG: Po sync_plan_position - current_position = ", current_position.x, ", ", current_position.y);
    }
    else {
      // Chybová hláška, pokud pozice není dosažitelná
      LCD_MESSAGE(MSG_ZPROBE_OUT);
      SERIAL_ECHO_MSG(STR_ZPROBE_OUT_SER);
    }
  }

#endif // Z_SAFE_HOMING

#if ENABLED(IMPROVE_HOMING_RELIABILITY)

  /**
   * Začátek pomalého homingu - sníží akceleraci pro spolehlivost
   */
  motion_state_t begin_slow_homing() {
    motion_state_t motion_state{0};
    // Uloží aktuální akceleraci
    motion_state.acceleration.set(planner.settings.max_acceleration_mm_per_s2[X_AXIS],
                                 planner.settings.max_acceleration_mm_per_s2[Y_AXIS]
                               );
    // Nastaví nízkou akceleraci pro homing
    planner.settings.max_acceleration_mm_per_s2[X_AXIS] = 100;
    planner.settings.max_acceleration_mm_per_s2[Y_AXIS] = 100;
    #if HAS_CLASSIC_JERK
      // Uloží a nuluje jerk
      motion_state.jerk_state = planner.max_jerk;
      planner.max_jerk.set(0, 0);
    #endif
    planner.refresh_acceleration_rates();
    return motion_state;
  }

  /**
   * Konec pomalého homingu - obnoví původní nastavení
   */
  void end_slow_homing(const motion_state_t &motion_state) {
    // Obnoví původní akceleraci
    planner.settings.max_acceleration_mm_per_s2[X_AXIS] = motion_state.acceleration.x;
    planner.settings.max_acceleration_mm_per_s2[Y_AXIS] = motion_state.acceleration.y;
    TERN_(HAS_CLASSIC_JERK, planner.max_jerk = motion_state.jerk_state);
    planner.refresh_acceleration_rates();
  }

#endif // IMPROVE_HOMING_RELIABILITY

/**
 * G28: Homing všech os podle nastavení
 *
 * Parametry
 *
 *  Žádné  Homing všech os bez parametrů.
 *         S QUICK_HOME povoleným se XY homuje společně, pak Z.
 *
 *  L<bool>   Vynutí stav levelingu ZAPNUTÝ (pokud možno) nebo VYPNUTÝ po homingu
 *            (Vyžaduje RESTORE_LEVELING_AFTER_G28 nebo ENABLE_LEVELING_AFTER_G28)
 *  O         Homing pouze pokud pozice není známá a důvěryhodná
 *  R<lineární> Zvedne o n mm/palců před homingem
 *
 * Parametry pro Cartesian/SCARA
 *
 *  X   Homing na X endstop
 *  Y   Homing na Y endstop
 *  Z   Homing na Z endstop
 */
void GcodeSuite::G28() {
  DEBUG_SECTION(log_G28, "G28", DEBUGGING(LEVELING));
  if (DEBUGGING(LEVELING)) log_machine_info();

  // AI_DEBUG: G28 začíná
  SERIAL_ECHOLNPGM("AI_DEBUG: G28() ZAČÍNÁ");
  SERIAL_ECHOLNPGM("AI_DEBUG: G28 - aktuální pozice na začátku = ", current_position.x, ", ", current_position.y, ", ", current_position.z);

  TERN_(BD_SENSOR, bdl.config_state = 0);

  /**
   * Nastaví laser výkon na false, aby planner nezpracovával aktuální nastavení výkonu.
   */
  #if ENABLED(LASER_FEATURE)
    planner.laser_inline.status.isPowered = false;
  #endif

  #if ENABLED(DUAL_X_CARRIAGE)
    bool IDEX_saved_duplication_state = extruder_duplication_enabled;
    DualXMode IDEX_saved_mode = dual_x_carriage_mode;
  #endif

  #if ENABLED(MARLIN_DEV_MODE)
    if (parser.seen_test('S')) {
      LOOP_NUM_AXES(a) set_axis_is_at_home((AxisEnum)a);
      sync_plan_position();
      SERIAL_ECHOLNPGM("Simulated Homing");
      report_current_position();
      return;
    }
  #endif

  // Homing (O)nly pokud pozice není známá
  if (!axes_should_home() && parser.seen_test('O')) {
    if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPGM("> homing není potřeba, přeskočit");
    return;
  }

  #if ENABLED(FULL_REPORT_TO_HOST_FEATURE)
    const M_StateEnum old_grblstate = M_State_grbl;
    set_and_report_grblstate(M_HOMING);
  #endif

  TERN_(HAS_DWIN_E3V2_BASIC, DWIN_HomingStart());
  TERN_(EXTENSIBLE_UI, ExtUI::onHomingStart());

  planner.synchronize();          // Počká na dokončení planner pohybů!

  SET_SOFT_ENDSTOP_LOOSE(false);  // Resetuje zbývající 'volný' stav pohybu

  // Vypne leveling matici před homingem
  #if CAN_SET_LEVELING_AFTER_G28
    const bool leveling_restore_state = parser.boolval('L', TERN1(RESTORE_LEVELING_AFTER_G28, planner.leveling_active));
  #endif

  // Zruší předchozí G29 session
  TERN_(PROBE_MANUALLY, g29_in_progress = false);

  // Vypne leveling před homingem
  TERN_(HAS_LEVELING, set_bed_leveling_enabled(false));

  // Reset na XY rovinu
  TERN_(CNC_WORKSPACE_PLANES, workspace_plane = PLANE_XY);

  // Počítá tento příkaz jako pohyb / aktivitu
  reset_stepper_timeout();

  // Kontrola, zda má osa vlastní homing proud
  #define HAS_CURRENT_HOME(N) (defined(N##_CURRENT_HOME) && N##_CURRENT_HOME != N##_CURRENT)
  #if HAS_CURRENT_HOME(X) || HAS_CURRENT_HOME(X2) || HAS_CURRENT_HOME(Y) || HAS_CURRENT_HOME(Y2)
    #define HAS_HOMING_CURRENT 1
  #endif

  #if HAS_HOMING_CURRENT
    // Lambda funkce pro debug výpis změn proudu
    auto debug_current = [](FSTR_P const s, const int16_t a, const int16_t b) {
      DEBUG_ECHOF(s); DEBUG_ECHOLNPGM(" current: ", a, " -> ", b);
    };
    
    // Nastaví homing proud pro X osu
    #if HAS_CURRENT_HOME(X)
      const int16_t tmc_save_current_X = stepperX.getMilliamps();
      stepperX.rms_current(X_CURRENT_HOME);
      if (DEBUGGING(LEVELING)) debug_current(F(STR_X), tmc_save_current_X, X_CURRENT_HOME);
    #endif
    
    // Nastaví homing proud pro X2 osu
    #if HAS_CURRENT_HOME(X2)
      const int16_t tmc_save_current_X2 = stepperX2.getMilliamps();
      stepperX2.rms_current(X2_CURRENT_HOME);
      if (DEBUGGING(LEVELING)) debug_current(F(STR_X2), tmc_save_current_X2, X2_CURRENT_HOME);
    #endif
    
    // Nastaví homing proud pro Y osu
    #if HAS_CURRENT_HOME(Y)
      const int16_t tmc_save_current_Y = stepperY.getMilliamps();
      stepperY.rms_current(Y_CURRENT_HOME);
      if (DEBUGGING(LEVELING)) debug_current(F(STR_Y), tmc_save_current_Y, Y_CURRENT_HOME);
    #endif
    
    // Nastaví homing proud pro Y2 osu
    #if HAS_CURRENT_HOME(Y2)
      const int16_t tmc_save_current_Y2 = stepperY2.getMilliamps();
      stepperY2.rms_current(Y2_CURRENT_HOME);
      if (DEBUGGING(LEVELING)) debug_current(F(STR_Y2), tmc_save_current_Y2, Y2_CURRENT_HOME);
    #endif
  #endif

  #if ENABLED(IMPROVE_HOMING_RELIABILITY)
    motion_state_t saved_motion_state = begin_slow_homing();
  #endif

  TERN_(HAS_DUPLICATION_MODE, set_duplication_enabled(false));

  remember_feedrate_scaling_off();

  endstops.enable(true); // Zapne endstopy pro další homing pohyb

  // Makro pro kontrolu bezpečnosti Z homingu
  #define _UNSAFE(A) (homeZ && TERN0(Z_SAFE_HOMING, axes_should_home(_BV(A##_AXIS))))

  // Určení, které osy potřebují homing
  const bool homeZ = TERN0(HAS_Z_AXIS, parser.seen_test('Z')),
             NUM_AXIS_LIST(              // Ostatní osy by měly být homovány před Z safe-homingem
               needX = _UNSAFE(X), needY = _UNSAFE(Y), needZ = false // NEPOUŽITO
             ),
             NUM_AXIS_LIST(              // Homing každé osy pokud je potřeba nebo označena
               homeX = needX || parser.seen_test('X'),
               homeY = needY || parser.seen_test('Y'),
               homeZZ = homeZ
             ),
             home_all = NUM_AXIS_GANG(   // Homing všech pokud všechny nebo žádná není označena
                  homeX == homeX, && homeY == homeX, && homeZ == homeX
               ),
             NUM_AXIS_LIST(
               doX = home_all || homeX, doY = home_all || homeY, doZ = home_all || homeZ
             );

  #if HAS_Z_AXIS
    UNUSED(needZ); UNUSED(homeZZ);
  #else
    constexpr bool doZ = false;
    #if !HAS_Y_AXIS
      constexpr bool doY = false;
    #endif
  #endif

  // Z homing první (pokud povoleno)
  TERN_(HOME_Z_FIRST, if (doZ) homeaxis(Z_AXIS));

  const bool seenR = parser.seenval('R');
  const float z_homing_height = seenR ? parser.value_linear_units() : Z_HOMING_HEIGHT;

  // Zvedne Z před homingem ostatních os
  if (z_homing_height && (seenR || NUM_AXIS_GANG(doX, || doY, || TERN0(Z_SAFE_HOMING, doZ)))) {
    // Zvedne Z před homingem ostatních os a Z není už dostatečně vysoko (nikdy nesníží Z)
    if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPGM("Zvedne Z (před homingem) o ", z_homing_height);
    do_z_clearance(z_homing_height);
    TERN_(BLTOUCH, bltouch.init());
  }

  // Diagonální pohyb první pokud se homují obě osy
  TERN_(QUICK_HOME, if (doX && doY) {
    SERIAL_ECHOLNPGM("AI_DEBUG: G28 - volá se quick_home_xy()");
    SERIAL_ECHOLNPGM("AI_DEBUG: G28 - pozice před quick_home_xy = ", current_position.x, ", ", current_position.y);
    quick_home_xy();
    SERIAL_ECHOLNPGM("AI_DEBUG: G28 - pozice po quick_home_xy = ", current_position.x, ", ", current_position.y);
  });

  #if HAS_Y_AXIS
    // Y homing (před X)
    if (ENABLED(HOME_Y_BEFORE_X) && (doY || TERN0(CODEPENDENT_XY_HOMING, doX)))
      homeaxis(Y_AXIS);
  #endif

  // X homing
  if (doX || (doY && ENABLED(CODEPENDENT_XY_HOMING) && DISABLED(HOME_Y_BEFORE_X))) {

    #if ENABLED(DUAL_X_CARRIAGE)

      // Vždy homing 2. (pravého) extruderu první
      active_extruder = 1;
      homeaxis(X_AXIS);

      // Zapamatuje si pozici tohoto extruderu pro pozdější změnu nástroje
      inactive_extruder_x = current_position.x;

      // Homing 1. (levého) extruderu
      active_extruder = 0;
      homeaxis(X_AXIS);

      // Považuje aktivní extruder za v "zaparkované" pozici
      idex_set_parked();

    #else

      homeaxis(X_AXIS);

    #endif
  }

  #if HAS_Y_AXIS
    // Y homing (po X)
    if (DISABLED(HOME_Y_BEFORE_X) && doY)
      homeaxis(Y_AXIS);
  #endif

  TERN_(IMPROVE_HOMING_RELIABILITY, end_slow_homing(saved_motion_state));

  // Z homing poslední pokud homing směrem k podložce
  #if HAS_Z_AXIS && DISABLED(HOME_Z_FIRST)
    if (doZ) {
      #if EITHER(Z_MULTI_ENDSTOPS, Z_STEPPER_AUTO_ALIGN)
        stepper.set_all_z_lock(false);
        stepper.set_separate_multi_axis(false);
      #endif

      #if ENABLED(Z_SAFE_HOMING)
        if (TERN1(POWER_LOSS_RECOVERY, !parser.seen_test('H'))) home_z_safely(); else homeaxis(Z_AXIS);
      #else
        homeaxis(Z_AXIS);
      #endif
      probe.move_z_after_homing();
    }
  #endif

  sync_plan_position();

  /**
   * Zachová DXC mód přes G28 pro IDEX tiskárny v DXC_DUPLICATION_MODE.
   * To je důležité, protože umožňuje uživateli nastavit IDEX Duplication mód přes LCD panel,
   * a pak tisknout standardní GCode soubor, který obsahuje jediný tisk s G28 a nemá žádné
   * jiné IDEX specifické příkazy.
   */
  #if ENABLED(DUAL_X_CARRIAGE)

    if (idex_is_duplicating()) {

      TERN_(IMPROVE_HOMING_RELIABILITY, saved_motion_state = begin_slow_homing());

      // Vždy homing 2. (pravého) extruderu první
      active_extruder = 1;
      homeaxis(X_AXIS);

      // Zapamatuje si pozici tohoto extruderu pro pozdější změnu nástroje
      inactive_extruder_x = current_position.x;

      // Homing 1. (levého) extruderu
      active_extruder = 0;
      homeaxis(X_AXIS);

      // Považuje aktivní extruder za zaparkovaný
      idex_set_parked();

      dual_x_carriage_mode = IDEX_saved_mode;
      set_duplication_enabled(IDEX_saved_duplication_state);

      TERN_(IMPROVE_HOMING_RELIABILITY, end_slow_homing(saved_motion_state));
    }

  #endif // DUAL_X_CARRIAGE

  endstops.not_homing();

  // Vyčistí endstop stav pro pollované stallGuard endstopy
  TERN_(SPI_ENDSTOPS, endstops.clear_endstop_state());

  TERN_(CAN_SET_LEVELING_AFTER_G28, if (leveling_restore_state) set_bed_leveling_enabled());

  restore_feedrate_and_scaling();

  // Obnoví homing proud
  #if HAS_HOMING_CURRENT
    if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPGM("Obnovení driver proudu...");
    
    // Obnoví původní proud pro X osu
    #if HAS_CURRENT_HOME(X)
      stepperX.rms_current(tmc_save_current_X);
    #endif
    
    // Obnoví původní proud pro X2 osu
    #if HAS_CURRENT_HOME(X2)
      stepperX2.rms_current(tmc_save_current_X2);
    #endif
    
    // Obnoví původní proud pro Y osu
    #if HAS_CURRENT_HOME(Y)
      stepperY.rms_current(tmc_save_current_Y);
    #endif
    
    // Obnoví původní proud pro Y2 osu
    #if HAS_CURRENT_HOME(Y2)
      stepperY2.rms_current(tmc_save_current_Y2);
    #endif
  #endif // HAS_HOMING_CURRENT

  ui.refresh();

  TERN_(HAS_DWIN_E3V2_BASIC, DWIN_HomingDone());
  TERN_(EXTENSIBLE_UI, ExtUI::onHomingDone());

  report_current_position();

  TERN_(FULL_REPORT_TO_HOST_FEATURE, set_and_report_grblstate(old_grblstate));

}
