; PLA Polokoule 3cm průměr, 20% výplň
; Vytvořeno pro Marlin firmware
; Průměr: 30mm, Výška: 15mm

G21 ; Nastavit jednotky na mm
G90 ; Absolutní pozicování
M82 ; Absolutní extruder

; Nastavení teplot
M104 S200 ; Nastavit teplotu hotendu na 200°C
M140 S60  ; Nastavit teplotu podložky na 60°C

; Počkat na dosažení teplot
M190 S60  ; Počkat na podložku
M109 S200 ; Počkat na hotend

; Homing a bed leveling
G28 ; Homing všech os
G29 ; Bed leveling (pokud je k dispozici)

; Nastavení pro tisk
M220 S100 ; Feedrate 100%
M221 S100 ; Flow rate 100%

; První vrstva - pomaleji
G0 Z5 F1000 ; Zvednout Z
G0 X150 Y150 F3000 ; Střed podložky
G0 Z0.2 F300 ; První vrstva

; Tisk polokoule - první vrstva (kruh)
G1 X150 Y135 F1500 ; Začátek kruhu
G2 X150 Y135 I0 J-15 F1500 ; Kruh o průměru 30mm

; Pokračování vrstvy
G1 X150 Y150 F1500 ; Střed
G1 X135 Y150 F1500 ; Vlevo
G1 X165 Y150 F1500 ; Vpravo
G1 X150 Y150 F1500 ; Střed

; Druhá vrstva
G0 Z0.4 F300
G1 X150 Y150 F1500 ; Střed
G1 X140 Y150 F1500 ; Vlevo
G1 X160 Y150 F1500 ; Vpravo
G1 X150 Y150 F1500 ; Střed

; Třetí vrstva
G0 Z0.6 F300
G1 X150 Y150 F1500 ; Střed
G1 X145 Y150 F1500 ; Vlevo
G1 X155 Y150 F1500 ; Vpravo
G1 X150 Y150 F1500 ; Střed

; Čtvrtá vrstva
G0 Z0.8 F300
G1 X150 Y150 F1500 ; Střed
G1 X147 Y150 F1500 ; Vlevo
G1 X153 Y150 F1500 ; Vpravo
G1 X150 Y150 F1500 ; Střed

; Pátá vrstva
G0 Z1.0 F300
G1 X150 Y150 F1500 ; Střed
G1 X148 Y150 F1500 ; Vlevo
G1 X152 Y150 F1500 ; Vpravo
G1 X150 Y150 F1500 ; Střed

; Šestá vrstva
G0 Z1.2 F300
G1 X150 Y150 F1500 ; Střed
G1 X149 Y150 F1500 ; Vlevo
G1 X151 Y150 F1500 ; Vpravo
G1 X150 Y150 F1500 ; Střed

; Sedmá vrstva
G0 Z1.4 F300
G1 X150 Y150 F1500 ; Střed
G1 X149.5 Y150 F1500 ; Vlevo
G1 X150.5 Y150 F1500 ; Vpravo
G1 X150 Y150 F1500 ; Střed

; Osmá vrstva
G0 Z1.6 F300
G1 X150 Y150 F1500 ; Střed

; Devátá vrstva
G0 Z1.8 F300
G1 X150 Y150 F1500 ; Střed

; Desátá vrstva
G0 Z2.0 F300
G1 X150 Y150 F1500 ; Střed

; Jedenáctá vrstva
G0 Z2.2 F300
G1 X150 Y150 F1500 ; Střed

; Dvanáctá vrstva
G0 Z2.4 F300
G1 X150 Y150 F1500 ; Střed

; Třináctá vrstva
G0 Z2.6 F300
G1 X150 Y150 F1500 ; Střed

; Čtrnáctá vrstva
G0 Z2.8 F300
G1 X150 Y150 F1500 ; Střed

; Patnáctá vrstva (poslední)
G0 Z3.0 F300
G1 X150 Y150 F1500 ; Střed

; Dokončení tisku
G0 Z10 F1000 ; Zvednout Z
G0 X150 Y150 F3000 ; Střed podložky

; Vypnout teploty
M104 S0 ; Vypnout hotend
M140 S0 ; Vypnout podložku

; Konec
M84 ; Vypnout motory
