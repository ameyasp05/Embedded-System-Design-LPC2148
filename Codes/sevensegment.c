#include<lpc214x.h>            //Header file for LPC214x Series microcontrollers

void delay(int );              //Function declaration for delay

int i;                         //Variable declared as integer

unsigned int a[]={0xf3,0x12,0x163,0x133,0x192,0x1b1,0x1f1,0x13,0x1f3,0x1b3}; //integer array with numbers for display

int main()

{ 

    IO0DIR=IO0DIR|0xffffffff;              //Sets direction as output for PORT 0 pins

    while(1)

    {

        for(i=0;i<=9;i++)

        {

            IO0SET=IO0SET|a[i];           //sets corresponding pins HIGH

            delay(9000);                  //Calls delay function

            IO0CLR=IO0CLR|a[i];           //Sets corresponding pins LOW

        }

    }

    return 0;

}


void delay(int k)              //Function for making delay

{

    int i,j;

    for(i=0;i<k;i++)

    for(j=0;j<=1000;j++);

}

