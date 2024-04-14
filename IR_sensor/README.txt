This project is intended to give and example of basic functionallity for an IR sensor.
It uses an IR sensor to track how long an object is detected, and an LCD display to show the cumulative time in MS.
The millis_counter variable updates every 1ms, but this only happens when an object is detected by the IR sensor.

*********************************************************************************************************************
NOTES
*********************************************************************************************************************

LCD display wiring: 
	DB4-7 		are pins 2-5
	RS,RW,EN 	are pins 6-8
IR sensor:
	pin 12

Timer 1 is used: 
	pins 9 and 10 may not work as expected
