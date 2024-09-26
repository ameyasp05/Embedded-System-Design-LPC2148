#include<lpc214x.h> 
#define EN 1<<10 
#define RS 1<<11 
#define RW 1<<20 
#define LCD_PORT 0x00FF0000; 
#define LCD_SHIFT 16 
void delay(void) 
{ 
int i,j; 
for(i=0;i<1000;i++); 
for(i=0;i<1000;i++); 
} 
void LCD_strobe() 
{ 
//delay(); 
IOSET0=EN; 
delay(); 
IOCLR0=EN; 
delay(); 
} 
void LCD_data(unsigned char ch) 
{ 
IOCLR1=LCD_PORT; 
IOSET1 =ch<<LCD_SHIFT; 
IOSET0=RS; 
IOCLR0=RW; 
LCD_strobe(); 
delay(); } 
void command (unsigned char ch) 
{ 
IOCLR1=LCD_PORT; 
IOSET1 =ch<<LCD_SHIFT; 
IOCLR0=RS; 
IOCLR0=RW; 
LCD_strobe(); 
delay(); 
} 
void LCD_init(void) 
{ 
PINSEL0 &= 0X00 ; //PO.10,P0.11 AS GPIO 
PINSEL1 &= 0X00 ; //P0.20 AS GPIO 
PINSEL2 &= 0X00 ; //P1 GPIO 
IODIR0 |= RS|EN|RW ; //set as output 
IODIR1 |= LCD_PORT; 
command(0X38); 
command(0X06); 
command(0X0C); 
command(0X01); 
command(0X80); 
} 
void LCD_display() 
{ 
command(0x80); 
LCD_data ('V'); 
LCD_data ('I'); 
LCD_data ('T'); 
} 
int main() { 
LCD_init(); 
LCD_display(); 
while(1); 
}