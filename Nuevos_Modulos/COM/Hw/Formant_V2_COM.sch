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
LIBS:Formant_V2_COM-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Módulo COM, Formant V2"
Date ""
Rev ""
Comp "Formant V2"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L DS1801 U?
U 1 1 5995BB66
P 2875 5350
F 0 "U?" H 2375 5350 60  0000 C CNN
F 1 "DS1801" H 2775 3850 60  0000 C CNN
F 2 "" H 2875 5350 60  0001 C CNN
F 3 "" H 2875 5350 60  0001 C CNN
	1    2875 5350
	-1   0    0    -1  
$EndComp
Text GLabel 4275 5850 2    60   Input ~ 0
COM_VOL_DATA
Text GLabel 4275 5750 2    60   Input ~ 0
COM_VOL_CLOCK
Text GLabel 4275 5650 2    60   Input ~ 0
COM_VOL_RESET
Wire Wire Line
	4275 5650 3625 5650
Wire Wire Line
	4275 5750 3625 5750
Wire Wire Line
	4275 5850 3625 5850
$EndSCHEMATC
