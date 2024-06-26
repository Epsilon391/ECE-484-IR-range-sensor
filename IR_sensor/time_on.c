#define __DELAY_BACKWARD_COMPATIBLE__
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "lib/hd44780.h"
#include <avr/interrupt.h>

#define IR 4 

void init_timer();
unsigned long millis_det();

volatile unsigned long millis_counter = 0;
volatile uint8_t object_detected = 0;

int main(void)
{
    // Setup
    LCD_Setup();
    init_timer(); // Initialize the timer
    LCD_Clear();
    
    while(1) 
    {
        if((PINB & (1 << IR)) == 0)
        {
            object_detected = 1; // Set the flag
            LCD_GotoXY(0, 0);
            LCD_PrintString("Detected For:");
            LCD_GotoXY(0, 1);
            LCD_PrintInteger(millis_det());
            LCD_PrintString(" ms");
        } else {
            object_detected = 0; // Clear the flag
        }
    }
}

ISR(TIMER1_COMPA_vect)
{
    if (object_detected == 1) {
        millis_counter++; 
    }
}


void init_timer()
{
    // Configure Timer 1 for a 1ms interrupt
    TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10); // CTC mode, prescaler = 64
    OCR1A = 250; // Timer compare value for 1ms at 16MHz
    TIMSK1 |= (1 << OCIE1A); // Enable Timer 1 compare match interrupt
    sei(); // Enable inturrupts
}

unsigned long millis_det()
{
    return millis_counter;
}

