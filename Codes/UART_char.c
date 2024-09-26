#include <lpc21xx.h>

int getkey(void);
char mystring[4] = {'V', 'I', 'T', 0x0A};

void delay() {
    int j = 0;
    for (j = 0; j < 1000000; j++);
}

int main() {
    /* UART Initialisation */
    U1FCR = 0x01;       // ENABLE UART1
    PINSEL0 = 0x050000; // Enable Txd and Rxd UART0
    U1LCR = 0x83;       // DLAB=1; 1 STOP BIT; 8-BIT DATA
    U1DLL = 97;         // Baud Rate=9600bps @ VPB clock=15MHz.
    U1LCR = 0x03;       // DLAB=0 for serial communication
    U1THR = 0;
    while (1) {
        int key = getkey(); 
        if (key == 'a') {
            for (int i = 0; i < 4; i++) {
                while (!(U1LSR & (0x20)));
                U1THR = mystring[i];
                delay();
            }
            break; 
        }
    }   
}

int getkey(void) {
    
    if ((IO0PIN & (1 << 0)) == 0) {
        return 'a'; // Button "a" is pressed
    } else {
        return 0;   // No key press
    }
}