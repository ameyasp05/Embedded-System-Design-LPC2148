#include<lpc21xx.h>
int getKey(void);
char mystring[4]={'V','I','T',0x0A};

void delay()
{ int j=0;
	 for(j=0;j<1000000;j++);
	 }

	 
int i=0;
int main(){
	U1FCR=0x01;
	PINSEL0=0x050000;
	U1LCR=0x83;
	U1DLL=97;
	U1LCR=0x03;
	U1THR=0;
	
	while(1){
		for (i=0;i<4;i++){
			while(!(U1LSR&(0x20)));
			U1THR=mystring[i];
			delay();
		}
	}
}