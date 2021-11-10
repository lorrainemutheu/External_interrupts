#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>

ISR(INT0_vect){
  PORTD ^= (1 << PORTD4); //toggle LED
}

int main(){
    DDRD |= 0x10;  //set direction of PD4 to output for LED  0b00010000
    DDRD &= 0xFB;  //set directon of PD2 to input for button  0b11111101
    PORTD |= (1 << PORTD2); //activate pull-up resistor PORTD2

    EIMSK |= (1 << INT0); //enable INT0
    
    EICRA = (1 << ISC01) | ~(1 << ISC00); //set fall edge trigger
    
    sei(); //enable global interrupt

   while(1){
    _delay_ms(500);
    }
}
