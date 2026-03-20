/*
 * Configuration.h — CR-10S Pro V2 + Microswiss Direct Drive
 *
 * Build flags (set in platformio.ini):
 *   -DMachineCR10SProV2 -DHotendAllMetal -DBedDC -DMicroswissDirectDrive (pokud není v platformio.ini)
 *
 * Vyčištěno od multi-machine podmínek. Pouze CR-10S Pro V2.
 */

#ifndef HotendAllMetal
  #define HotendAllMetal
#endif
#define MicroswissDirectDrive

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
#pragma once

#define CONFIGURATION_H_VERSION 02010300
#define DEBUG_LEVELING_FEATURE

#define STRING_CONFIG_H_AUTHOR "TinyMachines3D" // Who made the changes.
#define CUSTOM_VERSION_FILE Version.h // Path from the root directory (no quotes)

#if ANY(SKRMiniE3V2, SKRMiniE3V3, SKRE3Turbo)
  #define SKR_2209
  #define SKR_UART
  #if NONE(FORCE10SPRODISPLAY, MachineEnder3Touchscreen, FORCEV2DISPLAY)
    #define OrigLCD
  #else
    #define NO_CONTROLLER_CUSTOM_WIRING_WARNING
  #endif
#endif

#if ENABLED(CrealityTitan)
  #define E3DTitan
#endif

// CR-10S Pro V2 + Microswiss Direct Drive — resolved machine flags
#define MachineCR10SPro
#define MachineCR10Std
#define ABL_BI
#define lerdgeFilSensor
#define DirectDrive
#define FORCE10SPRODISPLAY
#define HotendStock
#define MeshStd
#define POWER_LOSS_RECOVERY
#define Z_STOP_PIN 19

#define SERIAL_PORT 0
#define LCD_SERIAL_PORT 2
#define LCD_BAUDRATE 115200
#define SERIAL_CATCHALL 0

#define BAUDRATE 250000

// CR-10S Pro V2 uses RAMPS Creality board
#define MOTHERBOARD BOARD_RAMPS_CREALITY

// CR-10S Pro V2 stepper drivers: TMC2208 in standalone mode
#define X_DRIVER_TYPE  TMC2208_STANDALONE
#define Y_DRIVER_TYPE  TMC2208_STANDALONE
#define Z_DRIVER_TYPE  TMC2208_STANDALONE
#define E0_DRIVER_TYPE TMC2208_STANDALONE
#define E1_DRIVER_TYPE TMC2208_STANDALONE

#ifdef I_DRIVER_TYPE
  #define AXIS4_NAME 'A' // :['A', 'B', 'C', 'U', 'V', 'W']
  #define AXIS4_ROTATES
#endif
#ifdef J_DRIVER_TYPE
  #define AXIS5_NAME 'B' // :['B', 'C', 'U', 'V', 'W']
  #define AXIS5_ROTATES
#endif
#ifdef K_DRIVER_TYPE
  #define AXIS6_NAME 'C' // :['C', 'U', 'V', 'W']
  #define AXIS6_ROTATES
#endif
#ifdef U_DRIVER_TYPE
  #define AXIS7_NAME 'U' // :['U', 'V', 'W']
#endif
#ifdef V_DRIVER_TYPE
  #define AXIS8_NAME 'V' // :['V', 'W']
#endif
#ifdef W_DRIVER_TYPE
  #define AXIS9_NAME 'W' // :['W']
#endif

#if ANY(Dual_BowdenSplitterY, Dual_CyclopsSingleNozzle, Dual_ChimeraDualNozzle)
  #define EXTRUDERS 2
#else
  #define EXTRUDERS 1
#endif
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

// CR-10S Pro V2: stock thermistor (type 1), DC bed (type 5)
#define TEMP_SENSOR_0   1
#define TEMP_SENSOR_1   0
#define TEMP_SENSOR_2   0
#define TEMP_SENSOR_3   0
#define TEMP_SENSOR_4   0
#define TEMP_SENSOR_5   0
#define TEMP_SENSOR_6   0
#define TEMP_SENSOR_7   0
#define TEMP_SENSOR_BED 5

#define TEMP_SENSOR_PROBE 0

#define TEMP_SENSOR_CHAMBER 0
#define TEMP_SENSOR_COOLER 0
#define TEMP_SENSOR_BOARD 0
#define TEMP_SENSOR_REDUNDANT 0

#define DUMMY_THERMISTOR_998_VALUE  25
#define DUMMY_THERMISTOR_999_VALUE 100

#if TEMP_SENSOR_IS_MAX_TC(0)
  #define MAX31865_SENSOR_OHMS_0      100 // (Ω) Typically 100 or 1000 (PT100 or PT1000)
  #define MAX31865_CALIBRATION_OHMS_0 430 // (Ω) Typically 430 for Adafruit PT100; 4300 for Adafruit PT1000
#endif
#if TEMP_SENSOR_IS_MAX_TC(1)
  #define MAX31865_SENSOR_OHMS_1      100
  #define MAX31865_CALIBRATION_OHMS_1 430
#endif
#if TEMP_SENSOR_IS_MAX_TC(2)
  #define MAX31865_SENSOR_OHMS_2      100
  #define MAX31865_CALIBRATION_OHMS_2 430
#endif

#define TEMP_SENSOR_REDUNDANT_MAX_DIFF 10

#if HAS_E_TEMP_SENSOR
  #define TEMP_RESIDENCY_TIME     2  // (seconds) Time to wait for hotend to "settle" in M109
  #if ENABLED(UnstableTemps)
    #define TEMP_WINDOW              5  // (°C) Temperature proximity for the "temperature reached" timer
    #define TEMP_HYSTERESIS          7  // (°C) Temperature proximity considered "close enough" to the target
  #else
    #define TEMP_WINDOW              1  // (°C) Temperature proximity for the "temperature reached" timer
    #define TEMP_HYSTERESIS          3  // (°C) Temperature proximity considered "close enough" to the target
  #endif

#endif
#if TEMP_SENSOR_BED
  #define TEMP_BED_RESIDENCY_TIME 5  // (seconds) Time to wait for bed to "settle" in M190
  #define TEMP_BED_WINDOW          2  // (°C) Temperature proximity for the "temperature reached" timer
  #define TEMP_BED_HYSTERESIS      3  // (°C) Temperature proximity considered "close enough" to the target
#endif

#if TEMP_SENSOR_CHAMBER
  #define TEMP_CHAMBER_RESIDENCY_TIME 10  // (seconds) Time to wait for chamber to "settle" in M191
  #define TEMP_CHAMBER_WINDOW          1  // (°C) Temperature proximity for the "temperature reached" timer
  #define TEMP_CHAMBER_HYSTERESIS      3  // (°C) Temperature proximity considered "close enough" to the target
#endif

#if TEMP_SENSOR_REDUNDANT
  #define TEMP_SENSOR_REDUNDANT_SOURCE    E1  // The sensor that will provide the redundant reading.
  #define TEMP_SENSOR_REDUNDANT_TARGET    E0  // The sensor that we are providing a redundant reading for.
  #define TEMP_SENSOR_REDUNDANT_MAX_DIFF  10  // (°C) Temperature difference that will trigger a print abort.
#endif

#define HEATER_0_MINTEMP   5
#define HEATER_1_MINTEMP   5
#define HEATER_2_MINTEMP   5
#define HEATER_3_MINTEMP   5
#define HEATER_4_MINTEMP   5
#define HEATER_5_MINTEMP   5
#define HEATER_6_MINTEMP   5
#define HEATER_7_MINTEMP   5
#define BED_MINTEMP        5
#define CHAMBER_MINTEMP    5

// Microswiss all-metal hotend
#define HEATER_0_MAXTEMP 315
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define HEATER_4_MAXTEMP 275
#define HEATER_5_MAXTEMP 275
#define HEATER_6_MAXTEMP 275
#define HEATER_7_MAXTEMP 275
#define BED_MAXTEMP      150
#define CHAMBER_MAXTEMP  60

#define HOTEND_OVERSHOOT 15   // (°C) Forbid temperatures over MAXTEMP - OVERSHOOT
#define BED_OVERSHOOT    10   // (°C) Forbid temperatures over MAXTEMP - OVERSHOOT
#define COOLER_OVERSHOOT  2   // (°C) Forbid temperatures closer than OVERSHOOT

#define PIDTEMP          // See the PID Tuning Guide at https://reprap.org/wiki/PID_Tuning

#define BANG_MAX 255     // Limits current to nozzle while in bang-bang mode; 255=full current
#define PID_MAX BANG_MAX // Limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#define PID_K1 0.95      // Smoothing factor within any PID loop

#if ENABLED(PIDTEMP)
  #define PID_EDIT_MENU         // Add PID editing to the "Advanced Settings" menu. (~700 bytes of PROGMEM)
  #define PID_AUTOTUNE_MENU     // Add PID auto-tuning to the "Advanced Settings" menu. (~250 bytes of PROGMEM)
                                  // Set/get with G-code: M301 E[extruder number, 0-2]

  #if ENABLED(PID_PARAMS_PER_HOTEND)
    #define DEFAULT_Kp_LIST {  22.20,  22.20 }
    #define DEFAULT_Ki_LIST {   1.08,   1.08 }
    #define DEFAULT_Kd_LIST { 114.00, 114.00 }
  #else
    // CR-10S Pro V2 PID values
    #define DEFAULT_Kp 25.25
    #define DEFAULT_Ki 2.17
    #define DEFAULT_Kd 73.44
  #endif
#endif

#if NONE(MachineCR10Orig, LowMemoryBoard, SKRMiniE3V2) || ENABLED(MelziHostOnly)
  #define PIDTEMPBED
#endif

#define MAX_BED_POWER 255 // limits duty cycle to bed; 255=full current

#if ENABLED(PIDTEMPBED)

  // CR-10S Pro V2 bed PID
  #define DEFAULT_bedKp 690.34
  #define DEFAULT_bedKi 111.47
  #define DEFAULT_bedKd 1068.83

#endif // PIDTEMPBED

#define MAX_CHAMBER_POWER 255 // limits duty cycle to chamber heater; 255=full current

#if ANY(PIDTEMP, PIDTEMPBED, PIDTEMPCHAMBER)
  #define PID_FUNCTIONAL_RANGE 10 // If the temperature difference between the target temperature and the actual temperature

#endif

#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170

#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 750

#define THERMAL_PROTECTION_HOTENDS // Enable thermal protection for all extruders
#define THERMAL_PROTECTION_BED     // Enable thermal protection for the heated bed
#define THERMAL_PROTECTION_CHAMBER // Enable thermal protection for the heated chamber
#define THERMAL_PROTECTION_COOLER  // Enable thermal protection for the laser cooling

// either in the usual order or reversed
#if ANY(MachineEnder4, MachineEnder6, MachineEnder7, MachineCR30)
  #define COREXY
#endif

#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG

#define ENDSTOPPULLUPS

#define X_MIN_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Y_MIN_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.

#define X_MAX_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Y_MAX_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Z_MAX_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.

#define Z_MIN_ENDSTOP_INVERTING false  // set to true to invert the logic of the endstop.
#define Z_MIN_PROBE_ENDSTOP_INVERTING true // INVERTOVÁNO - proximity senzor na pin 2 (X_MAX) má opačnou logiku

#if ANY(MachineEnder3V2, MachineEnder3S1, Creality422, MachineEnder2Pro, MachineCR10SmartPro) && NONE(SKRE3Turbo, SKR14Turbo, SKR14, SKR13)
  #define ENDSTOP_INTERRUPTS_FEATURE
#endif

#if ANY(MachineEnder5Plus, CableExtensionNoiseFilter, MachineCR6, MachineCR6Max, MachineEnder6, MachineCR10Smart, MachineSermoonD1)
  #define ENDSTOP_NOISE_THRESHOLD 2
#endif

#define DISTINCT_E_FACTORS

// CR-10S Pro V2 + Microswiss DD steps/mm
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 130 }  // E-steps: 130 stock, kalibrace přes M92 E343 v EEPROM

// CR-10S Pro V2 motion settings
#define DEFAULT_MAX_FEEDRATE          { 500, 500, 10, 70 }
#define DEFAULT_MAX_ACCELERATION      { 750, 750, 100, 60 }
#define DEFAULT_ACCELERATION          750
#define DEFAULT_RETRACT_ACCELERATION  1000
#define DEFAULT_TRAVEL_ACCELERATION   300

#if ENABLED(LIMITED_MAX_FR_EDITING)
  #define MAX_FEEDRATE_EDIT_VALUES    { 1000, 1000, 25, 150 } // ...or, set your own edit limits
#endif

#if ENABLED(LIMITED_MAX_ACCEL_EDITING)
  #define MAX_ACCEL_EDIT_VALUES       { 2000, 2000, 250, 500 } // ...or, set your own edit limits
#endif

#define CLASSIC_JERK
#if ENABLED(CLASSIC_JERK)
  #define DEFAULT_XJERK 10.0
  #define DEFAULT_YJERK  5.0
  #define DEFAULT_ZJERK  0.3

  #if ENABLED(LIMITED_JERK_EDITING)
    #define MAX_JERK_EDIT_VALUES { 20, 20, 0.6, 10 } // ...or, set your own edit limits
  #endif
#endif

#define DEFAULT_EJERK    5.0  // May be used by Linear Advance

#if DISABLED(CLASSIC_JERK)
  #define JUNCTION_DEVIATION_MM 0.013 // (mm) Distance from real junction edge
  #define JD_HANDLE_SMALL_SEGMENTS    // Use curvature estimation instead of just the junction angle
#endif

#if NONE(MachineCR10Orig, SKRMiniE3V2, MachineCR6, MachineCR6Max, MachineCR10Smart, MachineCR10SmartPro) || ENABLED(MelziHostOnly)
  #define S_CURVE_ACCELERATION
#endif

// Force the use of the probe for Z-axis homing
#define USE_PROBE_FOR_Z_HOMING  // AI_DEBUG: AKTIVNÍ - Použije probe pro Z homing

#define FIX_MOUNTED_PROBE

#define NOZZLE_TO_PROBE_OFFSET { -30, 15, -0.1 }  // Původní kalibrovaný offset

#define PROBING_MARGIN 35

// X and Y axis travel speed (mm/min) between probes
#define XY_PROBE_FEEDRATE (200*60)

#define Z_PROBE_FEEDRATE_FAST (12*60)

// Feedrate (mm/min) for the "accurate" probe of each point
#define Z_PROBE_FEEDRATE_SLOW (Z_PROBE_FEEDRATE_FAST / 2)

#if DISABLED(MachineCR10Orig) || ENABLED(MelziHostOnly)
  #define MULTIPLE_PROBING 2
#endif

#define Z_CLEARANCE_DEPLOY_PROBE   10 // Z Clearance for Deploy/Stow
#if ANY(MachineCR6, MachineCR6Max, MachineCR10Smart)
  #define Z_CLEARANCE_BETWEEN_PROBES  3 // Z Clearance between probe points
  #define Z_CLEARANCE_MULTI_PROBE     3 // Z Clearance between multiple probes
#else
  #define Z_CLEARANCE_BETWEEN_PROBES  5 // Z Clearance between probe points
  #define Z_CLEARANCE_MULTI_PROBE     5 // Z Clearance between multiple probes
#endif
#define Z_AFTER_PROBING           5 // Z position after probing is done

#define Z_PROBE_LOW_POINT          -5 // Farthest distance below the trigger-point to go before stopping

#define Z_PROBE_OFFSET_RANGE_MIN -9
#define Z_PROBE_OFFSET_RANGE_MAX 9

// Before deploy/stow pause for user confirmation

#if ENABLED(PROBING_HEATERS_OFF)
  #define WAIT_FOR_BED_HEATER     // Wait for bed to heat back up between probes (to improve accuracy)
  #define WAIT_FOR_HOTEND         // Wait for hotend to heat back up between probes (to improve accuracy & prevent cold extrude)
#endif

#if ANY(MachineCR6, MachineCR6Max, MachineCR10Smart)
  #define PREHEAT_BEFORE_PROBING
#endif
#if ENABLED(PREHEAT_BEFORE_PROBING)
  #define PROBING_NOZZLE_TEMP 170   // (°C) Only applies to E0 at this time
  #define PROBING_BED_TEMP     50
#endif

// :{ 0:'Low', 1:'High' }
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // For all extruders

#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false

#define DISABLE_E false             // For all extruders
#define DISABLE_INACTIVE_EXTRUDER   // Keep only the active extruder enabled

#if(ANY(MachineEnder4, MachineEnder5) && ANY(Creality422, Creality427))
  #define INVERT_X_DIR false
  #define INVERT_Y_DIR false
  #define INVERT_Z_DIR false
  #if(ENABLED(E3DTitan))
    #define INVERT_E0_DIR true
    #define INVERT_E1_DIR false
  #else
    #define INVERT_E0_DIR false
    #define INVERT_E1_DIR true
  #endif
#elif(ANY(MachineEnder4, MachineEnder5, MachineCR30) && NONE(Creality422, Creality427))
  #define INVERT_X_DIR true
  #define INVERT_Y_DIR true
  #define INVERT_Z_DIR true
  #if(ENABLED(E3DTitan))
    #define INVERT_E0_DIR false
    #define INVERT_E1_DIR true
  #else
    #define INVERT_E0_DIR true
    #define INVERT_E1_DIR false
  #endif
#elif ANY(MachineCR6, MachineCR6Max, MachineCR10Smart, MachineCR10SmartPro)
  #define INVERT_X_DIR true
  #define INVERT_Y_DIR false
  #define INVERT_Z_DIR true
  #define INVERT_E0_DIR true
  #define INVERT_E1_DIR false
#elif ANY(MachineCR10Orig, SKR13, SKR14, SKR14Turbo, SKRMiniE3V2, SKRMiniE3V3, SKRE3Turbo) && DISABLED(SKR_ReverseSteppers)
  #define INVERT_X_DIR true
  #define INVERT_Y_DIR true
  #if ANY(MachineEnder5Plus, MachineCR2020)
    #define INVERT_Z_DIR true
  #else
    #define INVERT_Z_DIR false
  #endif
  #if(ENABLED(E3DTitan))
    #define INVERT_E0_DIR false
    #define INVERT_E1_DIR true
  #else
    #define INVERT_E0_DIR true
    #define INVERT_E1_DIR false
  #endif
#else
  #if ANY(MachineCR10Orig, SKR13, SKR14, SKR14Turbo, SKRMiniE3V2, SKRMiniE3V3, SKRE3Turbo) && ENABLED(SKR_ReverseSteppers) && ENABLED(MachineEnder6)
    #define INVERT_X_DIR true
    #define INVERT_Y_DIR false
  #else
    #if ANY(MachineSermoonD1, MachineCR5)
      #define INVERT_X_DIR true
    #else
      #define INVERT_X_DIR false
    #endif
    #if ANY(MachineCRX,MachineCR10SPro, MachineCR10Max, MachineCR2020, MachineCR5, MachineEnder6, MachineEnder7)
      #define INVERT_Y_DIR true
    #else
      #define INVERT_Y_DIR false
    #endif
  #endif
  #if ANY(MachineEnder5Plus, MachineCR2020, MachineEnder6, MachineSermoonD1, MachineEnder7)
    #define INVERT_Z_DIR false
  #else
    #define INVERT_Z_DIR true
  #endif
  #if ANY(E3DTitan, MachineCR2020, MachineCR5, MachineEnder6, MachineEnder7)
    #define INVERT_E0_DIR true
    #define INVERT_E1_DIR false
  #else
    #define INVERT_E0_DIR false
    #define INVERT_E1_DIR true
  #endif
#endif

#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false
#define INVERT_E6_DIR false
#define INVERT_E7_DIR false

#define Z_HOMING_HEIGHT 4  // (in mm) Minimal z height before homing (G28) for Z clearance above the bed, clamps, ...

// Direction of endstops when homing; 1=MAX, -1=MIN

  #define X_HOME_DIR -1
  #define Y_HOME_DIR -1
  #define Z_HOME_DIR -1

// CR-10S Pro V2 bed dimensions
#define X_BED_SIZE 300
#define Y_BED_SIZE 300
#define Z_MAX_POS  400
#define X_MAX_POS  315
#define Y_MAX_POS  310
#define ClipClearance 5

// Travel limits — Microswiss Direct Drive offsets
#define X_MIN_POS -15
#define Y_MIN_POS -10
#define Z_MIN_POS  0

#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
  #define MIN_SOFTWARE_ENDSTOP_I
  #define MIN_SOFTWARE_ENDSTOP_J
  #define MIN_SOFTWARE_ENDSTOP_K
  #define MIN_SOFTWARE_ENDSTOP_U
  #define MIN_SOFTWARE_ENDSTOP_V
  #define MIN_SOFTWARE_ENDSTOP_W
#endif

#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
  #define MAX_SOFTWARE_ENDSTOP_I
  #define MAX_SOFTWARE_ENDSTOP_J
  #define MAX_SOFTWARE_ENDSTOP_K
  #define MAX_SOFTWARE_ENDSTOP_U
  #define MAX_SOFTWARE_ENDSTOP_V
  #define MAX_SOFTWARE_ENDSTOP_W
#endif
#if(NONE(MachineCR10Orig, LowMemoryBoard))
  #if EITHER(MIN_SOFTWARE_ENDSTOPS, MAX_SOFTWARE_ENDSTOPS)
    #define SOFT_ENDSTOPS_MENU_ITEM  // Enable/Disable software endstops from the LCD
  #endif
#endif

// Filament runout sensor — VYPNUTO (Microswiss nemá fil. runout, pin 2 sdílený s probe)

#define AUTO_BED_LEVELING_BILINEAR
#define RESTORE_LEVELING_AFTER_G28

#if ENABLED(PREHEAT_BEFORE_LEVELING)
  #define LEVELING_NOZZLE_TEMP 120   // (°C) Only applies to E0 at this time
  #define LEVELING_BED_TEMP     50
#endif

#define DEBUG_LEVELING_FEATURE

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_UBL, PROBE_MANUALLY)
  // Set a height for the start of manual adjustment
  #define MANUAL_PROBE_START_Z 0.2  // (mm) Comment out to use the last-measured height
#endif

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_BILINEAR, AUTO_BED_LEVELING_UBL)
  #if NONE(MachineCR10Orig, SKRMiniE3V2)
    #define ENABLE_LEVELING_FADE_HEIGHT
    #if ENABLED(ENABLE_LEVELING_FADE_HEIGHT)
      #define DEFAULT_LEVELING_FADE_HEIGHT 10.0 // (mm) Default fade height.
    #endif
  #endif

  #if DISABLED(ABL_UBL)
    #define SEGMENT_LEVELED_MOVES
    #define LEVELED_SEGMENT_LENGTH 5.0 // (mm) Length of all segments (except the last one)
  #endif

#if NONE(MachineCR10Orig, SKRMiniE3V2)
  #define G26_MESH_VALIDATION   // Enable G26 mesh validation
#endif
  #if ENABLED(G26_MESH_VALIDATION)
    #define MESH_TEST_NOZZLE_SIZE    0.4  // (mm) Diameter of primary nozzle.
    #define MESH_TEST_LAYER_HEIGHT   0.2  // (mm) Default layer height for G26.
    #define MESH_TEST_HOTEND_TEMP  205    // (°C) Default nozzle temperature for G26.
    #define MESH_TEST_BED_TEMP      60    // (°C) Default bed temperature for G26.
    #define G26_XY_FEEDRATE         20    // (mm/s) Feedrate for G26 XY moves.
    #define G26_XY_FEEDRATE_TRAVEL 100    // (mm/s) Feedrate for G26 XY travel moves.
    #define G26_RETRACT_MULTIPLIER   1.0  // G26 Q (retraction) used by default between mesh test elements.
  #endif

#endif

// MeshStd: 5x5 grid (MeshFast/MeshFine/MeshExtreme removed)
#define GRID_MAX_POINTS_X 5
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

#if EITHER(AUTO_BED_LEVELING_LINEAR, AUTO_BED_LEVELING_BILINEAR)

  // Probe along the Y axis, advancing X after each column
  #if ENABLED(MachineCR6)
    #define PROBE_Y_FIRST
  #endif
  #if ENABLED(AUTO_BED_LEVELING_BILINEAR)

    // Set Mesh bounds as an inset region of the bed
    #define MESH_INSET 40          // (mm) Inset from bed edges for mesh probing

    // Beyond the probed grid, continue the implied tilt?
    #define EXTRAPOLATE_BEYOND_GRID

    #if ENABLED(ABL_BILINEAR_SUBDIVISION)
      // Number of subdivisions between probe points
      #define BILINEAR_SUBDIVISIONS 3
    #endif

  #endif

#elif ENABLED(AUTO_BED_LEVELING_UBL)

  #define MESH_INSET 1
  #if NONE(MachineCR10SPro, MachineCRX, MachineEnder5Plus, MachineCR10Max, MachineEnder4, OrigLCD) || ANY(GraphicLCD, OrigLCD)
    #define MESH_EDIT_GFX_OVERLAY   // Display a graphics overlay while editing the mesh
  #endif

  #define UBL_HILBERT_CURVE       // Use Hilbert distribution for less travel when probing multiple points

  #define UBL_MESH_EDIT_MOVES_Z     // Sophisticated users prefer no movement of nozzle
  #define UBL_SAVE_ACTIVE_ON_M500   // Save the currently active mesh in the current slot on M500

  #define UBL_Z_RAISE_WHEN_OFF_MESH 0 // When the nozzle is off the mesh, this value is used
                                          // as the Z-Height correction value.

#elif ENABLED(MESH_BED_LEVELING)

#define MESH_INSET 20

#endif // BED_LEVELING

// LCD_BED_TRAMMING — used by Creality DWIN display
#define LCD_BED_TRAMMING
#define BED_TRAMMING_INSET_LFRB { 22, 22, 22, 22 } // (mm) Left, Front, Right, Back insets
#define BED_TRAMMING_HEIGHT      0.0        // (mm) Z height of nozzle at leveling points
#define BED_TRAMMING_Z_HOP       4.0        // (mm) Z height of nozzle between leveling points
#define BED_TRAMMING_LEVELING_ORDER { LF, RF, RB, LB }

#define Z_SAFE_HOMING

#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT (X_BED_SIZE / 2)  // X point for Z homing
  #define Z_SAFE_HOMING_Y_POINT (Y_BED_SIZE / 2)  // Y point for Z homing
#endif

// Homing speeds (linear=mm/min, rotational=°/min)
#define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (10*60) }

// Validate that endstops are triggered on homing moves
#define VALIDATE_HOMING_ENDSTOPS

#define EEPROM_SETTINGS     // Persistent storage with M500 and M501
#define LowMemoryBoard    // Give feedback on EEPROM commands. Disable to save PROGMEM.
#if DISABLED(LowMemoryBoard)
  #define EEPROM_CHITCHAT       // Give feedback on EEPROM commands. Disable to save PROGMEM.
#endif
#define EEPROM_BOOT_SILENT    // Keep M503 quiet and only give errors during first load
#if ENABLED(EEPROM_SETTINGS)
  #define EEPROM_AUTO_INIT  // Init EEPROM automatically on any errors.
#endif

#if NONE(MachineCR10Orig, MelziHostOnly)
  #define HOST_KEEPALIVE_FEATURE        // Disable this if your host doesn't like keepalive messages
  #define DEFAULT_KEEPALIVE_INTERVAL 2  // Number of seconds between "busy" messages. Set with M113.
  #define BUSY_WHILE_HEATING            // Some hosts require "busy" messages even during heating
#endif

#define PREHEAT_1_LABEL       "PLA"
#define PREHEAT_1_TEMP_HOTEND 180
#define PREHEAT_1_TEMP_BED     70
#define PREHEAT_1_TEMP_CHAMBER 35
#define PREHEAT_1_FAN_SPEED     0 // Value from 0 to 255

#define PREHEAT_2_LABEL       "ABS"
#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    110
#define PREHEAT_2_TEMP_CHAMBER 35
#define PREHEAT_2_FAN_SPEED     0 // Value from 0 to 255

#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE)
  #if(ANY(MachineEnder2, MachineEnder2Pro))
    #define NOZZLE_PARK_POINT { (0), (0), 10 }
  #else
    #define NOZZLE_PARK_POINT { (50), (10), 10 }
  #endif

  #define NOZZLE_PARK_MOVE          0   // Park motion: 0 = XY Move, 1 = X Only, 2 = Y Only, 3 = X before Y, 4 = Y before X
  #define NOZZLE_PARK_Z_RAISE_MIN   2   // (mm) Always raise Z by at least this distance
#define NOZZLE_PARK_XY_FEEDRATE 50   // X and Y axes feedrate in mm/s (also used for delta printers Z axis)
#define NOZZLE_PARK_Z_FEEDRATE 5      // Z axis feedrate in mm/s (not used for delta printers)
#endif

#if ANY(MachineCRX, PurgeBucket)
  #define NOZZLE_CLEAN_FEATURE
#endif
#if ENABLED(NOZZLE_CLEAN_FEATURE)
  // Default number of pattern repetitions
  #define NOZZLE_CLEAN_STROKES  5

  // Default number of triangles
  #define NOZZLE_CLEAN_TRIANGLES  3

  #define NOZZLE_CLEAN_START_POINT { X_MAX_POS, 40, (Z_MIN_POS + 1)}
  #define NOZZLE_CLEAN_END_POINT   { (X_MAX_POS - 10), 40, (Z_MIN_POS + 1) }

  // Circular pattern radius
  #define NOZZLE_CLEAN_CIRCLE_RADIUS 6.5
  // Circular pattern circle fragments number
  #define NOZZLE_CLEAN_CIRCLE_FN 10
  // Middle point of circle
  #define NOZZLE_CLEAN_CIRCLE_MIDDLE NOZZLE_CLEAN_START_POINT

  #define NOZZLE_CLEAN_GOBACK

  #define NOZZLE_CLEAN_NO_Z

  #define NOZZLE_CLEAN_MIN_TEMP 170

#endif

#if NONE(MachineCR10Orig, LowMemoryBoard) || ENABLED(MelziHostOnly)
 #define PRINTJOB_TIMER_AUTOSTART
#endif
#if NONE(MachineCR10Orig, LowMemoryBoard, SKRMiniE3V2)
  #define PRINTCOUNTER
  #if ENABLED(PRINTCOUNTER)
    #define PRINTCOUNTER_SAVE_INTERVAL 60 // (minutes) EEPROM save interval during print
  #endif
#endif

#define LCD_LANGUAGE en

#define DISPLAY_CHARSET_HD44780 JAPANESE

#define LCD_INFO_SCREEN_STYLE 0

#if DISABLED(MelziHostOnly)
  #define SDSUPPORT
#endif

#if ANY(MachineCR10Orig, SKRMiniE3V2) && DISABLED(MelziHostOnly) && ENABLED(ABL_BI)
  #define SLIM_LCD_MENUS
#endif

#if ANY(MachineCR20, MachineEnder3V2)
  #define ENCODER_PULSES_PER_STEP 4
#endif
#define ENCODER_STEPS_PER_MENU_ITEM 1

#if ENABLED(ENCODER_NOISE_FILTER)
  #define ENCODER_SAMPLES 10
#endif

#if NONE(MachineCR10Orig, LowMemoryBoard)
  #define INDIVIDUAL_AXIS_HOMING_MENU
#endif
  #define SPEAKER

#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 2
#define LCD_FEEDBACK_FREQUENCY_HZ 5000

#if ENABLED(MachineEnder4) && DISABLED(GraphicLCD)
  #define REPRAP_DISCOUNT_SMART_CONTROLLER
#elif ENABLED(MachineEnder2)
  #define ENDER2_STOCKDISPLAY
#elif ANY(MachineCR20, MachineCR2020)
  #define MKS_MINI_12864
#elif ANY(MachineEnder3V2, FORCEV2DISPLAY, MachineEnder3S1) && DISABLED(MachineEnder3Touchscreen)
  #define DWIN_MARLINUI_PORTRAIT
#elif ANY(OrigLCD, MachineCR10Orig, MachineEnder3Pro422, MachineEnder3Pro427, MachineEnder3Max, SKRMiniE3V2, SKRE3Turbo) && NONE(GraphicLCD, MachineEnder3Touchscreen, FORCE10SPRODISPLAY)
  #define CR10_STOCKDISPLAY
#elif NONE(MachineCR10SPro, MachineCRX, MachineEnder5Plus, MachineCR10Max, OrigLCD, MachineCR10Orig, SKRMiniE3V2, SKRMiniE3V3, FORCE10SPRODISPLAY, MachineCR6, MachineCR6Max, MachineCR10Smart, MachineCR10SmartPro, MachineEnder3Touchscreen) || ENABLED(GraphicLCD)
  #define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
#endif

#if DGUS_UI_IS(MKS)
  #define USE_MKS_GREEN_UI
#endif

#if ANY(MachineCR6, MachineCR6Max, MachineEnder3Touchscreen)
  #define DGUS_LCD_UI_CREALITY_TOUCH
#endif

#if ANY(MachineCR10SPro, MachineCRX, MachineEnder5Plus, MachineCR10Max, MachineEnder6, MachineCR5, MachineEnder7, MachineSermoonD1, MachineCR10Smart, MachineCR10SmartPro) && (NONE(GraphicLCD, OrigLCD)) || ENABLED(FORCE10SPRODISPLAY)
  #ifndef FORCE10SPRODISPLAY
    #define FORCE10SPRODISPLAY
  #endif
  #define EXTENSIBLE_UI
#endif

  #define FAN_SOFT_PWM
#define SOFT_PWM_SCALE 0

#if ANY(RGB_LED, RGBW_LED, PCA9632)
  #if ENABLED(RGB_STARTUP_TEST)
    #define RGB_STARTUP_TEST_INNER_MS 10  // (ms) Reduce or increase fading speed
  #endif
#endif

#if ANY(BLINKM, RGB_LED, RGBW_LED, PCA9632, PCA9533, NEOPIXEL_LED)
  #define PRINTER_EVENT_LEDS
#endif

#define SERVO_DELAY { 300 }

