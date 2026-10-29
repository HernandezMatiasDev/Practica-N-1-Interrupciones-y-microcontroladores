#include <htc.h>

#define _XTAL_FREQ 1000000

void main(void) {
    unsigned int valor_adc;
    unsigned char miles, centenas, decenas, unidades;

    TRISA = 0b00000001;   // RA0/AN0 como entrada
    TRISB = 0x00;         // Puerto B salida (datos a los latchs)
    TRISD = 0x00;         // RD6 y RD7 salida (LE de los latchs)
    PORTD = 0;          

    ADCON1 = 0b10001110;  
    ADCON0 = 0b01000001; 

    while (1) {
        __delay_us(20);       
        GO = 1;                
        while (GO) { }           

        valor_adc = ((unsigned int)ADRESH << 8) | ADRESL;

        miles    = valor_adc / 1000;
        centenas = (valor_adc / 100) % 10;
        decenas  = (valor_adc / 10) % 10;
        unidades = valor_adc % 10;

        PORTB = (decenas << 4) | unidades;
        RD6 = 1;
        __delay_us(10);
        RD6 = 0;

        PORTB = (miles << 4) | centenas;
        RD7 = 1;
        __delay_us(10);
        RD7 = 0;

        __delay_ms(50);
    }
}