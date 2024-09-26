#include<lpc214x.h>
/*
void UartInit(){

	PINSEL0= 0x05;
	U0LCR=0x83;
	U0DLM=0;
	U0DLL=97;
	U0LCR =0x03;

}

unsigned UART0_GetChar(){
	while(!(U0LSR&0x01));
	return(U0RBR);
}

void lm(unsigned char *temp){
	unsigned int i=0;
	
	do{
		temp[i] = UART0_GetChar();
	}
	while(temp[i++] != '*');
	temp[i] ='\0';
	
}



void UART0_PutChar(unsigned char ch){
	while(!(U0LSR&0x20));
		U0THR =ch;
}

void UART0_Puts(unsigned char *ch){
	while(*ch);
		UART0_PutChar(*ch++);
}

void main(){
	unsigned char ch,temp[100];
	UartInit();
	
		while (1);
		lm(temp);
	UART0_Puts(temp);
}

*/

#include <lpc214x.h>

#define LM35_ADC_CHANNEL 1  // ADC channel connected to LM35 (AD0.1)

void initUART(void) {
    // Configure UART0 for 9600 baud rate
    U0LCR = 0x83;  // 8 bits, no parity, 1 stop bit, DLAB = 1
    U0DLM = 0;     // Set divisor to 1 for 9600 baud rate
    U0DLL = 0x4E;  // Set divisor to 1 for 9600 baud rate
    U0LCR = 0x03;  // 8 bits, no parity, 1 stop bit, DLAB = 0
}

void initADC(void) {
    // Configure ADC: P0.25/AD0.1 as an analog input
    PINSEL1 |= (1 << 18);   // Select AD0.1 function
    AD0CR = (1 << 1) |      // SEL=1: Select channel 1 on ADC0
            (1 << 21) |     // PDN=1: ADC operational
            (1 << 8);       // CLKDIV=1: PCLK/2 (maximum allowed according to LM35 datasheet)
}

int readADC(void) {
    // Start conversion
    AD0CR |= (1 << 24);
    
    // Wait for conversion to complete
    while (!(AD0GDR & (1 << 31)));
    
    // Return ADC value
    return (AD0GDR >> 6) & 0x3FF;
}

void sendChar(char ch) {
    // Wait until the transmitter is ready
    while (!(U0LSR & (1 << 5)));
    
    // Send the character
    U0THR = ch;
}

void sendString(const char *str) {
    // Send each character in the string
    while (*str) {
        sendChar(*str++);
    }
}

void sendFloat(float value) {
    char buffer[20];
    sprintf(buffer, "%.2f", value);  // Format the float value with 2 decimal places
    sendString(buffer);
}

int main(void) {
    initUART();
    initADC();

    while (1) {
        int adcValue = readADC();
        float temperature = (adcValue * 3300.0 / 1023.0) / 10.0;

        // Send temperature value to serial monitor
        sendString("Temperature: ");
        sendFloat(temperature);
        sendString(" °C\r\n");
    }
}




