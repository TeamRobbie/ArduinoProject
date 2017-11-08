EESchema Schematic File Version 2
LIBS:components
LIBS:Arduino_Uno_R3_From_Scratch-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:l298
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
LIBS:Arduino_Uno_R3_From_Scratch
LIBS:MFN_Atmel
LIBS:MFN_STMicro
LIBS:Arduino_Uno_R3_From_Scratch-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 6
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
L L298 U?
U 1 1 5A036D45
P 4100 2600
F 0 "U?" H 4300 3450 60  0000 C CNN
F 1 "L298" H 3950 3450 60  0000 C CNN
F 2 "footprints:POWERSO20" H 4100 3700 60  0001 C CNN
F 3 "" H 4300 3450 60  0000 C CNN
F 4 "digikey" H 4100 3800 60  0001 C CNN "Vendor"
F 5 "497-3624-1-ND" H 4100 3900 60  0001 C CNN "PartNumber"
F 6 "IC BRIDGE DRIVER PAR 20POWERSO" H 4100 4000 60  0001 C CNN "Description"
	1    4100 2600
	1    0    0    -1  
$EndComp
$Comp
L Vin #PWR?
U 1 1 5A036DF3
P 4800 1450
F 0 "#PWR?" H 4800 1540 20  0001 C CNN
F 1 "Vin" H 4800 1570 30  0000 C CNN
F 2 "" H 4800 1450 60  0000 C CNN
F 3 "" H 4800 1450 60  0000 C CNN
	1    4800 1450
	1    0    0    -1  
$EndComp
$Comp
L diode_schottky_40V_1A D1
U 1 1 5A036E0C
P 4800 1950
F 0 "D1" H 4750 2030 50  0000 L CNN
F 1 "diode_schottky_40V_1A" H 4520 1870 50  0001 L CNN
F 2 "footprints:DO-214AC(SMA)" H 4650 1930 60  0001 C CNN
F 3 "" H 4750 2030 60  0001 C CNN
F 4 "digikey" H 4850 2130 60  0001 C CNN "Vendor"
F 5 "SS14CT-ND" H 4950 2230 60  0001 C CNN "PartNumber"
F 6 "DIODE SCHOTTKY 40V 1A SMA" H 5050 2330 60  0001 C CNN "Description"
	1    4800 1950
	0    1    1    0   
$EndComp
$Comp
L diode_schottky_40V_1A D2
U 1 1 5A036F46
P 4800 2750
F 0 "D2" H 4750 2830 50  0000 L CNN
F 1 "diode_schottky_40V_1A" H 4520 2670 50  0001 L CNN
F 2 "footprints:DO-214AC(SMA)" H 4650 2730 60  0001 C CNN
F 3 "" H 4750 2830 60  0001 C CNN
F 4 "digikey" H 4850 2930 60  0001 C CNN "Vendor"
F 5 "SS14CT-ND" H 4950 3030 60  0001 C CNN "PartNumber"
F 6 "DIODE SCHOTTKY 40V 1A SMA" H 5050 3130 60  0001 C CNN "Description"
	1    4800 2750
	0    1    1    0   
$EndComp
$Comp
L diode_schottky_40V_1A D3
U 1 1 5A036FCC
P 5000 2050
F 0 "D3" H 4950 2130 50  0000 L CNN
F 1 "diode_schottky_40V_1A" H 4720 1970 50  0001 L CNN
F 2 "footprints:DO-214AC(SMA)" H 4850 2030 60  0001 C CNN
F 3 "" H 4950 2130 60  0001 C CNN
F 4 "digikey" H 5050 2230 60  0001 C CNN "Vendor"
F 5 "SS14CT-ND" H 5150 2330 60  0001 C CNN "PartNumber"
F 6 "DIODE SCHOTTKY 40V 1A SMA" H 5250 2430 60  0001 C CNN "Description"
	1    5000 2050
	0    1    1    0   
$EndComp
$Comp
L diode_schottky_40V_1A D4
U 1 1 5A0370AF
P 5000 2750
F 0 "D4" H 4950 2830 50  0000 L CNN
F 1 "diode_schottky_40V_1A" H 4720 2670 50  0001 L CNN
F 2 "footprints:DO-214AC(SMA)" H 4850 2730 60  0001 C CNN
F 3 "" H 4950 2830 60  0001 C CNN
F 4 "digikey" H 5050 2930 60  0001 C CNN "Vendor"
F 5 "SS14CT-ND" H 5150 3030 60  0001 C CNN "PartNumber"
F 6 "DIODE SCHOTTKY 40V 1A SMA" H 5250 3130 60  0001 C CNN "Description"
	1    5000 2750
	0    1    1    0   
$EndComp
$Comp
L diode_schottky_40V_1A D5
U 1 1 5A037127
P 5200 2150
F 0 "D5" H 5150 2230 50  0000 L CNN
F 1 "diode_schottky_40V_1A" H 4920 2070 50  0001 L CNN
F 2 "footprints:DO-214AC(SMA)" H 5050 2130 60  0001 C CNN
F 3 "" H 5150 2230 60  0001 C CNN
F 4 "digikey" H 5250 2330 60  0001 C CNN "Vendor"
F 5 "SS14CT-ND" H 5350 2430 60  0001 C CNN "PartNumber"
F 6 "DIODE SCHOTTKY 40V 1A SMA" H 5450 2530 60  0001 C CNN "Description"
	1    5200 2150
	0    1    1    0   
$EndComp
$Comp
L diode_schottky_40V_1A D6
U 1 1 5A0371E2
P 5200 2750
F 0 "D6" H 5150 2830 50  0000 L CNN
F 1 "diode_schottky_40V_1A" H 4920 2670 50  0001 L CNN
F 2 "footprints:DO-214AC(SMA)" H 5050 2730 60  0001 C CNN
F 3 "" H 5150 2830 60  0001 C CNN
F 4 "digikey" H 5250 2930 60  0001 C CNN "Vendor"
F 5 "SS14CT-ND" H 5350 3030 60  0001 C CNN "PartNumber"
F 6 "DIODE SCHOTTKY 40V 1A SMA" H 5450 3130 60  0001 C CNN "Description"
	1    5200 2750
	0    1    1    0   
$EndComp
$Comp
L diode_schottky_40V_1A D7
U 1 1 5A037259
P 5400 2250
F 0 "D7" H 5350 2330 50  0000 L CNN
F 1 "diode_schottky_40V_1A" H 5120 2170 50  0001 L CNN
F 2 "footprints:DO-214AC(SMA)" H 5250 2230 60  0001 C CNN
F 3 "" H 5350 2330 60  0001 C CNN
F 4 "digikey" H 5450 2430 60  0001 C CNN "Vendor"
F 5 "SS14CT-ND" H 5550 2530 60  0001 C CNN "PartNumber"
F 6 "DIODE SCHOTTKY 40V 1A SMA" H 5650 2630 60  0001 C CNN "Description"
	1    5400 2250
	0    1    1    0   
$EndComp
$Comp
L diode_schottky_40V_1A D8
U 1 1 5A037316
P 5400 2750
F 0 "D8" H 5350 2830 50  0000 L CNN
F 1 "diode_schottky_40V_1A" H 5120 2670 50  0001 L CNN
F 2 "footprints:DO-214AC(SMA)" H 5250 2730 60  0001 C CNN
F 3 "" H 5350 2830 60  0001 C CNN
F 4 "digikey" H 5450 2930 60  0001 C CNN "Vendor"
F 5 "SS14CT-ND" H 5550 3030 60  0001 C CNN "PartNumber"
F 6 "DIODE SCHOTTKY 40V 1A SMA" H 5650 3130 60  0001 C CNN "Description"
	1    5400 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	4450 2050 5850 2050
Connection ~ 4800 2050
Wire Wire Line
	4450 2150 5850 2150
Connection ~ 5000 2150
Wire Wire Line
	4450 2250 5850 2250
Connection ~ 5200 2250
Wire Wire Line
	4450 2350 5850 2350
Connection ~ 5400 2350
Wire Wire Line
	4800 2050 4800 2650
Wire Wire Line
	5000 2150 5000 2650
Wire Wire Line
	5200 2250 5200 2650
Wire Wire Line
	5400 2350 5400 2650
$Comp
L GNDD #PWR?
U 1 1 5A0375DE
P 4800 2850
F 0 "#PWR?" H 4800 2600 50  0001 C CNN
F 1 "GNDD" H 4800 2725 50  0000 C CNN
F 2 "" H 4800 2850 50  0001 C CNN
F 3 "" H 4800 2850 50  0001 C CNN
	1    4800 2850
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR?
U 1 1 5A03760D
P 5000 2850
F 0 "#PWR?" H 5000 2600 50  0001 C CNN
F 1 "GNDD" H 5000 2725 50  0000 C CNN
F 2 "" H 5000 2850 50  0001 C CNN
F 3 "" H 5000 2850 50  0001 C CNN
	1    5000 2850
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR?
U 1 1 5A03763C
P 5200 2850
F 0 "#PWR?" H 5200 2600 50  0001 C CNN
F 1 "GNDD" H 5200 2725 50  0000 C CNN
F 2 "" H 5200 2850 50  0001 C CNN
F 3 "" H 5200 2850 50  0001 C CNN
	1    5200 2850
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR?
U 1 1 5A03766B
P 5400 2850
F 0 "#PWR?" H 5400 2600 50  0001 C CNN
F 1 "GNDD" H 5400 2725 50  0000 C CNN
F 2 "" H 5400 2850 50  0001 C CNN
F 3 "" H 5400 2850 50  0001 C CNN
	1    5400 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 1450 4800 1850
Wire Wire Line
	4500 1450 5400 1450
Wire Wire Line
	5000 1450 5000 1950
Wire Wire Line
	5200 1450 5200 2050
Connection ~ 5200 2050
Connection ~ 5000 1450
Wire Wire Line
	5400 1450 5400 2150
Connection ~ 5400 2150
Connection ~ 5200 1450
$Comp
L VSS 5v
U 1 1 5A038D22
P 4600 1200
F 0 "5v" H 4600 1050 50  0001 C CNN
F 1 "VSS" H 4600 1350 50  0000 C CNN
F 2 "" H 4600 1200 50  0001 C CNN
F 3 "" H 4600 1200 50  0001 C CNN
	1    4600 1200
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5A038F62
P 4600 2700
F 0 "C1" H 4625 2800 50  0000 L CNN
F 1 "100nF" H 4625 2600 50  0000 L CNN
F 2 "" H 4638 2550 50  0001 C CNN
F 3 "" H 4600 2700 50  0001 C CNN
	1    4600 2700
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR?
U 1 1 5A03907A
P 4600 2850
F 0 "#PWR?" H 4600 2600 50  0001 C CNN
F 1 "GNDD" H 4600 2725 50  0000 C CNN
F 2 "" H 4600 2850 50  0001 C CNN
F 3 "" H 4600 2850 50  0001 C CNN
	1    4600 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 1950 4600 1950
Wire Wire Line
	4600 1200 4600 2550
Connection ~ 4600 1950
Wire Wire Line
	4500 1450 4500 3050
Wire Wire Line
	4500 1850 4450 1850
Connection ~ 4800 1450
$Comp
L C C2
U 1 1 5A0391FD
P 4500 3200
F 0 "C2" H 4525 3300 50  0000 L CNN
F 1 "100nF" H 4525 3100 50  0000 L CNN
F 2 "" H 4538 3050 50  0001 C CNN
F 3 "" H 4500 3200 50  0001 C CNN
	1    4500 3200
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR?
U 1 1 5A03928E
P 4500 3350
F 0 "#PWR?" H 4500 3100 50  0001 C CNN
F 1 "GNDD" H 4500 3225 50  0000 C CNN
F 2 "" H 4500 3350 50  0001 C CNN
F 3 "" H 4500 3350 50  0001 C CNN
	1    4500 3350
	1    0    0    -1  
$EndComp
Connection ~ 4500 1850
Wire Wire Line
	3250 1200 4600 1200
Wire Wire Line
	3550 1200 3550 2550
Wire Wire Line
	3550 2550 3750 2550
Wire Wire Line
	3750 2050 3750 1800
Wire Wire Line
	3750 1800 2850 1800
Wire Wire Line
	2850 1800 2850 2150
$Comp
L 74AHC1G04 U?
U 1 1 5A039719
P 3300 2150
F 0 "U?" H 3495 2265 50  0000 C CNN
F 1 "74AHC1G04" H 3600 2000 50  0000 C CNN
F 2 "" H 3300 2150 50  0001 C CNN
F 3 "" H 3300 2150 50  0001 C CNN
	1    3300 2150
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR?
U 1 1 5A03977A
P 3250 2350
F 0 "#PWR?" H 3250 2100 50  0001 C CNN
F 1 "GNDD" H 3250 2225 50  0000 C CNN
F 2 "" H 3250 2350 50  0001 C CNN
F 3 "" H 3250 2350 50  0001 C CNN
	1    3250 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 1950 3250 1200
Connection ~ 3550 1200
$EndSCHEMATC