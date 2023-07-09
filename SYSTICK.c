//Daniel Jolin
//Lab1, systick register access

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/tm4c123gh6pm.h"

#define RED     GPIO_PIN_1
#define GREEN   GPIO_PIN_3
#define BLUE    GPIO_PIN_2
#define WHITE   (RED |BLUE |GREEN)
#define BLACK       0x0
#define PURPLE (RED | BLUE)
#define CYAN  (GREEN | BLUE)
#define YELLOW (RED |GREEN)
#define SW1      GPIO_PIN_4


const int SYSTICK_BASE = 0xE000E010 ;
uint8_t color = BLACK;
void enablePortF(void);
const int MS_15 = 15;


//structure for systick definition.
struct nvic_st_s
{
    volatile unsigned long ctrl;
    volatile unsigned long reload;
    volatile unsigned long current;
};

struct nvic_st_s* systick = (void *) SYSTICK_BASE;

//Delay, takes amount of time(ms) as argument.
void SysTick_Wait(uint32_t ms);

int main(void) {
    enablePortF();

    while (1) {
        if(GPIOPinRead(GPIO_PORTF_BASE, SW1) == 0) { //read SW1 input
            SysTick_Wait(MS_15); //debouncing delay
            if(GPIOPinRead(GPIO_PORTF_BASE, SW1) == 0) { //check switch again
                if(color == BLACK){
                    color = RED;
                }
                else if(color == RED) {
                        color = PURPLE;
                }
                else if(color == PURPLE) {
                        color = GREEN;
                }
                else if(color == GREEN) {
                        color = CYAN;
                }
                else if(color == CYAN) {
                        color = BLUE;
                }
                else if(color == BLUE) {
                        color = YELLOW;
                }
                else if(color == YELLOW) {
                        color = WHITE;
                }
                else if(color == WHITE) {
                        color = BLACK;
                }
                GPIO_PORTF_DATA_R = color;
                while(GPIOPinRead(GPIO_PORTF_BASE, SW1) == 0); // wait for SW1 to be released
            }
        }
    }
}

void SysTick_Wait(uint32_t ms)
{
    systick->ctrl = 0x0;
    systick->reload = (80000-1)*ms;  //set delay value
    systick->current = 0;       //clear CURRENT register
    while (systick->current > 100) //wait for count flag
    {
    };
    systick->ctrl = 0x0;
    systick->current = 0;

} ;

void enablePortF(void){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Enable the GPIO port that is used for on-board LED and SW1.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)) // Wait for the GPIO module to be ready.
    {
    }
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RED | BLUE | GREEN); // Set the LEDs as output.
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, SW1); // Set SW1 as input.
    GPIOPadConfigSet(GPIO_PORTF_BASE, SW1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU); // Enable pull-up resistor for SW1.
} ;

