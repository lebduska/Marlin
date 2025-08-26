# KOMPLETNÍ ZADÁNÍ PRO GPT-5: Vyčištění Marlin Configuration.h

## SOUBORY V BALÍČKU
1. **`GPT5_task_configuration_cleanup.md`** - Detailní zadání úkolu s pravidly
2. **`GPT5_input_configuration.h`** - Původní soubor Configuration.h (3141 řádků)

## RYCHLÝ ÚVOD
Potřebuji vyčistit konfigurační soubor Marlin firmware pro 3D tiskárnu **Creality CR-10S Pro V2**. 

### CÍLE:
- Odstranit všechny neaktivní `#if`/`#elif`/`#else`/`#endif` bloky 
- Ponechat pouze definice, které se skutečně vykonávají
- Zredukovat soubor z ~3100 na ~1500-2000 řádků
- Zachovat funkčnost firmware

### KLÍČOVÁ INFORMACE:
**AKTIVNÍ DEFINICE:**
```cpp
#define MachineCR10SProV2     // z build flags
#define HotendAllMetal        // z build flags  
#define BedDC                 // z build flags
#define MachineCR10SPro       // odvozeno z MachineCR10SProV2
#define SKR_2209             // odvozeno z MachineCR10SPro
#define LowMemoryBoard       // odvozeno z MachineCR10SPro
```

**NEAKTIVNÍ:** Všechna ostatní makra (ABL_*, SKR_UART, GraphicLCD, atd.)

### VÝSTUP:
Vrať kompletní vyčištěný soubor jako blok kódu:
```cpp
// vyčištěný Configuration.h obsah zde
```

### PŘÍKLAD TRANSFORMACE:
**PŘED:**
```cpp
#if ENABLED(MachineCR10SProV2)
  #define MachineCR10SPro
#endif
```

**PO:**
```cpp
#define MachineCR10SPro
```

Detaily najdeš v `GPT5_task_configuration_cleanup.md`. Vstupní soubor je `GPT5_input_configuration.h`.



