#include <htc.h>


#define LED_A        RB4
#define LED_B        RB5
#define BTN_1        RA0
#define BTN_2        RA1
#define TMR0_PRELOAD 12   // (256-12) * 256 (prescaler) * 4us = 249,856 ms


void main(void) {
    TRISA = 0b00000011;
    TRISB = 0x00;
    LED_A = 1;
    LED_B = 1;

    T0CS = 0;                 
    PSA  = 0;                 
    PS2 = 1; PS1 = 1; PS0 = 1; 

    while (BTN_1 && BTN_2) { } 

    LED_B = 0;                 
    TMR0  = TMR0_PRELOAD;
    T0IF  = 0;
    T0IE  = 1;
    GIE   = 1;

    while (1) { }              
}

void interrupt isr(void) {
    if (T0IF && T0IE) {
        TMR0  = TMR0_PRELOAD;
        LED_A = !LED_A;
        LED_B = !LED_B;
        T0IF  = 0;
    }
}