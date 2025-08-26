/*
   Basic Options

   Select Machine
*/

/*
20:41:31.558 > PIN: PB12        M42 P28          <unused/unknown> // Pi Netowork Reset Output
20:41:46.759 > PIN: PA15        M42 P15          <unused/unknown> Spare Pin1
*/

/*
   Hotend Type
   Choose one option below.
   E3D assumes the following mount :
   https://www.thingiverse.com/thing:2494642

   Configured with 5015 left wing, right wing ABL sensor (BLTouch or M18) only

   Mosquito may be set with either mounting option above and overrides temp sensor and max temp
   E3D Mounting assumes Groovemount
   Creality Mounting assumes bolt-on kit
*/

#ifndef HotendAllMetal
  #define HotendAllMetal // AI_DEBUG: AKTIVNÍ - build flag -DHotendAllMetal
#endif

/*
 * Select these if you have changed to a high performance extruder
 */

 #define MicroswissDirectDrive // AI_DEBUG: AKTIVNÍ - Direct drive extruder konfigurace

/*
   Choose bed type below. If you have an extenrally controlled
   ac bed, leave both disabled
*/

/*
   Choose ABL sensor type below
   Leave all disabled if no sensor is available
*/

/**
 * Screen options
 */

/*
   Choose bed leveling type here
   Requires a sensor from above
   Melzi board users may only select ABL_BI for bilinear leveling
   If a probe is enabled and nothing selected here, defaults to Bilinear
*/

/*
   For melzi boards these options allow you to cusomize what you want to do.
   Since the storage space is so small, it cannot fit most options together.
   Even just a probe and leveling with standard options is filling te entire program space!
*/

/**
 * Advanced motherboard replacement options
 */

 /*
  *
  * If any non-stock dual extruder is used, define type here
  */

/*
   Choose a probe grid density below. Faster probes less points, but is less accurate.
   Extreme is for extremely uneven or tilted bed surfaces.
   UBL and Extreme are recommended with solid bed mounts as it becomes a one time commissioning.
   Standard is recommended in most other scenarios.
*/

/*
   Disables SD Sort, Autotemp, Arc support, Linear Advance (Unless overridden with OrigLA above), Big edit fonts, and a few other little things
   Intended to resolve issues with certain newer boards experiencing motion errors under load.
   Enables Slim Menus
*/

/*
   Enclosure Controls
*/

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

/**
 * Configuration.h
 *
 * Basic settings such as:
 *
 * - Type of electronics
 * - Type of temperature sensor
 * - Printer geometry
 * - Endstop configuration
 * - LCD controller
 * - Extra features
 *
 * Advanced settings can be found in Configuration_adv.h
 */
#define CONFIGURATION_H_VERSION 02010300

#define Z_MIN_ENDSTOP_INVERTING true   // AI_DEBUG: DUPLICITNÍ! Předefinováno později na řádku 2034
#define Z_MIN_PROBE_ENDSTOP_INVERTING true  // AI_DEBUG: DUPLICITNÍ! Předefinováno později na řádku 2035

/**
 * Here are some useful links to help get your machine configured and calibrated:
 *
 * Example Configs:     https://github.com/MarlinFirmware/Configurations/branches/all
 *
 * Průša Calculator:    https://blog.prusaprinters.org/calculator_3416/
 *
 * Calibration Guides:  https://reprap.org/wiki/Calibration
 *                      https://reprap.org/wiki/Triffid_Hunter%27s_Calibration_Guide
 *                      https://sites.google.com/site/repraplogphase/calibration-of-your-reprap
 *                      https://youtu.be/wAL9d7FgInk
 *
 * Calibration Objects: https://www.thingiverse.com/thing:5573
 *                      https://www.thingiverse.com/thing:1278865
 */

#define STRING_CONFIG_H_AUTHOR "TinyMachines3D" // Who made the changes.
#define CUSTOM_VERSION_FILE Version.h // Path from the root directory (no quotes)

/**
 * *** VENDORS PLEASE READ ***
 *
 * Marlin allows you to add a custom boot image for Graphical LCDs.
 * With this option Marlin will first show your custom screen followed
 * by the standard Marlin logo with version number and web URL.
 *
 * We encourage you to take advantage of this new feature and we also
 * respectfully request that you retain the unmodified Marlin boot screen.
 */

#if BOTH(PowerShutoffKit, EnclosureLight)
  #undef EnclosureLight
#endif

#if ENABLED(MachineCR10SV3)
  #define MachineCR10SV2
  #define CrealityTitan
  #if NONE(ABL_NCSW, ABL_EZABL, ABL_BLTOUCH)
    #define ABL_BLTOUCH
  #endif
#endif

#if ENABLED(MachineCR10SmartPro)
  #define ABL_BLTOUCH
#endif

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

#if ANY(MachineCR6, MachineCR6Max)
  #if NONE(ABL_UBL, ABL_BI)
    #define ABL_BI
  #endif
#endif

#if ENABLED(OriginalCrealitySquareBoard)
  #define SD_DETECT_PIN -1
#endif

#if ENABLED(DDXExtruderKit)
  #define BondtechBMG
#endif

#if ENABLED(ABL_EZABL12MM)
  #define ABL_EZABL
#endif

#if ENABLED(MachineCR10SProV2) // AI_DEBUG: PROJDE - MachineCR10SProV2 je definováno
  #define MachineCR10SPro // AI_DEBUG: AKTIVNÍ - MachineCR10SProV2 blok projde
#endif // AI_DEBUG: PROJDE - MachineCR10SProV2 je definováno

#if ENABLED(MachineCR10SPro) // AI_DEBUG: PROJDE - MachineCR10SPro je definováno (díky MachineCR10SProV2)
  #define MachineCR10Std // AI_DEBUG: AKTIVNÍ - MachineCR10SPro blok projde
  #if DISABLED(ABL_BLTOUCH, ABL_EZABL, ABL_TOUCH_MI) // AI_DEBUG: PROJDE - ABL_BLTOUCH ani ABL_EZABL ani ABL_TOUCH_MI nejsou definovány
  #endif // AI_DEBUG: PROJDE - ABL_BLTOUCH ani ABL_EZABL ani ABL_TOUCH_MI nejsou definovány
  #if DISABLED(ABL_UBL) // AI_DEBUG: PROJDE - ABL_UBL není definováno
    #define ABL_BI // AI_DEBUG: AKTIVNÍ - ABL_BI je povolen
  #endif // AI_DEBUG: PROJDE - ABL_UBL není definováno
  #define lerdgeFilSensor // AI_DEBUG: AKTIVNÍ - lerdgeFilSensor je povolen
#endif // AI_DEBUG: PROJDE - MachineCR10SPro je definováno (díky MachineCR10SProV2)

#if ANY(MachineCR10SV2)
  #define lerdgeFilSensor
#endif

#if ANY(MachineCR10SV2, MachineCR10Max, MachineCR10SProV2) && ANY(ABL_EZABL, ABL_NCSW, ABL_BLTOUCH, ABL_TOUCH_MI) && NONE(SKR13, SKR14, SKR14Turbo, SKRPRO11) // AI_DEBUG: PROJDE - MachineCR10SProV2 je definováno, ale ABL_EZABL ani ABL_NCSW ani ABL_BLTOUCH ani ABL_TOUCH_MI nejsou definovány
  #define Z_STOP_PIN 19
#endif // AI_DEBUG: PROJDE - MachineCR10SProV2 je definováno, ale ABL podmínka není splněna

#if ANY(MachineEnder2, MachineEnder3, MachineEnder5, MachineCR10, MachineMini) &&NONE(SKR13, SKR14, SKR14Turbo, SKRPRO11, SKRE3Turbo, SKRMiniE3V2, SKRMiniE3V3, Creality422, Creality427, Melzi_To_SBoardUpgrade)
  #define MachineCR10Orig
#endif

#if ANY(MachineCR10, MachineCR10S, MachineCR10SV2, MachineCR10Smart, MachineCR10SmartPro) // AI_DEBUG: PROJDE - MachineCR10SPro je definováno (díky MachineCR10SProV2)
  #define MachineCR10Std // AI_DEBUG: AKTIVNÍ - MachineCR10Std je povolen
#endif // AI_DEBUG: PROJDE - MachineCR10SPro je definováno (díky MachineCR10SProV2)

#if ENABLED(MachineCR2020)
  #define EnclosureLight
  #define LCD_CONTRAST_INIT 165
  #define SUICIDE_PIN 12 // Power up method is triggering the kill. Need to add consistent inversion upstream
  #define SUICIDE_PIN_INVERTING true
  #define DirectDrive
#endif

#if ENABLED(PLUS)
  #if DISABLED(MachineCR10Orig)
    #define lerdgeFilSensor
  #endif
  #define HotendAllMetal
  #define EZRstruder
  #if DISABLED(ABL_UBL)
    #define ABL_BI
  #endif
  #if NONE(ABL_NCSW, ABL_EZABL, ABL_BLTOUCH)
    #define ABL_BLTOUCH
  #endif
#endif

#if ENABLED(MachineCRXPro)
  #define MachineCRX
  #if NONE(ABL_NCSW, ABL_EZABL, ABL_BLTOUCH)
    #define ABL_BLTOUCH
  #endif
#endif

#if ENABLED(FilSensors)
  #define AddonFilSensor
  #define lerdgeFilSensor
  #if ANY(MachineCRX, MachineCRXPro, Dual_BowdenSplitterY, Dual_CyclopsSingleNozzle, Dual_ChimeraDualNozzle)
    #define DualFilSensors
  #endif
#endif

#if ANY(MachineCRX, MachineCRXPro, MachineEnder5Plus, MachineCR10SPro, MachineCR5, MachineCR10Max, MachineEnder6, MachineSermoonD1, MachineEnder7, MachineCR10Smart, MachineCR10SmartPro) // AI_DEBUG: PROJDE - MachineCR10SPro je definováno (díky MachineCR10SProV2)
  #if NONE(GraphicLCD, OrigLCD, FORCE10SPRODISPLAY) // AI_DEBUG: PROJDE - FORCE10SPRODISPLAY není definováno
    #define FORCE10SPRODISPLAY // AI_DEBUG: AKTIVNÍ - FORCE10SPRODISPLAY je povolen
  #endif // AI_DEBUG: PROJDE - FORCE10SPRODISPLAY není definováno
#endif // AI_DEBUG: PROJDE - MachineCR10SPro je definováno (díky MachineCR10SProV2)

#if ANY(MachineEnder7, MachineSermoonD1, MachineCR10Smart, MachineCR5, MachineCR10SmartPro)
  #define DWINOS_4
#endif

#if ENABLED(MachineCR30)
  #define OrigLCD
  #define RET6_12864_LCD
  #define BedDC
#endif

#if ENABLED(MachineCRX)
  #define MachineCR10Std
  #define Dual_BowdenSplitterY
#endif

#if ANY(MachineEnder3V2, MachineEnder3Pro422, MachineEnder3Pro427, Creality422, Creality427, MachineEnder3Max, MachineEnder6, MachineEnder7, MachineSermoonD1, MachineEnder3S1)
  #define POWER_LOSS_RECOVERY
#endif

#if ANY(MachineEnder3Pro422, MachineEnder3Pro427)
  #define MachineEnder3
  #define RET6_12864_LCD
#endif

#if ANY(MachineEnder3Max, MachineEnder3V2, MachineEnder3Pro422) && DISABLED(Creality427)
  #ifndef Creality422
    #define Creality422
  #endif
#endif

#if ENABLED(MachineEnder3Pro427)
  #ifndef Creality427
    #define Creality427
  #endif
#endif

#if ANY(MachineEnder3Max, MachineEnder6)
  #define lerdgeFilSensor
#endif

#if (ANY(Creality422, Creality427, MachineEnder2Pro) && DISABLED(MachineEnder3V2)) || BOTH(OrigLCD, MachineEnder6)
  #ifndef FORCE10SPRODISPLAY
    #ifndef MachineEnder3Touchscreen
      #ifndef FORCEV2DISPLAY
        #define RET6_12864_LCD
        #ifndef OrigLCD
          #define OrigLCD
        #endif
      #endif
    #endif
  #endif
#endif

#if NONE(HotendStock, HotendE3D) // AI_DEBUG: PROJDE - HotendAllMetal je definováno, takže HotendStock a HotendE3D nejsou
  #define HotendStock // AI_DEBUG: AKTIVNÍ - fallback na HotendStock
#endif

#if NONE(ABL_UBL, ABL_BI, FORCE10SPRODISPLAY) // AI_DEBUG: PROJDE - žádný z těchto ABL systémů není definován
  #define ABL_BI // AI_DEBUG: AKTIVNÍ - fallback na ABL_BI
#endif

#if ANY(ABL_EZABL, ABL_NCSW, ABL_BLTOUCH, ABL_TOUCH_MI) && NONE(ABL_UBL, ABL_BI)
  #define ABL_BI
#endif

#if NONE(MeshFast, MeshStd, MeshFine, MeshExtreme) // AI_DEBUG: PROJDE - žádný z mesh typů není definován
  #define MeshStd // AI_DEBUG: AKTIVNÍ - fallback na MeshStd
#endif

#if ENABLED(MachineCR20Pro)
  #define LCD_CONTRAST_INIT 165
  #define MachineCR20
  #if NONE(ABL_NCSW, ABL_EZABL, ABL_BLTOUCH)
    #define ABL_BLTOUCH
  #endif
  #define HotendAllMetal
  #if DISABLED(ABL_UBL)
    #define ABL_BI
  #endif
  #define SolidBedMounts

#endif

#if ENABLED(SKRPRO11)
  #define FIL_RUNOUT_PIN   PE15
  #if DISABLED(I2C_EEPROM)
    #define FLASH_EEPROM_EMULATION
  #endif
#endif

#if ANY(MicroswissDirectDrive, DDXExtruderKit, CrealityTitan, E3DHemera, SpriteExtruder) // AI_DEBUG: PROJDE - MicroswissDirectDrive je definováno
  #define DirectDrive // AI_DEBUG: AKTIVNÍ - DirectDrive je povolen
#endif // AI_DEBUG: PROJDE - MicroswissDirectDrive je definováno

#if ENABLED(MachineCR10Orig, ABL_BI)
  #define LowMemoryBoard
#endif
#if NONE(MachineEnder4, MachineCR10SPro, MachineCRX, MachineCR10Max, MachineEnder5Plus) || ENABLED(GraphicLCD) // AI_DEBUG: PROJDE - MachineCR10SPro je definováno (díky MachineCR10SProV2), GraphicLCD není definováno
  #undef SolidBedMounts // AI_DEBUG: AKTIVNÍ - SolidBedMounts je odstraněn
#endif // AI_DEBUG: PROJDE - MachineCR10SPro je definováno (díky MachineCR10SProV2), GraphicLCD není definováno

#if NONE(LowMemoryBoard, MachineCR10Orig) // AI_DEBUG: PROJDE - LowMemoryBoard ani MachineCR10Orig nejsou definovány
  #define POWER_LOSS_RECOVERY // AI_DEBUG: AKTIVNÍ - POWER_LOSS_RECOVERY je povolen
#endif // AI_DEBUG: PROJDE - LowMemoryBoard ani MachineCR10Orig nejsou definovány

#if ENABLED(MachineSermoonD1)
  #ifndef Creality422
    #define Creality422
  #endif
#endif

#if NONE(BedDC, BedExternal, BedAC) // AI_DEBUG: PROJDE - BedDC ani BedExternal ani BedAC nejsou definovány
  #define BedDC // AI_DEBUG: AKTIVNÍ - BedDC je povolen
#endif // AI_DEBUG: PROJDE - BedDC ani BedExternal ani BedAC nejsou definovány

#if ANY(SKR13, SKR14, SKR14Turbo, SKRPRO11, SKRE3Turbo, SKRMiniE3V3, MachineEnder3V2, MachineEnder3S1, Creality422, Creality427, MachineEnder6, MachineSermoonD1, MachineCR30, MachineCR6, MachineCR6Max, MachineEnder7, MachineCR10Smart, MachineCR10SmartPro)
  #define MachineLargeROM
#endif

#if NONE(MachineCR10Orig, MachineEnder4, MachineCR10SPro, MachineCRX, MachineCR10Max, MachineEnder5Plus, MachineCR5, SKRMiniE3V2, FORCE10SPRODISPLAY) || ENABLED(GraphicLCD) // AI_DEBUG: PROJDE - MachineCR10SPro je definováno (díky MachineCR10SProV2), GraphicLCD není definováno
  #define SHOW_BOOTSCREEN // AI_DEBUG: AKTIVNÍ - SHOW_BOOTSCREEN je povolen

  #if DISABLED(MachineCR6, MachineCR6Max, MachineEnder3Touchscreen) // AI_DEBUG: PROJDE - MachineCR6 ani MachineCR6Max ani MachineEnder3Touchscreen nejsou definovány
    #define SHOW_CUSTOM_BOOTSCREEN // AI_DEBUG: AKTIVNÍ - SHOW_CUSTOM_BOOTSCREEN je povolen
  #endif // AI_DEBUG: PROJDE - MachineCR6 ani MachineCR6Max ani MachineEnder3Touchscreen nejsou definovány

  #if DISABLED(MachineEnder3V2, MachineEnder3S1, MachineCR6, MachineCR6Max, MachineEnder3Touchscreen, FORCEV2DISPLAY) // AI_DEBUG: PROJDE - MachineEnder3V2 ani MachineEnder3S1 ani MachineCR6 ani MachineCR6Max ani MachineEnder3Touchscreen ani FORCEV2DISPLAY nejsou definovány
    #define CUSTOM_STATUS_SCREEN_IMAGE // AI_DEBUG: AKTIVNÍ - CUSTOM_STATUS_SCREEN_IMAGE je povolen
  #endif // AI_DEBUG: PROJDE - MachineEnder3V2 ani MachineEnder3S1 ani MachineCR6 ani MachineCR6Max ani MachineEnder3Touchscreen ani FORCEV2DISPLAY nejsou definovány
#endif // AI_DEBUG: PROJDE - MachineCR10SPro je definováno (díky MachineCR10SProV2), GraphicLCD není definováno

/**
 * Select the serial port on the board to use for communication with the host.
 * This allows the connection of wireless adapters (for instance) to non-default port pins.
 * Serial port -1 is the USB emulated serial port, if available.
 * Note: The first serial port (-1 or 0) will always be used by the Arduino bootloader.
 *
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
#define SERIAL_PORT 0

/**
 * Select a secondary serial port on the board to use for communication with the host.
 * Currently Ethernet (-2) is only supported on Teensy 4.1 boards.
 * :[-2, -1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
#define LCD_SERIAL_PORT 2
#define LCD_BAUDRATE 115200
#define SERIAL_CATCHALL 0

/**
 * Serial Port Baud Rate
 * This is the default communication speed for all serial ports.
 * Set the baud rate defaults for additional serial ports below.
 *
 * 250000 works in most cases, but you might try a lower speed if
 * you commonly experience drop-outs during host printing.
 * You may try up to 1000000 to speed up SD file transfer.
 *
 * :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]
 */
#define BAUDRATE 250000

/**
 * Select a secondary serial port on the board to use for communication with the host.
 * Currently Ethernet (-2) is only supported on Teensy 4.1 boards.
 * :[-2, -1, 0, 1, 2, 3, 4, 5, 6, 7]
 */

/**
 * Select a third serial port on the board to use for communication with the host.
 * Currently only supported for AVR, DUE, LPC1768/9 and STM32/STM32F1
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */

#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_RAMPS_CREALITY
#endif

/**
 * Stepper Drivers
 *
 * These settings allow Marlin to tune stepper driver timing and enable advanced options for
 * stepper drivers that support them. You may also override timing options in Configuration_adv.h.
 *
 * A4988 is assumed for unspecified drivers.
 *
 * Use TMC2208/TMC2208_STANDALONE for TMC2225 drivers and TMC2209/TMC2209_STANDALONE for TMC2226 drivers.
 *
 * Options: A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
 *          TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
 *          TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
 *          TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
 *          TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
 * :['A4988', 'A5984', 'DRV8825', 'LV8729', 'TB6560', 'TB6600', 'TMC2100', 'TMC2130', 'TMC2130_STANDALONE', 'TMC2160', 'TMC2160_STANDALONE', 'TMC2208', 'TMC2208_STANDALONE', 'TMC2209', 'TMC2209_STANDALONE', 'TMC26X', 'TMC26X_STANDALONE', 'TMC2660', 'TMC2660_STANDALONE', 'TMC5130', 'TMC5130_STANDALONE', 'TMC5160', 'TMC5160_STANDALONE']
 */

#define X_DRIVER_TYPE  TMC2209_STANDALONE
#define Y_DRIVER_TYPE  TMC2209_STANDALONE
#define Z_DRIVER_TYPE  TMC2209_STANDALONE
#define E0_DRIVER_TYPE TMC2209_STANDALONE
#define E1_DRIVER_TYPE TMC2209_STANDALONE


/**
 * Additional Axis Settings
 *
 * Define AXISn_ROTATES for all axes that rotate or pivot.
 * Rotational axis coordinates are expressed in degrees.
 *
 * AXISn_NAME defines the letter used to refer to the axis in (most) G-code commands.
 * By convention the names and roles are typically:
 *   'A' : Rotational axis parallel to X
 *   'B' : Rotational axis parallel to Y
 *   'C' : Rotational axis parallel to Z
 *   'U' : Secondary linear axis parallel to X
 *   'V' : Secondary linear axis parallel to Y
 *   'W' : Secondary linear axis parallel to Z
 *
 * Regardless of these settings the axes are internally named I, J, K, U, V, W.
 */
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

#if ANY(Dual_BowdenSplitterY, Dual_CyclopsSingleNozzle)
  #define SINGLENOZZLE
#endif

#if ENABLED(SINGLENOZZLE)
  #define SINGLENOZZLE_STANDBY_TEMP
  #define SINGLENOZZLE_STANDBY_FAN
#endif

/**
 * Multi-Material Unit
 * Set to one of these predefined models:
 *
 *   PRUSA_MMU1           : Průša MMU1 (The "multiplexer" version)
 *   PRUSA_MMU2           : Průša MMU2
 *   PRUSA_MMU2S          : Průša MMU2S (Requires MK3S extruder with motion sensor, EXTRUDERS = 5)
 *   EXTENDABLE_EMU_MMU2  : MMU with configurable number of filaments (ERCF, SMuFF or similar with Průša MMU2 compatible firmware)
 *   EXTENDABLE_EMU_MMU2S : MMUS with configurable number of filaments (ERCF, SMuFF or similar with Průša MMU2 compatible firmware)
 *
 * Requires NOZZLE_PARK_FEATURE to park print head in case MMU unit fails.
 * See additional options in Configuration_adv.h.
 * :["PRUSA_MMU1", "PRUSA_MMU2", "PRUSA_MMU2S", "EXTENDABLE_EMU_MMU2", "EXTENDABLE_EMU_MMU2S"]
 */

#if ENABLED(SWITCHING_EXTRUDER)
  #define SWITCHING_EXTRUDER_SERVO_NR 0
  #define SWITCHING_EXTRUDER_SERVO_ANGLES { 0, 90 } // Angles for E0, E1[, E2, E3]
  #if EXTRUDERS > 3 // AI_DEBUG: PROJDE - EXTRUDERS = 1, takže 1 > 3 je false
    #define SWITCHING_EXTRUDER_E23_SERVO_NR 1
  #endif
#endif

#if ENABLED(SWITCHING_NOZZLE)
  #define SWITCHING_NOZZLE_SERVO_NR 0
  #define SWITCHING_NOZZLE_SERVO_ANGLES { 0, 90 }   // Angles for E0, E1 (single servo) or lowered/raised (dual servo)
  #define SWITCHING_NOZZLE_SERVO_DWELL 2500         // Dwell time to wait for servo to make physical move
#endif

/**
 * Two separate X-carriages with extruders that connect to a moving part
 * via a solenoid docking mechanism. Requires SOL1_PIN and SOL2_PIN.
 */

/**
 * Two separate X-carriages with extruders that connect to a moving part
 * via a magnetic docking mechanism using movements and no solenoid
 *
 * project   : https://www.thingiverse.com/thing:3080893
 * movements : https://youtu.be/0xCEiG9VS3k
 *             https://youtu.be/Bqbcs0CU2FE
 */

#if EITHER(PARKING_EXTRUDER, MAGNETIC_PARKING_EXTRUDER)

  #define PARKING_EXTRUDER_PARKING_X { -78, 184 }     // X positions for parking the extruders
  #define PARKING_EXTRUDER_GRAB_DISTANCE 1            // (mm) Distance to move beyond the parking point to grab the extruder

  #if ENABLED(PARKING_EXTRUDER)

    #define PARKING_EXTRUDER_SOLENOIDS_INVERT           // If enabled, the solenoid is NOT magnetized with applied voltage
    #define PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE LOW  // LOW or HIGH pin signal energizes the coil
    #define PARKING_EXTRUDER_SOLENOIDS_DELAY 250        // (ms) Delay for magnetic field. No delay if 0 or not defined.

  #elif ENABLED(MAGNETIC_PARKING_EXTRUDER)

    #define MPE_FAST_SPEED      9000      // (mm/min) Speed for travel before last distance point
    #define MPE_SLOW_SPEED      4500      // (mm/min) Speed for last distance travel to park and couple
    #define MPE_TRAVEL_DISTANCE   10      // (mm) Last distance point
    #define MPE_COMPENSATION       0      // Offset Compensation -1 , 0 , 1 (multiplier) only for coupling

  #endif

#endif

/**
 * Switching Toolhead
 *
 * Support for swappable and dockable toolheads, such as
 * the E3D Tool Changer. Toolheads are locked with a servo.
 */

/**
 * Magnetic Switching Toolhead
 *
 * Support swappable and dockable toolheads with a magnetic
 * docking mechanism using movement and no servo.
 */

/**
 * Electromagnetic Switching Toolhead
 *
 * Parking for CoreXY / HBot kinematics.
 * Toolheads are parked at one edge and held with an electromagnet.
 * Supports more than 2 Toolheads. See https://youtu.be/JolbsAKTKf4
 */

#if ANY(SWITCHING_TOOLHEAD, MAGNETIC_SWITCHING_TOOLHEAD, ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
  #define SWITCHING_TOOLHEAD_Y_POS          235         // (mm) Y position of the toolhead dock
  #define SWITCHING_TOOLHEAD_Y_SECURITY      10         // (mm) Security distance Y axis
  #define SWITCHING_TOOLHEAD_Y_CLEAR         60         // (mm) Minimum distance from dock for unobstructed X axis
  #define SWITCHING_TOOLHEAD_X_POS          { 215, 0 }  // (mm) X positions for parking the extruders
  #if ENABLED(SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_SERVO_NR       2         // Index of the servo connector
    #define SWITCHING_TOOLHEAD_SERVO_ANGLES { 0, 180 }  // (degrees) Angles for Lock, Unlock
  #elif ENABLED(MAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Y_RELEASE      5         // (mm) Security distance Y axis
    #define SWITCHING_TOOLHEAD_X_SECURITY   { 90, 150 } // (mm) Security distance X axis (T0,T1)
    #if ENABLED(PRIME_BEFORE_REMOVE)
      #define SWITCHING_TOOLHEAD_PRIME_MM           20  // (mm)   Extruder prime length
      #define SWITCHING_TOOLHEAD_RETRACT_MM         10  // (mm)   Retract after priming length
      #define SWITCHING_TOOLHEAD_PRIME_FEEDRATE    300  // (mm/min) Extruder prime feedrate
      #define SWITCHING_TOOLHEAD_RETRACT_FEEDRATE 2400  // (mm/min) Extruder retract feedrate
    #endif
  #elif ENABLED(ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Z_HOP          2         // (mm) Z raise for switching
  #endif
#endif

/**
 * "Mixing Extruder"
 *   - Adds G-codes M163 and M164 to set and "commit" the current mix factors.
 *   - Extends the stepping routines to move multiple steppers in proportion to the mix.
 *   - Optional support for Repetier Firmware's 'M164 S<index>' supporting virtual tools.
 *   - This implementation supports up to two mixing extruders.
 *   - Enable DIRECT_MIXING_IN_G1 for M165 and mixing in G1 (from Pia Taubert's reference implementation).
 */
#if ENABLED(MIXING_EXTRUDER)
  #define MIXING_STEPPERS 2        // Number of steppers in your mixing extruder
  #define MIXING_VIRTUAL_TOOLS 16  // Use the Virtual Tool method with M163 and M164
  #if ENABLED(GRADIENT_MIX)
  #endif
#endif

#if(ENABLED(Dual_ChimeraDualNozzle))
  #define HOTEND_OFFSET_X {0.0, 18.00} // (in mm) for each extruder, offset of the hotend on the X axis
  #define HOTEND_OFFSET_Y {0.0, 0.00}  // (in mm) for each extruder, offset of the hotend on the Y axis
#endif

/**
 * Power Supply Control
 *
 * Enable and connect the power supply to the PS_ON_PIN.
 * Specify whether the power supply is active HIGH or active LOW.
 */
#if ANY(MachineCR2020, PowerShutoffKit, MachineCR10Smart, MachineCR10SmartPro)
  #define PSU_CONTROL
#endif

#if ENABLED(PSU_CONTROL)
  #if ENABLED(PowerShutoffKit)
    #define PS_ON_PIN 12
    #define PSU_ACTIVE_STATE HIGH
  #elif ANY(MachineCR10Smart, MachineCR10SmartPro)
    #define PS_ON_PIN PA0
    #define PSU_ACTIVE_STATE HIGH
  #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
    #define PSU_ACTIVE_STATE LOW      // Set 'LOW' for ATX, 'HIGH' for X-Box // AI_DEBUG: AKTIVNÍ - fallback na PSU_ACTIVE_STATE LOW
  #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna

  #if ENABLED(AUTO_POWER_CONTROL)
    #define AUTO_POWER_FANS         // Turn on PSU if fans need power
    #define AUTO_POWER_E_FANS
    #define AUTO_POWER_CONTROLLERFAN
    #define AUTO_POWER_CHAMBER_FAN
    #define AUTO_POWER_COOLER_FAN
    #define POWER_TIMEOUT              30 // (s) Turn off power if the machine is idle for this duration
  #endif
  #if EITHER(AUTO_POWER_CONTROL, POWER_OFF_WAIT_FOR_COOLDOWN)
  #endif
#endif

/**
 * --NORMAL IS 4.7kΩ PULLUP!-- 1kΩ pullup can be used on hotend sensor, using correct resistor and table
 *
 * Temperature sensors available:
 *
 *  SPI RTD/Thermocouple Boards - IMPORTANT: Read the NOTE below!
 *  -------
 *    -5 : MAX31865 with Pt100/Pt1000, 2, 3, or 4-wire  (only for sensors 0-1)
 *                  NOTE: You must uncomment/set the MAX31865_*_OHMS_n defines below.
 *    -3 : MAX31855 with Thermocouple, -200°C to +700°C (only for sensors 0-1)
 *    -2 : MAX6675  with Thermocouple, 0°C to +700°C    (only for sensors 0-1)
 *
 *  NOTE: Ensure TEMP_n_CS_PIN is set in your pins file for each TEMP_SENSOR_n using an SPI Thermocouple. By default,
 *        Hardware SPI on the default serial bus is used. If you have also set TEMP_n_SCK_PIN and TEMP_n_MISO_PIN,
 *        Software SPI will be used on those ports instead. You can force Hardware SPI on the default bus in the
 *        Configuration_adv.h file. At this time, separate Hardware SPI buses for sensors are not supported.
 *
 *  Analog Themocouple Boards
 *  -------
 *    -4 : AD8495 with Thermocouple
 *    -1 : AD595  with Thermocouple
 *
 *  Analog Thermistors - 4.7kΩ pullup - Normal
 *  -------
 *     1 : 100kΩ  EPCOS - Best choice for EPCOS thermistors
 *   331 : 100kΩ  Same as #1, but 3.3V scaled for MEGA
 *   332 : 100kΩ  Same as #1, but 3.3V scaled for DUE
 *     2 : 200kΩ  ATC Semitec 204GT-2
 *   202 : 200kΩ  Copymaster 3D
 *     3 : ???Ω   Mendel-parts thermistor
 *     4 : 10kΩ   Generic Thermistor !! DO NOT use for a hotend - it gives bad resolution at high temp. !!
 *     5 : 100kΩ  ATC Semitec 104GT-2/104NT-4-R025H42G - Used in ParCan, J-Head, and E3D, SliceEngineering 300°C
 *   501 : 100kΩ  Zonestar - Tronxy X3A
 *   502 : 100kΩ  Zonestar - used by hot bed in Zonestar Průša P802M
 *   503 : 100kΩ  Zonestar (Z8XM2) Heated Bed thermistor
 *   504 : 100kΩ  Zonestar P802QR2 (Part# QWG-104F-B3950) Hotend Thermistor
 *   505 : 100kΩ  Zonestar P802QR2 (Part# QWG-104F-3950) Bed Thermistor
 *   512 : 100kΩ  RPW-Ultra hotend
 *     6 : 100kΩ  EPCOS - Not as accurate as table #1 (created using a fluke thermocouple)
 *     7 : 100kΩ  Honeywell 135-104LAG-J01
 *    71 : 100kΩ  Honeywell 135-104LAF-J01
 *     8 : 100kΩ  Vishay 0603 SMD NTCS0603E3104FXT
 *     9 : 100kΩ  GE Sensing AL03006-58.2K-97-G1
 *    10 : 100kΩ  RS PRO 198-961
 *    11 : 100kΩ  Keenovo AC silicone mats, most Wanhao i3 machines - beta 3950, 1%
 *    12 : 100kΩ  Vishay 0603 SMD NTCS0603E3104FXT (#8) - calibrated for Makibox hot bed
 *    13 : 100kΩ  Hisens up to 300°C - for "Simple ONE" & "All In ONE" hotend - beta 3950, 1%
 *    15 : 100kΩ  Calibrated for JGAurora A5 hotend
 *    18 : 200kΩ  ATC Semitec 204GT-2 Dagoma.Fr - MKS_Base_DKU001327
 *    22 : 100kΩ  GTM32 Pro vB - hotend - 4.7kΩ pullup to 3.3V and 220Ω to analog input
 *    23 : 100kΩ  GTM32 Pro vB - bed - 4.7kΩ pullup to 3.3v and 220Ω to analog input
 *    30 : 100kΩ  Kis3d Silicone heating mat 200W/300W with 6mm precision cast plate (EN AW 5083) NTC100K - beta 3950
 *    60 : 100kΩ  Maker's Tool Works Kapton Bed Thermistor - beta 3950
 *    61 : 100kΩ  Formbot/Vivedino 350°C Thermistor - beta 3950
 *    66 : 4.7MΩ  Dyze Design / Trianglelab T-D500 500°C High Temperature Thermistor
 *    67 : 500kΩ  SliceEngineering 450°C Thermistor
 *    68 : PT100 amplifier board from Dyze Design
 *    70 : 100kΩ  bq Hephestos 2
 *    75 : 100kΩ  Generic Silicon Heat Pad with NTC100K MGB18-104F39050L32
 *  2000 : 100kΩ  Ultimachine Rambo TDK NTCG104LH104KT1 NTC100K motherboard Thermistor
 *
 *  Analog Thermistors - 1kΩ pullup - Atypical, and requires changing out the 4.7kΩ pullup for 1kΩ.
 *  -------                           (but gives greater accuracy and more stable PID)
 *    51 : 100kΩ  EPCOS (1kΩ pullup)
 *    52 : 200kΩ  ATC Semitec 204GT-2 (1kΩ pullup)
 *    55 : 100kΩ  ATC Semitec 104GT-2 - Used in ParCan & J-Head (1kΩ pullup)
 *
 *  Analog Thermistors - 10kΩ pullup - Atypical
 *  -------
 *    99 : 100kΩ  Found on some Wanhao i3 machines with a 10kΩ pull-up resistor
 *
 *  Analog RTDs (Pt100/Pt1000)
 *  -------
 *   110 : Pt100  with 1kΩ pullup (atypical)
 *   147 : Pt100  with 4.7kΩ pullup
 *  1010 : Pt1000 with 1kΩ pullup (atypical)
 *  1022 : Pt1000 with 2.2kΩ pullup
 *  1047 : Pt1000 with 4.7kΩ pullup (E3D)
 *    20 : Pt100  with circuit in the Ultimainboard V2.x with mainboard ADC reference voltage = INA826 amplifier-board supply voltage.
 *                NOTE: (1) Must use an ADC input with no pullup. (2) Some INA826 amplifiers are unreliable at 3.3V so consider using sensor 147, 110, or 21.
 *    21 : Pt100  with circuit in the Ultimainboard V2.x with 3.3v ADC reference voltage (STM32, LPC176x....) and 5V INA826 amplifier board supply.
 *                NOTE: ADC pins are not 5V tolerant. Not recommended because it's possible to damage the CPU by going over 500°C.
 *   201 : Pt100  with circuit in Overlord, similar to Ultimainboard V2.x
 *
 *  Custom/Dummy/Other Thermal Sensors
 *  ------
 *     0 : not used
 *  1000 : Custom - Specify parameters in Configuration_adv.h
 *
 *   !!! Use these for Testing or Development purposes. NEVER for production machine. !!!
 *   998 : Dummy Table that ALWAYS reads 25°C or the temperature defined below.
 *   999 : Dummy Table that ALWAYS reads 100°C or the temperature defined below.
 *
 */
#if ENABLED(ConfigurableThermistors)
  #define TEMP_SENSOR_0 1000
#elif ENABLED(CrealityThermistor)
  #define TEMP_SENSOR_0 1
#elif ENABLED(SlicePT1000)
  #define TEMP_SENSOR_0 1047
#elif ENABLED(HotendMosquito)
  #define TEMP_SENSOR_0 67
#elif ENABLED(HotendE3D)
  #define TEMP_SENSOR_0 5
#elif ENABLED(HotendStock)
  #define TEMP_SENSOR_0 1
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
  // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu (TEMP_SENSOR_0 není definováno)
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna

#if DISABLED(Dual_ChimeraDualNozzle)
  #define TEMP_SENSOR_1 0
#else
  #define TEMP_SENSOR_1 TEMP_SENSOR_0
#endif

#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_5 0
#define TEMP_SENSOR_6 0
#define TEMP_SENSOR_7 0
#if ENABLED(ConfigurableThermistors) && ANY(BedDC, BedAC)
  #define TEMP_SENSOR_BED 1000
#elif ENABLED(BedDC)
	#define TEMP_SENSOR_BED 5
#elif ENABLED(BedAC)
	#define TEMP_SENSOR_BED 11
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
	#define TEMP_SENSOR_BED 0 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna

#define TEMP_SENSOR_PROBE 0

#if(ENABLED(EnclosureTempSensor))
  #define TEMP_SENSOR_CHAMBER 147
  #define TEMP_CHAMBER_PIN   12
#endif
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

#if HAS_E_TEMP_SENSOR // AI_DEBUG: PROJDE - EXTRUDERS = 1, takže HAS_E_TEMP_SENSOR je true
  #define TEMP_RESIDENCY_TIME     2  // (seconds) Time to wait for hotend to "settle" in M109 // AI_DEBUG: AKTIVNÍ - HAS_E_TEMP_SENSOR je true
  #if ENABLED(UnstableTemps)
    #define TEMP_WINDOW              5  // (°C) Temperature proximity for the "temperature reached" timer
    #define TEMP_HYSTERESIS          7  // (°C) Temperature proximity considered "close enough" to the target
  #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - UnstableTemps není definováno
    #define TEMP_WINDOW              1  // (°C) Temperature proximity for the "temperature reached" timer // AI_DEBUG: AKTIVNÍ - stabilní teploty
    #define TEMP_HYSTERESIS          3  // (°C) Temperature proximity considered "close enough" to the target // AI_DEBUG: AKTIVNÍ - stabilní teploty
  #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - UnstableTemps není definováno

#endif // AI_DEBUG: PROJDE - HAS_E_TEMP_SENSOR je true
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

/**
 * Redundant Temperature Sensor (TEMP_SENSOR_REDUNDANT)
 *
 * Use a temp sensor as a redundant sensor for another reading. Select an unused temperature sensor, and another
 * sensor you'd like it to be redundant for. If the two thermistors differ by TEMP_SENSOR_REDUNDANT_MAX_DIFF (°C),
 * the print will be aborted. Whichever sensor is selected will have its normal functions disabled; i.e. selecting
 * the Bed sensor (-1) will disable bed heating/monitoring.
 *
 * For selecting source/target use: COOLER, PROBE, BOARD, CHAMBER, BED, E0, E1, E2, E3, E4, E5, E6, E7
 */
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

#if ENABLED(HotendMosquito)
  #define HEATER_0_MAXTEMP 450
#elif ENABLED(HotendAllMetal)
	#define HEATER_0_MAXTEMP 315
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
	#define HEATER_0_MAXTEMP 255 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define HEATER_4_MAXTEMP 275
#define HEATER_5_MAXTEMP 275
#define HEATER_6_MAXTEMP 275
#define HEATER_7_MAXTEMP 275
#define BED_MAXTEMP      150
#define CHAMBER_MAXTEMP  60

/**
 * Thermal Overshoot
 * During heatup (and printing) the temperature can often "overshoot" the target by many degrees
 * (especially before PID tuning). Setting the target temperature too close to MAXTEMP guarantees
 * a MAXTEMP shutdown! Use these values to forbid temperatures being set too close to MAXTEMP.
 */
#define HOTEND_OVERSHOOT 15   // (°C) Forbid temperatures over MAXTEMP - OVERSHOOT
#define BED_OVERSHOOT    10   // (°C) Forbid temperatures over MAXTEMP - OVERSHOOT
#define COOLER_OVERSHOOT  2   // (°C) Forbid temperatures closer than OVERSHOOT

#define PIDTEMP          // See the PID Tuning Guide at https://reprap.org/wiki/PID_Tuning

#define BANG_MAX 255     // Limits current to nozzle while in bang-bang mode; 255=full current
#define PID_MAX BANG_MAX // Limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#define PID_K1 0.95      // Smoothing factor within any PID loop

#if ENABLED(PIDTEMP) // AI_DEBUG: PROJDE - PIDTEMP je definováno
  #if NONE(MachineCR10Orig, SKRMiniE3V2) // AI_DEBUG: PROJDE - MachineCR10Orig ani SKRMiniE3V2 nejsou definovány
    #define PID_EDIT_MENU         // Add PID editing to the "Advanced Settings" menu. (~700 bytes of PROGMEM) // AI_DEBUG: AKTIVNÍ - PIDTEMP blok projde
    #define PID_AUTOTUNE_MENU     // Add PID auto-tuning to the "Advanced Settings" menu. (~250 bytes of PROGMEM) // AI_DEBUG: AKTIVNÍ - PIDTEMP blok projde
  #endif // AI_DEBUG: PROJDE - MachineCR10Orig ani SKRMiniE3V2 nejsou definovány

  #if ENABLED(PID_PARAMS_PER_HOTEND)
    #define DEFAULT_Kp_LIST {  22.20,  22.20 }
    #define DEFAULT_Ki_LIST {   1.08,   1.08 }
    #define DEFAULT_Kd_LIST { 114.00, 114.00 }
  #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - PID_PARAMS_PER_HOTEND není definováno
    #if ANY(HotendMosquito, PID50W)
      #define DEFAULT_Kp 16.8
      #define DEFAULT_Ki 1.2
      #define DEFAULT_Kd 54.3
    #elif ENABLED(HotendStock)
      #if ANY(MachineCR10SPro, MachineCR10Max)
        #define DEFAULT_Kp 25.25
        #define DEFAULT_Ki 2.17
        #define DEFAULT_Kd 73.44
      #elif ENABLED(MachineEnder5Plus)
        #define  DEFAULT_Kp 14.72
        #define  DEFAULT_Ki 0.89
        #define  DEFAULT_Kd 61.22
      #elif ENABLED(MachineCRX)
        #define DEFAULT_Kp 19.00
        #define DEFAULT_Ki 1.40
        #define DEFAULT_Kd 66.00
      #elif ENABLED(MachineCR10SV2)
        #define  DEFAULT_Kp 19.47
        #define  DEFAULT_Ki 1.59
        #define  DEFAULT_Kd 59.40
      #elif ENABLED(MachineCR2020)
        #define  DEFAULT_Kp 22.2
        #define  DEFAULT_Ki 1.08
        #define  DEFAULT_Kd 114
      #elif ENABLED(MachineEnder3V2)
        #define DEFAULT_Kp 28.72
        #define DEFAULT_Ki 2.62
        #define DEFAULT_Kd 78.81
      #elif ENABLED(MachineEnder3S1)
        #define DEFAULT_Kp 17.10
        #define DEFAULT_Ki 1.39
        #define DEFAULT_Kd 52.79
      #elif ANY(MachineCR6, MachineCR6Max, MachineCR10Smart, MachineCR10SmartPro)
       #define DEFAULT_Kp  14.32
       #define DEFAULT_Ki   0.81
        #define DEFAULT_Kd 63.12
      #else
        #define  DEFAULT_Kp 17.42
        #define  DEFAULT_Ki 1.27
        #define  DEFAULT_Kd 59.93
      #endif
    #elif ENABLED(HotendE3D)
      #define  DEFAULT_Kp 23.36
      #define  DEFAULT_Ki 1.99
      #define  DEFAULT_Kd 87.46
    #endif

  #endif
#endif

/**
 * Model Predictive Control for hotend
 *
 * Use a physical model of the hotend to control temperature. When configured correctly
 * this gives better responsiveness and stability than PID and it also removes the need
 * for PID_EXTRUSION_SCALING and PID_FAN_SCALING. Use M306 T to autotune the model.
 * @section mpctemp
 */
#if ENABLED(MPCTEMP)

  #define MPC_MAX BANG_MAX                            // (0..255) Current to nozzle while MPC is active.
  #define MPC_HEATER_POWER { 40.0f }                  // (W) Heat cartridge powers.

  #define MPC_INCLUDE_FAN                             // Model the fan speed?

  #define MPC_BLOCK_HEAT_CAPACITY { 16.7f }           // (J/K) Heat block heat capacities.
  #define MPC_SENSOR_RESPONSIVENESS { 0.22f }         // (K/s per ∆K) Rate of change of sensor temperature from heat block.
  #define MPC_AMBIENT_XFER_COEFF { 0.068f }           // (W/K) Heat transfer coefficients from heat block to room air with fan off.
  #if ENABLED(MPC_INCLUDE_FAN)
    #define MPC_AMBIENT_XFER_COEFF_FAN255 { 0.097f }  // (W/K) Heat transfer coefficients from heat block to room air with fan on full.
  #endif

  #if ENABLED(MPC_INCLUDE_FAN)
  #endif

  #define FILAMENT_HEAT_CAPACITY_PERMM { 5.6e-3f }    // 0.0056 J/K/mm for 1.75mm PLA (0.0149 J/K/mm for 2.85mm PLA).

  #define MPC_SMOOTHING_FACTOR 0.5f                   // (0.0...1.0) Noisy temperature sensors may need a lower value for stabilization.
  #define MPC_MIN_AMBIENT_CHANGE 1.0f                 // (K/s) Modeled ambient temperature rate of change, when correcting model inaccuracies.
  #define MPC_STEADYSTATE 0.5f                        // (K/s) Temperature change rate for steady state logic to be enforced.

  #define MPC_TUNING_POS { X_CENTER, Y_CENTER, 1.0f } // (mm) M306 Autotuning position, ideally bed center at first layer height.
  #define MPC_TUNING_END_Z 10.0f                      // (mm) M306 Autotuning final Z position.
#endif

/**
 * PID Bed Heating
 *
 * If this option is enabled set PID constants below.
 * If this option is disabled, bang-bang will be used and BED_LIMIT_SWITCHING will enable hysteresis.
 *
 * The PID frequency will be the same as the extruder PWM.
 * If PID_dT is the default, and correct for the hardware/configuration, that means 7.689Hz,
 * which is fine for driving a square wave into a resistive load and does not significantly
 * impact FET heating. This also works fine on a Fotek SSR-10DA Solid State Relay into a 250W
 * heater. If your configuration is significantly different than this and you don't understand
 * the issues involved, don't use bed PID until someone else verifies that your hardware works.
 * @section bed temp
 */
#if NONE(MachineCR10Orig, LowMemoryBoard, SKRMiniE3V2) || ENABLED(MelziHostOnly) // AI_DEBUG: PROJDE - MachineCR10Orig ani LowMemoryBoard ani SKRMiniE3V2 nejsou definovány, MelziHostOnly není definováno
  #define PIDTEMPBED // AI_DEBUG: AKTIVNÍ - PIDTEMPBED je povolen
#endif // AI_DEBUG: PROJDE - PIDTEMPBED je povolen

/**
 * Max Bed Power
 * Applies to all forms of bed control (PID, bang-bang, and bang-bang with hysteresis).
 * When set to any value below 255, enables a form of PWM to the bed that acts like a divider
 * so don't use it unless you are OK with PWM on your bed. (See the comment on enabling PIDTEMPBED)
 */
#define MAX_BED_POWER 255 // limits duty cycle to bed; 255=full current

#if ENABLED(PIDTEMPBED) // AI_DEBUG: PROJDE - PIDTEMPBED je definováno

  #if ANY(MachineEnder3V2, MachineEnder3S1)
    #define  DEFAULT_bedKp 462.10
    #define  DEFAULT_bedKi 85.47
    #define  DEFAULT_bedKd 624.59
  #elif ANY(MachineCR6, MachineCR6Max)
    #define DEFAULT_bedKp 79.49
    #define DEFAULT_bedKi 1.17
    #define DEFAULT_bedKd 1349.52
  #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
    #define  DEFAULT_bedKp 690.34 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnoty
    #define  DEFAULT_bedKi 111.47 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnoty
    #define  DEFAULT_bedKd 1068.83 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnoty
  #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna

#endif // PIDTEMPBED // AI_DEBUG: PROJDE - PIDTEMPBED je definováno

/**
 * PID Chamber Heating
 *
 * If this option is enabled set PID constants below.
 * If this option is disabled, bang-bang will be used and CHAMBER_LIMIT_SWITCHING will enable
 * hysteresis.
 *
 * The PID frequency will be the same as the extruder PWM.
 * If PID_dT is the default, and correct for the hardware/configuration, that means 7.689Hz,
 * which is fine for driving a square wave into a resistive load and does not significantly
 * impact FET heating. This also works fine on a Fotek SSR-10DA Solid State Relay into a 200W
 * heater. If your configuration is significantly different than this and you don't understand
 * the issues involved, don't use chamber PID until someone else verifies that your hardware works.
 * @section chamber temp
 */

/**
 * Max Chamber Power
 * Applies to all forms of chamber control (PID, bang-bang, and bang-bang with hysteresis).
 * When set to any value below 255, enables a form of PWM to the chamber heater that acts like a divider
 * so don't use it unless you are OK with PWM on your heater. (See the comment on enabling PIDTEMPCHAMBER)
 */
#define MAX_CHAMBER_POWER 255 // limits duty cycle to chamber heater; 255=full current

#if ENABLED(PIDTEMPCHAMBER)
  #define MIN_CHAMBER_POWER 0

  #define DEFAULT_chamberKp 37.04
  #define DEFAULT_chamberKi 1.40
  #define DEFAULT_chamberKd 655.17

#endif // PIDTEMPCHAMBER

#if ANY(PIDTEMP, PIDTEMPBED, PIDTEMPCHAMBER) // AI_DEBUG: PROJDE - PIDTEMP a PIDTEMPBED jsou definovány
  #define PID_FUNCTIONAL_RANGE 10 // If the temperature difference between the target temperature and the actual temperature // AI_DEBUG: AKTIVNÍ - PID funkce jsou povoleny

#endif // AI_DEBUG: PROJDE - PID funkce jsou povoleny

/**
 * Prevent extrusion if the temperature is below EXTRUDE_MINTEMP.
 * Add M302 to set the minimum extrusion temperature and/or turn
 * cold extrusion prevention on and off.
 *
 * *** IT IS HIGHLY RECOMMENDED TO LEAVE THIS OPTION ENABLED! ***
 */
#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170

/**
 * Prevent a single extrusion longer than EXTRUDE_MAXLENGTH.
 * Note: For Bowden Extruders make this large enough to allow load/unload.
 */
#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 750

/**
 * Thermal Protection provides additional protection to your printer from damage
 * and fire. Marlin always includes safe min and max temperature ranges which
 * protect against a broken or disconnected thermistor wire.
 *
 * The issue: If a thermistor falls out, it will report the much lower
 * temperature of the air in the room, and the the firmware will keep
 * the heater on.
 *
 * If you get "Thermal Runaway" or "Heating failed" errors the
 * details can be tuned in Configuration_adv.h
 */

#define THERMAL_PROTECTION_HOTENDS // Enable thermal protection for all extruders
#define THERMAL_PROTECTION_BED     // Enable thermal protection for the heated bed
#define THERMAL_PROTECTION_CHAMBER // Enable thermal protection for the heated chamber
#define THERMAL_PROTECTION_COOLER  // Enable thermal protection for the laser cooling

#if ANY(MachineEnder4, MachineEnder6, MachineEnder7, MachineCR30)
  #define COREXY
#endif

#if ENABLED(MachineCR30)
  #define BELTPRINTER
#endif

#if ENABLED(POLARGRAPH)
  #define POLARGRAPH_MAX_BELT_LEN  1035.0 // (mm) Belt length at full extension. Override with M665 H.
  #define DEFAULT_SEGMENTS_PER_SECOND 5   // Move segmentation based on duration
  #define PEN_UP_DOWN_MENU                // Add "Pen Up" and "Pen Down" to the MarlinUI menu
#endif

#if ENABLED(DELTA)

  #define DEFAULT_SEGMENTS_PER_SECOND 200

  #if ENABLED(DELTA_AUTO_CALIBRATION)
    #define DELTA_CALIBRATION_DEFAULT_POINTS 4
  #endif

  #if EITHER(DELTA_AUTO_CALIBRATION, DELTA_CALIBRATION_MENU)
    #define PROBE_MANUALLY_STEP 0.05      // (mm)
  #endif

  #define PRINTABLE_RADIUS       140.0    // (mm)

  #define DELTA_MAX_RADIUS       140.0    // (mm)

  #define DELTA_DIAGONAL_ROD 250.0        // (mm)

  #define DELTA_HEIGHT 250.00             // (mm) Get this value from G33 auto calibrate

  #define DELTA_ENDSTOP_ADJ { 0.0, 0.0, 0.0 } // Get these values from G33 auto calibrate

  #define DELTA_RADIUS 124.0              // (mm) Get this value from G33 auto calibrate

  #define DELTA_TOWER_ANGLE_TRIM { 0.0, 0.0, 0.0 } // Get these values from G33 auto calibrate

#endif

/**
 * MORGAN_SCARA was developed by QHARLEY in South Africa in 2012-2013.
 * Implemented and slightly reworked by JCERNY in June, 2014.
 *
 * Mostly Printed SCARA is an open source design by Tyler Williams. See:
 *   https://www.thingiverse.com/thing:2487048
 *   https://www.thingiverse.com/thing:1241491
 */
#if EITHER(MORGAN_SCARA, MP_SCARA)
  #define DEFAULT_SEGMENTS_PER_SECOND 200

  #define SCARA_LINKAGE_1 150       // (mm)
  #define SCARA_LINKAGE_2 150       // (mm)

  #define SCARA_OFFSET_X  100       // (mm)
  #define SCARA_OFFSET_Y  -56       // (mm)

  #if ENABLED(MORGAN_SCARA)

    #define FEEDRATE_SCALING        // Convert XY feedrate from mm/s to degrees/s on the fly

    #define MIDDLE_DEAD_ZONE_R   0  // (mm)

    #define THETA_HOMING_OFFSET  0  // Calculated from Calibration Guide and M360 / M114. See http://reprap.harleystudio.co.za/?page_id=1073
    #define PSI_HOMING_OFFSET    0  // Calculated from Calibration Guide and M364 / M114. See http://reprap.harleystudio.co.za/?page_id=1073

  #elif ENABLED(MP_SCARA)

    #define SCARA_OFFSET_THETA1  12 // degrees
    #define SCARA_OFFSET_THETA2 131 // degrees

  #endif

#endif

#if ENABLED(AXEL_TPARA)
  #define DEBUG_TPARA_KINEMATICS
  #define DEFAULT_SEGMENTS_PER_SECOND 200

  #define TPARA_LINKAGE_1 120       // (mm)
  #define TPARA_LINKAGE_2 120       // (mm)

  #define TPARA_OFFSET_X    0       // (mm)
  #define TPARA_OFFSET_Y    0       // (mm)
  #define TPARA_OFFSET_Z    0       // (mm)

  #define FEEDRATE_SCALING        // Convert XY feedrate from mm/s to degrees/s on the fly

  #define MIDDLE_DEAD_ZONE_R   0  // (mm)

  #define THETA_HOMING_OFFSET  0
  #define PSI_HOMING_OFFSET    0
#endif

/**
 * POLAR Kinematics
 *  developed by Kadir ilkimen for PolarBear CNC and babyBear
 *  https://github.com/kadirilkimen/Polar-Bear-Cnc-Machine
 *  https://github.com/kadirilkimen/babyBear-3D-printer
 *
 * A polar machine can have different configurations.
 * This kinematics is only compatible with the following configuration:
 *        X : Independent linear
 *   Y or B : Polar
 *        Z : Independent linear
 *
 * For example, PolarBear has CoreXZ plus Polar Y or B.
 *
 * Motion problem for Polar axis near center / origin:
 *
 * 3D printing:
 * Movements very close to the center of the polar axis take more time than others.
 * This brief delay results in more material deposition due to the pressure in the nozzle.
 *
 * Current Kinematics and feedrate scaling deals with this by making the movement as fast
 * as possible. It works for slow movements but doesn't work well with fast ones. A more
 * complicated extrusion compensation must be implemented.
 *
 * Ideally, it should estimate that a long rotation near the center is ahead and will cause
 * unwanted deposition. Therefore it can compensate the extrusion beforehand.
 *
 * Laser cutting:
 * Same thing would be a problem for laser engraving too. As it spends time rotating at the
 * center point, more likely it will burn more material than it should. Therefore similar
 * compensation would be implemented for laser-cutting operations.
 *
 * Milling:
 * This shouldn't be a problem for cutting/milling operations.
 */
#if ENABLED(POLAR)
  #define DEFAULT_SEGMENTS_PER_SECOND 180   // If movement is choppy try lowering this value
  #define PRINTABLE_RADIUS 82.0f            // (mm) Maximum travel of X axis

  #define POLAR_FAST_RADIUS 3.0f            // (mm)

  #define POLAR_CENTER_OFFSET 0.0f          // (mm)

  #define FEEDRATE_SCALING                  // Convert XY feedrate from mm/s to degrees/s on the fly
#endif

#if ANY(MachineEnder5, MachineEnder5Plus, MachineEnder6)
  #define USE_ZMIN_PLUG
  #define USE_XMAX_PLUG
  #define USE_YMAX_PLUG
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
  #define USE_XMIN_PLUG // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
  #if ENABLED(MachineEnder7)
    #define USE_YMAX_PLUG
  #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineEnder7 není definováno
    #define USE_YMIN_PLUG // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
  #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineEnder7 není definováno
  #define USE_ZMIN_PLUG // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
#endif

#define ENDSTOPPULLUPS
#if DISABLED(ENDSTOPPULLUPS)
#endif

#if DISABLED(ENDSTOPPULLDOWNS)
#endif

#if ANY(MachineEnder4, MachineCR2020, MachineCR30, MachineCR5, MachineEnder3S1)
  #define X_MIN_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
  #define X_MIN_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop. // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
#if ANY(MachineCR2020, MachineCR30, MachineCR5, MachineEnder3S1)
  #define Y_MIN_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
  #define Y_MIN_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop. // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
#define I_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define J_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define K_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define U_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define V_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define W_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define X_MAX_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Y_MAX_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Z_MAX_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define I_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define J_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define K_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define W_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.

#if NONE(ABL_EZABL, MachineCR2020) // AI_DEBUG: PODMÍNKA NEPLATÍ - ABL_EZABL není definováno, MachineCR2020 není definováno
  #define Z_MIN_ENDSTOP_INVERTING false 
  #define Z_MIN_PROBE_ENDSTOP_INVERTING false
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - podmínka je false
  #define Z_MIN_ENDSTOP_INVERTING true  // AI_DEBUG: AKTIVNÍ - redefinuje řádek 313 na true
  #define Z_MIN_PROBE_ENDSTOP_INVERTING true // AI_DEBUG: AKTIVNÍ - redefinuje řádek 314 na true
#endif

#if ANY(MachineEnder3V2, MachineEnder3S1, Creality422, MachineEnder2Pro, MachineCR10SmartPro) && NONE(SKRE3Turbo, SKR14Turbo, SKR14, SKR13)
  #define ENDSTOP_INTERRUPTS_FEATURE
#endif

/**
 * Endstop Noise Threshold
 *
 * Enable if your probe or endstops falsely trigger due to noise.
 *
 * - Higher values may affect repeatability or accuracy of some bed probes.
 * - To fix noise install a 100nF ceramic capacitor in parallel with the switch.
 * - This feature is not required for common micro-switches mounted on PCBs
 *   based on the Makerbot design, which already have the 100nF capacitor.
 *
 * :[2,3,4,5,6,7]
 */
#if ANY(MachineEnder5Plus, CableExtensionNoiseFilter, MachineCR6, MachineCR6Max, MachineEnder6, MachineCR10Smart, MachineSermoonD1)
  #define ENDSTOP_NOISE_THRESHOLD 2
#endif

/**
 * Default Settings
 *
 * These settings can be reset by M502
 *
 * Note that if EEPROM is enabled, saved values will override these.
 */

/**
 * With this option each E stepper can have its own factors for the
 * following movement settings. If fewer factors are given than the
 * total number of extruders, the last value applies to the rest.
 */
#define DISTINCT_E_FACTORS

/**
 * Default Axis Steps Per Unit (linear=steps/mm, rotational=steps/°)
 * Override with M92
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */

#if ENABLED(CrealityTitan)
  #define EStepsmm 382.14
#elif ENABLED(MicroswissDirectDrive) // AI_DEBUG: PROJDE - MicroswissDirectDrive je definováno
  #define EStepsmm 130 // AI_DEBUG: AKTIVNÍ - MicroswissDirectDrive blok projde
#elif ENABLED(BondtechLGX)
  #define EStepsmm 400
#elif(ENABLED(BondtechBMG) || ENABLED(E3DTitan))
  #define EStepsmm 415
#elif ENABLED(E3DHemera)
  #define EStepsmm 409
#elif ENABLED(SpriteExtruder)
  #define EStepsmm 430
#elif ANY(EZRstruder, MachineCR10SV2)
  #define EStepsmm 93
#elif ENABLED(MachineCR5)
  #define EStepsmm 137.65
#elif ANY(MachineCR10SPro, MachineCR10Max, MachineCRXPro, MachineEnder6, MachineEnder7, MachineCR30)
  #define EStepsmm 140
#elif ENABLED(MachineCR2020)
  #define EStepsmm 113
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
  #define EStepsmm 95 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna

#if ANY(MachineEnder5Plus, MachineCR5)
  #define ZStepsmm 800
#elif ENABLED(MachineCR30)
  #define ZStepsmm 1152.95
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
  #define ZStepsmm 400 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna

#if ENABLED(Stepper09Deg)
  #define EstepMultiplier 2
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - Stepper09Deg není definováno
  #define EstepMultiplier 1 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - Stepper09Deg není definováno

#if ENABLED(MachineEnder7)
  #define XYStepsmm 200
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineEnder7 není definováno
  #define XYStepsmm 80 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineEnder7 není definováno

#define DEFAULT_AXIS_STEPS_PER_UNIT   { XYStepsmm, XYStepsmm, ZStepsmm, (EStepsmm*EstepMultiplier) }

/**
 * Default Max Feed Rate (linear=mm/s, rotational=°/s)
 * Override with M203
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */
#if ANY(MachineCR20Pro, MachineEnder2Pro)
  #define DEFAULT_MAX_FEEDRATE          { 750, 750, 10, 75 }
  #define DEFAULT_MAX_ACCELERATION      { 2000, 2000, 100, 75 }
  #define DEFAULT_ACCELERATION          750    // X, Y, Z and E acceleration for printing moves
  #define DEFAULT_RETRACT_ACCELERATION  1000    // E acceleration for retracts
  #define DEFAULT_TRAVEL_ACCELERATION   300    // X, Y, Z acceleration for travel (non printing) moves
#elif ANY(MachineMini, MachineCR20, MachineEnder2, MachineEnder3, MachineEnder3Max, MachineEnder3V2, MachineEnder3S1, MachineEnder4, MachineEnder5, MachineEnder5Plus, MachineCR5, MachineSermoonD1)
  #define DEFAULT_MAX_FEEDRATE          { 750, 750, 10, 75 }
  #define DEFAULT_MAX_ACCELERATION      { 2000, 2000, 100, 75 }
  #define DEFAULT_ACCELERATION          750    // X, Y, Z and E acceleration for printing moves
  #define DEFAULT_RETRACT_ACCELERATION  1000    // E acceleration for retracts
  #define DEFAULT_TRAVEL_ACCELERATION   300    // X, Y, Z acceleration for travel (non printing) moves
#elif (ANY(MachineCR10SPro, MachineCR6, MachineCR6Max, MachineCR30))
  #define DEFAULT_MAX_FEEDRATE          { 500, 500, 10, 70 }
  #define DEFAULT_MAX_ACCELERATION      { 750, 750, 100, 60 }
  #define DEFAULT_ACCELERATION          750    // X, Y, Z and E acceleration for printing moves
  #define DEFAULT_RETRACT_ACCELERATION  1000    // E acceleration for retracts
  #define DEFAULT_TRAVEL_ACCELERATION   300    // X, Y, Z acceleration for travel (non printing) moves
#elif (ENABLED(MachineCR10Std))
  #define DEFAULT_MAX_FEEDRATE          { 500, 500, 10, 75 }
  #define DEFAULT_MAX_ACCELERATION      { 1500, 1500, 100, 75 }
  #define DEFAULT_ACCELERATION          750    // X, Y, Z and E acceleration for printing moves
  #define DEFAULT_RETRACT_ACCELERATION  1000    // E acceleration for retracts
  #define DEFAULT_TRAVEL_ACCELERATION   300    // X, Y, Z acceleration for travel (non printing) moves
#elif ENABLED( MachineS4)
  #define DEFAULT_MAX_FEEDRATE          { 500, 400, 10, 75 }
  #define DEFAULT_MAX_ACCELERATION      { 1000, 750, 100, 75 }
  #define DEFAULT_ACCELERATION          750    // X, Y, Z and E acceleration for printing moves
  #define DEFAULT_RETRACT_ACCELERATION  1000    // E acceleration for retracts
  #define DEFAULT_TRAVEL_ACCELERATION   300    // X, Y, Z acceleration for travel (non printing) moves
#elif ANY(MachineS5, MachineCR10Max)
  #define DEFAULT_MAX_FEEDRATE          { 500, 400, 15, 75 }
  #define DEFAULT_MAX_ACCELERATION      { 1000, 700, 100, 75 }
  #define DEFAULT_ACCELERATION          500    // X, Y, Z and E acceleration for printing moves
  #define DEFAULT_RETRACT_ACCELERATION  1000    // E acceleration for retracts
  #define DEFAULT_TRAVEL_ACCELERATION   300    // X, Y, Z acceleration for travel (non printing) moves
#elif ANY(MachineCR2020, MachineEnder6)
  #define DEFAULT_MAX_FEEDRATE          { 750, 750, 10, 75 }
  #define DEFAULT_MAX_ACCELERATION      { 7000, 7000, 100, 75 }
  #define DEFAULT_ACCELERATION          2000    // X, Y, Z and E acceleration for printing moves
  #define DEFAULT_RETRACT_ACCELERATION  1000    // E acceleration for retracts
  #define DEFAULT_TRAVEL_ACCELERATION   300    // X, Y, Z acceleration for travel (non printing) moves
#elif ENABLED(MachineEnder7)
  #define DEFAULT_MAX_FEEDRATE          { 750, 750, 10, 75 }
  #define DEFAULT_MAX_ACCELERATION      { 25000, 25000, 100, 75 }
  #define DEFAULT_ACCELERATION          10000    // X, Y, Z and E acceleration for printing moves
  #define DEFAULT_RETRACT_ACCELERATION  1000    // E acceleration for retracts
  #define DEFAULT_TRAVEL_ACCELERATION   10000    // X, Y, Z acceleration for travel (non printing) moves
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
  // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnoty (nejsou definovány)
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna

#if ENABLED(LIMITED_MAX_FR_EDITING)
  #define MAX_FEEDRATE_EDIT_VALUES    { 1000, 1000, 25, 150 } // ...or, set your own edit limits
#endif

/**
 * Default Max Acceleration (speed change with time) (linear=mm/(s^2), rotational=°/(s^2))
 * (Maximum start speed for accelerated moves)
 * Override with M201
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */

#if ENABLED(LIMITED_MAX_ACCEL_EDITING)
  #define MAX_ACCEL_EDIT_VALUES       { 2000, 2000, 250, 500 } // ...or, set your own edit limits
#endif

/**
 * Default Acceleration (speed change with time) (linear=mm/(s^2), rotational=°/(s^2))
 * Override with M204
 *
 *   M204 P    Acceleration
 *   M204 R    Retract Acceleration
 *   M204 T    Travel Acceleration
 */

/**
 * Default Jerk limits (mm/s)
 * Override with M205 X Y Z . . . E
 *
 * "Jerk" specifies the minimum speed change that requires acceleration.
 * When changing speed and direction, if the difference is less than the
 * value set here, it may happen instantaneously.
 */
#define CLASSIC_JERK // AI_DEBUG: AKTIVNÍ - CLASSIC_JERK je definováno
#if ENABLED(CLASSIC_JERK) // AI_DEBUG: PROJDE - CLASSIC_JERK je definováno
  #if ANY(MachineEnder6, MachineEnder5, MachineEnder5Plus, MachineSermoonD1, MachineCR5)
    #define DEFAULT_XJERK 20.0
    #define DEFAULT_YJERK 20.0
  #elif ENABLED(MachineEnder7)
    #define DEFAULT_XJERK 20.0
    #define DEFAULT_YJERK 20.0
  #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
    #define DEFAULT_XJERK 10.0 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnoty
    #define DEFAULT_YJERK 5.0 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnoty
  #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z podmínek není splněna
  #define DEFAULT_ZJERK  0.3 // AI_DEBUG: AKTIVNÍ - CLASSIC_JERK blok projde

  #if ENABLED(LIMITED_JERK_EDITING)
    #define MAX_JERK_EDIT_VALUES { 20, 20, 0.6, 10 } // ...or, set your own edit limits
  #endif
#endif // AI_DEBUG: PROJDE - CLASSIC_JERK je definováno

#define DEFAULT_EJERK    5.0  // May be used by Linear Advance

/**
 * Junction Deviation Factor
 *
 * See:
 *   https://reprap.org/forum/read.php?1,739819
 *   https://blog.kyneticcnc.com/2018/10/computing-junction-deviation-for-marlin.html
 */
#if DISABLED(CLASSIC_JERK)
  #define JUNCTION_DEVIATION_MM 0.013 // (mm) Distance from real junction edge
  #define JD_HANDLE_SMALL_SEGMENTS    // Use curvature estimation instead of just the junction angle
#endif

/**
 * S-Curve Acceleration
 *
 * This option eliminates vibration during printing by fitting a Bézier
 * curve to move acceleration, producing much smoother direction changes.
 *
 * See https://github.com/synthetos/TinyG/wiki/Jerk-Controlled-Motion-Explained
 */
#if NONE(MachineCR10Orig, SKRMiniE3V2, MachineCR6, MachineCR6Max, MachineCR10Smart, MachineCR10SmartPro) || ENABLED(MelziHostOnly) // AI_DEBUG: PROJDE - MachineCR10Orig ani SKRMiniE3V2 ani MachineCR6 ani MachineCR6Max ani MachineCR10Smart ani MachineCR10SmartPro nejsou definovány, MelziHostOnly není definováno
  #define S_CURVE_ACCELERATION // AI_DEBUG: AKTIVNÍ - S_CURVE_ACCELERATION je povolen
#endif // AI_DEBUG: PROJDE - S_CURVE_ACCELERATION je povolen

/**
 * Enable this option for a probe connected to the Z-MIN pin.
 * The probe replaces the Z-MIN endstop and is used for Z homing.
 * (Automatically enables USE_PROBE_FOR_Z_HOMING.)
 */
#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN // AI_DEBUG: AKTIVNÍ - Probe využívá Z_MIN pin
#define USE_PROBE_FOR_Z_HOMING // AI_DEBUG: AKTIVNÍ - Použije probe pro Z homing

/**
 * Z_MIN_PROBE_PIN
 *
 * Define this pin if the probe is not connected to Z_MIN_PIN.
 * If not defined the default pin for the selected MOTHERBOARD
 * will be used. Most of the time the default is what you want.
 *
 *  - The simplest option is to use a free endstop connector.
 *  - Use 5V for powered (usually inductive) sensors.
 *
 *  - RAMPS 1.3/1.4 boards may use the 5V, GND, and Aux4->D32 pin:
 *    - For simple switches connect...
 *      - normally-closed switches to GND and D32.
 *      - normally-open switches to 5V and D32.
 */
#if ENABLED(MachineCR5)
  #define Z_MIN_PROBE_PIN 19 // Pin 32 is the RAMPS default
#endif

#if ENABLED(MachineCR10SProV2) // AI_DEBUG: PROJDE - MachineCR10SProV2 je definováno
  #define Z_MIN_PROBE_PIN 19 // Pin 19 for proximity sensor // AI_DEBUG: AKTIVNÍ - MachineCR10SProV2 blok projde
#endif // AI_DEBUG: PROJDE - MachineCR10SProV2 blok projde
/**
 * Probe Type
 *
 * Allen Key Probes, Servo Probes, Z-Sled Probes, FIX_MOUNTED_PROBE, etc.
 * Activate one of these to use Auto Bed Leveling below.
 */

/**
 * A Fix-Mounted Probe either doesn't deploy or needs manual deployment.
 *   (e.g., an inductive probe or a nozzle-based probe-switch.)
 */

#define FIX_MOUNTED_PROBE // AI_DEBUG: AKTIVNÍ - Pevně namontovaný probe (proximity sensor)

/**
 * Z Servo Probe, such as an endstop switch on a rotating arm.
 */

/**
 * MagLev V4 probe by MDD
 *
 * This probe is deployed and activated by powering a built-in electromagnet.
 */
#if ENABLED(MAGLEV4)
  #define MAGLEV_TRIGGER_DELAY 15     // Changing this risks overheating the coil
#endif

/**
 * Touch-MI Probe by hotends.fr
 *
 * This probe is deployed and activated by moving the X-axis to a magnet at the edge of the bed.
 * By default, the magnet is assumed to be on the left and activated by a home. If the magnet is
 * on the right, enable and set TOUCH_MI_DEPLOY_XPOS to the deploy position.
 *
 * Also requires: BABYSTEPPING, BABYSTEP_ZPROBE_OFFSET, Z_SAFE_HOMING,
 *                and a minimum Z_HOMING_HEIGHT of 10.
 */
#if ENABLED(ABL_TOUCH_MI)
  #define TOUCH_MI_PROBE
#endif
#if ENABLED(TOUCH_MI_PROBE)
  #define TOUCH_MI_RETRACT_Z 0.5                  // Height at which the probe retracts
#endif

#if ENABLED(ABL_BLTOUCH)
  #if DISABLED(MachineCR10Orig)
    #define PROBING_FANS_OFF          // Turn fans off when probing
  #endif

  #if ENABLED(MachineEnder4) && NONE(SKR13, SKR14, SKR14Turbo, SKRPRO11, SKRE3Turbo)
    #define SOLENOID_PROBE PIN_15
  #endif
#endif

#if ENABLED(RACK_AND_PINION_PROBE)
  #define Z_PROBE_DEPLOY_X  X_MIN_POS
  #define Z_PROBE_RETRACT_X X_MAX_POS
#endif

/**
 * Magnetically Mounted Probe
 * For probes such as Euclid, Klicky, Klackender, etc.
 */
#if ENABLED(MAG_MOUNTED_PROBE)
  #define PROBE_DEPLOY_FEEDRATE (133*60)  // (mm/min) Probe deploy speed
  #define PROBE_STOW_FEEDRATE   (133*60)  // (mm/min) Probe stow speed

  #define MAG_MOUNTED_DEPLOY_1 { PROBE_DEPLOY_FEEDRATE, { 245, 114, 30 } }  // Move to side Dock & Attach probe
  #define MAG_MOUNTED_DEPLOY_2 { PROBE_DEPLOY_FEEDRATE, { 210, 114, 30 } }  // Move probe off dock
  #define MAG_MOUNTED_DEPLOY_3 { PROBE_DEPLOY_FEEDRATE, {   0,   0,  0 } }  // Extra move if needed
  #define MAG_MOUNTED_DEPLOY_4 { PROBE_DEPLOY_FEEDRATE, {   0,   0,  0 } }  // Extra move if needed
  #define MAG_MOUNTED_DEPLOY_5 { PROBE_DEPLOY_FEEDRATE, {   0,   0,  0 } }  // Extra move if needed
  #define MAG_MOUNTED_STOW_1   { PROBE_STOW_FEEDRATE,   { 245, 114, 20 } }  // Move to dock
  #define MAG_MOUNTED_STOW_2   { PROBE_STOW_FEEDRATE,   { 245, 114,  0 } }  // Place probe beside remover
  #define MAG_MOUNTED_STOW_3   { PROBE_STOW_FEEDRATE,   { 230, 114,  0 } }  // Side move to remove probe
  #define MAG_MOUNTED_STOW_4   { PROBE_STOW_FEEDRATE,   { 210, 114, 20 } }  // Side move to remove probe
  #define MAG_MOUNTED_STOW_5   { PROBE_STOW_FEEDRATE,   {   0,   0,  0 } }  // Extra move if needed
#endif

#if ENABLED(DUET_SMART_EFFECTOR)
  #define SMART_EFFECTOR_MOD_PIN  -1  // Connect a GPIO pin to the Smart Effector MOD pin
#endif

/**
 * Use StallGuard2 to probe the bed with the nozzle.
 * Requires stallGuard-capable Trinamic stepper drivers.
 * CAUTION: This can damage machines with Z lead screws.
 *          Take extreme care when setting up this feature.
 */

/**
 * Allen key retractable z-probe as seen on many Kossel delta printers - https://reprap.org/wiki/Kossel#Automatic_bed_leveling_probe
 * Deploys by touching z-axis belt. Retracts by pushing the probe down.
 */
#if ENABLED(Z_PROBE_ALLEN_KEY)

  #define Z_PROBE_ALLEN_KEY_DEPLOY_1 { 30.0, PRINTABLE_RADIUS, 100.0 }
  #define Z_PROBE_ALLEN_KEY_DEPLOY_1_FEEDRATE XY_PROBE_FEEDRATE

  #define Z_PROBE_ALLEN_KEY_DEPLOY_2 { 0.0, PRINTABLE_RADIUS, 100.0 }
  #define Z_PROBE_ALLEN_KEY_DEPLOY_2_FEEDRATE (XY_PROBE_FEEDRATE)/10

  #define Z_PROBE_ALLEN_KEY_DEPLOY_3 { 0.0, (PRINTABLE_RADIUS) * 0.75, 100.0 }
  #define Z_PROBE_ALLEN_KEY_DEPLOY_3_FEEDRATE XY_PROBE_FEEDRATE

  #define Z_PROBE_ALLEN_KEY_STOW_1 { -64.0, 56.0, 23.0 } // Move the probe into position
  #define Z_PROBE_ALLEN_KEY_STOW_1_FEEDRATE XY_PROBE_FEEDRATE

  #define Z_PROBE_ALLEN_KEY_STOW_2 { -64.0, 56.0, 3.0 } // Push it down
  #define Z_PROBE_ALLEN_KEY_STOW_2_FEEDRATE (XY_PROBE_FEEDRATE)/10

  #define Z_PROBE_ALLEN_KEY_STOW_3 { -64.0, 56.0, 50.0 } // Move it up to clear
  #define Z_PROBE_ALLEN_KEY_STOW_3_FEEDRATE XY_PROBE_FEEDRATE

  #define Z_PROBE_ALLEN_KEY_STOW_4 { 0.0, 0.0, 50.0 }
  #define Z_PROBE_ALLEN_KEY_STOW_4_FEEDRATE XY_PROBE_FEEDRATE

#endif // Z_PROBE_ALLEN_KEY

/**
 * Z Probe to nozzle (X,Y) offset, relative to (0, 0).
 *
 * X and Y offset
 *   Use a caliper or ruler to measure the distance from the tip of
 *   the Nozzle to the center-point of the Probe in the X and Y axes.
 *
 * Z offset
 * - For the Z offset use your best known value and adjust at runtime.
 * - Common probes trigger below the nozzle and have negative values for Z offset.
 * - Probes triggering above the nozzle height are uncommon but do exist. When using
 *   probes such as this, carefully set Z_CLEARANCE_DEPLOY_PROBE and Z_CLEARANCE_BETWEEN_PROBES
 *   to avoid collisions during probing.
 *
 * Tune and Adjust
 * -  Probe Offsets can be tuned at runtime with 'M851', LCD menus, babystepping, etc.
 * -  PROBE_OFFSET_WIZARD (configuration_adv.h) can be used for setting the Z offset.
 *
 
 *
 *     +-- BACK ---+
 *     |           |
 *   L |    (+) P  | R <-- probe (20,20)
 *   E |           | I
 *   F | (-) N (+) | G <-- nozzle (10,10)
 *   T |           | H
 *     |    (-)    | T
 *     |           |
 *     O-- FRONT --+
 *   (0,0)
 *
 * Specify a Probe position as { X, Y, Z }
 */
#define NOZZLE_TO_PROBE_OFFSET { -150, -150, 0 } // AI_DEBUG: AKTIVNÍ - Offset probe vůči nozzle (-150,-150,0)

#if ENABLED(ABL_BLTOUCH)
  #define PROBING_MARGIN 3
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - ABL_BLTOUCH není definováno
  #define PROBING_MARGIN 10 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - ABL_BLTOUCH není definováno

#define XY_PROBE_FEEDRATE (200*60)

#define Z_PROBE_FEEDRATE_FAST (12*60)

#define Z_PROBE_FEEDRATE_SLOW (Z_PROBE_FEEDRATE_FAST / 2)

/**
 * Probe Activation Switch
 * A switch indicating proper deployment, or an optical
 * switch triggered when the carriage is near the bed.
 */
#if ANY(MachineCR6, MachineCR6Max, MachineCR10Smart)
  #define PROBE_ACTIVATION_SWITCH
#endif
#if ENABLED(PROBE_ACTIVATION_SWITCH)
  #define PROBE_ACTIVATION_SWITCH_STATE LOW // State indicating probe is active
#endif

/**
 * Tare Probe (determine zero-point) prior to each probe.
 * Useful for a strain gauge or piezo sensor that needs to factor out
 * elements such as cables pulling on the carriage.
 */
#if ANY(MachineCR6, MachineCR6Max, MachineCR10Smart)
  #define PROBE_TARE
#endif
#if ENABLED(PROBE_TARE)
  #define PROBE_TARE_TIME  200    // (ms) Time to hold tare pin
  #define PROBE_TARE_DELAY 200    // (ms) Delay after tare before
  #define PROBE_TARE_STATE LOW   // State to write pin for tare
  #if ENABLED(PROBE_ACTIVATION_SWITCH)
  #endif
#endif

/**
 * Probe Enable / Disable
 * The probe only provides a triggered signal when enabled.
 */
#if ENABLED(PROBE_ENABLE_DISABLE)
#endif

/**
 * Multiple Probing
 *
 * You may get improved results by probing 2 or more times.
 * With EXTRA_PROBING the more atypical reading(s) will be disregarded.
 *
 * A total of 2 does fast/slow probes with a weighted average.
 * A total of 3 or more adds more slow probes, taking the average.
 */
#if DISABLED(MachineCR10Orig) || ENABLED(MelziHostOnly)
  #define MULTIPLE_PROBING 2
#endif

/**
 * Z probes require clearance when deploying, stowing, and moving between
 * probe points to avoid hitting the bed and other hardware.
 * Servo-mounted probes require extra space for the arm to rotate.
 * Inductive probes need space to keep from triggering early.
 *
 * Use these settings to specify the distance (mm) to raise the probe (or
 * lower the bed). The values set here apply over and above any (negative)
 * probe Z Offset set with NOZZLE_TO_PROBE_OFFSET, M851, or the LCD.
 * Only integer values >= 1 are valid here.
 *
 * Example: `M851 Z-5` with a CLEARANCE of 4  =>  9mm from bed to nozzle.
 *     But: `M851 Z+1` with a CLEARANCE of 2  =>  2mm from bed to nozzle.
 */
#if ENABLED(MachineEnder5)
  #define Z_CLEARANCE_DEPLOY_PROBE   0 // Z Clearance for Deploy/Stow
#else
  #define Z_CLEARANCE_DEPLOY_PROBE   10 // Z Clearance for Deploy/Stow
#endif
#if ANY(MachineCR6, MachineCR6Max, MachineCR10Smart)
  #define Z_CLEARANCE_BETWEEN_PROBES  3 // Z Clearance between probe points
  #define Z_CLEARANCE_MULTI_PROBE     3 // Z Clearance between multiple probes
#else
  #define Z_CLEARANCE_BETWEEN_PROBES  5 // Z Clearance between probe points
  #define Z_CLEARANCE_MULTI_PROBE     5 // Z Clearance between multiple probes
#endif
#if DISABLED(TOUCH_MI_PROBE)
  #define Z_AFTER_PROBING           5 // Z position after probing is done
#endif

#define Z_PROBE_LOW_POINT          -5 // Farthest distance below the trigger-point to go before stopping

#define Z_PROBE_OFFSET_RANGE_MIN -9
#define Z_PROBE_OFFSET_RANGE_MAX 9

#if ANY(ABL_EZABL, ABL_BLTOUCH, ABL_NCSW, ABL_TOUCH_MI, MachineCR6, MachineCR6Max, MachineCR10Smart) && NONE(MachineCR10Orig, SKRMiniE3V2, SKRE3Turbo)
#endif

#if ENABLED(PAUSE_BEFORE_DEPLOY_STOW)
#endif

/**
 * Enable one or more of the following if probing seems unreliable.
 * Heaters and/or fans can be disabled during probing to minimize electrical
 * noise. A delay can also be added to allow noise and vibration to settle.
 * These options are most useful for the BLTouch probe, but may also improve
 * readings with inductive probes and piezo sensors.
 */
#if (ANY(ABL_EZABL, ABL_NCSW, MachineCR6, MachineCR6Max)) && DISABLED(MachineCR10Orig)
#endif
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
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z předchozích podmínek není splněna
  #if ANY(MachineCR10Orig, SKR13, SKR14, SKR14Turbo, SKRMiniE3V2, SKRMiniE3V3, SKRE3Turbo) && ENABLED(SKR_ReverseSteppers) && ENABLED(MachineEnder6)
    #define INVERT_X_DIR true
    #define INVERT_Y_DIR false
  #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineCR10Orig blok neprojde
    #if ANY(MachineSermoonD1, MachineCR5)
      #define INVERT_X_DIR true
    #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineSermoonD1 ani MachineCR5 nejsou definovány
      #define INVERT_X_DIR false // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
    #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineSermoonD1 ani MachineCR5 nejsou definovány
    #if ANY(MachineCRX,MachineCR10SPro, MachineCR10Max, MachineCR2020, MachineCR5, MachineEnder6, MachineEnder7) // AI_DEBUG: PROJDE - MachineCR10SPro je definováno
      #define INVERT_Y_DIR true // AI_DEBUG: AKTIVNÍ - MachineCR10SPro blok projde
    #else
      #define INVERT_Y_DIR false
    #endif // AI_DEBUG: PROJDE - MachineCR10SPro je definováno
  #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineCR10Orig blok neprojde
  #if ANY(MachineEnder5Plus, MachineCR2020, MachineEnder6, MachineSermoonD1, MachineEnder7)
    #define INVERT_Z_DIR false
  #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineEnder5Plus ani MachineCR2020 ani MachineEnder6 ani MachineSermoonD1 ani MachineEnder7 nejsou definovány
    #define INVERT_Z_DIR true // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
  #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineEnder5Plus ani MachineCR2020 ani MachineEnder6 ani MachineSermoonD1 ani MachineEnder7 nejsou definovány
  #if ANY(E3DTitan, MachineCR2020, MachineCR5, MachineEnder6, MachineEnder7)
    #define INVERT_E0_DIR true
    #define INVERT_E1_DIR false
  #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - E3DTitan ani MachineCR2020 ani MachineCR5 ani MachineEnder6 ani MachineEnder7 nejsou definovány
    #define INVERT_E0_DIR false // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
    #define INVERT_E1_DIR true // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
  #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - E3DTitan ani MachineCR2020 ani MachineCR5 ani MachineEnder6 ani MachineEnder7 nejsou definovány
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z předchozích podmínek není splněna

// AI_DEBUG: AKTIVNÍ - tyto definice jsou vždy aktivní (pro více extruderů)
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false
#define INVERT_E6_DIR false
#define INVERT_E7_DIR false

/**
 * Set Z_IDLE_HEIGHT if the Z-Axis moves on its own when steppers are disabled.
 *  - Use a low value (i.e., Z_MIN_POS) if the nozzle falls down to the bed.
 *  - Use a large value (i.e., Z_MAX_POS) if the bed falls down, away from the nozzle.
 */

#if ANY(MachineEnder5)
  #define Z_HOMING_HEIGHT 0
#elif ENABLED(TOUCH_MI_PROBE)
  #define Z_HOMING_HEIGHT 10
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z předchozích podmínek není splněna
  #define Z_HOMING_HEIGHT 4  // (in mm) Minimal z height before homing (G28) for Z clearance above the bed, clamps, ... // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z předchozích podmínek není splněna

#if ANY(MachineEnder5, MachineEnder5Plus, MachineEnder6)
  #define X_HOME_DIR 1
  #define Y_HOME_DIR 1
  #define Z_HOME_DIR -1
#else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z předchozích podmínek není splněna
  #define X_HOME_DIR -1 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
  #if ENABLED(MachineEnder7)
    #define Y_HOME_DIR 1
  #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineEnder7 není definováno
    #define Y_HOME_DIR -1 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
  #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineEnder7 není definováno
  #define Z_HOME_DIR -1 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
#endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z předchozích podmínek není splněna

  #if ENABLED(MachineMini)
    #define X_BED_SIZE 300
    #define Y_BED_SIZE 220
    #define Z_MAX_POS 300
    #define X_MAX_POS 300
    #define Y_MAX_POS 220
    #define ClipClearance 15
  #elif ENABLED(MachineEnder2)
    #define X_BED_SIZE 150
    #define Y_BED_SIZE 150
    #define Z_MAX_POS 200
    #define X_MAX_POS 150
    #define Y_MAX_POS 150
    #define ClipClearance 15
    #elif ENABLED(MachineEnder2Pro)
    #define X_BED_SIZE 165
    #define Y_BED_SIZE 165
    #define Z_MAX_POS 180
    #define X_MAX_POS 165
    #define Y_MAX_POS 165
    #define ClipClearance 15
  #elif ENABLED(MachineEnder3Max)
    #define X_BED_SIZE 300
    #define Y_BED_SIZE 300
    #define Z_MAX_POS 340
    #define X_MAX_POS 300
    #define Y_MAX_POS 300
    #define ClipClearance 10
  #elif ENABLED(MachineCR6)
    #define X_BED_SIZE 235
    #define Y_BED_SIZE 235
    #define X_MAX_POS X_BED_SIZE
    #define Y_MAX_POS Y_BED_SIZE
    #define Z_MAX_POS 250
    #define ClipClearance 5
  #elif ENABLED(MachineCR6Max)
    #define X_BED_SIZE 400
    #define Y_BED_SIZE 400
    #define X_MAX_POS 410
    #define Y_MAX_POS 404
    #define Z_MAX_POS 405
    #define ClipClearance 5
  #elif ANY(MachineEnder3, MachineEnder3V2)
    #define X_BED_SIZE 230
    #define Y_BED_SIZE 230
    #define Z_MAX_POS 250
    #define X_MAX_POS 245
    #define Y_MAX_POS 240
    #define ClipClearance 15
  #elif ANY(MachineEnder3S1)
    #define X_BED_SIZE 220
    #define Y_BED_SIZE 220
    #define Z_MAX_POS 270
    #define X_MAX_POS 250
    #define Y_MAX_POS 228
    #define ClipClearance 15
  #elif(ANY(MachineEnder4, MachineEnder5))
    #define X_BED_SIZE 220
    #define Y_BED_SIZE 220
    #define Z_MAX_POS 300
    #define X_MAX_POS 230
    #define Y_MAX_POS 225
    #define ClipClearance 15
  #elif ENABLED(MachineEnder5Plus)
    #define Y_BED_SIZE 360
    #define Z_MAX_POS 400
    #if ENABLED(E3DHemera)
      #define X_BED_SIZE 352
      #define X_MAX_POS 352
    #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - E3DHemera není definováno
      #define X_BED_SIZE 360 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
      #define X_MAX_POS 360 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
    #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - E3DHemera není definováno
    #define Y_MAX_POS 360
    #define ClipClearance 25
  #elif ENABLED(MachineCR5)
    #define X_BED_SIZE 300
    #define Y_BED_SIZE 225
    #define Z_MAX_POS 380
    #define X_MAX_POS 305
    #define Y_MAX_POS 225
    #define ClipClearance 15
  #elif ENABLED(MachineEnder6)
    #define X_BED_SIZE 260
    #define Y_BED_SIZE 260
    #define Z_MAX_POS 400
    #define X_MAX_POS 260
    #define Y_MAX_POS 260
    #define ClipClearance 10
  #elif ENABLED(MachineSermoonD1)
    #define X_BED_SIZE 290
    #define Y_BED_SIZE 270
    #define Z_MAX_POS 320
    #define X_MAX_POS 290
    #define Y_MAX_POS 270
    #define ClipClearance 10
  #elif ENABLED(MachineEnder7)
    #define X_BED_SIZE 250
    #define Y_BED_SIZE 250
    #define Z_MAX_POS 350
    #define X_MAX_POS 255
    #define Y_MAX_POS 255
    #define ClipClearance 10
  #elif ENABLED(MachineCR30)
    #define X_BED_SIZE 220
    #define Y_BED_SIZE 250
    #define Z_MAX_POS 20000000
    #define X_MAX_POS X_BED_SIZE
    #define Y_MAX_POS Y_BED_SIZE
    #define ClipClearance 2
  #elif ENABLED(MachineCR20)
    #define X_BED_SIZE 230
    #define Y_BED_SIZE 230
    #define Z_MAX_POS 250
    #define X_MAX_POS 240
    #define Y_MAX_POS 240
    #define ClipClearance 15
  #elif ENABLED(MachineCRX)
    #define X_BED_SIZE 300
    #define Y_BED_SIZE 300
    #define Z_MAX_POS 400
    #define X_MAX_POS 315
    #define Y_MAX_POS 308
    #define ClipClearance 15
  #elif ENABLED(MachineCR10SProV2) // AI_DEBUG: PROJDE - MachineCR10SProV2 je definováno
    #define X_BED_SIZE 300 // AI_DEBUG: AKTIVNÍ - MachineCR10SProV2 blok projde
    #define Y_BED_SIZE 300 // AI_DEBUG: AKTIVNÍ - MachineCR10SProV2 blok projde
    #define Z_MAX_POS 400 // AI_DEBUG: AKTIVNÍ - MachineCR10SProV2 blok projde
    #define X_MAX_POS 315 // AI_DEBUG: AKTIVNÍ - MachineCR10SProV2 blok projde
    #define Y_MAX_POS 310 // AI_DEBUG: AKTIVNÍ - MachineCR10SProV2 blok projde
    #define ClipClearance 5 // AI_DEBUG: AKTIVNÍ - MachineCR10SProV2 blok projde
  #elif ENABLED(MachineCR10SPro)
    #define X_BED_SIZE 300
    #define Y_BED_SIZE 300
    #define Z_MAX_POS 400
    #define X_MAX_POS 315
    #define Y_MAX_POS 310
    #define ClipClearance 10
  #elif ENABLED(MachineCR10Std)
    #define X_BED_SIZE 300
    #define Y_BED_SIZE 300
    #define Z_MAX_POS 400
    #define X_MAX_POS 315
    #define Y_MAX_POS 310
    #define ClipClearance 15
  #elif ENABLED( MachineS4)
    #define X_BED_SIZE 400
    #define Y_BED_SIZE 400
    #define Z_MAX_POS 400
    #define X_MAX_POS 410
    #define Y_MAX_POS 400
    #define ClipClearance 15
  #elif ENABLED(MachineCR10Max)
    #define X_BED_SIZE 470
    #define Y_BED_SIZE 470
    #define Z_MAX_POS 470
    #define X_MAX_POS 470
    #define Y_MAX_POS 470
    #define ClipClearance 15
  #elif ENABLED(MachineS5)
    #define X_BED_SIZE 500
    #define Y_BED_SIZE 500
    #define Z_MAX_POS 500
    #define X_MAX_POS 510
    #define Y_MAX_POS 500
    #define ClipClearance 20
  #elif ENABLED(MachineCR2020)
    #define X_BED_SIZE 200
    #define Y_BED_SIZE 202.5
    #define Z_MAX_POS 210
    #define X_MAX_POS 200
    #define Y_MAX_POS 202.5
    #define ClipClearance 15
  #endif

  #ifndef ClipClearance
    #define ClipClearance 0
  #endif

#if ENABLED(MicroswissDirectDrive) // AI_DEBUG: PROJDE - MicroswissDirectDrive je definováno
  #define X_MIN_POS -15 // AI_DEBUG: AKTIVNÍ - MicroswissDirectDrive blok projde
  #define Y_MIN_POS -10 // AI_DEBUG: AKTIVNÍ - MicroswissDirectDrive blok projde
#elif ENABLED(MachineEnder2Pro)
  #define X_MIN_POS -18
  #define Y_MIN_POS -2
#elif ENABLED(TOUCH_MI_PROBE)
  #define X_MIN_POS -4
  #define Y_MIN_POS -10
#elif ANY(MachineCR6, MachineCR10Smart, MachineEnder3S1, MachineCR10SmartPro)
  #define X_MIN_POS -5
  #define Y_MIN_POS -2
#elif ENABLED(MachineCR6Max)
  #define X_MIN_POS -10
  #define Y_MIN_POS -3
#elif ENABLED(MachineCR30)
  #define X_MIN_POS 0
  #define Y_MIN_POS -5
#else
  #define X_MIN_POS 0
  #define Y_MIN_POS 0
#endif // AI_DEBUG: PROJDE - MicroswissDirectDrive je definováno
#define Z_MIN_POS 0
#ifndef X_MAX_POS
  #define X_MAX_POS X_BED_SIZE
#endif
#ifndef Y_MAX_POS
  #define Y_MAX_POS Y_BED_SIZE
#endif

/**
 * Software Endstops
 *
 * - Prevent moves outside the set machine bounds.
 * - Individual axes can be disabled, if desired.
 * - X and Y only apply to Cartesian robots.
 * - Use 'M211' to set software endstops on/off or report current state
 */

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
#if(NONE(MachineCR10Orig, LowMemoryBoard)) // AI_DEBUG: PROJDE - MachineCR10Orig není definováno, LowMemoryBoard je definováno
  #if EITHER(MIN_SOFTWARE_ENDSTOPS, MAX_SOFTWARE_ENDSTOPS) // AI_DEBUG: PROJDE - MIN_SOFTWARE_ENDSTOPS i MAX_SOFTWARE_ENDSTOPS jsou definovány
    #define SOFT_ENDSTOPS_MENU_ITEM  // Enable/Disable software endstops from the LCD // AI_DEBUG: AKTIVNÍ - software endstops menu item je povolen
  #endif // AI_DEBUG: PROJDE - MIN_SOFTWARE_ENDSTOPS i MAX_SOFTWARE_ENDSTOPS jsou definovány
#endif // AI_DEBUG: PROJDE - MachineCR10Orig není definováno, LowMemoryBoard je definováno

/**
 * Filament Runout Sensors
 * Mechanical or opto endstops are used to check for the presence of filament.
 *
 * IMPORTANT: Runout will only trigger if Marlin is aware that a print job is running.
 * Marlin knows a print job is running when:
 *  1. Running a print job from media started with M24.
 *  2. The Print Job Timer has been started with M75.
 *  3. The heaters were turned on with a wait command (M109) and PRINTJOB_TIMER_AUTOSTART is enabled.
 *
 * RAMPS-based boards use SERVO3_PIN for the first runout sensor.
 * For other boards you may need to define FIL_RUNOUT_PIN, FIL_RUNOUT2_PIN, etc.
 */
#if DISABLED(MachineCR10Orig) || ANY(Melzi_To_SBoardUpgrade, AddonFilSensor, lerdgeFilSensor, DualFilSensors) // AI_DEBUG: PROJDE - MachineCR10Orig není definováno, takže DISABLED(MachineCR10Orig) je true
  #define FILAMENT_RUNOUT_SENSOR // AI_DEBUG: AKTIVNÍ - filament runout sensor je povolen
#endif
#if ENABLED(FILAMENT_RUNOUT_SENSOR) // AI_DEBUG: PROJDE - FILAMENT_RUNOUT_SENSOR je definováno
   #if ENABLED(DualFilSensors)
    #if DISABLED(SKR13, SKR14, SKR14Turbo, SKRPRO11, SKRE3Turbo)
      #define NUM_RUNOUT_SENSORS   2     // Number of sensors, up to one per extruder. Define a FIL_RUNOUT#_PIN for each.
      #define ENABLED_ADDON , true
      #define DISABLED_ADDON , false
      #define MODE_ADDON_7 , 7
      #define MODE_ADDON_2 , 2
      #define MODE_ADDON_1 , 1
    #endif
    #define FIL_RUNOUT2_PIN 15
  #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - DualFilSensors není definováno
    #define NUM_RUNOUT_SENSORS   1     // Number of sensors, up to one per extruder. Define a FIL_RUNOUT#_PIN for each. // AI_DEBUG: AKTIVNÍ - single sensor fallback
      #define ENABLED_ADDON // AI_DEBUG: AKTIVNÍ - single sensor fallback
      #define DISABLED_ADDON // AI_DEBUG: AKTIVNÍ - single sensor fallback
      #define MODE_ADDON_7 // AI_DEBUG: AKTIVNÍ - single sensor fallback
      #define MODE_ADDON_2 // AI_DEBUG: AKTIVNÍ - single sensor fallback
      #define MODE_ADDON_1 // AI_DEBUG: AKTIVNÍ - single sensor fallback
  #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - DualFilSensors není definováno
  #if NONE(MachineCR10Orig, MachineCR20, MachineEnder3,  MachineEnder2, MachineEnder2Pro, MachineEnder3V2, MachineEnder4, MachineEnder5, MachineCRX, Melzi_To_SBoardUpgrade) || ANY(AddonFilSensor, lerdgeFilSensor, DualFilSensors) // AI_DEBUG: PROJDE - MachineCR10Orig ani MachineCR20 ani MachineEnder3 ani MachineEnder2 ani MachineEnder2Pro ani MachineEnder3V2 ani MachineEnder4 ani MachineEnder5 ani MachineCRX ani Melzi_To_SBoardUpgrade nejsou definovány
    #define FIL_RUNOUT_ENABLED { true ENABLED_ADDON} // Default enabled state for sensors E0[, E1[, E2[, E3...]]]. Override with M591EnnSn followed by M500. // AI_DEBUG: AKTIVNÍ - filament runout je povolen
  #else
    #define FIL_RUNOUT_ENABLED { false DISABLED_ADDON} // Default enabled state for sensors E0[, E1[, E2[, E3...]]]. Override with M591EnnSn followed by M500.
  #endif // AI_DEBUG: PROJDE - MachineCR10Orig ani MachineCR20 ani MachineEnder3 ani MachineEnder2 ani MachineEnder2Pro ani MachineEnder3V2 ani MachineEnder4 ani MachineEnder5 ani MachineCRX ani Melzi_To_SBoardUpgrade nejsou definovány

  #if ENABLED(FilamentEncoder)
    #define FIL_RUNOUT_MODE    { 7 MODE_ADDON_7}    // Default mode for sensors E0[, E1[, E2[, E3...]]]. 0:NONE  1:Switch NO  2:Switch NC  7:Motion Sensor Override with M591EnPnn
  #elif DISABLED(lerdgeFilSensor) && ( ANY(AddonFilSensor, DualFilSensors) || NONE(MachineCR10Orig, MachineCR20, MachineEnder3, MachineEnder2, MachineEnder2Pro,  MachineEnder3V2, MachineEnder4, MachineEnder5, MachineCRX, Melzi_To_SBoardUpgrade)) // AI_DEBUG: PROJDE - lerdgeFilSensor není definováno, MachineCR10Orig ani MachineCR20 ani MachineEnder3 ani MachineEnder2 ani MachineEnder2Pro ani MachineEnder3V2 ani MachineEnder4 ani MachineEnder5 ani MachineCRX ani Melzi_To_SBoardUpgrade nejsou definovány
    #define FIL_RUNOUT_MODE    { 2 MODE_ADDON_2}    // Default mode for sensors E0[, E1[, E2[, E3...]]]. 0:NONE  1:Switch NO  2:Switch NC  7:Motion Sensor Override with M591EnPnn // AI_DEBUG: AKTIVNÍ - filament runout mode 2 (Switch NC)
  #else
    #define FIL_RUNOUT_MODE    { 1 MODE_ADDON_1}    // Default mode for sensors E0[, E1[, E2[, E3...]]]. 0:NONE  1:Switch NO  2:Switch NC  7:Motion Sensor Override with M591EnPnn
  #endif // AI_DEBUG: PROJDE - lerdgeFilSensor není definováno, MachineCR10Orig ani MachineCR20 ani MachineEnder3 ani MachineEnder2 ani MachineEnder2Pro ani MachineEnder3V2 ani MachineEnder4 ani MachineEnder5 ani MachineCRX ani Melzi_To_SBoardUpgrade nejsou definovány

  #define FILAMENT_RUNOUT_SCRIPT "M600"

  #if ENABLED(FilamentEncoder)
    #define FILAMENT_RUNOUT_DISTANCE_MM 12
  #elif ANY(MachineEnder5Plus, MachineCR10SPro, MachineCR10SProV2) // AI_DEBUG: PROJDE - MachineCR10SProV2 je definováno
    #define FILAMENT_RUNOUT_DISTANCE_MM 10 // AI_DEBUG: AKTIVNÍ - MachineCR10SProV2 blok projde
  #else
    #define FILAMENT_RUNOUT_DISTANCE_MM 5
  #endif // AI_DEBUG: PROJDE - MachineCR10SProV2 je definováno

  #if DISABLED(MachineEnder3S1) // AI_DEBUG: PROJDE - MachineEnder3S1 není definováno
    #define FIL_RUNOUT_PULLUP          // Use internal pullup for filament runout pins. // AI_DEBUG: AKTIVNÍ - filament runout pullup je povolen
  #else
    #define FIL_RUNOUT_PULLDOWN      // Use internal pulldown for filament runout pins.
  #endif // AI_DEBUG: PROJDE - MachineEnder3S1 není definováno

#endif

/**
 * Choose one of the options below to enable G29 Bed Leveling. The parameters
 * and behavior of G29 will change depending on your selection.
 *
 *  If using a Probe for Z Homing, enable Z_SAFE_HOMING also!
 *
 * - AUTO_BED_LEVELING_3POINT
 *   Probe 3 arbitrary points on the bed (that aren't collinear)
 *   You specify the XY coordinates of all 3 points.
 *   The result is a single tilted plane. Best for a flat bed.
 *
 * - AUTO_BED_LEVELING_LINEAR
 *   Probe several points in a grid.
 *   You specify the rectangle and the density of sample points.
 *   The result is a single tilted plane. Best for a flat bed.
 *
 * - AUTO_BED_LEVELING_BILINEAR
 *   Probe several points in a grid.
 *   You specify the rectangle and the density of sample points.
 *   The result is a mesh, best for large or uneven beds.
 *
 * - AUTO_BED_LEVELING_UBL (Unified Bed Leveling)
 *   A comprehensive bed leveling system combining the features and benefits
 *   of other systems. UBL also includes integrated Mesh Generation, Mesh
 *   Validation and Mesh Editing systems.
 *
 * - MESH_BED_LEVELING
 *   Probe a grid manually
 *   The result is a mesh, suitable for large or uneven beds. (See BILINEAR.)
 *   For machines without a probe, Mesh Bed Leveling provides a method to perform
 *   leveling in steps so you can manually adjust the Z height at each grid-point.
 *   With an LCD controller the process is guided step-by-step.
 */
  
#define AUTO_BED_LEVELING_BILINEAR // AI_DEBUG: AKTIVNÍ - Bilineární bed leveling systém
/**
 * Normally G28 leaves leveling disabled on completion. Enable one of
 * these options to restore the prior leveling state or to always enable
 * leveling immediately after G28.
 */
#define RESTORE_LEVELING_AFTER_G28

/**
 * Auto-leveling needs preheating
 */
#if ENABLED(PREHEAT_BEFORE_LEVELING)
  #define LEVELING_NOZZLE_TEMP 120   // (°C) Only applies to E0 at this time
  #define LEVELING_BED_TEMP     50
#endif

/**
 * Bed Distance Sensor
 *
 * Measures the distance from bed to nozzle with accuracy of 0.01mm.
 * For information about this sensor https://github.com/markniu/Bed_Distance_sensor
 * Uses I2C port, so it requires I2C library markyue/Panda_SoftMasterI2C.
 */

/**
 * Enable detailed logging of G28, G29, M48, etc.
 * Turn on with the command 'M111 S32'.
 * NOTE: Requires a lot of PROGMEM!
 */
#if ENABLED(MachineLargeROM)
#endif
#define DEBUG_LEVELING_FEATURE // AI_DEBUG: AKTIVNÍ - Debug leveling aktivován zde (řádek 3266)

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_UBL, PROBE_MANUALLY)
  #define MANUAL_PROBE_START_Z 0.2  // (mm) Comment out to use the last-measured height
#endif

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_BILINEAR, AUTO_BED_LEVELING_UBL) // AI_DEBUG: PROJDE - AUTO_BED_LEVELING_BILINEAR je definováno
  /**
   * Gradually reduce leveling correction until a set height is reached,
   * at which point movement will be level to the machine's XY plane.
   * The height can be set with M420 Z<height>
   */
  #if NONE(MachineCR10Orig, SKRMiniE3V2) // AI_DEBUG: PROJDE - MachineCR10Orig ani SKRMiniE3V2 nejsou definovány
    #define ENABLE_LEVELING_FADE_HEIGHT
    #if ENABLED(ENABLE_LEVELING_FADE_HEIGHT)
      #define DEFAULT_LEVELING_FADE_HEIGHT 10.0 // (mm) Default fade height.
    #endif
  #endif

  /**
   * For Cartesian machines, instead of dividing moves on mesh boundaries,
   * split up moves into short segments like a Delta. This follows the
   * contours of the bed more closely than edge-to-edge straight moves.
   */
  #if DISABLED(ABL_UBL) // AI_DEBUG: PROJDE - ABL_UBL není definováno
    #define SEGMENT_LEVELED_MOVES // AI_DEBUG: AKTIVNÍ - segment leveling moves jsou povoleny
    #define LEVELED_SEGMENT_LENGTH 5.0 // (mm) Length of all segments (except the last one) // AI_DEBUG: AKTIVNÍ - segment leveling délka je nastavena
  #endif // AI_DEBUG: PROJDE - ABL_UBL není definováno

  /**
   * Enable the G26 Mesh Validation Pattern tool.
   */
#if NONE(MachineCR10Orig, SKRMiniE3V2) // AI_DEBUG: PROJDE - MachineCR10Orig ani SKRMiniE3V2 nejsou definovány
  #define G26_MESH_VALIDATION   // Enable G26 mesh validation // AI_DEBUG: AKTIVNÍ - G26 mesh validation je povolen
#endif // AI_DEBUG: PROJDE - MachineCR10Orig ani SKRMiniE3V2 nejsou definovány
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

#if ENABLED(MeshFast)
  #define GRID_MAX_POINTS_X 3
#elif ENABLED(MeshStd) // AI_DEBUG: PROJDE - MeshStd je definováno
  #if ANY(MachineCR6, MachineEnder3Touchscreen)
     #define GRID_MAX_POINTS_X 4
  #elif ENABLED(MachineCR6Max)
    #define GRID_MAX_POINTS_X 7
  #elif ENABLED(ABL_UBL)
    #define GRID_MAX_POINTS_X 6
  #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z předchozích podmínek není splněna
    #define GRID_MAX_POINTS_X 5 // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
  #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - žádná z předchozích podmínek není splněna
#elif ENABLED( MeshFine)
  #define GRID_MAX_POINTS_X 8
#elif ENABLED(MeshExtreme)
  #define GRID_MAX_POINTS_X 15
#else
  #define GRID_MAX_POINTS_X 3
#endif
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

#if EITHER(AUTO_BED_LEVELING_LINEAR, AUTO_BED_LEVELING_BILINEAR) // AI_DEBUG: PROJDE - AUTO_BED_LEVELING_BILINEAR je definováno

  #if ENABLED(MachineCR6)
    #define PROBE_Y_FIRST
  #endif
  #if ENABLED(AUTO_BED_LEVELING_BILINEAR) // AI_DEBUG: PROJDE - AUTO_BED_LEVELING_BILINEAR je definováno

    #define EXTRAPOLATE_BEYOND_GRID // AI_DEBUG: AKTIVNÍ - extrapolace za grid je povolena

    #if ENABLED(ABL_BILINEAR_SUBDIVISION)
      #define BILINEAR_SUBDIVISIONS 3
    #endif

  #endif // AI_DEBUG: PROJDE - AUTO_BED_LEVELING_BILINEAR je definováno

#elif ENABLED(AUTO_BED_LEVELING_UBL)

  #define MESH_INSET 1
  #if NONE(MachineCR10SPro, MachineCRX, MachineEnder5Plus, MachineCR10Max, MachineEnder4, OrigLCD) || ANY(GraphicLCD, OrigLCD)
    #define MESH_EDIT_GFX_OVERLAY   // Display a graphics overlay while editing the mesh
  #endif

  #define UBL_HILBERT_CURVE       // Use Hilbert distribution for less travel when probing multiple points

  #define UBL_MESH_EDIT_MOVES_Z     // Sophisticated users prefer no movement of nozzle
  #define UBL_SAVE_ACTIVE_ON_M500   // Save the currently active mesh in the current slot on M500

  #define UBL_Z_RAISE_WHEN_OFF_MESH 0 // When the nozzle is off the mesh, this value is used

#elif ENABLED(MESH_BED_LEVELING)

#if(ENABLED(MachineEnder3))
  #define MESH_INSET 40          // Set Mesh bounds as an inset region of the bed
#elif ENABLED(MachineCR10SV2)
  #define MESH_INSET 30
#else
  #define MESH_INSET 20          // Set Mesh bounds as an inset region of the bed
#endif

#endif // BED_LEVELING

/**
 * Add a bed leveling sub-menu for ABL or MBL.
 * Include a guided procedure if manual probing is enabled.
 */
#if NONE(ABL_EZABL, ABL_NCSW, ABL_BLTOUCH, ABL_TOUCH_MI, SKRMiniE3V2, MachineEnder3V2, FORCE10SPRODISPLAY, MachineCR6, MachineCR6Max, MachineSermoonD1, MachineEnder7, MachineCR30, MachineCR10Smart, MachineCR10SmartPro, FORCEV2DISPLAY) && (NONE(MachineCRX, MachineEnder3Touchscreen) || ANY(GraphicLCD, OrigLCD)) // AI_DEBUG: PROJDE - ABL_BLTOUCH je definováno, MachineCRX ani MachineEnder3Touchscreen nejsou definovány, GraphicLCD ani OrigLCD nejsou definovány
  #define LCD_BED_LEVELING // AI_DEBUG: AKTIVNÍ - LCD bed leveling je povolen
#endif // AI_DEBUG: PROJDE - ABL_BLTOUCH je definováno, MachineCRX ani MachineEnder3Touchscreen nejsou definovány, GraphicLCD ani OrigLCD nejsou definovány

#if ENABLED(LCD_BED_LEVELING) // AI_DEBUG: PROJDE - LCD_BED_LEVELING je definováno
  #define MESH_EDIT_Z_STEP  0.025 // (mm) Step size while manually probing Z axis. // AI_DEBUG: AKTIVNÍ - mesh edit Z step je nastaven
  #define LCD_PROBE_Z_RANGE 8     // (mm) Z Range centered on Z_MIN_POS for LCD Z adjustment // AI_DEBUG: AKTIVNÍ - LCD probe Z range je nastaven
  #if NONE(MachineCR10Orig, SKRMiniE3V2) // AI_DEBUG: PROJDE - MachineCR10Orig ani SKRMiniE3V2 nejsou definovány
    #define MESH_EDIT_MENU        // Add a menu to edit mesh points // AI_DEBUG: AKTIVNÍ - mesh edit menu je povolen
  #endif // AI_DEBUG: PROJDE - MachineCR10Orig ani SKRMiniE3V2 nejsou definovány
#endif // AI_DEBUG: PROJDE - LCD_BED_LEVELING je definováno

#if NONE(SolidBedMounts, SKRMiniE3V2, MachineCR10Orig, MachineCR30) // AI_DEBUG: PROJDE - SolidBedMounts ani SKRMiniE3V2 ani MachineCR10Orig ani MachineCR30 nejsou definovány
  #define LCD_BED_TRAMMING // AI_DEBUG: AKTIVNÍ - LCD bed tramming je povolen
#endif // AI_DEBUG: PROJDE - SolidBedMounts ani SKRMiniE3V2 ani MachineCR10Orig ani MachineCR30 nejsou definovány
#if ENABLED(LCD_BED_TRAMMING)
  #define BED_TRAMMING_INSET_LFRB { 22, 22, 22, 22 } // (mm) Left, Front, Right, Back insets
  #define BED_TRAMMING_HEIGHT      0.0        // (mm) Z height of nozzle at leveling points
  #define BED_TRAMMING_Z_HOP       4.0        // (mm) Z height of nozzle between leveling points
  #if ENABLED(BED_TRAMMING_USE_PROBE)
    #define BED_TRAMMING_PROBE_TOLERANCE 0.1  // (mm)
    #define BED_TRAMMING_VERIFY_RAISED        // After adjustment triggers the probe, re-probe to verify
  #endif

  /**
   * Corner Leveling Order
   *
   * Set 2 or 4 points. When 2 points are given, the 3rd is the center of the opposite edge.
   *
   *  LF  Left-Front    RF  Right-Front
   *  LB  Left-Back     RB  Right-Back
   *
   * Examples:
   *
   *      Default        {LF,RB,LB,RF}         {LF,RF}           {LB,LF}
   *  LB --------- RB   LB --------- RB    LB --------- RB   LB --------- RB
   *  |  4       3  |   | 3         2 |    |     <3>     |   | 1           |
   *  |             |   |             |    |             |   |          <3>|
   *  |  1       2  |   | 1         4 |    | 1         2 |   | 2           |
   *  LF --------- RF   LF --------- RF    LF --------- RF   LF --------- RF
   */
  #define BED_TRAMMING_LEVELING_ORDER { LF, RF, RB, LB }
#endif

/**
 * Commands to execute at the end of G29 probing.
 * Useful to retract or move the Z probe out of the way.
 */

#define MANUAL_X_HOME_POS 150 // AI_DEBUG: AKTIVNÍ - Manuální X home pozice na 150mm
#define MANUAL_Y_HOME_POS 150 // AI_DEBUG: AKTIVNÍ - Manuální Y home pozice na 150mm

/**
 * Use "Z Safe Homing" to avoid homing with a Z probe outside the bed area.
 *
 * - Moves the Z probe (or nozzle) to a defined XY point before Z homing.
 * - Allows Z homing only when XY positions are known and trusted.
 * - If stepper drivers sleep, XY homing may be required again before Z homing.
 */

#define Z_SAFE_HOMING // AI_DEBUG: AKTIVNÍ - Bezpečné Z homing aktivováno

#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT (X_BED_SIZE / 2)  // X point for Z homing
  #define Z_SAFE_HOMING_Y_POINT (Y_BED_SIZE / 2)  // Y point for Z homing
#endif

#define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (10*60) }

#define VALIDATE_HOMING_ENDSTOPS

/**
 * Bed Skew Compensation
 *
 * This feature corrects for misalignment in the XYZ axes.
 *
 * Take the following steps to get the bed skew in the XY plane:
 *  1. Print a test square (e.g., https://www.thingiverse.com/thing:2563185)
 *  2. For XY_DIAG_AC measure the diagonal A to C
 *  3. For XY_DIAG_BD measure the diagonal B to D
 *  4. For XY_SIDE_AD measure the edge A to D
 *
 * Marlin automatically computes skew factors from these measurements.
 * Skew factors may also be computed and set manually:
 *
 *  - Compute AB     : SQRT(2*AC*AC+2*BD*BD-4*AD*AD)/2
 *  - XY_SKEW_FACTOR : TAN(PI/2-ACOS((AC*AC-AB*AB-AD*AD)/(2*AB*AD)))
 *
 * If desired, follow the same procedure for XZ and YZ.
 * Use these diagrams for reference:
 *
 *    Y                     Z                     Z
 *    ^     B-------C       ^     B-------C       ^     B-------C
 *    |    /       /        |    /       /        |    /       /
 *    |   /       /         |   /       /         |   /       /
 *    |  A-------D          |  A-------D          |  A-------D
 *    +-------------->X     +-------------->X     +-------------->Y
 *     XY_SKEW_FACTOR        XZ_SKEW_FACTOR        YZ_SKEW_FACTOR
 */

#if ENABLED(SKEW_CORRECTION)
  #define XY_DIAG_AC 282.8427124746
  #define XY_DIAG_BD 282.8427124746
  #define XY_SIDE_AD 200

  #if ENABLED(SKEW_CORRECTION_FOR_Z)
    #define XZ_DIAG_AC 282.8427124746
    #define XZ_DIAG_BD 282.8427124746
    #define YZ_DIAG_AC 282.8427124746
    #define YZ_DIAG_BD 282.8427124746
    #define YZ_SIDE_AD 200

  #endif

#endif

/**
 * EEPROM
 *
 * Persistent storage to preserve configurable settings across reboots.
 *
 *   M500 - Store settings to EEPROM.
 *   M501 - Read settings from EEPROM. (i.e., Throw away unsaved changes)
 *   M502 - Revert settings to "factory" defaults. (Follow with M500 to init the EEPROM.)
 */
#define EEPROM_SETTINGS     // Persistent storage with M500 and M501
#define LowMemoryBoard    // AI_DEBUG: AKTIVNÍ - Konfigurace pro low memory board, šetří PROGMEM
#if DISABLED(LowMemoryBoard)
  #define EEPROM_CHITCHAT       // Give feedback on EEPROM commands. Disable to save PROGMEM.
#endif
#define EEPROM_BOOT_SILENT    // Keep M503 quiet and only give errors during first load
#if ENABLED(EEPROM_SETTINGS)
  #define EEPROM_AUTO_INIT  // Init EEPROM automatically on any errors.
#endif

#if NONE(MachineCR10Orig, MelziHostOnly) // AI_DEBUG: PROJDE - MachineCR10Orig ani MelziHostOnly nejsou definovány
  #define HOST_KEEPALIVE_FEATURE        // Disable this if your host doesn't like keepalive messages // AI_DEBUG: AKTIVNÍ - host keepalive feature je povolen
  #define DEFAULT_KEEPALIVE_INTERVAL 2  // Number of seconds between "busy" messages. Set with M113. // AI_DEBUG: AKTIVNÍ - keepalive interval je nastaven na 2 sekundy
  #define BUSY_WHILE_HEATING            // Some hosts require "busy" messages even during heating // AI_DEBUG: AKTIVNÍ - busy while heating je povolen
#endif // AI_DEBUG: PROJDE - MachineCR10Orig ani MelziHostOnly nejsou definovány

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

/**
 * Nozzle Park
 *
 * Park the nozzle at the given XYZ position on idle or G27.
 *
 * The "P" parameter controls the action applied to the Z axis:
 *
 *    P0  (Default) If Z is below park Z raise the nozzle.
 *    P1  Raise the nozzle always to Z-park height.
 *    P2  Raise the nozzle by Z-park amount, limited to Z_MAX_POS.
 */
#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE) // AI_DEBUG: PROJDE - NOZZLE_PARK_FEATURE je definováno
  #if(ANY(MachineEnder2, MachineEnder2Pro))
    #define NOZZLE_PARK_POINT { (0), (0), 10 }
  #else // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineEnder2 ani MachineEnder2Pro nejsou definovány
    #define NOZZLE_PARK_POINT { (50), (10), 10 } // AI_DEBUG: AKTIVNÍ - fallback na výchozí hodnotu
  #endif // AI_DEBUG: TENTO BLOK SE VYKONÁ - MachineEnder2 ani MachineEnder2Pro nejsou definovány

  #define NOZZLE_PARK_MOVE          0   // Park motion: 0 = XY Move, 1 = X Only, 2 = Y Only, 3 = X before Y, 4 = Y before X
  #define NOZZLE_PARK_Z_RAISE_MIN   2   // (mm) Always raise Z by at least this distance
#define NOZZLE_PARK_XY_FEEDRATE 50   // X and Y axes feedrate in mm/s (also used for delta printers Z axis)
#define NOZZLE_PARK_Z_FEEDRATE 5      // Z axis feedrate in mm/s (not used for delta printers)
#endif

/**
 * Clean Nozzle Feature
 *
 * Adds the G12 command to perform a nozzle cleaning process.
 *
 * Parameters:
 *   P  Pattern
 *   S  Strokes / Repetitions
 *   T  Triangles (P1 only)
 *
 * Patterns:
 *   P0  Straight line (default). This process requires a sponge type material
 *       at a fixed bed location. "S" specifies strokes (i.e. back-forth motions)
 *       between the start / end points.
 *
 *   P1  Zig-zag pattern between (X0, Y0) and (X1, Y1), "T" specifies the
 *       number of zig-zag triangles to do. "S" defines the number of strokes.
 *       Zig-zags are done in whichever is the narrower dimension.
 *       For example, "G12 P1 S1 T3" will execute:
 *
 *          --
 *         |  (X0, Y1) |     /\        /\        /\     | (X1, Y1)
 *         |           |    /  \      /  \      /  \    |
 *       A |           |   /    \    /    \    /    \   |
 *         |           |  /      \  /      \  /      \  |
 *         |  (X0, Y0) | /        \/        \/        \ | (X1, Y0)
 *          --         +--------------------------------+
 *                       |________|_________|_________|
 *                           T1        T2        T3
 *
 *   P2  Circular pattern with middle at NOZZLE_CLEAN_CIRCLE_MIDDLE.
 *       "R" specifies the radius. "S" specifies the stroke count.
 *       Before starting, the nozzle moves to NOZZLE_CLEAN_START_POINT.
 *
 *   Caveats: The ending Z should be the same as starting Z.
 */
#if ANY(MachineCRX, PurgeBucket)
  #define NOZZLE_CLEAN_FEATURE
#endif
#if ENABLED(NOZZLE_CLEAN_FEATURE)
  #define NOZZLE_CLEAN_STROKES  5

  #define NOZZLE_CLEAN_TRIANGLES  3

  #define NOZZLE_CLEAN_START_POINT { X_MAX_POS, 40, (Z_MIN_POS + 1)}
  #define NOZZLE_CLEAN_END_POINT   { (X_MAX_POS - 10), 40, (Z_MIN_POS + 1) }

  #define NOZZLE_CLEAN_CIRCLE_RADIUS 6.5
  #define NOZZLE_CLEAN_CIRCLE_FN 10
  #define NOZZLE_CLEAN_CIRCLE_MIDDLE NOZZLE_CLEAN_START_POINT

  #define NOZZLE_CLEAN_GOBACK

  #define NOZZLE_CLEAN_NO_Z

  #define NOZZLE_CLEAN_MIN_TEMP 170

#endif

/**
 * Print Job Timer
 *
 * Automatically start and stop the print job timer on M104/M109/M140/M190/M141/M191.
 * The print job timer will only be stopped if the bed/chamber target temp is
 * below BED_MINTEMP/CHAMBER_MINTEMP.
 *
 *   M104 (hotend, no wait)  - high temp = none,        low temp = stop timer
 *   M109 (hotend, wait)     - high temp = start timer, low temp = stop timer
 *   M140 (bed, no wait)     - high temp = none,        low temp = stop timer
 *   M190 (bed, wait)        - high temp = start timer, low temp = none
 *   M141 (chamber, no wait) - high temp = none,        low temp = stop timer
 *   M191 (chamber, wait)    - high temp = start timer, low temp = none
 *
 * For M104/M109, high temp is anything over EXTRUDE_MINTEMP / 2.
 * For M140/M190, high temp is anything over BED_MINTEMP.
 * For M141/M191, high temp is anything over CHAMBER_MINTEMP.
 *
 * The timer can also be controlled with the following commands:
 *
 *   M75 - Start the print job timer
 *   M76 - Pause the print job timer
 *   M77 - Stop the print job timer
 */
#if NONE(MachineCR10Orig, LowMemoryBoard) || ENABLED(MelziHostOnly) // AI_DEBUG: PROJDE - MachineCR10Orig není definováno, LowMemoryBoard je definováno, MelziHostOnly není definováno
 #define PRINTJOB_TIMER_AUTOSTART // AI_DEBUG: AKTIVNÍ - print job timer autostart je povolen
#endif // AI_DEBUG: PROJDE - MachineCR10Orig není definováno, LowMemoryBoard je definováno, MelziHostOnly není definováno
/**
 * Print Counter
 *
 * Track statistical data such as:
 *
 *  - Total print jobs
 *  - Total successful print jobs
 *  - Total failed print jobs
 *  - Total time printing
 *
 * View the current statistics with M78.
 */
#if NONE(MachineCR10Orig, LowMemoryBoard, SKRMiniE3V2) // AI_DEBUG: PROJDE - MachineCR10Orig není definováno, LowMemoryBoard je definováno, SKRMiniE3V2 není definováno
  #define PRINTCOUNTER // AI_DEBUG: AKTIVNÍ - print counter je povolen
  #if ENABLED(PRINTCOUNTER) // AI_DEBUG: PROJDE - PRINTCOUNTER je definováno
    #define PRINTCOUNTER_SAVE_INTERVAL 60 // (minutes) EEPROM save interval during print // AI_DEBUG: AKTIVNÍ - print counter save interval je nastaven na 60 minut
  #endif // AI_DEBUG: PROJDE - PRINTCOUNTER je definováno
#endif // AI_DEBUG: PROJDE - MachineCR10Orig není definováno, LowMemoryBoard je definováno, SKRMiniE3V2 není definováno

/**
 * Password
 *
 * Set a numerical password for the printer which can be requested:
 *
 *  - When the printer boots up
 *  - Upon opening the 'Print from Media' Menu
 *  - When SD printing is completed or aborted
 *
 * The following G-codes can be used:
 *
 *  M510 - Lock Printer. Blocks all commands except M511.
 *  M511 - Unlock Printer.
 *  M512 - Set, Change and Remove Password.
 *
 * If you forget the password and get locked out you'll need to re-flash
 * the firmware with the feature disabled, reset EEPROM, and (optionally)
 * re-flash the firmware again with this feature enabled.
 */
#if ENABLED(PASSWORD_FEATURE)
  #define PASSWORD_LENGTH 4                 // (#) Number of digits (1-9). 3 or 4 is recommended
  #define PASSWORD_ON_STARTUP
  #define PASSWORD_UNLOCK_GCODE             // Unlock with the M511 P<password> command. Disable to prevent brute-force attack.
  #define PASSWORD_CHANGE_GCODE             // Change the password with M512 P<old> S<new>.
#endif

/**
 * Password
 *
 * Set a numerical password for the printer which can be requested:
 *
 *  - When the printer boots up
 *  - Upon opening the 'Print from Media' Menu
 *  - When SD printing is completed or aborted
 *
 * The following G-codes can be used:
 *
 *  M510 - Lock Printer. Blocks all commands except M511.
 *  M511 - Unlock Printer.
 *  M512 - Set, Change and Remove Password.
 *
 * If you forget the password and get locked out you'll need to re-flash
 * the firmware with the feature disabled, reset EEPROM, and (optionally)
 * re-flash the firmware again with this feature enabled.
 */
#if ENABLED(PASSWORD_FEATURE)
  #define PASSWORD_LENGTH 4                 // (#) Number of digits (1-9). 3 or 4 is recommended
  #define PASSWORD_ON_STARTUP
  #define PASSWORD_UNLOCK_GCODE             // Unlock with the M511 P<password> command. Disable to prevent brute-force attack.
  #define PASSWORD_CHANGE_GCODE             // Change the password with M512 P<old> N<new>.
#endif

/**
 * LCD LANGUAGE
 *
 * Select the language to display on the LCD. These languages are available:
 *
 *   en, an, bg, ca, cz, da, de, el, el_CY, es, eu, fi, fr, gl, hr, hu, it,
 *   jp_kana, ko_KR, nl, pl, pt, pt_br, ro, ru, sk, sv, tr, uk, vi, zh_CN, zh_TW
 *
 * :{ 'en':'English', 'an':'Aragonese', 'bg':'Bulgarian', 'ca':'Catalan', 'cz':'Czech', 'da':'Danish', 'de':'German', 'el':'Greek (Greece)', 'el_CY':'Greek (Cyprus)', 'es':'Spanish', 'eu':'Basque-Euskera', 'fi':'Finnish', 'fr':'French', 'gl':'Galician', 'hr':'Croatian', 'hu':'Hungarian', 'it':'Italian', 'jp_kana':'Japanese', 'ko_KR':'Korean (South Korea)', 'nl':'Dutch', 'pl':'Polish', 'pt':'Portuguese', 'pt_br':'Portuguese (Brazilian)', 'ro':'Romanian', 'ru':'Russian', 'sk':'Slovak', 'sv':'Swedish', 'tr':'Turkish', 'uk':'Ukrainian', 'vi':'Vietnamese', 'zh_CN':'Chinese (Simplified)', 'zh_TW':'Chinese (Traditional)' }
 */
#define LCD_LANGUAGE en

/**
 * LCD Character Set
 *
 * Note: This option is NOT applicable to Graphical Displays.
 *
 * All character-based LCDs provide ASCII plus one of these
 * language extensions:
 *
 *  - JAPANESE ... the most common
 *  - WESTERN  ... with more accented characters
 *  - CYRILLIC ... for the Russian language
 *
 * To determine the language extension installed on your controller:
 *
 *  - Compile and upload with LCD_LANGUAGE set to 'test'
 *  - Click the controller to view the LCD menu
 *  - The LCD will display Japanese, Western, or Cyrillic text
 *
 * See https://marlinfw.org/docs/development/lcd_language.html
 *
 * :['JAPANESE', 'WESTERN', 'CYRILLIC']
 */
#define DISPLAY_CHARSET_HD44780 JAPANESE

/**
 * Info Screen Style (0:Classic, 1:Průša)
 *
 * :[0:'Classic', 1:'Průša']
 */
#define LCD_INFO_SCREEN_STYLE 0

/**
 * SD CARD
 *
 * SD Card support is disabled by default. If your controller has an SD slot,
 * you must uncomment the following option or it won't work.
 */
#if DISABLED(MelziHostOnly) // AI_DEBUG: PROJDE - MelziHostOnly není definováno, takže DISABLED(MelziHostOnly) je true
  #define SDSUPPORT // AI_DEBUG: AKTIVNÍ - SD support je povolen
#endif // AI_DEBUG: PROJDE - MelziHostOnly není definováno, takže DISABLED(MelziHostOnly) je true

/**
 * SD CARD: ENABLE CRC
 *
 * Use CRC checks and retries on the SD communication.
 */

/**
 * LCD Menu Items
 *
 * Disable all menus and only display the Status Screen, or
 * just remove some extraneous menu items to recover space.
 */
#if ANY(MachineCR10Orig, SKRMiniE3V2) && DISABLED(MelziHostOnly) && ENABLED(ABL_BI)
  #define SLIM_LCD_MENUS
#endif

#if ANY(MachineCR20, MachineEnder3V2)
  #define ENCODER_PULSES_PER_STEP 4
#endif
#define ENCODER_STEPS_PER_MENU_ITEM 1

/**
 * Encoder Direction Options
 *
 * Test your encoder's behavior first with both options disabled.
 *
 *  Reversed Value Edit and Menu Nav? Enable REVERSE_ENCODER_DIRECTION.
 *  Reversed Menu Navigation only?    Enable REVERSE_MENU_DIRECTION.
 *  Reversed Value Editing only?      Enable BOTH options.
 */

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
#elif NONE(MachineCR10SPro, MachineCRX, MachineEnder5Plus, MachineCR10Max, OrigLCD, MachineCR10Orig, SKRMiniE3V2, SKRMiniE3V3, FORCE10SPRODISPLAY, MachineCR6, MachineCR6Max, MachineCR10Smart, MachineCR10SmartPro, MachineEnder3Touchscreen) || ENABLED(GraphicLCD) // AI_DEBUG: PROJDE - MachineCR10SPro není definováno, MachineCRX není definováno, MachineEnder5Plus není definováno, MachineCR10Max není definováno, OrigLCD není definováno, MachineCR10Orig není definováno, SKRMiniE3V2 není definováno, SKRMiniE3V3 není definováno, FORCE10SPRODISPLAY není definováno, MachineCR6 není definováno, MachineCR6Max není definováno, MachineCR10Smart není definováno, MachineCR10SmartPro není definováno, MachineEnder3Touchscreen není definováno, GraphicLCD není definováno
  #define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER // AI_DEBUG: AKTIVNÍ - REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER je povolen
#endif // AI_DEBUG: PROJDE - MachineCR10SPro není definováno, MachineCRX není definováno, MachineEnder5Plus není definováno, MachineCR10Max není definováno, OrigLCD není definováno, MachineCR10Orig není definováno, SKRMiniE3V2 není definováno, SKRMiniE3V3 není definováno, FORCE10SPRODISPLAY není definováno, MachineCR6 není definováno, MachineCR6Max není definováno, MachineCR10Smart není definováno, MachineCR10SmartPro není definováno, MachineEnder3Touchscreen není definováno, GraphicLCD není definováno

#if ENABLED(SAV_3DGLCD)
  #define U8GLIB_SSD1306
#endif

/**
 * DGUS Touch Display with DWIN OS. (Choose one.)
 *
 * ORIGIN (Marlin DWIN_SET)
 *  - Download https://github.com/coldtobi/Marlin_DGUS_Resources
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *  - Product: https://www.aliexpress.com/item/32993409517.html
 *
 * FYSETC (Supplier default)
 *  - Download https://github.com/FYSETC/FYSTLCD-2.0
 *  - Copy the downloaded SCREEN folder to the SD card.
 *  - Product: https://www.aliexpress.com/item/32961471929.html
 *
 * HIPRECY (Supplier default)
 *  - Download https://github.com/HiPrecy/Touch-Lcd-LEO
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *
 * MKS (MKS-H43) (Supplier default)
 *  - Download https://github.com/makerbase-mks/MKS-H43
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *  - Product: https://www.aliexpress.com/item/1005002008179262.html
 *
 * RELOADED (T5UID1)
 *  - Download https://github.com/Desuuuu/DGUS-reloaded/releases
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *
 * IA_CREALITY (T5UID1)
 *  - Download https://github.com/InsanityAutomation/Marlin/raw/CrealityDwin2.0_Bleeding/TM3D_Combined480272_Landscape_V7.7z
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *
 * Flash display with DGUS Displays for Marlin:
 *  - Format the SD card to FAT32 with an allocation size of 4kb.
 *  - Download files as specified for your type of display.
 *  - Plug the microSD card into the back of the display.
 *  - Boot the display and wait for the update to complete.
 */
#if DGUS_UI_IS(MKS)
  #define USE_MKS_GREEN_UI
#endif


#if ANY(MachineCR6, MachineCR6Max, MachineEnder3Touchscreen)
  #define DGUS_LCD_UI_CREALITY_TOUCH
#endif

#if EITHER(ANYCUBIC_LCD_I3MEGA, ANYCUBIC_LCD_CHIRON)
#endif

#if ANY(MachineCR10SPro, MachineCRX, MachineEnder5Plus, MachineCR10Max, MachineEnder6, MachineCR5, MachineEnder7, MachineSermoonD1, MachineCR10Smart, MachineCR10SmartPro) && (NONE(GraphicLCD, OrigLCD)) || ENABLED(FORCE10SPRODISPLAY) // AI_DEBUG: PROJDE - MachineCR10SPro není definováno, MachineCRX není definováno, MachineEnder5Plus není definováno, MachineCR10Max není definováno, MachineEnder6 není definováno, MachineCR5 není definováno, MachineEnder7 není definováno, MachineSermoonD1 není definováno, MachineCR10Smart není definováno, MachineCR10SmartPro není definováno, GraphicLCD není definováno, OrigLCD není definováno, FORCE10SPRODISPLAY není definováno
  #ifndef FORCE10SPRODISPLAY // AI_DEBUG: PROJDE - FORCE10SPRODISPLAY není definováno
    #define FORCE10SPRODISPLAY
  #endif
  #define EXTENSIBLE_UI
#endif

#if ENABLED(EXTENSIBLE_UI) // AI_DEBUG: PROJDE - EXTENSIBLE_UI je definováno
#endif // AI_DEBUG: PROJDE - EXTENSIBLE_UI je definováno

/**
 * Specific TFT Model Presets. Enable one of the following options
 * or enable TFT_GENERIC and set sub-options.
 */

#if ENABLED(TFT_GENERIC)
  #define TFT_DRIVER AUTO

#endif

/**
 * TFT UI - User Interface Selection. Enable one of the following options:
 *
 *   TFT_CLASSIC_UI - Emulated DOGM - 128x64 Upscaled
 *   TFT_COLOR_UI   - Marlin Default Menus, Touch Friendly, using full TFT capabilities
 *   TFT_LVGL_UI    - A Modern UI using LVGL
 *
 *   For LVGL_UI also copy the 'assets' folder from the build directory to the
 *   root of your SD card, together with the compiled firmware.
 */

#if ENABLED(TFT_COLOR_UI)
  /**
   * TFT Font for Color_UI. Choose one of the following:
   *
   * NOTOSANS  - Default font with antialiasing. Supports Latin Extended and non-Latin characters.
   * UNIFONT   - Lightweight font, no antialiasing. Supports Latin Extended and non-Latin characters.
   * HELVETICA - Lightweight font, no antialiasing. Supports Basic Latin (0x0020-0x007F) and Latin-1 Supplement (0x0080-0x00FF) characters only.
   */
  #define TFT_FONT  NOTOSANS

#endif

#if ENABLED(TFT_LVGL_UI)
#endif

/**
 * TFT Rotation. Set to one of the following values:
 *
 *   TFT_ROTATE_90,  TFT_ROTATE_90_MIRROR_X,  TFT_ROTATE_90_MIRROR_Y,
 *   TFT_ROTATE_180, TFT_ROTATE_180_MIRROR_X, TFT_ROTATE_180_MIRROR_Y,
 *   TFT_ROTATE_270, TFT_ROTATE_270_MIRROR_X, TFT_ROTATE_270_MIRROR_Y,
 *   TFT_MIRROR_X, TFT_MIRROR_Y, TFT_NO_ROTATION
 */

#if ENABLED(TOUCH_SCREEN)
  #define BUTTON_DELAY_EDIT      50 // (ms) Button repeat delay for edit screens
  #define BUTTON_DELAY_MENU     250 // (ms) Button repeat delay for menus

  #define TOUCH_SCREEN_CALIBRATION

  #if BOTH(TOUCH_SCREEN_CALIBRATION, EEPROM_SETTINGS)
    #define TOUCH_CALIBRATION_AUTO_SAVE // Auto save successful calibration values to EEPROM
  #endif

  #if ENABLED(TFT_COLOR_UI)
  #endif
#endif

  #define FAN_SOFT_PWM
#define SOFT_PWM_SCALE 0

/**
 * RGB LED / LED Strip Control
 *
 * Enable support for an RGB LED connected to 5V digital pins, or
 * an RGB Strip connected to MOSFETs controlled by digital pins.
 *
 * Adds the M150 command to set the LED (or LED strip) color.
 * If pins are PWM capable (e.g., 4, 5, 6, 11) then a range of
 * luminance values can be set from 0 to 255.
 * For NeoPixel LED an overall brightness parameter is also available.
 *
 *  === CAUTION ===
 *  LED Strips require a MOSFET Chip between PWM lines and LEDs,
 *  as the Arduino cannot handle the current the LEDs will require.
 *  Failure to follow this precaution can destroy your Arduino!
 *
 *  NOTE: A separate 5V power supply is required! The NeoPixel LED needs
 *  more current than the Arduino 5V linear regulator can produce.
 *
 *  Requires PWM frequency between 50 <> 100Hz (Check HAL or variant)
 *  Use FAST_PWM_FAN, if possible, to reduce fan noise.
 */

#if EITHER(RGB_LED, RGBW_LED)
#endif

#if ANY(RGB_LED, RGBW_LED, PCA9632)
  #if ENABLED(RGB_STARTUP_TEST)
    #define RGB_STARTUP_TEST_INNER_MS 10  // (ms) Reduce or increase fading speed
  #endif
#endif

#if ENABLED(NEOPIXEL_LED)
  #define NEOPIXEL_TYPE   NEO_RGB // NEO_GRBW / NEO_GRB - four/three channel driver type (defined in Adafruit_NeoPixel.h)
  #define NEOPIXEL_PIXELS 30       // Number of LEDs in the strip. (Longest strip when NEOPIXEL2_SEPARATE is disabled.)
  #define NEOPIXEL_IS_SEQUENTIAL   // Sequential display for temperature change - LED by LED. Disable to change all LEDs at once.
  #define NEOPIXEL_BRIGHTNESS 127  // Initial brightness (0-255)
  #define NEOPIXEL_STARTUP_TEST  // Cycle through colors at startup

  #if ENABLED(NEOPIXEL2_SEPARATE)
    #define NEOPIXEL2_PIXELS           15 // Number of LEDs in the strip
    #define NEOPIXEL2_BRIGHTNESS      127 // Initial brightness (0-255)
    #define NEOPIXEL2_STARTUP_TEST        // Cycle through colors at startup
    #define NEOPIXEL_M150_DEFAULT      -1 // Default strip for M150 without 'S'. Use -1 to set all by default.
  #else
  #endif

#endif

/**
 * Printer Event LEDs
 *
 * During printing, the LEDs will reflect the printer status:
 *
 *  - Gradually change from blue to violet as the heated bed gets to target temp
 *  - Gradually change from violet to red as the hotend gets to temperature
 *  - Change to white to illuminate work surface
 *  - Change to green once print has finished
 *  - Turn off after the print has finished and the user has pushed a button
 */
#if ANY(BLINKM, RGB_LED, RGBW_LED, PCA9632, PCA9533, NEOPIXEL_LED)
  #define PRINTER_EVENT_LEDS
#endif

/**
 * Number of servos
 *
 * For some servo-related options NUM_SERVOS will be set automatically.
 * Set this manually if there are extra servos needing manual control.
 * Set to 0 to turn off servo support.
 */

#define SERVO_DELAY { 300 }




