EESchema Schematic File Version 2
LIBS:SensorArray-rescue
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
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
LIBS:cyclophone
LIBS:SensorArray-cache
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
L 4051 U4
U 1 1 5A8D892B
P 4550 6550
F 0 "U4" H 4650 6550 50  0000 C CNN
F 1 "4051" H 4650 6350 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 4550 6550 60  0001 C CNN
F 3 "" H 4550 6550 60  0001 C CNN
	1    4550 6550
	1    0    0    -1  
$EndComp
Text Label 5400 7050 0    60   ~ 0
VSS
Text Label 3450 6950 0    60   ~ 0
S0
Text Label 3450 7050 0    60   ~ 0
S1
Text Label 3450 7150 0    60   ~ 0
S2
Text Label 5400 5950 0    60   ~ 0
Mux_Out
Text Label 3450 6850 0    60   ~ 0
VSS
Text Label 3450 5950 0    60   ~ 0
Sensor3
Text Label 3450 6050 0    60   ~ 0
Sensor2
Text Label 3450 6250 0    60   ~ 0
Sensor4
Text Label 3450 6150 0    60   ~ 0
Sensor1
Text Label 3450 6550 0    60   ~ 0
VDD
Text Label 3450 6650 0    60   ~ 0
Sensor5
Text Label 3450 6450 0    60   ~ 0
SensorRechts
Text Label 3450 6350 0    60   ~ 0
SensorLinks
$Comp
L Conn_01x03_Female J1
U 1 1 5A8DC018
P 3250 7050
F 0 "J1" H 3250 7250 50  0000 C CNN
F 1 "Conn_01x03_Female" H 3250 6850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 3250 7050 50  0001 C CNN
F 3 "" H 3250 7050 50  0001 C CNN
	1    3250 7050
	-1   0    0    -1  
$EndComp
$Comp
L Conn_01x03_Female J2
U 1 1 5A8DC312
P 6600 5950
F 0 "J2" H 6600 6150 50  0000 C CNN
F 1 "Conn_01x03_Female" H 6600 5750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 6600 5950 50  0001 C CNN
F 3 "" H 6600 5950 50  0001 C CNN
	1    6600 5950
	1    0    0    -1  
$EndComp
Text Label 6250 5850 0    60   ~ 0
VDD
Text Label 6250 6050 0    60   ~ 0
VSS
$Comp
L TCRT5000 U1
U 1 1 5A8DD7ED
P 1650 2350
F 0 "U1" H 1650 1800 60  0000 C CNN
F 1 "TCRT5000" H 1650 2800 60  0000 C CNN
F 2 "SensorArrayFootprints:TCRT5000" H 1650 2350 60  0001 C CNN
F 3 "" H 1650 2350 60  0000 C CNN
	1    1650 2350
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5A8DB20A
P 900 2300
F 0 "R1" V 980 2300 50  0000 C CNN
F 1 "R" V 900 2300 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 830 2300 50  0001 C CNN
F 3 "" H 900 2300 50  0001 C CNN
	1    900  2300
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 5A8DB252
P 900 2550
F 0 "R8" V 980 2550 50  0000 C CNN
F 1 "R" V 900 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 830 2550 50  0001 C CNN
F 3 "" H 900 2550 50  0001 C CNN
	1    900  2550
	0    1    1    0   
$EndComp
$Comp
L TCRT5000 U2
U 1 1 5A8DBA84
P 3200 2350
F 0 "U2" H 3200 1800 60  0000 C CNN
F 1 "TCRT5000" H 3200 2800 60  0000 C CNN
F 2 "SensorArrayFootprints:TCRT5000" H 3200 2350 60  0001 C CNN
F 3 "" H 3200 2350 60  0000 C CNN
	1    3200 2350
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5A8DBA8A
P 2450 2300
F 0 "R2" V 2530 2300 50  0000 C CNN
F 1 "R" V 2450 2300 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2380 2300 50  0001 C CNN
F 3 "" H 2450 2300 50  0001 C CNN
	1    2450 2300
	0    1    1    0   
$EndComp
$Comp
L R R9
U 1 1 5A8DBA90
P 2450 2550
F 0 "R9" V 2530 2550 50  0000 C CNN
F 1 "R" V 2450 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2380 2550 50  0001 C CNN
F 3 "" H 2450 2550 50  0001 C CNN
	1    2450 2550
	0    1    1    0   
$EndComp
$Comp
L TCRT5000 U3
U 1 1 5A8DBBD7
P 4750 2350
F 0 "U3" H 4750 1800 60  0000 C CNN
F 1 "TCRT5000" H 4750 2800 60  0000 C CNN
F 2 "SensorArrayFootprints:TCRT5000" H 4750 2350 60  0001 C CNN
F 3 "" H 4750 2350 60  0000 C CNN
	1    4750 2350
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5A8DBBDD
P 4000 2300
F 0 "R3" V 4080 2300 50  0000 C CNN
F 1 "R" V 4000 2300 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3930 2300 50  0001 C CNN
F 3 "" H 4000 2300 50  0001 C CNN
	1    4000 2300
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 5A8DBBE3
P 4000 2550
F 0 "R10" V 4080 2550 50  0000 C CNN
F 1 "R" V 4000 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3930 2550 50  0001 C CNN
F 3 "" H 4000 2550 50  0001 C CNN
	1    4000 2550
	0    1    1    0   
$EndComp
$Comp
L TCRT5000 U5
U 1 1 5A8DBBF2
P 6300 2350
F 0 "U5" H 6300 1800 60  0000 C CNN
F 1 "TCRT5000" H 6300 2800 60  0000 C CNN
F 2 "SensorArrayFootprints:TCRT5000" H 6300 2350 60  0001 C CNN
F 3 "" H 6300 2350 60  0000 C CNN
	1    6300 2350
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5A8DBBF8
P 5550 2300
F 0 "R4" V 5630 2300 50  0000 C CNN
F 1 "R" V 5550 2300 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5480 2300 50  0001 C CNN
F 3 "" H 5550 2300 50  0001 C CNN
	1    5550 2300
	0    1    1    0   
$EndComp
$Comp
L R R11
U 1 1 5A8DBBFE
P 5550 2550
F 0 "R11" V 5630 2550 50  0000 C CNN
F 1 "R" V 5550 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5480 2550 50  0001 C CNN
F 3 "" H 5550 2550 50  0001 C CNN
	1    5550 2550
	0    1    1    0   
$EndComp
$Comp
L TCRT5000 U6
U 1 1 5A8DC291
P 7850 2400
F 0 "U6" H 7850 1850 60  0000 C CNN
F 1 "TCRT5000" H 7850 2850 60  0000 C CNN
F 2 "SensorArrayFootprints:TCRT5000" H 7850 2400 60  0001 C CNN
F 3 "" H 7850 2400 60  0000 C CNN
	1    7850 2400
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5A8DC297
P 7100 2350
F 0 "R5" V 7180 2350 50  0000 C CNN
F 1 "R" V 7100 2350 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7030 2350 50  0001 C CNN
F 3 "" H 7100 2350 50  0001 C CNN
	1    7100 2350
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 5A8DC29D
P 7100 2600
F 0 "R12" V 7180 2600 50  0000 C CNN
F 1 "R" V 7100 2600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7030 2600 50  0001 C CNN
F 3 "" H 7100 2600 50  0001 C CNN
	1    7100 2600
	0    1    1    0   
$EndComp
$Comp
L TCRT5000 U7
U 1 1 5A8DC2AC
P 9400 2400
F 0 "U7" H 9400 1850 60  0000 C CNN
F 1 "TCRT5000" H 9400 2850 60  0000 C CNN
F 2 "SensorArrayFootprints:TCRT5000" H 9400 2400 60  0001 C CNN
F 3 "" H 9400 2400 60  0000 C CNN
	1    9400 2400
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5A8DC2B2
P 8650 2350
F 0 "R6" V 8730 2350 50  0000 C CNN
F 1 "R" V 8650 2350 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 8580 2350 50  0001 C CNN
F 3 "" H 8650 2350 50  0001 C CNN
	1    8650 2350
	0    1    1    0   
$EndComp
$Comp
L R R13
U 1 1 5A8DC2B8
P 8650 2600
F 0 "R13" V 8730 2600 50  0000 C CNN
F 1 "R" V 8650 2600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 8580 2600 50  0001 C CNN
F 3 "" H 8650 2600 50  0001 C CNN
	1    8650 2600
	0    1    1    0   
$EndComp
$Comp
L TCRT5000 U8
U 1 1 5A8DC2C7
P 10950 2400
F 0 "U8" H 10950 1850 60  0000 C CNN
F 1 "TCRT5000" H 10950 2850 60  0000 C CNN
F 2 "SensorArrayFootprints:TCRT5000" H 10950 2400 60  0001 C CNN
F 3 "" H 10950 2400 60  0000 C CNN
	1    10950 2400
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 5A8DC2CD
P 10200 2350
F 0 "R7" V 10280 2350 50  0000 C CNN
F 1 "R" V 10200 2350 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 10130 2350 50  0001 C CNN
F 3 "" H 10200 2350 50  0001 C CNN
	1    10200 2350
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 5A8DC2D3
P 10200 2600
F 0 "R14" V 10280 2600 50  0000 C CNN
F 1 "R" V 10200 2600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 10130 2600 50  0001 C CNN
F 3 "" H 10200 2600 50  0001 C CNN
	1    10200 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	5250 7050 5400 7050
Wire Wire Line
	3850 6950 3450 6950
Wire Wire Line
	3850 7050 3450 7050
Wire Wire Line
	3850 7150 3450 7150
Wire Wire Line
	5250 5950 6400 5950
Wire Wire Line
	3450 6850 3850 6850
Wire Wire Line
	3850 6550 3450 6550
Wire Wire Line
	3850 6650 3450 6650
Wire Wire Line
	3850 6450 3450 6450
Wire Wire Line
	3850 6350 3450 6350
Wire Wire Line
	3850 6250 3450 6250
Wire Wire Line
	3850 6150 3450 6150
Wire Wire Line
	3850 6050 3450 6050
Wire Wire Line
	3850 5950 3450 5950
Connection ~ 750  2300
Connection ~ 2150 2650
Wire Wire Line
	1150 2300 1050 2300
Wire Wire Line
	1050 2550 1150 2550
Wire Wire Line
	1100 2550 1100 2900
Connection ~ 1100 2550
Wire Wire Line
	2150 2400 2150 3400
Connection ~ 2300 2300
Connection ~ 3700 2650
Wire Wire Line
	2700 2300 2600 2300
Wire Wire Line
	2600 2550 2700 2550
Wire Wire Line
	2650 2550 2650 2900
Connection ~ 2650 2550
Wire Wire Line
	3700 2400 3700 3400
Connection ~ 3850 2300
Connection ~ 5250 2650
Wire Wire Line
	4250 2300 4150 2300
Wire Wire Line
	4150 2550 4250 2550
Wire Wire Line
	4200 2550 4200 2900
Connection ~ 4200 2550
Wire Wire Line
	5250 2400 5250 3400
Connection ~ 5400 2300
Connection ~ 6800 2650
Wire Wire Line
	5800 2300 5700 2300
Wire Wire Line
	5700 2550 5800 2550
Wire Wire Line
	5750 2550 5750 2900
Connection ~ 5750 2550
Wire Wire Line
	6800 2400 6800 3400
Wire Wire Line
	6950 1500 6950 2600
Wire Wire Line
	750  1500 10500 1500
Connection ~ 6950 2350
Connection ~ 8350 2700
Wire Wire Line
	7350 2350 7250 2350
Wire Wire Line
	7250 2600 7350 2600
Wire Wire Line
	7300 2600 7300 2950
Connection ~ 7300 2600
Wire Wire Line
	8350 2450 8350 3400
Wire Wire Line
	8500 1500 8500 2600
Connection ~ 8500 2350
Connection ~ 9900 2700
Wire Wire Line
	8900 2350 8800 2350
Wire Wire Line
	8800 2600 8900 2600
Wire Wire Line
	8850 2600 8850 2950
Connection ~ 8850 2600
Wire Wire Line
	9900 2450 9900 3400
Connection ~ 10050 2350
Connection ~ 11450 2700
Wire Wire Line
	10450 2350 10350 2350
Wire Wire Line
	10350 2600 10450 2600
Wire Wire Line
	10400 2600 10400 2950
Connection ~ 10400 2600
Wire Wire Line
	11450 2450 11450 3400
Wire Wire Line
	10050 1500 10050 2600
Connection ~ 10050 1500
Connection ~ 8500 1500
Connection ~ 5400 1500
Connection ~ 6950 1500
Connection ~ 3850 1500
Connection ~ 2300 1500
Wire Wire Line
	5400 1500 5400 2550
Wire Wire Line
	3850 1500 3850 2550
Wire Wire Line
	2300 1500 2300 2550
Wire Wire Line
	750  1500 750  2550
Wire Wire Line
	2150 3400 11750 3400
Connection ~ 11450 3400
Connection ~ 9900 3400
Connection ~ 8350 3400
Connection ~ 6800 3400
Connection ~ 5250 3400
Connection ~ 3700 3400
Text Label 1100 2900 0    60   ~ 0
SensorLinks
Text Label 2650 2900 0    60   ~ 0
Sensor1
Text Label 4200 2900 0    60   ~ 0
Sensor2
Text Label 5750 2900 0    60   ~ 0
Sensor3
Text Label 7300 2950 0    60   ~ 0
Sensor4
Text Label 8850 2950 0    60   ~ 0
Sensor5
Text Label 10400 2950 0    60   ~ 0
SensorRechts
Text Label 10500 1500 0    60   ~ 0
VDD
Text Label 11750 3400 0    60   ~ 0
VSS
Wire Wire Line
	6400 6050 6250 6050
Wire Wire Line
	6400 5850 6250 5850
$EndSCHEMATC
