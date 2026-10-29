#include <htc.h>
#define _XTAL_FREQ 1000000
  
bit pressed = 0; 

void main() {
  
    TRISA = 0b00000011;
    TRISB = 0b00000000; 

    RB4 = 1; 
    RB5 = 1; 

    while(1) {
        
        if (!(pressed)) 
        {
            
            if (RA0 == 0 || RA1 == 0) 
            {
                pressed = 1;
            }
            
        } 
        else
        {
            RB4 = 1; 
            RB5 = 0; 
            __delay_ms(250); 

            RB4 = 0; 
            RB5 = 1; 
            __delay_ms(250); 
        }
    }
}