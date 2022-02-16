#include "xc.h"
#define __XTAL_FREQ 20000000

unsigned char digital;

void interrupt ADC()
{
    if(ADIF == 1)
    {
        digital = (ADRESH<<8);
        digital = digital + ADRESL;
        ADIF = 0;
    }
}

void main(){
    GIE = 1;
    PEIE = 1;
    ADIE = 1;
    int Left = 0;
    int Right = 0;
    
    TRISB = 0;
    TRISC = 0;
    
    ADCON0 = 0x41;
    ADCON1 = 0x8E;
    
    while(1){
        ADCON0 = ADCON0 | (0x04);
            
        int temp = (int)(digital/2.046);
        
        Left = temp%10;
        Right = (int)(temp/10);
        
        switch (Right)
        {
        case 0:
            PORTC = 0b00000000; // display no:0
            break;
        case 1:
            PORTC = 0b00000001; // display no:1
            break;
        case 2:
            PORTC = 0b00000010; // display no:2
            break;
        case 3:
            PORTC = 0b00000011; // display no:3
            break;
        case 4:
            PORTC = 0b00000100; // display no:4
            break;
        case 5:
            PORTC = 0b00000101; // display no:5
            break;
        case 6:
            PORTC = 0b00000110; // display no:6
            break;
        case 7:
            PORTC = 0b00000111; // display no:7
            break;
        case 8:
            PORTC = 0b00001000; // display no:8
            break;
        case 9:
            PORTC = 0b00001001; // display no:9
            break;
        default:
            PORTC = 0b00000000;// default statements
            break;
        }
        switch (Left)
        {
        case 0:
            PORTB = 0b00000000; // display no:0
            break;
        case 1:
            PORTB = 0b00000001; // display no:1
            break;
        case 2:
            PORTB = 0b00000010; // display no:2
            break;
        case 3:
            PORTB = 0b00000011; // display no:3
            break;
        case 4:
            PORTB = 0b00000100; // display no:4
            break;
        case 5:
            PORTB = 0b00000101; // display no:5
            break;
        case 6:
            PORTB = 0b00000110; // display no:6
            break;
        case 7:
            PORTB = 0b00000111; // display no:7
            break;
        case 8:
            PORTB = 0b00001000; // display no:8
            break;
        case 9:
            PORTB = 0b00001001; // display no:9
            break;
        default:
            PORTB = 0b00000000;// default statements
            break;
        }
    }
}
