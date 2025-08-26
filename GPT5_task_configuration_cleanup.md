# GPT-5 Task: Marlin Configuration.h Cleanup

## ÚKOL
Vyčisti soubor `Marlin/Configuration.h` tak, aby obsahoval pouze aktivní konfigurační větve pro tiskárnu **Creality CR-10S Pro V2**. Odstraň všechny neaktivní `#if`/`#elif`/`#else`/`#endif` bloky a ponechej pouze ty definice, které se skutečně vykonávají.

## VSTUPNÍ KONTEXT

### AKTIVNÍ DEFINICE (definovány z externích zdrojů):
```cpp
// Z platformio.ini - prostředí 10SProV2_BIL:
#define MachineCR10SProV2
#define HotendAllMetal  
#define BedDC
#define __MARLIN_FIRMWARE__
#define NDEBUG

// Odvozené definice (z Configuration.h):
#define MachineCR10SPro        // definováno díky MachineCR10SProV2
#define SKR_2209              // definováno v MachineCR10SPro bloku
#define LowMemoryBoard        // definováno v MachineCR10SPro bloku
```

### NEAKTIVNÍ DEFINICE (nejsou definovány):
```cpp
// Tyto makra NEJSOU definována:
SKR_UART, ABL_EZABL, ABL_NCSW, ABL_BLTOUCH, ABL_TOUCH_MI, ABL_UBL, ABL_BI
GraphicLCD, OrigLCD, FORCE10SPRODISPLAY, FORCEV2DISPLAY
MachineEnder3Touchscreen, DualZ, HotendMosquito, HotendE3D
CrealityViewerKit, MachineEnder3V2, MachineEnder3S1
```

## PRAVIDLA PRO ČIŠTĚNÍ

### 1. VYHODNOŤ PODMÍNKY
Pro každý `#if`, `#elif`, `#else` blok:
- Pokud je podmínka **TRUE** → ponechej obsah bloku, odstraň podmínky
- Pokud je podmínka **FALSE** → odstraň celý blok včetně obsahu
- Použij C preprocesor logiku: `ENABLED(X)` = `defined(X)`, `DISABLED(X)` = `!defined(X)`

### 2. PŘÍKLADY TRANSFORMACÍ

**PŘED:**
```cpp
#if ENABLED(MachineCR10SProV2)
  #define MachineCR10SPro
#endif

#if ENABLED(MachineCR10SPro)
  #define MOTHERBOARD BOARD_RAMPS_CREALITY
  #define SKR_2209
  #define LowMemoryBoard
#endif
```

**PO:**
```cpp
#define MachineCR10SPro
#define MOTHERBOARD BOARD_RAMPS_CREALITY
#define SKR_2209
#define LowMemoryBoard
```

**PŘED:**
```cpp
#if ENABLED(SKR_UART)
  #define X_DRIVER_TYPE TMC2208
#elif ENABLED(SKR_2209)
  #define X_DRIVER_TYPE TMC2209_STANDALONE
#else
  #define X_DRIVER_TYPE A4988
#endif
```

**PO:**
```cpp
#define X_DRIVER_TYPE TMC2209_STANDALONE
```

### 3. ZACHOVEJ STRUKTURU
- Ponechej všechny komentáře (kromě AI_DEBUG)
- Zachovej původní odsazení
- Nezměň pořadí definic
- Odstraň pouze `AI_DEBUG` komentáře

### 4. VÝSTUP
Vrať kompletní vyčištěný soubor `Configuration.h` jako:
```
```cpp
// vyčištěný obsah souboru
```
```

## DŮLEŽITÉ UPOZORNĚNÍ
- Pracuj POUZE s podmíněnými bloky (`#if`/`#elif`/`#else`/`#endif`)
- NEMĚŇ běžné `#define` direktivy mimo podmíněné bloky
- ZACHOVEJ všechny `#include` direktivy
- Výsledný soubor musí být syntakticky správný C/C++ kód

## TESTOVACÍ KRITÉRIUM
Výsledný soubor by měl být podstatně kratší (odhaduji ~1500-2000 řádků místo původních 3141 řádků) a obsahovat pouze aktivní konfiguraci pro CR-10S Pro V2 s proximity sensorem.
