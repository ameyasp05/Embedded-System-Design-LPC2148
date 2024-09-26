#include<LPC214x.h>

void delay()
{
	unsigned int i;
	for(i=0; i<2000; i++){}
	}

void main()
{
		unsigned int value;
		while(1)
		{
			value = 0;
			while ( value != 1023 )
				{
					DACR = ( (1<<16) | (value<<6) );
					value++;
				}
			}
		
}		else if((IOPIN1&col4)==0){
			key='/';
			keypad_delay();
			return key;
		}
		
		
		IOCLR1|=row3;
		IOSET1|=(row1|row2|row4);//third column=0
		
		if((IOPIN1&col1)==0){
			key='1';
			keypad_delay();
			return key;
		}
		
		else if((IOPIN1&col2)==0){
			key='2';
			keypad_delay();
			return key;
		}
		
		else if((IOPIN1&col3)==0){
			key='3';
			keypad_delay();
			return key;
		}
		
		else if((IOPIN1&col4)==0){
			key='-';
			keypad_delay();
			return key;
		}