; Kompletní Kalibrační Test
; Testuje: Flow Rate, Bed Leveling, Retrakci
; Vytiskne se několik testovacích vzorů

M104 S200 ; Nastavit teplotu trysky na 200°C
M140 S60  ; Nastavit teplotu podložky na 60°C
M190 S60  ; Čekat na teplotu podložky
M109 S200 ; Čekat na teplotu trysky

G28      ; Home all axes
G29      ; Auto bed leveling
M420 S1  ; Zapnout bed leveling

; Nastavit parametry
M220 S100 ; Feed rate 100%
M221 S100 ; Flow rate 100%

; ===== TEST 1: Flow Rate =====
; První vrstva - test flow rate
G0 Z0.2   ; Zvednout na 0.2mm
G0 X10 Y10 F3000 ; Přejít na start

; Čtverce s různými rychlostmi
G0 X10 Y10 F3000
G1 X40 Y10 F1200
G1 X40 Y40 F1200
G1 X10 Y40 F1200
G1 X10 Y10 F1200

G0 X50 Y10 F3000
G1 X80 Y10 F1200
G1 X80 Y40 F1200
G1 X50 Y40 F1200
G1 X50 Y10 F1200

G0 X90 Y10 F3000
G1 X120 Y10 F1200
G1 X120 Y40 F1200
G1 X90 Y40 F1200
G1 X90 Y10 F1200

; ===== TEST 2: Bed Leveling Grid =====
; Grid pattern pro kontrolu rovnosti
G0 X10 Y60 F3000
G1 X40 Y60 F1200
G1 X40 Y90 F1200
G1 X10 Y90 F1200
G1 X10 Y60 F1200

G0 X50 Y60 F3000
G1 X80 Y60 F1200
G1 X80 Y90 F1200
G1 X50 Y90 F1200
G1 X50 Y60 F1200

G0 X90 Y60 F3000
G1 X120 Y60 F1200
G1 X120 Y90 F1200
G1 X90 Y90 F1200
G1 X90 Y60 F1200

; ===== TEST 3: Retrakce =====
; Test retrakce - linie s mezerami
G0 X10 Y120 F3000
G1 X120 Y120 F1200
G0 X10 Y130 F3000
G1 X120 Y130 F1200
G0 X10 Y140 F3000
G1 X120 Y140 F1200

; ===== TEST 4: Různé rychlosti =====
; Test různých rychlostí pro flow rate
G0 X10 Y160 F3000
G1 X60 Y160 F600   ; 10mm/s
G0 X10 Y170 F3000
G1 X60 Y170 F1200  ; 20mm/s
G0 X10 Y180 F3000
G1 X60 Y180 F1800  ; 30mm/s
G0 X10 Y190 F3000
G1 X60 Y190 F2400  ; 40mm/s

; Dokončit
G0 Z10 F3000
M104 S0   ; Vypnout trysku
M140 S0   ; Vypnout podložku
M84       ; Vypnout motory

; ===== VYHODNOCENÍ =====
; Flow Rate Test:
; - Čtverce by měly mít stejnou tloušťku
; - Pokud jsou tenké - zvýšit E-steps nebo flow rate
; - Pokud jsou tlusté - snížit E-steps nebo flow rate

; Bed Leveling Test:
; - Grid čtverce by měly mít stejnou tloušťku
; - Pokud jsou některé tenší - upravit Z-offset
; - Použít babystepping pro jemné úpravy

; Retrakce Test:
; - Linie by měly být konzistentní
; - Mezi liniemi by neměly být struny

; Rychlost Test:
; - Všechny linie by měly mít stejnou tloušťku
; - Rychlost by neměla ovlivňovat flow rate
