//Analog to Digital Convertor

#include<lpc21xx.h>

void delay()

{

int i,j;

for (j=0;j<1000;j++);

}

int main()

{

int dig_data;

PINSEL1=0x01000000;
//for P0.28 as analog i/p

IODIR0=0x001ff800; //P0.19 to P0.12 as o/p for LEDs

while(1)
{

ADDR=0;
//Initially data reg=0

ADCR=0x01200402;
//Channel-0 as i/p;s/w clk;Power down mode;START NOW

do

{ dig_data=ADDR;

delay();


}

while(!(dig_data&0x800000000)); //Read till DONE=1 i.e end of conversion

{

/* to display on LEDs */

IOCLR0=0x000ff000;
//Clear all LEDs

IOSET0=dig_data<<5;
//P0.6-P0.15(ADC) becomes P0.16-P0.25(LEDs)

}

}
}