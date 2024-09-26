// Led blinking

#include<lpc21xx.h>

void delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<time;j++);
	}
}

int main(){
	PINSEL0=0x0000;//GPIO
	IODIR0=0xFF;//out
	while(1){
		IOSET0=0xFF;
		delay(100);
		IOCLR0=0xFF;
		delay(100);
	}
	
	return 0;
}