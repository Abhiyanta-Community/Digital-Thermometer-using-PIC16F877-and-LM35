#include <pic16f877a.h>         
#include "xc.h"
#define _XTAL_FREQ 20000000

int count = 0;
void interrupt Count(){
    
       if(TMR0IF == 1)
    {   
                     count++;
                     TMR0IF = 0;
    }
}

void main()
{ 
	int i=0;
	TRISB = 0;
	PORTB = 0;
	GIE = 1;
    PEIE = 1;
    TMR0IE = 1;
	OPTION_REG = 0x07;
	TMR0 = 59;
    int seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; //hex equivalent of segment patterns
    
	while(1){
        
		if(count == 100)
        {
			i++;
			count = 0;
        }
        
        switch (i)
        {
        case 0:
            PORTB = seg[0]; // display no:0
            break;
        case 1:
            PORTB = seg[1]; // display no:1
            break;
        case 2:
            PORTB = seg[2]; // display no:2
            break;
        case 3:
            PORTB = seg[3]; // display no:3
            break;
        case 4:
            PORTB = seg[4]; // display no:4
            break;
        case 5:
            PORTB = seg[5]; // display no:5
            break;
        case 6:
            PORTB = seg[6]; // display no:6
            break;
        case 7:
            PORTB = seg[7]; // display no:7
            break;
        case 8:
            PORTB = seg[8]; // display no:8
            break;
        case 9:
            PORTB = seg[9]; // display no:9
            break;
        default:
            i=0;// default statements
            break;
        }
    }
}
