#include<LPC214x.h>

void delay()
{
	unsigned int i;
	for(i=0; i<2000; i++){}
}

int main()
{
	unsigned int value;
	while(1)
	{
		
		value = 1023;
		DACR = ( (1<<16) | (value<<6) );
		delay();
		value = 0;
		DACR = ( (1<<16) | (value<<6) );
		delay();
	}
}