#include<lpc214x.h>            
void delay(int );            
int i;                         
unsigned int a[]={0xf3,0x12,0x163,0x133,0x192,0x1b1,0x1f1,0x13,0x1f3,0x1b3}; 
int main()
{ 
    IO0DIR=IO0DIR|0xffffffff;              
    while(1)
    {
        for(i=0;i<=9;i++)
        {
            IO0SET=IO0SET|a[i];           
            delay(9000);                 
            IO0CLR=IO0CLR|a[i];           
        }
    }
    return 0;
}


void delay(int k)              
{

    int i,j;

    for(i=0;i<k;i++)

    for(j=0;j<=1000;j++);

}