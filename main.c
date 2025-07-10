/*
 * Traffic_Light_Project.c
 *
 * Created: 2025/07/09 17:03:42
 * Author : Thato Maelane
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

int main(void)
{
    // Set PB2, PB3, PB4 as outputs
    DDRB |= (1<<PB2) | (1<<PB3) | (1<<PB4);

    // Set PD2 as input for maintenance switch
    DDRD &= ~(1<<PD2);
    PORTD |= (1<<PD2); // Enable pull-up resistor on PD2

    while (1)
    {
        // Check if the maintenance switch is NOT pressed (switch open)
        if (PIND & (1<<PD2))
        {
            // RED ON, others OFF
            PORTB = (1<<PB2);
            _delay_ms(3000);

            // YELLOW ON, others OFF
            PORTB = (1<<PB3);
            _delay_ms(3000);

            // GREEN ON, others OFF
            PORTB = (1<<PB4);
            _delay_ms(3000);
        }
        else
        {
            // Maintenance mode: All LEDs OFF
            PORTB &= ~((1<<PB2) | (1<<PB3) | (1<<PB4));
        }
    }
}
