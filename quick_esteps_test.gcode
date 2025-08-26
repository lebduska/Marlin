; Quick E-steps Test
; Rychlý test E-steps - vytlačí 100mm filamentu
; Měří se skutečná délka vs. požadovaná délka

M104 S200 ; Nastavit teplotu trysky na 200°C
M109 S200 ; Čekat na teplotu trysky

; Nastavit parametry
M220 S100 ; Feed rate 100%
M221 S100 ; Flow rate 100%

; Test E-steps - vytlačit 100mm
G92 E0     ; Reset extruder position
G1 E100 F100 ; Vytlačit 100mm při 100mm/s

; Dokončit
M104 S0   ; Vypnout trysku
M84       ; Vypnout motory

; ===== INSTRUKCE =====
; 1. Označit filament 120mm od trysky
; 2. Spustit tento G-code
; 3. Změřit, kolik mm se skutečně vytlačilo
; 4. Výpočet nových E-steps:
;    Nové E-steps = (Aktuální E-steps × 100) ÷ Skutečná délka
;    
;    Příklad:
;    - Aktuální E-steps: 500
;    - Skutečná délka: 95mm
;    - Nové E-steps: (500 × 100) ÷ 95 = 526.3
;    
;    Zaokrouhlit na 526 a upravit v firmware
