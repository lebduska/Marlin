; Flow Rate Calibration Test
; Testuje správnost E-steps a flow rate
; Vytiskne se jedna vrstva s různými rychlostmi

M104 S200 ; Nastavit teplotu trysky na 200°C
M140 S60  ; Nastavit teplotu podložky na 60°C
M190 S60  ; Čekat na teplotu podložky
M109 S200 ; Čekat na teplotu trysky

G28      ; Home all axes
G29      ; Auto bed leveling
M420 S1  ; Zapnout bed leveling

; Nastavit rychlost pro první vrstvu
M220 S100 ; Feed rate 100%
M221 S100 ; Flow rate 100%

; První vrstva - test flow rate
G0 Z0.2   ; Zvednout na 0.2mm
G0 X10 Y10 F3000 ; Přejít na start

; Test pattern - čtverce s různými rychlostmi
; Čtverec 1 - rychlost 20mm/s
G0 X10 Y10 F1200
G1 X40 Y10 F1200
G1 X40 Y40 F1200
G1 X10 Y40 F1200
G1 X10 Y10 F1200

; Čtverec 2 - rychlost 30mm/s
G0 X50 Y10 F1800
G1 X80 Y10 F1800
G1 X80 Y40 F1800
G1 X50 Y40 F1800
G1 X50 Y10 F1800

; Čtverec 3 - rychlost 40mm/s
G0 X90 Y10 F2400
G1 X120 Y10 F2400
G1 X120 Y40 F2400
G1 X90 Y40 F2400
G1 X90 Y10 F2400

; Test retrakce
G0 X10 Y60 F3000
G1 X120 Y60 F1200

; Dokončit
G0 Z10 F3000
M104 S0   ; Vypnout trysku
M140 S0   ; Vypnout podložku
M84       ; Vypnout motory

; Instrukce:
; 1. Vytiskne se jedna vrstva 0.2mm
; 2. Čtverce by měly mít stejnou tloušťku
; 3. Linie by měly být konzistentní
; 4. Pokud jsou linie tenké - zvýšit flow rate
; 5. Pokud jsou linie tlusté - snížit flow rate
