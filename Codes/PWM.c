#include<lpc214x.h>
unsigned long int x;

int main(){
	PINSEL0=0x00000400;
	
	PWMMR0 = 0x0000000F;
	PWMMR5 = 0x00000000;
	
	PWMMCR = 0x00000003;
	PWMPCR = 0x00002000;
	PWMTCR = 0x00000009;
	
	PWMLER = 0x00000020;
	
	while(1){
		PWMIR = 0x00000001;
		PWMMR5=x;
		
		if(x>=PWMMR0)
			x=0;
		x=x+1;
		
		PWMLER=0x000000020;
	
	
	}
	
}