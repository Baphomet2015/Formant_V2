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
LIBS:Formant_V2_VCO-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Módulo VCO, Formant V2"
Date ""
Rev "1.0"
Comp "FORMANT V2"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74LS132 U?
U 1 1 59B16AD0
P 9650 1600
F 0 "U?" H 9650 1700 50  0000 C CNN
F 1 "HCT132" H 9650 1500 50  0000 C CNN
F 2 "" H 9650 1600 50  0000 C CNN
F 3 "" H 9650 1600 50  0000 C CNN
	1    9650 1600
	1    0    0    -1  
$EndComp
$Comp
L BC547 Q?
U 1 1 59B16BCF
P 8325 1150
F 0 "Q?" H 8200 1375 50  0000 L CNN
F 1 "BC547" H 8050 1300 50  0000 L CNN
F 2 "TO-92" H 7775 1300 50  0000 L CIN
F 3 "" H 8325 1150 50  0000 L CNN
	1    8325 1150
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 59B16C9D
P 8800 1150
F 0 "R?" V 8600 1075 50  0000 C CNN
F 1 "330" V 8700 1100 50  0000 C CNN
F 2 "" V 8730 1150 50  0000 C CNN
F 3 "" H 8800 1150 50  0000 C CNN
	1    8800 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	8950 1150 10400 1150
Wire Wire Line
	10400 1150 10400 1600
Wire Wire Line
	10400 1600 10250 1600
Wire Wire Line
	8525 1150 8650 1150
$Comp
L C C?
U 1 1 59B16DF2
P 7775 1150
F 0 "C?" H 7800 1250 50  0000 L CNN
F 1 "3n3" H 7800 1050 50  0000 L CNN
F 2 "" H 7813 1000 50  0000 C CNN
F 3 "" H 7775 1150 50  0000 C CNN
	1    7775 1150
	-1   0    0    1   
$EndComp
Wire Wire Line
	7775 1300 7775 1500
Wire Wire Line
	7775 1500 8225 1500
Wire Wire Line
	8225 1500 8225 1350
$Comp
L +5V #PWR?
U 1 1 59B17E53
P 9000 675
F 0 "#PWR?" H 9000 525 50  0001 C CNN
F 1 "+5V" H 9000 815 50  0000 C CNN
F 2 "" H 9000 675 50  0000 C CNN
F 3 "" H 9000 675 50  0000 C CNN
	1    9000 675 
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 59B17F09
P 9000 925
F 0 "R?" H 8875 975 50  0000 C CNN
F 1 "1K" H 8900 875 50  0000 C CNN
F 2 "" V 8930 925 50  0000 C CNN
F 3 "" H 9000 925 50  0000 C CNN
	1    9000 925 
	-1   0    0    1   
$EndComp
Wire Wire Line
	9000 1075 9000 1500
Wire Wire Line
	9000 1500 9050 1500
Wire Wire Line
	9000 675  9000 775 
Wire Wire Line
	9000 675  7775 675 
Wire Wire Line
	7775 675  7775 1000
Wire Wire Line
	8225 950  8225 675 
Connection ~ 8225 675 
Connection ~ 9000 675 
$EndSCHEMATC
