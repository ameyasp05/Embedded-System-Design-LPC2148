#include <lpc214x.h>

int main(){
	IODIR1 &= (0<<16) & (0<<17) & (0<<18);
	
	IODIR0 = (1<<5) | (1<<6);
	
	while(1){
		if(!(IOPIN1 & (1<<16)))       //clockwise
			IOPIN0=0x00000040;
		if(!(IOPIN1 & (1<<18)))        //off
			IOPIN0=0x00000060;
		if(!((IOPIN1 & (1<<17))))      // anticlockwise
			IOPIN0=0x00000020;
	}
}