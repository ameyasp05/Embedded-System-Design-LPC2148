#include<lpc214x.h>

#define fosc 8000000

void delay(unsigned int);
void lcddata(unsigned char);
void lcdcmd(unsigned char);
void lcd_string(unsigned char*);

main()
{
	unsigned char sec,hr, hr0, hr10, sec0,sec10,min10,min;
	unsigned int pclk, new;
}

int pclk=(fosc/4) ;
int new=((pclk/32768)-1);
int PREINT=new;
PREFRAC=pclk- ((PREINT+1 )*32768) ;

PINSEL0=0x00000000;
PINSEL2=0x00000000;

IO0DIR=0x0000fff;
IO1DIR=0x000F0000;

lcdcmd(0x39);
delay(5);
lcdcmd(0x01);
