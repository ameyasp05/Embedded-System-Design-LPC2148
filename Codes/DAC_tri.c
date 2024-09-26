#include <LPC214x.h>

void delay_ms(){
	int i;
	for(i=0;i<2000;i++){
	}
}

int main(){
	int i,j;
	PINSEL1=1<<19;
	DACR=0;

	while(1){
		for(i=0;i<1024;i++){
			DACR=i<<6;
			delay_ms();
	}
		for(i=1023;i>=0;i--){
			DACR=i<<6;
			delay_ms();
	}
		
	}	
}