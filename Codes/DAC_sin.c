 #include<lpc214x.h>
unsigned int count[]={  49, 36, 25, 16, 9, 4, 1, 0, 1, 4, 9, 16, 25, 36, 49};
void loop(void);
void setup(void);
void delay(void);
	void delay()
{
	unsigned int i;
	for(i=0;i<4500;i++)
	{}
}
	
	void setup()
	{
		PINSEL1=2<<18;
		IODIR0=1<<25;
	}

	void loop()
	{  
		unsigned int i;
		for(i=0;i<100;i++)
		{
			DACR=count[i]<<6;
			delay();
		}
	}
	
	int main()
		{
			setup();
			while(1)
			{loop();
       }
}