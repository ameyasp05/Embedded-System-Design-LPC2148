#include <lpc214x.h>


void PLL(){
	PLL0CON= 0x01;
	PLL0CFG= 0x24;
	
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	
	while((PLL0STAT & (1<<10) )==0);
	PLL0CON=0x03;
	
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	
	VPBDIV=0x01;
}

void delayms(unsigned int t){
	T0CTCR=0x0;
	T0PR=59999;
	T0TCR=0x02;
	T0TCR=0x01 ;
	
	while(T0TC<t);
	T0TCR=0x00;
	

}

int main(void){
	IO0DIR |= (1<<0);
	PLL();
	
	while(1){
		IOSET0 |= (1<<0);
		delayms(500);
		IOCLR0 |= (1<<0);
		delayms(500);
	
	}

}


