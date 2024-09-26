#include<lpc214x.h>

int main(){
	PLL0CON=0x01; // enable but not select
	PLL0CFG=0x24;
	
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	
	while ((PLL0STAT & (1<<10) )==0);
	
	PLL0CON=0x01; 
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	
	VPBDIV=0x01;  //pclk =cclk
	
	
return 0;
}