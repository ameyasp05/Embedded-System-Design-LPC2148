#include "lpc214x.h"     // Include LPC2148 header file

#define LED_PIN  16      // Define LED to PIN 16
#define LED_PORT IO1PIN  // Define LED to Port1
#define LED_DIR  IO1DIR  // Define Port1 direction register
 
void delayMs(unsigned int x);
 
int main()
{
    PINSEL2 = 0x00000000;        // Define port lines as GPIO
    LED_DIR  |=  (1 << LED_PIN); // Define LED pin as O/P
    LED_PORT &= ~(1 << LED_PIN); // Turn off the LED initially

    while(1) // Loop forever
    {
        LED_PORT |=  (1 << LED_PIN); // Turn ON LED
        delayMs(1000);               // 1 second delay
        LED_PORT &= ~(1 << LED_PIN); // Turn OFF LED
        delayMs(1000);               // 1 second delay
    }
    return 0;
}

//Blocking delay function
void delayMs(unsigned int x)
{
    unsigned int j;

    for(;x>0;x--)
        for(j=0; j<0x1FFF; j++);
}