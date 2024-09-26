#include <lpc214x.h>

#define DAC_RESOLUTION 1023 // 10-bit DAC

void delay(unsigned int count) {
    unsigned int i;
    for(i = 0; i < count; i++);
}

void DAC_Init() {
    PINSEL1 |= (1 << 20); // Select DACOUT on P0.26
    DACR = 0x0000; // Set DAC value to 0 initially
}

int main() {
    DAC_Init();
    
    while(1) {
        int value;
        
        // Generate triangular wave
        for(value = 0; value <= DAC_RESOLUTION; value++) {
            DACR = (value << 6) & 0x3FFC0; // Update DAC value
            delay(1000); // Delay for waveform frequency control
        }
        
        for(value = DAC_RESOLUTION; value >= 0; value--) {
            DACR = (value << 6) & 0x3FFC0; // Update DAC value
            delay(1000); // Delay for waveform frequency control
        }
    }
    
    
}
