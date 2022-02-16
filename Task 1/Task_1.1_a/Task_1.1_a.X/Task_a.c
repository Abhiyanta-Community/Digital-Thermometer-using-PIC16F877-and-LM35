#include <xc.h>
#define _XTAL_FREQ 20000000 //Specify the XTAL crystal FREQ

void main() //The main function
{
    int i;
    TRISE=0X00; //Instruct the MCU that the PORTE pins are used as Output.
    PORTE=0X00; //Make all output of RE LOW

while(1)    //Get into the Infinite While loop
    {
    RE0=1; //LED ON
    for(i=0;i<5000;i++);   //Wait
    RE0=0; //LED OFF
    for(i=0;i<5000;i++);   //Wait
    
    RE1=1; //LED ON
    for(i=0;i<5000;i++);   //Wait
    RE1=0; //LED OFF
    for(i=0;i<5000;i++);   //Wait
    
    RE2=1; //LED ON
    for(i=0;i<5000;i++);   //Wait
    RE2=0; //LED OFF
    for(i=0;i<5000;i++);   //Wait
    
    RE2=1; //LED ON
    for(i=0;i<5000;i++);   //Wait
    RE2=0; //LED OFF
    for(i=0;i<5000;i++);   //Wait
    
    RE1=1; //LED ON
    for(i=0;i<5000;i++);   //Wait
    RE1=0; //LED OFF
    for(i=0;i<5000;i++);   //Wait
    
    RE0=1; //LED ON
    for(i=0;i<5000;i++);   //Wait
    RE0=0; //LED OFF
    for(i=0;i<50000;i++);   //Wait
    //Repeat.
    }
}
