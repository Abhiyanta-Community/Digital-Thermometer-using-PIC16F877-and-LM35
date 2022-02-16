     
#include "xc.h"
#include<stdio.h>
#define _XTAL_FREQ 20000000

int count = 0;
void Timer1Delay(void);

void interrupt Count(){
    
       if(TMR0IF == 1)
    {   
                     count++;
                     TMR0IF = 0;
    }
}

void Timer1Delay(void){     //10ms delay
    T1CON=0x01;             //Timer-1 16-bit mode Prescaler 1:4
    TMR1H=0x30;             //Count Hight Byte
    TMR1L=0xD4;             //Count Low Byte
    
    //Runing loop for 100 times produces 1 second 10ms x 100 = 1 second
    for(int j=0;j<=100;j++)
    {        
        TMR1ON=1;              //Run timer
        while(TMR1IF==0);     //Wait for flag to over flow
        TMR1ON=0;              //Switch off timer
        TMR1IF=0;             //Clear Interrupt
    }
}

void main()
{ 
	int j,i=0;
	TRISB = 0;
	PORTB = 0;
	GIE = 1;
    PEIE = 1;
    TMR0IE = 1;
	OPTION_REG = 0x07;
	TMR0 = 59;
    TRISE=0X00; //Instruct the MCU that the PORTE pins are used as Output.
    PORTE=0X00; //Make all output of RE LOW
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
        //default:
            i=0;// default statements
            printf("%d",i);
            break;
        }
        
        RE0=1; //LED ON
        Timer1Delay();   //Wait
        RE0=0; //LED OFF
        Timer1Delay();   //Wait
    
        RE1=1; //LED ON
        Timer1Delay();  //Wait
        RE1=0; //LED OFF
        Timer1Delay();   //Wait
    
        RE2=1; //LED ON
        Timer1Delay();   //Wait
        RE2=0; //LED OFF
        Timer1Delay();   //Wait
    
        RE2=1; //LED ON
        Timer1Delay();   //Wait
        RE2=0; //LED OFF
        Timer1Delay();   //Wait
    
        RE1=1; //LED ON
        Timer1Delay();   //Wait
        RE1=0; //LED OFF
        Timer1Delay();   //Wait
    
        RE0=1; //LED ON
        Timer1Delay();   //Wait
        RE0=0; //LED OFF
        Timer1Delay();   //Wait
    //Repeat.
    }
}