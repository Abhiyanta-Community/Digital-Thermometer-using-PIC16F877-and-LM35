#include "xc.h"
#define __XTAL_FREQ 20000000

unsigned char digital;

void interrupt ADC(){
    if(PIR1bits.ADIF == 1){
        digital = (ADRESH<<8);
        digital = digital + ADRESL;
        PIR1bits.ADIF = 0;
    }
}

void main(){
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;
    int i;
    TRISB = 0;
    PORTBbits.RB1 = 0;
    PORTBbits.RB0 = 0;
    
    ADCON0 = 0x41;
    ADCON1 = 0x8E;
    
    while(1){
        ADCON0 = ADCON0 | (0x04);
            
        int temp = (int)(digital/2.046);
        
        if(temp < 45 && temp >35){
            PORTBbits.RB0 = 1;
            for(i=0;i<1000;i++);
            PORTBbits.RB0 = 0;
            for(i=0;i<1000;i++);
        }
        else if(temp < 20){
            PORTBbits.RB1 = 1;
            for(i=0;i<1000;i++);
            PORTBbits.RB1 = 0;
            for(i=0;i<1000;i++);
        }
        else if(temp == -55 || temp == 150){
            PORTBbits.RB1 = 1;
            PORTBbits.RB0 = 1;
        }
    }
}
