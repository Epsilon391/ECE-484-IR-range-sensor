This project is intended to give and example of basic functionallity for an IR sensor.
It uses an IR sensor to track how long an object is detected, and an LCD display to show the cumulative time in MS.
The millis_counter variable updates every 1ms, but this only happens when an object is detected by the IR sensor.

*********************************************************************************************************************
NOTES
*********************************************************************************************************************

TO USE (wiring and compile)

LCD display wiring: 
	DB4-7 		are pins 2-5
	RS,RW,EN 	are pins 6-8
IR sensor wiring:
	OUT             is pin 12
Compile:
	open compile_script.py and replace line 34 with your own AVR path.
	open a console with command window and navigate to your IR_sensor file path.
	run the command in quotes: "python .\compile_script.py 4 com9" (change 9 to your com port).

If modifying:
	Timer 1 is used, so pins 9 and 10 may not work as expected


