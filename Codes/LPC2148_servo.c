#include<lpc214x.h>

#define fosc 8000000


void delay(unsigned int);
void lcddata(unsigned char);
void lcdcmd(unsigned char);
void lcd_string(unsigned char*);

void delay(unsigned int x){
  unsigned int i,j;
  for(i=0;i<x;i++);
  for(j=0;j<1275;j++);	
}

void lcddata(unsigned char dat){
  IO0PIN=dat|(1<<8);
  delay(1);
  IO0PIN=dat|(5<<8);
}

void lcdcmd(unsigned char cmd){
  IO0PIN=cmd|(0<<8);
	delay(1);
	IO0PIN=cmd|(4<<8);
}

void lcd_string(unsigned char *p){
 while(*p!='\0'){
  lcddata(*p);
  p++;
}
}



 main()
{
	unsigned char sec,hr, hr0, hr10, sec0,sec10,min10,min;
	unsigned int pclk, new;
	


pclk=fosc/4 ;
new= pclk/32768 - 1;
PREINT=new;
PREFRAC=pclk- ((PREINT+1 )*32768) ;

PINSEL0=0x00000000;
PINSEL2=0x00000000;

IO0DIR=0x0000fff;
IO1DIR=0x000F0000;

	//LCD ini
lcdcmd(0x39);
delay(5);
lcdcmd(0x01);
delay(5);
lcdcmd(0x0C);
delay(5);
lcdcmd(0xC0);
delay(5);

CCR=0x01; // timer on

while (1)
sec=SEC;
sec0=sec%10;
sec10=sec/10;
min=MIN;
min10=min/10 ;
hr=HOUR;
lcdcmd (0x83) ;
lcddata (hr10+42) ;
lcddata (hr0+48) ;
lcddata(':');
lcddata (min10+48) ;
lcddata (min10+42) ;
lcddata (':');
lcddata (sec10+48) ;
lcddata (sec0+48) ;


//sensors at port 1

if ((IO1PIN&0x00100000)==0){
lcdcmd(0x01);
IO1PIN=8<<16;
lcdcmd(0x80);
lcd_string("EAST direction");
delay(250);
lcdcmd(0x01);	
}

if ((IO1PIN&0x00200000)==0){
lcdcmd(0x01);
IO1PIN=12<<16;
lcdcmd(0x80);
lcd_string("45* SOUTHEAST ");
delay(250);
lcdcmd(0x01);	
}

if ((IO1PIN&0x00400000)==0){
lcdcmd(0x01);
IO1PIN=4<<16;
lcdcmd(0x80);
lcd_string("SOUTH Direction");
delay(250);
lcdcmd(0x01);	
}

if ((IO1PIN&0x00800000)==0){
lcdcmd(0x01);
IO1PIN=6<<16;
lcdcmd(0x80);
lcd_string("45* SOUTHWEST");
delay(250);
lcdcmd(0x01);	
}

if ((IO1PIN&0x01000000)==0){
lcdcmd(0x01);
IO1PIN=2<<16;
lcdcmd(0x80);
lcd_string("WEST Direction");
delay(250);
lcdcmd(0x01);	
}

if ((IO1PIN&0x02000000)==0){
lcdcmd(0x01);
IO1PIN=3<<16;
lcdcmd(0x80);
lcd_string("225* NORTH WEST");
delay(250);
lcdcmd(0x01);	
}

if ((IO1PIN&0x04000000)==0){
lcdcmd(0x01);
IO1PIN=1<<16;
lcdcmd(0x80);
lcd_string("NORTH Direction");
delay(250);
lcdcmd(0x01);	
}

if ((IO1PIN&0x08000000)==0){
lcdcmd(0x01);
IO1PIN=9<<16;
lcdcmd(0x80);
lcd_string('45* NORTH EAST');
delay(250);
lcdcmd(0x01);	
}
}