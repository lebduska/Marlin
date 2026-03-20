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



#define AUTOTEMP
#if ENABLED(AUTOTEMP)
  #define AUTOTEMP_OLDWEIGHT    0.98
  #define AUTOTEMP_MIN          210
  #define AUTOTEMP_MAX          250
  #define AUTOTEMP_FACTOR       0.1f
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

// @section extruder

#define EXTRUDER_AUTO_FAN_TEMPERATURE 50
#define EXTRUDER_AUTO_FAN_SPEED 255

#define FAN_KICKSTART_TIME  100  // (ms)

// @section homing

#define HOMING_BUMP_MM      { 8, 8, 2 }       // (linear=mm, rotational=°)
#define HOMING_BUMP_DIVISOR { 2, 2, 4 }       // Re-Bump Speed Divisor

#define HOMING_BACKOFF_POST_MM { 8, 8, 2 }  // (linear=mm, rotational=°)

#define QUICK_HOME                          // If G28 contains XY do a diagonal move first


// @section motion

#define AXIS_RELATIVE_MODES { false, false, false, false }

#define INVERT_X_STEP_PIN false
#define INVERT_Y_STEP_PIN false
#define INVERT_Z_STEP_PIN false
#define INVERT_E_STEP_PIN false

#define DEFAULT_STEPPER_DEACTIVE_TIME 120
#define DISABLE_INACTIVE_X true
#define DISABLE_INACTIVE_Y true
#define DISABLE_INACTIVE_Z true
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

#if HAS_MARLINUI_MENU
  #if HAS_BED_PROBE
    #define PROBE_DEPLOY_STOW_MENU
  #endif
  #define LCD_INFO_MENU
#endif

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

#define SET_PROGRESS_MANUALLY
#if ENABLED(SET_PROGRESS_MANUALLY)
  #define SET_PROGRESS_PERCENT
  #define SET_REMAINING_TIME
#endif

#if HAS_DISPLAY && EITHER(SDSUPPORT, SET_PROGRESS_MANUALLY)
  #define SHOW_PROGRESS_PERCENT
  #define SHOW_ELAPSED_TIME
  #define SHOW_REMAINING_TIME
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

  #define UTF_FILENAME_SUPPORT
  #define LONG_FILENAME_HOST_SUPPORT
  #define SCROLL_LONG_FILENAMES
  #define AUTO_REPORT_SD_STATUS

#endif // SDSUPPORT

#define NO_SD_HOST_DRIVE

// DGUS / DWIN display (CR-10S Pro V2 touch screen)
#if HAS_DGUS_LCD || ENABLED(DGUS_LCD_UI_CREALITY_TOUCH) || ENABLED(FORCE10SPRODISPLAY)
  #ifndef LCD_SERIAL_PORT
    #define LCD_SERIAL_PORT 3
    #define LCD_BAUDRATE 115200
  #endif
  #define DGUS_RX_BUFFER_SIZE 128
  #define DGUS_TX_BUFFER_SIZE 48
  #define DGUS_UPDATE_INTERVAL_MS  500
#endif

// @section safety

#define USE_WATCHDOG

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
  #endif

  #define BABYSTEP_ZPROBE_OFFSET
#endif

// @section extruder

// Linear Pressure Control v1.5
#define LIN_ADVANCE
#if ENABLED(LIN_ADVANCE)
  #define ADVANCE_K 0.0
  #define ALLOW_LOW_EJERK
#endif

// @section leveling

// Probing Margins
#if PROBE_SELECTED && !IS_KINEMATIC
  #define PROBING_MARGIN_FRONT (PROBING_MARGIN + ClipClearance)
  #define PROBING_MARGIN_BACK (PROBING_MARGIN + ClipClearance)
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

  #if AXIS_IS_TMC_CONFIG(Y)
    #define Y_CURRENT       730
    #define Y_CURRENT_HOME  800
    #define Y_MICROSTEPS     16
    #define Y_RSENSE          0.11
    #define Y_CHAIN_POS      -1
  #endif

  #if AXIS_IS_TMC_CONFIG(Z)
    #define Z_CURRENT       850
    #define Z_CURRENT_HOME  950
    #define Z_MICROSTEPS     16
    #define Z_RSENSE          0.11
    #define Z_CHAIN_POS      -1
  #endif

  #if AXIS_IS_TMC_CONFIG(E0)
    #define E0_CURRENT      730
    #define E0_MICROSTEPS    16
    #define E0_RSENSE         0.11
    #define E0_CHAIN_POS     -1
  #endif

  // @section tmc/stealthchop

  #if HAS_STEALTHCHOP
    #define STEALTHCHOP_XY
    #define STEALTHCHOP_Z
    #define STEALTHCHOP_E
  #endif

  #define CHOPPER_TIMING CHOPPER_DEFAULT_24V

  // @section tmc/hybrid

  #define HYBRID_THRESHOLD

  #define X_HYBRID_THRESHOLD     150  // [mm/s]
  #define Y_HYBRID_THRESHOLD     150
  #define Z_HYBRID_THRESHOLD      10
  #define E0_HYBRID_THRESHOLD     30

  // @section tmc/config

  #define SQUARE_WAVE_STEPPING

  #define TMC_ADV() {  }

#endif // HAS_TRINAMIC_CONFIG || HAS_TMC26X

// @section reporting

#define AUTO_REPORT_TEMPERATURES

#define EXTENDED_CAPABILITIES_REPORT

// @section gcode

#define FASTER_GCODE_PARSER

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

  #define MAIN_MENU_ITEM_1_DESC "Setup"
  #define MAIN_MENU_ITEM_1_GCODE "M190S55\nG28\nG29\nM400\nM104S215\nG28\nM109S215\nM420S1\nG1X100Y100F5000\nG1Z0\nM500\nM77\nM117 Set Z Offset"
  #define MAIN_MENU_ITEM_1_CONFIRM

  #define MAIN_MENU_ITEM_2_DESC "PID Tune"
  #define MAIN_MENU_ITEM_2_GCODE "M106S128\nM303C8S215E0U\nM500\nM117 PID Tune Done"
  #define MAIN_MENU_ITEM_2_CONFIRM

  #define MAIN_MENU_ITEM_3_DESC "Prep for Z Adjust"
  #define MAIN_MENU_ITEM_3_GCODE "M190S55\nM104S215\nG28\nG29L1\nG1 X100Y100F5000\nG1Z0"
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

#define DIRECT_PIN_CONTROL
