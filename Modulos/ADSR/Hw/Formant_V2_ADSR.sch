EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Baphomet_Libreria
LIBS:arduino
LIBS:switches
LIBS:Formant_V2_ADSR-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ARDUINO_NANO ARDUINO?
U 1 1 5A05EEF9
P 2175 4325
F 0 "ARDUINO?" H 2125 5225 70  0001 C CNN
F 1 "ARDUINO NANO" H 2250 5250 70  0000 C CNN
F 2 "" H 2175 4325 60  0000 C CNN
F 3 "" H 2175 4325 60  0000 C CNN
	1    2175 4325
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A05EF88
P 1425 3325
F 0 "#PWR?" H 1425 3075 50  0001 C CNN
F 1 "GND" H 1300 3225 50  0001 C CNN
F 2 "" H 1425 3325 50  0000 C CNN
F 3 "" H 1425 3325 50  0000 C CNN
	1    1425 3325
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 5A05EFA1
P 3175 3750
F 0 "#PWR?" H 3175 3500 50  0001 C CNN
F 1 "GND" H 3175 3600 50  0001 C CNN
F 2 "" H 3175 3750 50  0000 C CNN
F 3 "" H 3175 3750 50  0000 C CNN
	1    3175 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2775 3675 3175 3675
Wire Wire Line
	3175 3675 3175 3750
$Comp
L +5V #PWR?
U 1 1 5A05EFB6
P 3075 3525
F 0 "#PWR?" H 3075 3375 50  0001 C CNN
F 1 "+5V" H 3075 3665 50  0000 C CNN
F 2 "" H 3075 3525 50  0000 C CNN
F 3 "" H 3075 3525 50  0000 C CNN
	1    3075 3525
	1    0    0    -1  
$EndComp
Wire Wire Line
	3075 3525 3075 3875
Wire Wire Line
	3075 3875 2775 3875
Wire Wire Line
	1325 3975 1575 3975
Wire Wire Line
	2875 4675 2775 4675
Wire Wire Line
	1225 4075 1575 4075
Wire Wire Line
	2975 4575 2775 4575
Wire Wire Line
	1425 3875 1575 3875
Wire Wire Line
	1325 3125 1325 3975
Wire Wire Line
	1225 3050 1225 4075
Wire Wire Line
	1425 3875 1425 3325
Wire Wire Line
	1125 2950 1125 4175
Wire Wire Line
	1125 4175 1575 4175
Text GLabel 800  4975 0    60   Input ~ 0
GATE
$Comp
L R R?
U 1 1 5A06A034
P 850 6200
F 0 "R?" H 725 6250 50  0000 C CNN
F 1 "100K" H 700 6150 50  0000 C CNN
F 2 "" V 780 6200 50  0000 C CNN
F 3 "" H 850 6200 50  0000 C CNN
	1    850  6200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A06A16A
P 850 6500
F 0 "#PWR?" H 850 6250 50  0001 C CNN
F 1 "GND" H 850 6350 50  0001 C CNN
F 2 "" H 850 6500 50  0000 C CNN
F 3 "" H 850 6500 50  0000 C CNN
	1    850  6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  6350 850  6500
$Comp
L SW_DPDT_x2 SW?
U 1 1 5A0622BB
P 1800 5525
F 0 "SW?" H 1800 5695 50  0001 C CNN
F 1 "ADSR_AD_1" H 2450 5650 50  0000 C CNN
F 2 "" H 1800 5525 50  0000 C CNN
F 3 "" H 1800 5525 50  0000 C CNN
	1    1800 5525
	1    0    0    -1  
$EndComp
$Comp
L SW_DPDT_x2 SW?
U 1 1 5A06270A
P 1800 5900
F 0 "SW?" H 1800 6070 50  0001 C CNN
F 1 "ADSR_AD_2" H 2450 6025 50  0000 C CNN
F 2 "" H 1800 5900 50  0000 C CNN
F 3 "" H 1800 5900 50  0000 C CNN
	1    1800 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1575 4875 1525 4875
Wire Wire Line
	1525 4875 1525 5525
Wire Wire Line
	1175 5525 1600 5525
Wire Wire Line
	1575 4775 1475 4775
Wire Wire Line
	1475 4775 1475 6050
Wire Wire Line
	1475 5900 1600 5900
$Comp
L GND #PWR?
U 1 1 5A06315E
P 2175 6050
F 0 "#PWR?" H 2175 5800 50  0001 C CNN
F 1 "GND" H 2175 5900 50  0001 C CNN
F 2 "" H 2175 6050 50  0000 C CNN
F 3 "" H 2175 6050 50  0000 C CNN
	1    2175 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 5625 2175 5625
Wire Wire Line
	2175 5625 2175 6050
Wire Wire Line
	2000 6000 2175 6000
Connection ~ 2175 6000
$Comp
L +5V #PWR?
U 1 1 5A0633D5
P 2125 5375
F 0 "#PWR?" H 2125 5225 50  0001 C CNN
F 1 "+5V" H 2125 5515 50  0000 C CNN
F 2 "" H 2125 5375 50  0000 C CNN
F 3 "" H 2125 5375 50  0000 C CNN
	1    2125 5375
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 5800 2125 5800
Wire Wire Line
	2125 5800 2125 5375
Wire Wire Line
	2000 5425 2125 5425
Connection ~ 2125 5425
$Comp
L POT 1MLog?
U 1 1 5A0A13AA
P 4100 1875
F 0 "1MLog?" V 4000 1875 50  0000 C CNN
F 1 "POT" V 4100 1875 50  0000 C CNN
F 2 "" H 4100 1875 50  0000 C CNN
F 3 "" H 4100 1875 50  0000 C CNN
	1    4100 1875
	1    0    0    -1  
$EndComp
$Comp
L POT 1MLog?
U 1 1 5A0A13B0
P 4650 1875
F 0 "1MLog?" V 4550 1875 50  0000 C CNN
F 1 "POT" V 4650 1875 50  0000 C CNN
F 2 "" H 4650 1875 50  0000 C CNN
F 3 "" H 4650 1875 50  0000 C CNN
	1    4650 1875
	1    0    0    -1  
$EndComp
$Comp
L POT 1MLog?
U 1 1 5A0A13B6
P 5225 1875
F 0 "1MLog?" V 5125 1875 50  0000 C CNN
F 1 "POT" V 5225 1875 50  0000 C CNN
F 2 "" H 5225 1875 50  0000 C CNN
F 3 "" H 5225 1875 50  0000 C CNN
	1    5225 1875
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5A0A13BC
P 4100 2250
F 0 "R?" V 4180 2250 50  0000 C CNN
F 1 "1K" V 4100 2250 50  0000 C CNN
F 2 "" V 4030 2250 50  0000 C CNN
F 3 "" H 4100 2250 50  0000 C CNN
	1    4100 2250
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5A0A13C2
P 4650 2250
F 0 "R?" V 4730 2250 50  0000 C CNN
F 1 "220" V 4650 2250 50  0000 C CNN
F 2 "" V 4580 2250 50  0000 C CNN
F 3 "" H 4650 2250 50  0000 C CNN
	1    4650 2250
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5A0A13C8
P 5225 2250
F 0 "R?" V 5305 2250 50  0000 C CNN
F 1 "1K" V 5225 2250 50  0000 C CNN
F 2 "" V 5155 2250 50  0000 C CNN
F 3 "" H 5225 2250 50  0000 C CNN
	1    5225 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 1500 4100 1725
Wire Wire Line
	4100 1600 4250 1600
Wire Wire Line
	4650 1600 4800 1600
Wire Wire Line
	4800 1600 4800 1875
Wire Wire Line
	5225 1500 5225 1725
Wire Wire Line
	5225 1600 5375 1600
Wire Wire Line
	4100 2025 4100 2100
Wire Wire Line
	4650 2025 4650 2100
Wire Wire Line
	5225 2025 5225 2100
$Comp
L D D?
U 1 1 5A0A13D7
P 4100 2650
F 0 "D?" H 4100 2750 50  0000 C CNN
F 1 "1N4148" H 4100 2550 50  0000 C CNN
F 2 "" H 4100 2650 50  0000 C CNN
F 3 "" H 4100 2650 50  0000 C CNN
	1    4100 2650
	0    1    1    0   
$EndComp
$Comp
L D 1N?
U 1 1 5A0A13DD
P 4650 2650
F 0 "1N?" H 4650 2750 50  0000 C CNN
F 1 "D" H 4650 2550 50  0000 C CNN
F 2 "" H 4650 2650 50  0000 C CNN
F 3 "" H 4650 2650 50  0000 C CNN
	1    4650 2650
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5A0A13E3
P 5225 2650
F 0 "D?" H 5225 2750 50  0000 C CNN
F 1 "1N4148" H 5225 2550 50  0000 C CNN
F 2 "" H 5225 2650 50  0000 C CNN
F 3 "" H 5225 2650 50  0000 C CNN
	1    5225 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	4100 2400 4100 2500
Wire Wire Line
	4650 2400 4650 2500
Wire Wire Line
	5225 2400 5225 2500
$Comp
L CP C?
U 1 1 5A0A13EC
P 5000 3050
F 0 "C?" H 5025 3150 50  0000 L CNN
F 1 "10uF/16V" H 5025 2950 50  0000 L CNN
F 2 "" H 5038 2900 50  0000 C CNN
F 3 "" H 5000 3050 50  0000 C CNN
	1    5000 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2800 4100 2850
Wire Wire Line
	4100 2850 5900 2850
Wire Wire Line
	4650 2800 4650 2900
Connection ~ 4650 2850
Connection ~ 5000 2850
$Comp
L D D?
U 1 1 5A0A13F7
P 4650 3050
F 0 "D?" H 4650 3150 50  0000 C CNN
F 1 "1N4148" H 4650 2950 50  0000 C CNN
F 2 "" H 4650 3050 50  0000 C CNN
F 3 "" H 4650 3050 50  0000 C CNN
	1    4650 3050
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5A0A13FD
P 5000 3350
F 0 "#PWR?" H 5000 3100 50  0001 C CNN
F 1 "GND" H 5000 3200 50  0001 C CNN
F 2 "" H 5000 3350 50  0000 C CNN
F 3 "" H 5000 3350 50  0000 C CNN
	1    5000 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3200 5000 3350
Wire Wire Line
	4650 3200 4650 3250
Wire Wire Line
	4650 3250 5000 3250
Connection ~ 5000 3250
$Comp
L POT 10K?
U 1 1 5A0A1407
P 5600 1875
F 0 "10K?" V 5500 1825 50  0000 C CNN
F 1 "POT" V 5600 1875 50  0000 C CNN
F 2 "" H 5600 1875 50  0000 C CNN
F 3 "" H 5600 1875 50  0000 C CNN
	1    5600 1875
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5A0A140D
P 5600 775
F 0 "#PWR?" H 5600 625 50  0001 C CNN
F 1 "+5V" H 5600 915 50  0000 C CNN
F 2 "" H 5600 775 50  0000 C CNN
F 3 "" H 5600 775 50  0000 C CNN
	1    5600 775 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 1450 5600 1725
$Comp
L GND #PWR?
U 1 1 5A0A1414
P 5600 2175
F 0 "#PWR?" H 5600 1925 50  0001 C CNN
F 1 "GND" H 5600 2025 50  0001 C CNN
F 2 "" H 5600 2175 50  0000 C CNN
F 3 "" H 5600 2175 50  0000 C CNN
	1    5600 2175
	1    0    0    -1  
$EndComp
$Comp
L +15V #PWR?
U 1 1 5A0A141A
P 6100 3150
F 0 "#PWR?" H 6100 3000 50  0001 C CNN
F 1 "+15V" H 5925 3200 50  0000 C CNN
F 2 "" H 6100 3150 50  0000 C CNN
F 3 "" H 6100 3150 50  0000 C CNN
	1    6100 3150
	-1   0    0    1   
$EndComp
Wire Wire Line
	6100 2250 6100 2450
$Comp
L -15V #PWR?
U 1 1 5A0A1421
P 6100 2250
F 0 "#PWR?" H 6100 2350 50  0001 C CNN
F 1 "-15V" H 6100 2400 50  0000 C CNN
F 2 "" H 6100 2250 50  0000 C CNN
F 3 "" H 6100 2250 50  0000 C CNN
	1    6100 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 2650 5825 2650
Wire Wire Line
	5825 2650 5825 2400
Wire Wire Line
	5825 2400 6625 2400
$Comp
L R R?
U 1 1 5A0A142A
P 8025 2650
F 0 "R?" V 8105 2650 50  0000 C CNN
F 1 "470" V 8025 2650 50  0000 C CNN
F 2 "" V 7955 2650 50  0000 C CNN
F 3 "" H 8025 2650 50  0000 C CNN
	1    8025 2650
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 5A0A1430
P 8025 2400
F 0 "R?" V 8105 2400 50  0000 C CNN
F 1 "470" V 8025 2400 50  0000 C CNN
F 2 "" V 7955 2400 50  0000 C CNN
F 3 "" H 8025 2400 50  0000 C CNN
	1    8025 2400
	0    1    1    0   
$EndComp
Connection ~ 6625 2750
Wire Wire Line
	7875 2200 7875 2650
Connection ~ 7875 2650
Text GLabel 8225 2400 2    60   Output ~ 0
ADSR_2_EOS
Text GLabel 8225 2650 2    60   Output ~ 0
ADSR_2_ENV
Text Notes 3950 1575 0    79   ~ 16
R
Text Notes 4525 1575 0    79   ~ 16
A
Text Notes 5100 1575 0    79   ~ 16
D
Text Notes 5475 1575 0    79   ~ 16
S
Connection ~ 4650 1600
$Comp
L 4066 U?
U 4 1 5A0A1440
P 4100 1200
F 0 "U?" H 4300 1051 50  0001 C CNN
F 1 "4066" V 4175 925 50  0000 C CNN
F 2 "" H 4100 1200 60  0001 C CNN
F 3 "" H 4100 1200 60  0001 C CNN
	4    4100 1200
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 2025 5600 2175
Wire Wire Line
	5375 1600 5375 1875
Connection ~ 5225 1600
Wire Wire Line
	5225 2800 5225 2850
Connection ~ 5225 2850
Wire Wire Line
	5000 2850 5000 2900
$Comp
L GND #PWR?
U 1 1 5A0A1454
P 5225 800
F 0 "#PWR?" H 5225 550 50  0001 C CNN
F 1 "GND" H 5125 675 50  0001 C CNN
F 2 "" H 5225 800 50  0000 C CNN
F 3 "" H 5225 800 50  0000 C CNN
	1    5225 800 
	-1   0    0    1   
$EndComp
Wire Wire Line
	5225 800  5225 900 
Wire Wire Line
	5750 1875 5775 1875
$Comp
L C C?
U 1 1 5A0A145E
P 5925 1875
F 0 "C?" H 5950 1975 50  0000 L CNN
F 1 "100nF" H 5950 1775 50  0000 L CNN
F 2 "" H 5963 1725 50  0000 C CNN
F 3 "" H 5925 1875 50  0000 C CNN
	1    5925 1875
	1    0    0    -1  
$EndComp
Wire Wire Line
	5925 1300 5925 1725
Wire Wire Line
	5925 1650 5600 1650
Connection ~ 5600 1650
$Comp
L GND #PWR?
U 1 1 5A0A1467
P 5925 2175
F 0 "#PWR?" H 5925 1925 50  0001 C CNN
F 1 "GND" H 5925 2025 50  0001 C CNN
F 2 "" H 5925 2175 50  0000 C CNN
F 3 "" H 5925 2175 50  0000 C CNN
	1    5925 2175
	1    0    0    -1  
$EndComp
Wire Wire Line
	5925 2025 5925 2175
Wire Wire Line
	4250 1600 4250 1875
Connection ~ 4100 1600
$Comp
L GND #PWR?
U 1 1 5A0A1471
P 4100 800
F 0 "#PWR?" H 4100 550 50  0001 C CNN
F 1 "GND" H 4000 675 50  0001 C CNN
F 2 "" H 4100 800 50  0000 C CNN
F 3 "" H 4100 800 50  0000 C CNN
	1    4100 800 
	-1   0    0    1   
$EndComp
Wire Wire Line
	4100 800  4100 900 
$Comp
L GND #PWR?
U 1 1 5A0A1478
P 4350 1275
F 0 "#PWR?" H 4350 1025 50  0001 C CNN
F 1 "GND" H 4350 1125 50  0001 C CNN
F 2 "" H 4350 1275 50  0000 C CNN
F 3 "" H 4350 1275 50  0000 C CNN
	1    4350 1275
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 1200 4350 1275
$Comp
L +5V #PWR?
U 1 1 5A0A147F
P 3775 1025
F 0 "#PWR?" H 3775 875 50  0001 C CNN
F 1 "+5V" H 3650 1075 50  0000 C CNN
F 2 "" H 3775 1025 50  0000 C CNN
F 3 "" H 3775 1025 50  0000 C CNN
	1    3775 1025
	1    0    0    -1  
$EndComp
Wire Wire Line
	3775 1200 3850 1200
$Comp
L LM358 U?
U 2 1 5A0A1489
P 6200 2750
F 0 "U?" H 6200 2950 50  0000 L CNN
F 1 "LM358" H 6200 3025 50  0000 L CNN
F 2 "" H 6200 2750 50  0000 C CNN
F 3 "" H 6200 2750 50  0000 C CNN
	2    6200 2750
	1    0    0    1   
$EndComp
$Comp
L POT_TRIM RV?
U 1 1 5A0A148F
P 5600 1300
F 0 "RV?" H 5750 1250 50  0000 C CNN
F 1 "20K" H 5750 1175 50  0000 C CNN
F 2 "" H 5600 1300 50  0000 C CNN
F 3 "" H 5600 1300 50  0000 C CNN
	1    5600 1300
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5A0A1495
P 5600 950
F 0 "R?" H 5750 925 50  0000 C CNN
F 1 "1K" H 5750 1025 50  0000 C CNN
F 2 "" V 5530 950 50  0000 C CNN
F 3 "" H 5600 950 50  0000 C CNN
	1    5600 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 1300 5925 1300
Connection ~ 5925 1650
$Comp
L LM358 U?
U 2 1 5A0A149F
P 7300 2650
F 0 "U?" H 7300 2850 50  0000 L CNN
F 1 "LM358" H 7300 2925 50  0000 L CNN
F 2 "" H 7300 2650 50  0000 C CNN
F 3 "" H 7300 2650 50  0000 C CNN
	2    7300 2650
	1    0    0    1   
$EndComp
Wire Wire Line
	6500 2750 7000 2750
$Comp
L +15V #PWR?
U 1 1 5A0A14A6
P 7200 3200
F 0 "#PWR?" H 7200 3050 50  0001 C CNN
F 1 "+15V" H 7075 3200 50  0000 C CNN
F 2 "" H 7200 3200 50  0000 C CNN
F 3 "" H 7200 3200 50  0000 C CNN
	1    7200 3200
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5A0A14AD
P 7425 2300
F 0 "R?" V 7505 2300 50  0000 C CNN
F 1 "10K" V 7425 2300 50  0000 C CNN
F 2 "" V 7355 2300 50  0000 C CNN
F 3 "" H 7425 2300 50  0000 C CNN
	1    7425 2300
	0    1    1    0   
$EndComp
$Comp
L -15V #PWR?
U 1 1 5A0A14B3
P 7200 2250
F 0 "#PWR?" H 7200 2350 50  0001 C CNN
F 1 "-15V" H 7200 2400 50  0000 C CNN
F 2 "" H 7200 2250 50  0000 C CNN
F 3 "" H 7200 2250 50  0000 C CNN
	1    7200 2250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7200 2250 7200 2350
Wire Wire Line
	7575 2300 7725 2300
$Comp
L R R?
U 1 1 5A0A14BD
P 6925 2975
F 0 "R?" V 7005 2975 50  0000 C CNN
F 1 "27K" V 6925 2975 50  0000 C CNN
F 2 "" V 6855 2975 50  0000 C CNN
F 3 "" H 6925 2975 50  0000 C CNN
	1    6925 2975
	-1   0    0    1   
$EndComp
Wire Wire Line
	7275 2300 6925 2300
Wire Wire Line
	6925 2300 6925 2825
Wire Wire Line
	7000 2550 6925 2550
Connection ~ 6925 2550
$Comp
L GND #PWR?
U 1 1 5A0A14C7
P 6925 3200
F 0 "#PWR?" H 6925 2950 50  0001 C CNN
F 1 "GND" H 6925 3050 50  0001 C CNN
F 2 "" H 6925 3200 50  0000 C CNN
F 3 "" H 6925 3200 50  0000 C CNN
	1    6925 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8175 2400 8225 2400
Wire Wire Line
	8225 2650 8175 2650
Wire Wire Line
	6625 2400 6625 2750
Wire Wire Line
	2875 4675 2875 6700
Wire Wire Line
	6100 3050 6100 3150
Wire Wire Line
	7200 2950 7200 3200
Wire Wire Line
	6925 3125 6925 3200
Wire Wire Line
	3775 1025 3775 1200
$Comp
L LM358 U?
U 2 1 5A0A883F
P 7425 1675
F 0 "U?" H 7625 1825 50  0000 L CNN
F 1 "LM358" H 7625 1750 50  0000 L CNN
F 2 "" H 7425 1675 50  0000 C CNN
F 3 "" H 7425 1675 50  0000 C CNN
	2    7425 1675
	-1   0    0    1   
$EndComp
$Comp
L -15V #PWR?
U 1 1 5A0A88FE
P 7525 1300
F 0 "#PWR?" H 7525 1400 50  0001 C CNN
F 1 "-15V" H 7525 1450 50  0000 C CNN
F 2 "" H 7525 1300 50  0000 C CNN
F 3 "" H 7525 1300 50  0000 C CNN
	1    7525 1300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7525 1300 7525 1375
$Comp
L +15V #PWR?
U 1 1 5A0A8F0A
P 7525 2050
F 0 "#PWR?" H 7525 1900 50  0001 C CNN
F 1 "+15V" H 7400 2050 50  0000 C CNN
F 2 "" H 7525 2050 50  0000 C CNN
F 3 "" H 7525 2050 50  0000 C CNN
	1    7525 2050
	1    0    0    1   
$EndComp
Wire Wire Line
	7525 1975 7525 2050
$Comp
L D 1N4148
U 1 1 5A0A92BA
P 7875 1350
F 0 "1N4148" H 7900 1175 50  0000 C CNN
F 1 "D" H 7875 1250 50  0000 C CNN
F 2 "" H 7875 1350 50  0000 C CNN
F 3 "" H 7875 1350 50  0000 C CNN
	1    7875 1350
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7075 1350 7075 1675
Wire Wire Line
	7075 1675 7125 1675
Wire Wire Line
	7725 1575 8325 1575
$Comp
L GND #PWR?
U 1 1 5A0A94C5
P 7825 1850
F 0 "#PWR?" H 7825 1600 50  0001 C CNN
F 1 "GND" H 7825 1700 50  0001 C CNN
F 2 "" H 7825 1850 50  0000 C CNN
F 3 "" H 7825 1850 50  0000 C CNN
	1    7825 1850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7725 1775 7825 1775
Wire Wire Line
	7825 1775 7825 1850
$Comp
L R R?
U 1 1 5A0A95D4
P 8025 2200
F 0 "R?" V 8105 2200 50  0000 C CNN
F 1 "4K7" V 8025 2200 50  0000 C CNN
F 2 "" V 7955 2200 50  0000 C CNN
F 3 "" H 8025 2200 50  0000 C CNN
	1    8025 2200
	0    1    1    0   
$EndComp
Connection ~ 7875 2400
Wire Wire Line
	8175 2200 8325 2200
Connection ~ 8075 1350
$Comp
L LED D?
U 1 1 5A0A981A
P 7875 1175
F 0 "D?" H 7900 925 50  0000 C CNN
F 1 "LED" H 7875 1000 50  0000 C CNN
F 2 "" H 7875 1175 50  0000 C CNN
F 3 "" H 7875 1175 50  0000 C CNN
	1    7875 1175
	1    0    0    1   
$EndComp
Wire Wire Line
	8075 1175 8025 1175
Wire Wire Line
	8025 1350 8075 1350
Wire Wire Line
	7725 1175 7725 1350
Wire Wire Line
	7725 1350 7075 1350
Connection ~ 7725 1350
Wire Wire Line
	8325 2200 8325 1575
Wire Wire Line
	8075 1175 8075 1575
Connection ~ 8075 1575
Wire Wire Line
	5600 775  5600 800 
Wire Wire Line
	5600 1100 5600 1150
$Comp
L POT 1MLog?
U 1 1 5A0ABBDD
P 4050 4950
F 0 "1MLog?" V 3950 4950 50  0000 C CNN
F 1 "POT" V 4050 4950 50  0000 C CNN
F 2 "" H 4050 4950 50  0000 C CNN
F 3 "" H 4050 4950 50  0000 C CNN
	1    4050 4950
	1    0    0    -1  
$EndComp
$Comp
L POT 1MLog?
U 1 1 5A0ABBE3
P 4600 4950
F 0 "1MLog?" V 4500 4950 50  0000 C CNN
F 1 "POT" V 4600 4950 50  0000 C CNN
F 2 "" H 4600 4950 50  0000 C CNN
F 3 "" H 4600 4950 50  0000 C CNN
	1    4600 4950
	1    0    0    -1  
$EndComp
$Comp
L POT 1MLog?
U 1 1 5A0ABBE9
P 5175 4950
F 0 "1MLog?" V 5075 4950 50  0000 C CNN
F 1 "POT" V 5175 4950 50  0000 C CNN
F 2 "" H 5175 4950 50  0000 C CNN
F 3 "" H 5175 4950 50  0000 C CNN
	1    5175 4950
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5A0ABBEF
P 4050 5325
F 0 "R?" V 4130 5325 50  0000 C CNN
F 1 "1K" V 4050 5325 50  0000 C CNN
F 2 "" V 3980 5325 50  0000 C CNN
F 3 "" H 4050 5325 50  0000 C CNN
	1    4050 5325
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5A0ABBF5
P 4600 5325
F 0 "R?" V 4680 5325 50  0000 C CNN
F 1 "220" V 4600 5325 50  0000 C CNN
F 2 "" V 4530 5325 50  0000 C CNN
F 3 "" H 4600 5325 50  0000 C CNN
	1    4600 5325
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5A0ABBFB
P 5175 5325
F 0 "R?" V 5255 5325 50  0000 C CNN
F 1 "1K" V 5175 5325 50  0000 C CNN
F 2 "" V 5105 5325 50  0000 C CNN
F 3 "" H 5175 5325 50  0000 C CNN
	1    5175 5325
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 4575 4050 4800
Wire Wire Line
	4050 4675 4200 4675
Wire Wire Line
	4600 4675 4750 4675
Wire Wire Line
	4750 4675 4750 4950
Wire Wire Line
	5175 4575 5175 4800
Wire Wire Line
	5175 4675 5325 4675
Wire Wire Line
	4050 5100 4050 5175
Wire Wire Line
	4600 5100 4600 5175
Wire Wire Line
	5175 5100 5175 5175
$Comp
L D D?
U 1 1 5A0ABC0A
P 4050 5725
F 0 "D?" H 4050 5825 50  0000 C CNN
F 1 "1N4148" H 4050 5625 50  0000 C CNN
F 2 "" H 4050 5725 50  0000 C CNN
F 3 "" H 4050 5725 50  0000 C CNN
	1    4050 5725
	0    1    1    0   
$EndComp
$Comp
L D 1N?
U 1 1 5A0ABC10
P 4600 5725
F 0 "1N?" H 4600 5825 50  0000 C CNN
F 1 "D" H 4600 5625 50  0000 C CNN
F 2 "" H 4600 5725 50  0000 C CNN
F 3 "" H 4600 5725 50  0000 C CNN
	1    4600 5725
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5A0ABC16
P 5175 5725
F 0 "D?" H 5175 5825 50  0000 C CNN
F 1 "1N4148" H 5175 5625 50  0000 C CNN
F 2 "" H 5175 5725 50  0000 C CNN
F 3 "" H 5175 5725 50  0000 C CNN
	1    5175 5725
	0    1    1    0   
$EndComp
Wire Wire Line
	4050 5475 4050 5575
Wire Wire Line
	4600 5475 4600 5575
Wire Wire Line
	5175 5475 5175 5575
$Comp
L CP C?
U 1 1 5A0ABC1F
P 4950 6125
F 0 "C?" H 4975 6225 50  0000 L CNN
F 1 "10uF/16V" H 4975 6025 50  0000 L CNN
F 2 "" H 4988 5975 50  0000 C CNN
F 3 "" H 4950 6125 50  0000 C CNN
	1    4950 6125
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 5875 4050 5925
Wire Wire Line
	4050 5925 5850 5925
Wire Wire Line
	4600 5875 4600 5975
Connection ~ 4600 5925
Connection ~ 4950 5925
$Comp
L D D?
U 1 1 5A0ABC2A
P 4600 6125
F 0 "D?" H 4600 6225 50  0000 C CNN
F 1 "1N4148" H 4600 6025 50  0000 C CNN
F 2 "" H 4600 6125 50  0000 C CNN
F 3 "" H 4600 6125 50  0000 C CNN
	1    4600 6125
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5A0ABC30
P 4950 6425
F 0 "#PWR?" H 4950 6175 50  0001 C CNN
F 1 "GND" H 4950 6275 50  0001 C CNN
F 2 "" H 4950 6425 50  0000 C CNN
F 3 "" H 4950 6425 50  0000 C CNN
	1    4950 6425
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 6275 4950 6425
Wire Wire Line
	4600 6275 4600 6325
Wire Wire Line
	4600 6325 4950 6325
Connection ~ 4950 6325
$Comp
L POT 10K?
U 1 1 5A0ABC3A
P 5550 4950
F 0 "10K?" V 5450 4900 50  0000 C CNN
F 1 "POT" V 5550 4950 50  0000 C CNN
F 2 "" H 5550 4950 50  0000 C CNN
F 3 "" H 5550 4950 50  0000 C CNN
	1    5550 4950
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5A0ABC40
P 5550 3850
F 0 "#PWR?" H 5550 3700 50  0001 C CNN
F 1 "+5V" H 5550 3990 50  0000 C CNN
F 2 "" H 5550 3850 50  0000 C CNN
F 3 "" H 5550 3850 50  0000 C CNN
	1    5550 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 4525 5550 4800
$Comp
L GND #PWR?
U 1 1 5A0ABC47
P 5550 5250
F 0 "#PWR?" H 5550 5000 50  0001 C CNN
F 1 "GND" H 5550 5100 50  0001 C CNN
F 2 "" H 5550 5250 50  0000 C CNN
F 3 "" H 5550 5250 50  0000 C CNN
	1    5550 5250
	1    0    0    -1  
$EndComp
$Comp
L +15V #PWR?
U 1 1 5A0ABC4D
P 6050 6225
F 0 "#PWR?" H 6050 6075 50  0001 C CNN
F 1 "+15V" H 5875 6275 50  0000 C CNN
F 2 "" H 6050 6225 50  0000 C CNN
F 3 "" H 6050 6225 50  0000 C CNN
	1    6050 6225
	-1   0    0    1   
$EndComp
Wire Wire Line
	6050 5325 6050 5525
$Comp
L -15V #PWR?
U 1 1 5A0ABC54
P 6050 5325
F 0 "#PWR?" H 6050 5425 50  0001 C CNN
F 1 "-15V" H 6050 5475 50  0000 C CNN
F 2 "" H 6050 5325 50  0000 C CNN
F 3 "" H 6050 5325 50  0000 C CNN
	1    6050 5325
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 5725 5775 5725
Wire Wire Line
	5775 5725 5775 5475
Wire Wire Line
	5775 5475 6575 5475
$Comp
L R R?
U 1 1 5A0ABC5D
P 7975 5725
F 0 "R?" V 8055 5725 50  0000 C CNN
F 1 "470" V 7975 5725 50  0000 C CNN
F 2 "" V 7905 5725 50  0000 C CNN
F 3 "" H 7975 5725 50  0000 C CNN
	1    7975 5725
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 5A0ABC63
P 7975 5475
F 0 "R?" V 8055 5475 50  0000 C CNN
F 1 "470" V 7975 5475 50  0000 C CNN
F 2 "" V 7905 5475 50  0000 C CNN
F 3 "" H 7975 5475 50  0000 C CNN
	1    7975 5475
	0    1    1    0   
$EndComp
Connection ~ 6575 5825
Wire Wire Line
	7825 5275 7825 5725
Connection ~ 7825 5725
Text GLabel 8175 5475 2    60   Output ~ 0
ADSR_1_EOS
Text GLabel 8175 5725 2    60   Output ~ 0
ADSR_1_ENV
Text Notes 3900 4625 0    79   ~ 16
R
Text Notes 4475 4625 0    79   ~ 16
A
Text Notes 5050 4650 0    79   ~ 16
D
Text Notes 5425 4650 0    79   ~ 16
S
Connection ~ 4600 4675
$Comp
L 4066 U?
U 1 1 5A0ABC73
P 4050 4275
F 0 "U?" H 4250 4126 50  0001 C CNN
F 1 "4066" V 4125 4000 50  0000 C CNN
F 2 "" H 4050 4275 60  0001 C CNN
F 3 "" H 4050 4275 60  0001 C CNN
	1    4050 4275
	0    1    1    0   
$EndComp
Wire Wire Line
	5550 5100 5550 5250
$Comp
L 4066 U?
U 2 1 5A0ABC7A
P 5175 4275
F 0 "U?" H 5375 4126 50  0001 C CNN
F 1 "4066" V 5250 4000 50  0000 C CNN
F 2 "" H 5175 4275 60  0001 C CNN
F 3 "" H 5175 4275 60  0001 C CNN
	2    5175 4275
	0    1    1    0   
$EndComp
Wire Wire Line
	5325 4675 5325 4950
Connection ~ 5175 4675
Wire Wire Line
	5175 5875 5175 5925
Connection ~ 5175 5925
Wire Wire Line
	4950 5925 4950 5975
$Comp
L GND #PWR?
U 1 1 5A0ABC85
P 5175 3875
F 0 "#PWR?" H 5175 3625 50  0001 C CNN
F 1 "GND" H 5075 3750 50  0001 C CNN
F 2 "" H 5175 3875 50  0000 C CNN
F 3 "" H 5175 3875 50  0000 C CNN
	1    5175 3875
	-1   0    0    1   
$EndComp
Wire Wire Line
	5175 3875 5175 3975
Wire Wire Line
	5700 4950 5725 4950
$Comp
L C C?
U 1 1 5A0ABC8D
P 5875 4950
F 0 "C?" H 5900 5050 50  0000 L CNN
F 1 "100nF" H 5900 4850 50  0000 L CNN
F 2 "" H 5913 4800 50  0000 C CNN
F 3 "" H 5875 4950 50  0000 C CNN
	1    5875 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5875 4375 5875 4800
Wire Wire Line
	5875 4725 5550 4725
Connection ~ 5550 4725
$Comp
L GND #PWR?
U 1 1 5A0ABC96
P 5875 5250
F 0 "#PWR?" H 5875 5000 50  0001 C CNN
F 1 "GND" H 5875 5100 50  0001 C CNN
F 2 "" H 5875 5250 50  0000 C CNN
F 3 "" H 5875 5250 50  0000 C CNN
	1    5875 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5875 5100 5875 5250
Wire Wire Line
	4200 4675 4200 4950
Connection ~ 4050 4675
$Comp
L GND #PWR?
U 1 1 5A0ABC9F
P 4050 3875
F 0 "#PWR?" H 4050 3625 50  0001 C CNN
F 1 "GND" H 3950 3750 50  0001 C CNN
F 2 "" H 4050 3875 50  0000 C CNN
F 3 "" H 4050 3875 50  0000 C CNN
	1    4050 3875
	-1   0    0    1   
$EndComp
Wire Wire Line
	4050 3875 4050 3975
$Comp
L GND #PWR?
U 1 1 5A0ABCA6
P 4300 4350
F 0 "#PWR?" H 4300 4100 50  0001 C CNN
F 1 "GND" H 4300 4200 50  0001 C CNN
F 2 "" H 4300 4350 50  0000 C CNN
F 3 "" H 4300 4350 50  0000 C CNN
	1    4300 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 4275 4300 4350
$Comp
L +5V #PWR?
U 1 1 5A0ABCAD
P 3725 4100
F 0 "#PWR?" H 3725 3950 50  0001 C CNN
F 1 "+5V" H 3600 4150 50  0000 C CNN
F 2 "" H 3725 4100 50  0000 C CNN
F 3 "" H 3725 4100 50  0000 C CNN
	1    3725 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3725 4275 3800 4275
$Comp
L LM358 U?
U 1 1 5A0ABCB4
P 6150 5825
F 0 "U?" H 6150 6025 50  0000 L CNN
F 1 "LM358" H 6150 6100 50  0000 L CNN
F 2 "" H 6150 5825 50  0000 C CNN
F 3 "" H 6150 5825 50  0000 C CNN
	1    6150 5825
	1    0    0    1   
$EndComp
$Comp
L POT_TRIM RV?
U 1 1 5A0ABCBA
P 5550 4375
F 0 "RV?" H 5700 4325 50  0000 C CNN
F 1 "20K" H 5700 4250 50  0000 C CNN
F 2 "" H 5550 4375 50  0000 C CNN
F 3 "" H 5550 4375 50  0000 C CNN
	1    5550 4375
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5A0ABCC0
P 5550 4025
F 0 "R?" H 5700 4000 50  0000 C CNN
F 1 "1K" H 5700 4100 50  0000 C CNN
F 2 "" V 5480 4025 50  0000 C CNN
F 3 "" H 5550 4025 50  0000 C CNN
	1    5550 4025
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 4375 5875 4375
Connection ~ 5875 4725
$Comp
L LM358 U?
U 1 1 5A0ABCC8
P 7250 5725
F 0 "U?" H 7250 5925 50  0000 L CNN
F 1 "LM358" H 7250 6000 50  0000 L CNN
F 2 "" H 7250 5725 50  0000 C CNN
F 3 "" H 7250 5725 50  0000 C CNN
	1    7250 5725
	1    0    0    1   
$EndComp
Wire Wire Line
	6450 5825 6950 5825
$Comp
L +15V #PWR?
U 1 1 5A0ABCCF
P 7150 6275
F 0 "#PWR?" H 7150 6125 50  0001 C CNN
F 1 "+15V" H 7025 6275 50  0000 C CNN
F 2 "" H 7150 6275 50  0000 C CNN
F 3 "" H 7150 6275 50  0000 C CNN
	1    7150 6275
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5A0ABCD5
P 7375 5375
F 0 "R?" V 7455 5375 50  0000 C CNN
F 1 "10K" V 7375 5375 50  0000 C CNN
F 2 "" V 7305 5375 50  0000 C CNN
F 3 "" H 7375 5375 50  0000 C CNN
	1    7375 5375
	0    1    1    0   
$EndComp
$Comp
L -15V #PWR?
U 1 1 5A0ABCDB
P 7150 5325
F 0 "#PWR?" H 7150 5425 50  0001 C CNN
F 1 "-15V" H 7150 5475 50  0000 C CNN
F 2 "" H 7150 5325 50  0000 C CNN
F 3 "" H 7150 5325 50  0000 C CNN
	1    7150 5325
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7150 5325 7150 5425
Wire Wire Line
	7525 5375 7675 5375
Wire Wire Line
	7825 5725 7550 5725
$Comp
L R R?
U 1 1 5A0ABCE5
P 6875 6050
F 0 "R?" V 6955 6050 50  0000 C CNN
F 1 "27K" V 6875 6050 50  0000 C CNN
F 2 "" V 6805 6050 50  0000 C CNN
F 3 "" H 6875 6050 50  0000 C CNN
	1    6875 6050
	-1   0    0    1   
$EndComp
Wire Wire Line
	7225 5375 6875 5375
Wire Wire Line
	6875 5375 6875 5900
Wire Wire Line
	6950 5625 6875 5625
Connection ~ 6875 5625
$Comp
L GND #PWR?
U 1 1 5A0ABCEF
P 6875 6275
F 0 "#PWR?" H 6875 6025 50  0001 C CNN
F 1 "GND" H 6875 6125 50  0001 C CNN
F 2 "" H 6875 6275 50  0000 C CNN
F 3 "" H 6875 6275 50  0000 C CNN
	1    6875 6275
	1    0    0    -1  
$EndComp
Wire Wire Line
	8125 5475 8175 5475
Wire Wire Line
	8175 5725 8125 5725
Connection ~ 7675 5725
Wire Wire Line
	6575 5475 6575 6700
Wire Wire Line
	6050 6125 6050 6225
Wire Wire Line
	7150 6025 7150 6275
Wire Wire Line
	6875 6200 6875 6275
Wire Wire Line
	3725 4100 3725 4275
$Comp
L LM358 U?
U 1 1 5A0ABCFD
P 7375 4750
F 0 "U?" H 7575 4900 50  0000 L CNN
F 1 "LM358" H 7575 4825 50  0000 L CNN
F 2 "" H 7375 4750 50  0000 C CNN
F 3 "" H 7375 4750 50  0000 C CNN
	1    7375 4750
	-1   0    0    1   
$EndComp
$Comp
L -15V #PWR?
U 1 1 5A0ABD03
P 7475 4375
F 0 "#PWR?" H 7475 4475 50  0001 C CNN
F 1 "-15V" H 7475 4525 50  0000 C CNN
F 2 "" H 7475 4375 50  0000 C CNN
F 3 "" H 7475 4375 50  0000 C CNN
	1    7475 4375
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7475 4375 7475 4450
$Comp
L +15V #PWR?
U 1 1 5A0ABD0A
P 7475 5125
F 0 "#PWR?" H 7475 4975 50  0001 C CNN
F 1 "+15V" H 7350 5125 50  0000 C CNN
F 2 "" H 7475 5125 50  0000 C CNN
F 3 "" H 7475 5125 50  0000 C CNN
	1    7475 5125
	1    0    0    1   
$EndComp
Wire Wire Line
	7475 5050 7475 5125
$Comp
L D 1N?
U 1 1 5A0ABD11
P 7825 4425
F 0 "1N?" H 7850 4250 50  0000 C CNN
F 1 "D" H 7825 4325 50  0000 C CNN
F 2 "" H 7825 4425 50  0000 C CNN
F 3 "" H 7825 4425 50  0000 C CNN
	1    7825 4425
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7025 4425 7025 4750
Wire Wire Line
	7025 4750 7075 4750
Wire Wire Line
	7675 4650 8275 4650
$Comp
L GND #PWR?
U 1 1 5A0ABD1A
P 7775 4925
F 0 "#PWR?" H 7775 4675 50  0001 C CNN
F 1 "GND" H 7775 4775 50  0001 C CNN
F 2 "" H 7775 4925 50  0000 C CNN
F 3 "" H 7775 4925 50  0000 C CNN
	1    7775 4925
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7675 4850 7775 4850
Wire Wire Line
	7775 4850 7775 4925
$Comp
L R R?
U 1 1 5A0ABD22
P 7975 5275
F 0 "R?" V 8055 5275 50  0000 C CNN
F 1 "4K7" V 7975 5275 50  0000 C CNN
F 2 "" V 7905 5275 50  0000 C CNN
F 3 "" H 7975 5275 50  0000 C CNN
	1    7975 5275
	0    1    1    0   
$EndComp
Connection ~ 7825 5475
Wire Wire Line
	8125 5275 8275 5275
Connection ~ 8025 4425
$Comp
L LED D?
U 1 1 5A0ABD2B
P 7825 4250
F 0 "D?" H 7850 4000 50  0000 C CNN
F 1 "LED" H 7825 4075 50  0000 C CNN
F 2 "" H 7825 4250 50  0000 C CNN
F 3 "" H 7825 4250 50  0000 C CNN
	1    7825 4250
	1    0    0    1   
$EndComp
Wire Wire Line
	8025 4250 7975 4250
Wire Wire Line
	7975 4425 8025 4425
Wire Wire Line
	7675 4250 7675 4425
Wire Wire Line
	7675 4425 7025 4425
Connection ~ 7675 4425
Wire Wire Line
	8275 5275 8275 4650
Wire Wire Line
	8025 4250 8025 4650
Connection ~ 8025 4650
Wire Wire Line
	5550 3850 5550 3875
Wire Wire Line
	5550 4175 5550 4225
Wire Wire Line
	5725 4950 5725 6600
Wire Wire Line
	2975 4575 2975 6600
Wire Wire Line
	4600 3725 4600 4800
Wire Wire Line
	5025 3975 5025 3675
Wire Wire Line
	3900 2950 3900 3975
Wire Wire Line
	2975 6600 5725 6600
Wire Wire Line
	6575 6700 2875 6700
Wire Wire Line
	6725 2750 6725 6875
Wire Wire Line
	6725 6875 3075 6875
Wire Wire Line
	3075 6875 3075 4475
Wire Wire Line
	3075 4475 2775 4475
Wire Wire Line
	5775 1875 5775 3825
Wire Wire Line
	5775 3825 6675 3825
Wire Wire Line
	6675 3825 6675 7000
Wire Wire Line
	6675 7000 3175 7000
Wire Wire Line
	3175 7000 3175 4375
Wire Wire Line
	3175 4375 2775 4375
Wire Wire Line
	1325 3125 4200 3125
Wire Wire Line
	4200 3125 4200 3725
Wire Wire Line
	4200 3725 4600 3725
Wire Wire Line
	1225 3050 4275 3050
Wire Wire Line
	4275 3050 4275 3675
Wire Wire Line
	4275 3675 5025 3675
Wire Wire Line
	1125 2950 3900 2950
Wire Wire Line
	4650 1725 4650 625 
Wire Wire Line
	4650 625  1050 625 
Wire Wire Line
	1050 625  1050 4275
Wire Wire Line
	1050 4275 1575 4275
Wire Wire Line
	975  550  5075 550 
Wire Wire Line
	975  550  975  4375
Wire Wire Line
	975  4375 1575 4375
Wire Wire Line
	3950 900  3950 700 
Wire Wire Line
	3950 700  900  700 
Wire Wire Line
	900  700  900  4475
Wire Wire Line
	900  4475 1575 4475
Text GLabel 1650 2700 2    60   Output ~ 0
TX
Wire Wire Line
	1650 2700 1550 2700
Wire Wire Line
	1550 2700 1550 3575
Wire Wire Line
	1550 3575 1575 3575
Text GLabel 1625 2450 2    60   Input ~ 0
RX
Wire Wire Line
	1625 2450 1500 2450
Wire Wire Line
	1500 2450 1500 3675
Wire Wire Line
	1500 3675 1575 3675
Text Notes 8525 3175 0    157  ~ 31
ADSR 2
Text Notes 8400 5050 0    157  ~ 31
ADSR 1
$Comp
L 4066 U?
U 3 1 5A0A1448
P 5225 1200
F 0 "U?" H 5425 1051 50  0001 C CNN
F 1 "4066" V 5300 925 50  0000 C CNN
F 2 "" H 5225 1200 60  0001 C CNN
F 3 "" H 5225 1200 60  0001 C CNN
	3    5225 1200
	0    1    1    0   
$EndComp
Wire Wire Line
	5075 550  5075 900 
Connection ~ 6725 2750
Wire Wire Line
	7675 5375 7675 5725
Wire Wire Line
	7725 2300 7725 2650
Wire Wire Line
	7875 2650 7600 2650
Connection ~ 7725 2650
$Comp
L R R?
U 1 1 5A48C7E0
P 1475 6200
F 0 "R?" H 1350 6250 50  0000 C CNN
F 1 "100K" H 1325 6150 50  0000 C CNN
F 2 "" V 1405 6200 50  0000 C CNN
F 3 "" H 1475 6200 50  0000 C CNN
	1    1475 6200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A48C7E6
P 1475 6500
F 0 "#PWR?" H 1475 6250 50  0001 C CNN
F 1 "GND" H 1475 6350 50  0001 C CNN
F 2 "" H 1475 6500 50  0000 C CNN
F 3 "" H 1475 6500 50  0000 C CNN
	1    1475 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1475 6350 1475 6500
$Comp
L R R?
U 1 1 5A48C976
P 1175 6200
F 0 "R?" H 1050 6250 50  0000 C CNN
F 1 "100K" H 1025 6150 50  0000 C CNN
F 2 "" V 1105 6200 50  0000 C CNN
F 3 "" H 1175 6200 50  0000 C CNN
	1    1175 6200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A48C97C
P 1175 6500
F 0 "#PWR?" H 1175 6250 50  0001 C CNN
F 1 "GND" H 1175 6350 50  0001 C CNN
F 2 "" H 1175 6500 50  0000 C CNN
F 3 "" H 1175 6500 50  0000 C CNN
	1    1175 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1175 6350 1175 6500
Connection ~ 1475 5900
Wire Wire Line
	1175 5525 1175 6050
Connection ~ 1525 5525
$Comp
L CONN_01X02 P?
U 1 1 5DAD0CD9
P 650 4650
F 0 "P?" H 650 4925 50  0000 C CNN
F 1 "pulsador para pruebas" V 750 4975 50  0000 C CNN
F 2 "" H 650 4650 50  0000 C CNN
F 3 "" H 650 4650 50  0000 C CNN
	1    650  4650
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1575 4975 800  4975
Wire Wire Line
	850  4700 850  6050
Connection ~ 850  4975
$Comp
L +5V #PWR?
U 1 1 5DAD3FDB
P 1000 4600
F 0 "#PWR?" H 1000 4450 50  0001 C CNN
F 1 "+5V" V 975 4800 50  0000 C CNN
F 2 "" H 1000 4600 50  0000 C CNN
F 3 "" H 1000 4600 50  0000 C CNN
	1    1000 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	850  4600 1000 4600
$EndSCHEMATC
