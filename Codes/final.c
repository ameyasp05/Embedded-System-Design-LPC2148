#include<lpc214x.h>

unsigned int i,j;

void delay(unsigned int t){
	for (i=0;i<t;i++){
		for (j=0;j<t;j++){}
	} 
}

int main() {
    PINSEL0 = 0x00000000;
    IODIR0 |= (1 << 2) | (1 << 3);  
    IODIR0 &= ~((1 << 0) | (1 << 1));  

    while (1) {
        if ((IO0PIN & (1 << 0)) == 0) {  
            IOSET0 = (1 << 2);  
            delay(1000);  
            IOCLR0 = (1 << 2);  
        }

        if ((IO0PIN & (1 << 1)) == 0) {  
            IOSET0 = (1 << 3);  
            delay(1000);  
            IOCLR0 = (1 << 3);  
					
        }
    }
    return 0;
}