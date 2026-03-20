/*
 * Configuration_adv.h — CR-10S Pro V2 + Microswiss Direct Drive
 *
 * Build flags: -DMachineCR10SProV2 -DHotendAllMetal -DBedDC
 * Derived: MachineCR10SPro, MachineCR10Std, ABL_BI, lerdgeFilSensor,
 *          DirectDrive, FORCE10SPRODISPLAY, HotendStock, MeshStd,
 *          POWER_LOSS_RECOVERY, BOARD_RAMPS_CREALITY, TMC2208_STANDALONE
 *
 * Cleaned from multi-machine conditions. CR-10S Pro V2 only.
 */
#pragma once

#define CONFIGURATION_ADV_H_VERSION 02010300

// @section temperature

#define THERMOCOUPLE_MAX_ERRORS 15

#if TEMP_SENSOR_0 == 1000
  #define HOTEND0_PULLUP_RESISTOR_OHMS    4700
  #define HOTEND0_RESISTANCE_25C_OHMS   100000
  #define HOTEND0_BETA                    3950
  #define HOTEND0_SH_C_COEFF                 0
#endif

#if TEMP_SENSOR_1 == 1000
  #define HOTEND1_PULLUP_RESISTOR_OHMS    4700
  #define HOTEND1_RESISTANCE_25C_OHMS   100000
  #define HOTEND1_BETA                    3950
  #define HOTEND1_SH_C_COEFF                 0
#endif

#if TEMP_SENSOR_BED == 1000
  #define BED_PULLUP_RESISTOR_OHMS        4700
  #define BED_RESISTANCE_25C_OHMS       100000
  #define BED_BETA                        3950
  #define BED_SH_C_COEFF                     0
#endif

// Heated Bed Bang-Bang options
#if DISABLED(PIDTEMPBED)
  #define BED_CHECK_INTERVAL 5000   // (ms)
  #if ENABLED(BED_LIMIT_SWITCHING)
    #define BED_HYSTERESIS 2        // (°C)
  #endif
#endif

// Thermal Protection — Hotends
#if ENABLED(THERMAL_PROTECTION_HOTENDS)
  #define THERMAL_PROTECTION_PERIOD 60        // Seconds
  #define THERMAL_PROTECTION_HYSTERESIS 10     // Degrees Celsius

  #define ADAPTIVE_FAN_SLOWING              // Slow part cooling fan if temperature drops
  #if ENABLED(ADAPTIVE_FAN_SLOWING) && EITHER(MPCTEMP, PIDTEMP)
    //#define TEMP_TUNING_MAINTAIN_FAN
  #endif

  #define WATCH_TEMP_PERIOD 60                // Seconds
  #define WATCH_TEMP_INCREASE 2               // Degrees Celsius
#endif

// Thermal Protection — Bed (BedDC, non-large bed)
#if ENABLED(THERMAL_PROTECTION_BED)
  #define THERMAL_PROTECTION_BED_PERIOD 50    // Seconds
  #define THERMAL_PROTECTION_BED_HYSTERESIS 2 // Degrees Celsius
  #define WATCH_BED_TEMP_PERIOD 180                // Seconds
  #define WATCH_BED_TEMP_INCREASE 2               // Degrees Celsius
#endif

// Thermal Protection — Chamber
#if ENABLED(THERMAL_PROTECTION_CHAMBER)
  #define THERMAL_PROTECTION_CHAMBER_PERIOD 20    // Seconds
  #define THERMAL_PROTECTION_CHAMBER_HYSTERESIS 2 // Degrees Celsius
  #define WATCH_CHAMBER_TEMP_PERIOD 60            // Seconds
  #define WATCH_CHAMBER_TEMP_INCREASE 2           // Degrees Celsius
#endif

// Thermal Protection — Cooler
#if ENABLED(THERMAL_PROTECTION_COOLER)
  #define THERMAL_PROTECTION_COOLER_PERIOD     10 // Seconds
  #define THERMAL_PROTECTION_COOLER_HYSTERESIS  3 // Degrees Celsius
  #define WATCH_COOLER_TEMP_PERIOD             60 // Seconds
  #define WATCH_COOLER_TEMP_INCREASE            3 // Degrees Celsius
#endif

#if ANY(THERMAL_PROTECTION_HOTENDS, THERMAL_PROTECTION_BED, THERMAL_PROTECTION_CHAMBER, THERMAL_PROTECTION_COOLER)
  //#define THERMAL_PROTECTION_VARIANCE_MONITOR
#endif

#if ENABLED(PIDTEMP)
  //#define PID_EXTRUSION_SCALING
  #if ENABLED(PID_EXTRUSION_SCALING)
    #define DEFAULT_Kc (100)
    #define LPQ_MAX_LEN 50
  #endif
  //#define PID_FAN_SCALING
  #if ENABLED(PID_FAN_SCALING)
    //#define PID_FAN_SCALING_ALTERNATIVE_DEFINITION
    #if ENABLED(PID_FAN_SCALING_ALTERNATIVE_DEFINITION)
      #define PID_FAN_SCALING_AT_FULL_SPEED 13.0
      #define PID_FAN_SCALING_AT_MIN_SPEED   6.0
      #define PID_FAN_SCALING_MIN_SPEED     10.0
      #define DEFAULT_Kf (255.0*PID_FAN_SCALING_AT_MIN_SPEED-PID_FAN_SCALING_AT_FULL_SPEED*PID_FAN_SCALING_MIN_SPEED)/(255.0-PID_FAN_SCALING_MIN_SPEED)
      #define PID_FAN_SCALING_LIN_FACTOR (PID_FAN_SCALING_AT_FULL_SPEED-DEFAULT_Kf)/255.0
    #else
      #define PID_FAN_SCALING_LIN_FACTOR (0)
      #define DEFAULT_Kf 10
      #define PID_FAN_SCALING_MIN_SPEED 10
    #endif
  #endif
#endif

// Autotemp
#define AUTOTEMP
#if ENABLED(AUTOTEMP)
  #define AUTOTEMP_OLDWEIGHT    0.98
  #define AUTOTEMP_MIN          210
  #define AUTOTEMP_MAX          250
  #define AUTOTEMP_FACTOR       0.1f
  //#define AUTOTEMP_PROPORTIONAL
  #if ENABLED(AUTOTEMP_PROPORTIONAL)
    #define AUTOTEMP_MIN_P      0
    #define AUTOTEMP_MAX_P      5
    #define AUTOTEMP_FACTOR_P   1
  #endif
#endif

// @section extruder

// Hotend Idle Timeout
#define HOTEND_IDLE_TIMEOUT
#if ENABLED(HOTEND_IDLE_TIMEOUT)
  #define HOTEND_IDLE_TIMEOUT_SEC (15*60)    // (seconds)
  #define HOTEND_IDLE_MIN_TRIGGER   170     // (°C)
  #define HOTEND_IDLE_NOZZLE_TARGET   0     // (°C)
  #define HOTEND_IDLE_BED_TARGET      0     // (°C)
#endif

// @section temperature

#define TEMP_SENSOR_AD595_OFFSET  0.0
#define TEMP_SENSOR_AD595_GAIN    1.0
#define TEMP_SENSOR_AD8495_OFFSET 0.0
#define TEMP_SENSOR_AD8495_GAIN   1.0

// @section extruder

// Extruder cooling fans
#define E1_AUTO_FAN_PIN -1
#define E2_AUTO_FAN_PIN -1
#define E3_AUTO_FAN_PIN -1
#define E4_AUTO_FAN_PIN -1
#define E5_AUTO_FAN_PIN -1
#define E6_AUTO_FAN_PIN -1
#define E7_AUTO_FAN_PIN -1
#define CHAMBER_AUTO_FAN_PIN -1
#define COOLER_AUTO_FAN_PIN -1

#define EXTRUDER_AUTO_FAN_TEMPERATURE 50
#define EXTRUDER_AUTO_FAN_SPEED 255   // 255 == full speed
#define CHAMBER_AUTO_FAN_TEMPERATURE 30
#define CHAMBER_AUTO_FAN_SPEED 255
#define COOLER_AUTO_FAN_TEMPERATURE 18
#define COOLER_AUTO_FAN_SPEED 255

// Fan Kickstart
#define FAN_KICKSTART_TIME  100  // (ms)

// Part-Cooling Fan Multiplexer
#define FANMUX0_PIN -1
#define FANMUX1_PIN -1
#define FANMUX2_PIN -1

// @section homing

#define HOMING_BUMP_MM      { 8, 8, 2 }       // (linear=mm, rotational=°)
#define HOMING_BUMP_DIVISOR { 2, 2, 4 }       // Re-Bump Speed Divisor

#define HOMING_BACKOFF_POST_MM { 8, 8, 2 }  // (linear=mm, rotational=°)

#define QUICK_HOME                          // If G28 contains XY do a diagonal move first

// @section bltouch

#if ENABLED(BLTOUCH)
  //#define BLTOUCH_DELAY 500
  //#define BLTOUCH_FORCE_SW_MODE

  // CR-10S Pro V2 is not in the exclusion list, so 5V mode is set
  #define BLTOUCH_SET_5V_MODE
  //#define BLTOUCH_FORCE_MODE_SET

  #define BLTOUCH_HS_MODE true

  //#define BLTOUCH_LCD_VOLTAGE_MENU
#endif // BLTOUCH

// @section extras

// Z Steppers Auto-Alignment (requires DualZ + probe)
#if ENABLED(DualZ) &&  ANY(ABL_EZABL, ABL_NCSW, ABL_BLTOUCH, ABL_TOUCH_MI)
  #define Z_STEPPER_AUTO_ALIGN
#endif
#if ENABLED(Z_STEPPER_AUTO_ALIGN)
  #ifndef Z_STEPPER_ALIGN_XY
    //#define Z_STEPPERS_ORIENTATION 0
  #endif
  #ifndef Z_STEPPER_ALIGN_STEPPER_XY
    #define Z_STEPPER_ALIGN_AMP 1.0
  #endif
  #define G34_MAX_GRADE              5    // (%)
  #define Z_STEPPER_ALIGN_ITERATIONS 8
  #define Z_STEPPER_ALIGN_ACC        0.02
  #define RESTORE_LEVELING_AFTER_G34
  #define HOME_AFTER_G34
#endif

// @section motion

#define AXIS_RELATIVE_MODES { false, false, false, false }

#define INVERT_X_STEP_PIN false
#define INVERT_Y_STEP_PIN false
#define INVERT_Z_STEP_PIN false
#define INVERT_I_STEP_PIN false
#define INVERT_J_STEP_PIN false
#define INVERT_K_STEP_PIN false
#define INVERT_U_STEP_PIN false
#define INVERT_V_STEP_PIN false
#define INVERT_W_STEP_PIN false
#define INVERT_E_STEP_PIN false

// Idle Stepper Shutdown
#define DEFAULT_STEPPER_DEACTIVE_TIME 120
#define DISABLE_INACTIVE_X true
#define DISABLE_INACTIVE_Y true
#define DISABLE_INACTIVE_Z true
#define DISABLE_INACTIVE_I true
#define DISABLE_INACTIVE_J true
#define DISABLE_INACTIVE_K true
#define DISABLE_INACTIVE_U true
#define DISABLE_INACTIVE_V true
#define DISABLE_INACTIVE_W true
#define DISABLE_INACTIVE_E true

// Default Minimum Feedrates
#define DEFAULT_MINIMUMFEEDRATE       0.0     // (mm/s)
#define DEFAULT_MINTRAVELFEEDRATE     0.0     // (mm/s)

#define DEFAULT_MINSEGMENTTIME        20000   // (µs)

// Slowdown
#define SLOWDOWN
#if ENABLED(SLOWDOWN)
  #define SLOWDOWN_DIVISOR 2
#endif

#define MINIMUM_PLANNER_SPEED 0.05 // (mm/s)

// Microstep settings
#define MICROSTEP_MODES { 16, 16, 16, 16, 16, 16 } // [1,2,4,8,16]

//===========================================================================
//=============================Additional Features===========================
//===========================================================================

// @section lcd

#if HAS_MANUAL_MOVE_MENU
  #define MANUAL_FEEDRATE { 50*60, 50*60, 4*60, 2*60 } // (mm/min)
  #define FINE_MANUAL_MOVE 0.025    // (mm)
  #if IS_ULTIPANEL
    #define MANUAL_E_MOVES_RELATIVE
    #define ULTIPANEL_FEEDMULTIPLY
  #endif
#endif

// Encoder Rate Multiplier
#define ENCODER_RATE_MULTIPLIER
#if ENABLED(ENCODER_RATE_MULTIPLIER)
  #define ENCODER_5X_STEPS_PER_SEC    30
  #define ENCODER_10X_STEPS_PER_SEC   80
  #if DISABLED(DWIN_MARLINUI_PORTRAIT)
    #define ENCODER_100X_STEPS_PER_SEC  130
  #endif
#endif

#if HAS_BED_PROBE && EITHER(HAS_MARLINUI_MENU, HAS_TFT_LVGL_UI)
  //#define PROBE_OFFSET_WIZARD
  #if ENABLED(PROBE_OFFSET_WIZARD)
    //#define PROBE_OFFSET_WIZARD_START_Z -4.0
    //#define PROBE_OFFSET_WIZARD_XY_POS { X_CENTER, Y_CENTER }
  #endif
#endif

#if HAS_MARLINUI_MENU
  #if HAS_BED_PROBE
    //#define X_AXIS_TWIST_COMPENSATION
    #if ENABLED(X_AXIS_TWIST_COMPENSATION)
      #define XATC_START_Z 0.0
      #define XATC_MAX_POINTS 3
      #define XATC_Y_POSITION Y_CENTER
      #define XATC_Z_OFFSETS { 0, 0, 0 }
    #endif
    #define PROBE_DEPLOY_STOW_MENU
  #endif

  #define LCD_INFO_MENU
  #if ENABLED(LCD_INFO_MENU)
    //#define LCD_PRINTER_INFO_IS_BOOTSCREEN
  #endif
#endif // HAS_MARLINUI_MENU

#if HAS_DISPLAY
  #define SOUND_ON_DEFAULT

  #if ENABLED(SHOW_BOOTSCREEN)
    #define BOOTSCREEN_TIMEOUT 4000       // (ms)
    #if EITHER(HAS_MARLINUI_U8GLIB, TFT_COLOR_UI)
      #define BOOT_MARLIN_LOGO_SMALL
    #endif
  #endif

  #define STATUS_MESSAGE_SCROLLING
#endif // HAS_DISPLAY

// M73 — Set print job progress
#define SET_PROGRESS_MANUALLY
#if ENABLED(SET_PROGRESS_MANUALLY)
  #define SET_PROGRESS_PERCENT
  #define SET_REMAINING_TIME
  //#define SET_INTERACTION_TIME
  //#define M73_REPORT
  #if BOTH(M73_REPORT, SDSUPPORT)
    #define M73_REPORT_SD_ONLY
  #endif
#endif

// LCD Print Progress options
#if HAS_DISPLAY && EITHER(SDSUPPORT, SET_PROGRESS_MANUALLY)
  #define SHOW_PROGRESS_PERCENT
  #define SHOW_ELAPSED_TIME
  #define SHOW_REMAINING_TIME
  #if ENABLED(SET_INTERACTION_TIME)
    #define SHOW_INTERACTION_TIME
  #endif

  #if EITHER(HAS_MARLINUI_HD44780, IS_TFTGLCD_PANEL)
    #define LCD_PROGRESS_BAR
    #if ENABLED(LCD_PROGRESS_BAR)
      #define PROGRESS_BAR_BAR_TIME 2000  // (ms)
      #define PROGRESS_BAR_MSG_TIME 3000  // (ms)
      #define PROGRESS_MSG_EXPIRE      0  // (ms)
    #endif
  #endif
#endif

#if ENABLED(SDSUPPORT)

  // SD Card detect state — CR-10S Pro is in the exclusion list, so no override
  // (MachineCR10SPro is in NONE() list, so SD_DETECT_STATE is NOT defined here)

  #define SD_PROCEDURE_DEPTH 1
  #define SD_FINISHED_STEPPERRELEASE true
  #define SD_FINISHED_RELEASECOMMAND "M84"

  #define SDCARD_RATHERRECENTFIRST
  #define SD_MENU_CONFIRM_START

  #define EVENT_GCODE_SD_ABORT "G91\nG1Z5\nG90\nM84\nM104S0\nM140S0"

  #if ENABLED(PRINTER_EVENT_LEDS)
    #define PE_LEDS_COMPLETED_TIME  (30*60)
  #endif

  // Power Loss Recovery
  //#define POWER_LOSS_RECOVERY
  #if ENABLED(POWER_LOSS_RECOVERY)
    #define PLR_ENABLED_DEFAULT   false
    #define POWER_LOSS_MIN_Z_CHANGE 0.05 // (mm)
  #endif

  // SD filename support
  #define UTF_FILENAME_SUPPORT
  #define LONG_FILENAME_HOST_SUPPORT
  #define SCROLL_LONG_FILENAMES

  // Auto-report SdCard status
  #define AUTO_REPORT_SD_STATUS

#endif // SDSUPPORT

#define NO_SD_HOST_DRIVE   // Disable SD Card access over USB

// Additional options for Graphical Displays
#if HAS_MARLINUI_U8GLIB
  #define XYZ_NO_FRAME

  #define STATUS_HOTEND_INVERTED
  #define STATUS_HOTEND_ANIM
  #define STATUS_BED_ANIM
  #define STATUS_CHAMBER_ANIM
  #define BOOT_MARLIN_LOGO_SMALL

  #if IS_U8GLIB_ST7920
    //#define DOGM_SPI_DELAY_US 5
    #if ENABLED(Big_UI)
      #define LIGHTWEIGHT_UI
    #endif
    #if ENABLED(LIGHTWEIGHT_UI)
      #define STATUS_EXPIRE_SECONDS 20
    #endif
  #endif
#endif // HAS_MARLINUI_U8GLIB

#if HAS_MARLINUI_U8GLIB || IS_DWIN_MARLINUI
  #define MENU_HOLLOW_FRAME
#endif

// Additional options for DGUS / DWIN displays
#if HAS_DGUS_LCD || ENABLED(DGUS_LCD_UI_CREALITY_TOUCH) || ENABLED(FORCE10SPRODISPLAY)
  #ifndef LCD_SERIAL_PORT
    #define LCD_SERIAL_PORT 3
    #define LCD_BAUDRATE 115200
  #endif

  #define DGUS_RX_BUFFER_SIZE 128
  #define DGUS_TX_BUFFER_SIZE 48

  #define DGUS_UPDATE_INTERVAL_MS  500    // (ms)

  #if DGUS_UI_IS(FYSETC, MKS, HIPRECY)
    #define DGUS_PRINT_FILENAME
    #define DGUS_PREHEAT_UI

    #if DGUS_UI_IS(FYSETC, MKS)
      //#define DGUS_UI_MOVE_DIS_OPTION
    #else
      #define DGUS_UI_MOVE_DIS_OPTION
    #endif

    #define DGUS_FILAMENT_LOADUNLOAD
    #if ENABLED(DGUS_FILAMENT_LOADUNLOAD)
      #define DGUS_FILAMENT_PURGE_LENGTH 10
      #define DGUS_FILAMENT_LOAD_LENGTH_PER_TIME 0.5
    #endif

    #define DGUS_UI_WAITING
    #if ENABLED(DGUS_UI_WAITING)
      #define DGUS_UI_WAITING_STATUS 10
      #define DGUS_UI_WAITING_STATUS_PERIOD 8
    #endif
  #endif
#endif // HAS_DGUS_LCD

// Specify additional languages
#if ANY(DOGLCD, TFT_COLOR_UI, TOUCH_UI_FTDI_EVE, IS_DWIN_MARLINUI)
  #ifdef LCD_LANGUAGE_2
    //#define LCD_LANGUAGE_AUTO_SAVE
  #endif
#endif

#if TFT_SCALED_DOGLCD
  //#define TFT_MARLINUI_COLOR 0xFFFF
  //#define TFT_MARLINBG_COLOR 0x0000
  //#define TFT_DISABLED_COLOR 0x0003
  //#define TFT_BTCANCEL_COLOR 0xF800
  //#define TFT_BTARROWS_COLOR 0xDEE6
  //#define TFT_BTOKMENU_COLOR 0x145F
#endif

#if HAS_ADC_BUTTONS
  #define ADC_BUTTON_DEBOUNCE_DELAY 16
#endif

// @section safety

#define USE_WATCHDOG
#if ENABLED(USE_WATCHDOG)
  //#define WATCHDOG_RESET_MANUAL
#endif

// @section lcd

// Babystepping
#define BABYSTEPPING
#if ENABLED(BABYSTEPPING)
  #define INTEGRATED_BABYSTEPPING
  #define BABYSTEP_ALWAYS_AVAILABLE
  #define BABYSTEP_INVERT_Z false
  #define BABYSTEP_MULTIPLICATOR_Z  10       // Kalibrováno pro LCD babystepping
  #define BABYSTEP_MULTIPLICATOR_XY 1

  #define DOUBLECLICK_FOR_Z_BABYSTEPPING
  #if ENABLED(DOUBLECLICK_FOR_Z_BABYSTEPPING)
    #define DOUBLECLICK_MAX_INTERVAL 1250
    //#define MOVE_Z_WHEN_IDLE
    #if ENABLED(MOVE_Z_WHEN_IDLE)
      #define MOVE_Z_IDLE_MULTIPLICATOR 1
    #endif
  #endif

  #if NONE(ABL_EZABL, ABL_NCSW, ABL_BLTOUCH, ABL_TOUCH_MI, MachineCR6, MachineCR6Max, MachineCR10Smart) || ENABLED(MESH_BED_LEVELING)
    #define BABYSTEP_DISPLAY_TOTAL          // Display total babysteps since last G28
  #else
    #define BABYSTEP_ZPROBE_OFFSET          // Combine M851 Z and Babystepping
  #endif
  #if ENABLED(BABYSTEP_ZPROBE_OFFSET)
    //#define BABYSTEP_HOTEND_Z_OFFSET
  #endif
#endif

// @section extruder

// Linear Pressure Control v1.5
#define LIN_ADVANCE
#if ENABLED(LIN_ADVANCE)
  #if ENABLED(DISTINCT_E_FACTORS)
    #define ADVANCE_K { 0.0 }    // (mm) per extruder
  #else
    #define ADVANCE_K 0.0        // (mm)
  #endif
  #define ALLOW_LOW_EJERK       // Recommended for direct drive hotends
#endif

// @section leveling

#if EITHER(AUTO_BED_LEVELING_3POINT, AUTO_BED_LEVELING_UBL)
  //#define PROBE_PT_1_X 15
  //#define PROBE_PT_1_Y 180
  //#define PROBE_PT_2_X 15
  //#define PROBE_PT_2_Y 20
  //#define PROBE_PT_3_X 170
  //#define PROBE_PT_3_Y 20
#endif

// Probing Margins
#if PROBE_SELECTED && !IS_KINEMATIC
  #define PROBING_MARGIN_FRONT (PROBING_MARGIN + ClipClearance)
  #define PROBING_MARGIN_BACK (PROBING_MARGIN + ClipClearance)
#endif

#if EITHER(MESH_BED_LEVELING, AUTO_BED_LEVELING_UBL)
  //#define MESH_MIN_X MESH_INSET
  //#define MESH_MIN_Y MESH_INSET
  //#define MESH_MAX_X X_BED_SIZE - (MESH_INSET)
  //#define MESH_MAX_Y Y_BED_SIZE - (MESH_INSET)
#endif

#if BOTH(AUTO_BED_LEVELING_UBL, EEPROM_SETTINGS)
  //#define OPTIMIZED_MESH_STORAGE
#endif

// G29 Retry
#if ENABLED(ABL_BI) && NONE(MachineCR10Orig, LowMemoryBoard, SKRMiniE3V2, MachineCR30)
  //#define G29_RETRY_AND_RECOVER
#endif
#if ENABLED(G29_RETRY_AND_RECOVER)
  #define G29_MAX_RETRIES 3
  #define G29_HALT_ON_FAILURE
  #define G29_SUCCESS_COMMANDS "M117 Bed leveling done."
  #define G29_RECOVER_COMMANDS "M117 Probe failed.\nG28\n"
  #define G29_FAILURE_COMMANDS "M117 Bed leveling failed.\nG0 Z10\nM300 P25 S880\nM300 P50 S0\nM300 P25 S880\nM300 P50 S0\nM300 P25 S880\nM300 P50 S0\nG4 S1"
#endif

// @section extras

// G2/G3 Arc Support
#define ARC_SUPPORT                 // Requires ~3226 bytes
#if ENABLED(ARC_SUPPORT)
  #define MIN_ARC_SEGMENT_MM      0.1
  #define MAX_ARC_SEGMENT_MM      1.0
  #define MIN_CIRCLE_SEGMENTS    72
  #define N_ARC_CORRECTION       25
#endif

#if EITHER(ARC_SUPPORT, BEZIER_CURVE_SUPPORT)
  //#define CNC_WORKSPACE_PLANES
#endif

// Moves with fewer steps than this will be joined with the next move
#define MIN_STEPS_PER_SEGMENT 6

// @section temperature

// @section motion

// Buffers
#if DISABLED(EXTENSIBLE_UI)
  #define BLOCK_BUFFER_SIZE 16
#else
  #define BLOCK_BUFFER_SIZE 8
#endif

// @section serial

#define MAX_CMD_SIZE 96
#define BUFSIZE 4

#define TX_BUFFER_SIZE 0

#if RX_BUFFER_SIZE >= 1024
  //#define SERIAL_XON_XOFF
#endif

#if ENABLED(SDSUPPORT)
  //#define SERIAL_STATS_MAX_RX_QUEUED
  //#define SERIAL_STATS_DROPPED_RX
#endif

// Emergency Command Parser
#define EMERGENCY_PARSER

// No Timeouts
#define NO_TIMEOUTS 1000 // Milliseconds

// Advanced OK
#define ADVANCED_OK

#define SERIAL_OVERRUN_PROTECTION

#define PROPORTIONAL_FONT_RATIO 1.0

// @section extras

// @section advanced pause

// Advanced Pause for Filament Change
#define ADVANCED_PAUSE_FEATURE
#if ENABLED(ADVANCED_PAUSE_FEATURE)
  #define PAUSE_PARK_RETRACT_FEEDRATE         60  // (mm/s)
  #define PAUSE_PARK_RETRACT_LENGTH            4  // (mm)
  #define FILAMENT_CHANGE_UNLOAD_FEEDRATE     20  // (mm/s) CR-10S Pro specific
  #define FILAMENT_CHANGE_UNLOAD_ACCEL        25  // (mm/s^2)
  #define FILAMENT_CHANGE_UNLOAD_LENGTH      75   // CR-10S Pro V2 specific
  #define FILAMENT_CHANGE_SLOW_LOAD_FEEDRATE   6  // (mm/s)
  #define FILAMENT_CHANGE_SLOW_LOAD_LENGTH     0  // (mm)
  #define FILAMENT_CHANGE_FAST_LOAD_FEEDRATE  20  // (mm/s)
  #define FILAMENT_CHANGE_FAST_LOAD_ACCEL     15  // (mm/s^2)
  #define FILAMENT_CHANGE_FAST_LOAD_LENGTH   FILAMENT_CHANGE_UNLOAD_LENGTH  // (mm)
  #define ADVANCED_PAUSE_PURGE_FEEDRATE        3  // (mm/s)
  #define ADVANCED_PAUSE_PURGE_LENGTH         20  // (mm)
  #define ADVANCED_PAUSE_RESUME_PRIME          0  // (mm)
  #define ADVANCED_PAUSE_FANS_PAUSE

  #define FILAMENT_UNLOAD_PURGE_RETRACT        4  // (mm)
  #define FILAMENT_UNLOAD_PURGE_DELAY       5000  // (ms)
  #define FILAMENT_UNLOAD_PURGE_LENGTH         0  // (mm)
  #define FILAMENT_UNLOAD_PURGE_FEEDRATE      25  // (mm/s)

  #define PAUSE_PARK_NOZZLE_TIMEOUT           45  // (seconds)
  #define FILAMENT_CHANGE_ALERT_BEEPS          2
  #define PAUSE_PARK_NO_STEPPER_TIMEOUT

  #define PARK_HEAD_ON_PAUSE
  #define FILAMENT_LOAD_UNLOAD_GCODES           // Add M701/M702
  #define FILAMENT_UNLOAD_ALL_EXTRUDERS
#endif

// @section tmc_smart

#if HAS_TRINAMIC_CONFIG || HAS_TMC26X

  #define HOLD_MULTIPLIER    0.5

  #define INTERPOLATE      true

  #if AXIS_IS_TMC_CONFIG(X)
    #define X_CURRENT       730
    #define X_CURRENT_HOME  800
    #define X_MICROSTEPS     16
    #define X_RSENSE          0.11
    #define X_CHAIN_POS      -1
  #endif

  #if AXIS_IS_TMC_CONFIG(X2)
    #define X2_CURRENT      800
    #define X2_CURRENT_HOME 850
    #define X2_MICROSTEPS    X_MICROSTEPS
    #define X2_RSENSE         0.11
    #define X2_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(Y)
    #define Y_CURRENT       730
    #define Y_CURRENT_HOME  800
    #define Y_MICROSTEPS     16
    #define Y_RSENSE          0.11
    #define Y_CHAIN_POS      -1
  #endif

  #if AXIS_IS_TMC_CONFIG(Y2)
    #define Y2_CURRENT      800
    #define Y2_CURRENT_HOME 850
    #define Y2_MICROSTEPS    Y_MICROSTEPS
    #define Y2_RSENSE         0.11
    #define Y2_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(Z)
    #define Z_CURRENT       850
    #define Z_CURRENT_HOME  950
    #define Z_MICROSTEPS     16
    #define Z_RSENSE          0.11
    #define Z_CHAIN_POS      -1
  #endif

  #if AXIS_IS_TMC_CONFIG(Z2)
    #define Z2_CURRENT      850
    #define Z2_CURRENT_HOME Z2_CURRENT
    #define Z2_MICROSTEPS    Z_MICROSTEPS
    #define Z2_RSENSE         0.11
    #define Z2_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(Z3)
    #define Z3_CURRENT      800
    #define Z3_CURRENT_HOME Z3_CURRENT
    #define Z3_MICROSTEPS    Z_MICROSTEPS
    #define Z3_RSENSE         0.11
    #define Z3_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(Z4)
    #define Z4_CURRENT      800
    #define Z4_CURRENT_HOME Z4_CURRENT
    #define Z4_MICROSTEPS    Z_MICROSTEPS
    #define Z4_RSENSE         0.11
    #define Z4_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(I)
    #define I_CURRENT      800
    #define I_CURRENT_HOME I_CURRENT
    #define I_MICROSTEPS    16
    #define I_RSENSE         0.11
    #define I_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(J)
    #define J_CURRENT      800
    #define J_CURRENT_HOME J_CURRENT
    #define J_MICROSTEPS    16
    #define J_RSENSE         0.11
    #define J_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(K)
    #define K_CURRENT      800
    #define K_CURRENT_HOME K_CURRENT
    #define K_MICROSTEPS    16
    #define K_RSENSE         0.11
    #define K_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(U)
    #define U_CURRENT      800
    #define U_CURRENT_HOME U_CURRENT
    #define U_MICROSTEPS     8
    #define U_RSENSE         0.11
    #define U_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(V)
    #define V_CURRENT      800
    #define V_CURRENT_HOME V_CURRENT
    #define V_MICROSTEPS     8
    #define V_RSENSE         0.11
    #define V_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(W)
    #define W_CURRENT      800
    #define W_CURRENT_HOME W_CURRENT
    #define W_MICROSTEPS     8
    #define W_RSENSE         0.11
    #define W_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(E0)
    #define E0_CURRENT      730
    #define E0_MICROSTEPS    16
    #define E0_RSENSE         0.11
    #define E0_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(E1)
    #define E1_CURRENT      730
    #define E1_MICROSTEPS   E0_MICROSTEPS
    #define E1_RSENSE         0.11
    #define E1_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(E2)
    #define E2_CURRENT      800
    #define E2_MICROSTEPS   E0_MICROSTEPS
    #define E2_RSENSE         0.11
    #define E2_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(E3)
    #define E3_CURRENT      800
    #define E3_MICROSTEPS   E0_MICROSTEPS
    #define E3_RSENSE         0.11
    #define E3_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(E4)
    #define E4_CURRENT      800
    #define E4_MICROSTEPS   E0_MICROSTEPS
    #define E4_RSENSE         0.11
    #define E4_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(E5)
    #define E5_CURRENT      800
    #define E5_MICROSTEPS   E0_MICROSTEPS
    #define E5_RSENSE         0.11
    #define E5_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(E6)
    #define E6_CURRENT      800
    #define E6_MICROSTEPS   E0_MICROSTEPS
    #define E6_RSENSE         0.11
    #define E6_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC_CONFIG(E7)
    #define E7_CURRENT      800
    #define E7_MICROSTEPS   E0_MICROSTEPS
    #define E7_RSENSE         0.11
    #define E7_CHAIN_POS     -1
  #endif

  // @section tmc/stealthchop

  #if HAS_STEALTHCHOP
    #define STEALTHCHOP_XY
    #define STEALTHCHOP_Z
    #define STEALTHCHOP_I
    #define STEALTHCHOP_J
    #define STEALTHCHOP_K
    #define STEALTHCHOP_U
    #define STEALTHCHOP_V
    #define STEALTHCHOP_W
    #define STEALTHCHOP_E
  #endif

  #define CHOPPER_TIMING CHOPPER_DEFAULT_24V

  // @section tmc/hybrid

  #define HYBRID_THRESHOLD

  #define X_HYBRID_THRESHOLD     150  // [mm/s]
  #define X2_HYBRID_THRESHOLD    100
  #define Y_HYBRID_THRESHOLD     150
  #define Y2_HYBRID_THRESHOLD    100
  #define Z_HYBRID_THRESHOLD      10
  #define Z2_HYBRID_THRESHOLD     10
  #define Z3_HYBRID_THRESHOLD      3
  #define Z4_HYBRID_THRESHOLD      3
  #define I_HYBRID_THRESHOLD       3
  #define J_HYBRID_THRESHOLD       3
  #define K_HYBRID_THRESHOLD       3
  #define U_HYBRID_THRESHOLD       3
  #define V_HYBRID_THRESHOLD       3
  #define W_HYBRID_THRESHOLD       3
  #define E0_HYBRID_THRESHOLD     30
  #define E1_HYBRID_THRESHOLD     30
  #define E2_HYBRID_THRESHOLD     30
  #define E3_HYBRID_THRESHOLD     30
  #define E4_HYBRID_THRESHOLD     30
  #define E5_HYBRID_THRESHOLD     30
  #define E6_HYBRID_THRESHOLD     30
  #define E7_HYBRID_THRESHOLD     30

  // @section tmc/config

  #define SQUARE_WAVE_STEPPING

  #define TMC_ADV() {  }

#endif // HAS_TRINAMIC_CONFIG || HAS_TMC26X

// @section reporting

#define AUTO_REPORT_TEMPERATURES

#define EXTENDED_CAPABILITIES_REPORT
#if ENABLED(EXTENDED_CAPABILITIES_REPORT)
  //#define M115_GEOMETRY_REPORT
#endif

// @section volumetrics

#if DISABLED(NO_VOLUMETRICS)
  //#define VOLUMETRIC_DEFAULT_ON
  //#define VOLUMETRIC_EXTRUDER_LIMIT
  #if ENABLED(VOLUMETRIC_EXTRUDER_LIMIT)
    #define DEFAULT_VOLUMETRIC_EXTRUDER_LIMIT 0.00
  #endif
#endif

// @section gcode

#define FASTER_GCODE_PARSER
#if ENABLED(FASTER_GCODE_PARSER)
  //#define GCODE_QUOTED_STRINGS
#endif

// @section gcode

// Custom Menu — Leveling Tools
#if ANY(ABL_UBL, ABL_BI)
  #define CUSTOM_MENU_MAIN
#endif

#if ENABLED(CUSTOM_MENU_MAIN)
  #define CUSTOM_MENU_MAIN_TITLE "Leveling Tools"
  #define CUSTOM_MENU_MAIN_SCRIPT_AUDIBLE_FEEDBACK
  #define CUSTOM_MENU_MAIN_SCRIPT_RETURN
  #define CUSTOM_MENU_MAIN_ONLY_IDLE

  #define CommBedTmp "55"   // BedDC

  #if ENABLED(DualZ)
    #define DualZComm "\nG34I8"
  #else
    #define DualZComm ""
  #endif

  #if ENABLED(EXTENSIBLE_UI)
    #define PRINTTIMERSTOP ""
  #else
    #define PRINTTIMERSTOP "M77\n"
  #endif

  #define MAIN_MENU_ITEM_1_DESC "Setup"
  #if (ENABLED(ABL_UBL))
    #define MAIN_MENU_ITEM_1_GCODE "M190S" CommBedTmp "\nG28" DualZComm "\nG29P1\nG29P3\nG29S1\nG29S0\nG29F0.0\nG29A\nM104S215\nG28\nM109S215\nG1X150Y150F5000\nG1Z0\nM500\nM400\n" PRINTTIMERSTOP "M117 Set Z Offset"
  #elif ENABLED(ABL_BI)
    #define MAIN_MENU_ITEM_1_GCODE "M190S" CommBedTmp "\nG28" DualZComm "\nG29\nM400\nM104S215\nG28\nM109S215\nM420S1\nG1X100Y100F5000\nG1Z0\nM500\n" PRINTTIMERSTOP "M117 Set Z Offset"
  #endif
  #define MAIN_MENU_ITEM_1_CONFIRM

  #define MAIN_MENU_ITEM_2_DESC "PID Tune"
  #define MAIN_MENU_ITEM_2_GCODE "M106S128\nM303C8S215E0U\nM500\nM117 PID Tune Done"
  #define MAIN_MENU_ITEM_2_CONFIRM

  #define MAIN_MENU_ITEM_3_DESC "Prep for Z Adjust"
  #define MAIN_MENU_ITEM_3_GCODE "M190S" CommBedTmp "\nM104S215\nG28\nG29L1\nG1 X100Y100F5000\nG1Z0"
  #define MAIN_MENU_ITEM_3_CONFIRM

  #define MAIN_MENU_ITEM_4_DESC "Store Settings"
  #define MAIN_MENU_ITEM_4_GCODE "M500\nM117 Settings Stored"
  #define MAIN_MENU_ITEM_4_CONFIRM
#endif

// @section host

#define HOST_ACTION_COMMANDS
#if ENABLED(HOST_ACTION_COMMANDS)
  #define HOST_PROMPT_SUPPORT
  #if ENABLED(HOST_PROMPT_SUPPORT)
    #define HOST_STATUS_NOTIFICATIONS
  #endif
  #define HOST_START_MENU_ITEM
#endif

// @section extras

// Cancel Objects — disabled because EXTENSIBLE_UI is enabled
// #define CANCEL_OBJECTS

// @section stats

#if ENABLED(PRINTCOUNTER)
  #define SERVICE_WARNING_BUZZES  3
#endif

// @section develop

#define DIRECT_PIN_CONTROL

#if HAS_ETHERNET
  #define MAC_ADDRESS { 0xDE, 0xAD, 0xBE, 0xEF, 0xF0, 0x0D }
#endif
