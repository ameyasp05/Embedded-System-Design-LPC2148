#include<lpc214x.h>

void pwm_init()
{
	PINSEL0 = 0x8002;
	PWMMR0 = 150000;
	PWMMCR = 0x02;
	PWMPCR = 0x600;
	PWMTCR = 0x09;
	
}

int main()
{
	pwm_init();
	while(1){
		PWMMR1=75000;
		PWMMR2=90000;
		PWMLER=0x6;
		
	}
}