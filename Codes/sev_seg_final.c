#include<lpc214x.h>

void delay(unsigned int t){
	for (unsigned int i=0;i<t;i++){}
		for (unsigned int j=0;j<2000;j++){}
}
int a[16]={0x0C,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};

int main(){
	PINSEL0 =0x00000000;
	IODIR0 =0xFFF;
	
	while(1){
		unsigned int i;
		for(i=0;i<16;i++){
		IOPIN0=a[i];
			delay(5000);
	}}


}