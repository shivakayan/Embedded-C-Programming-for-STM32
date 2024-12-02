# LED + STM32 + Switch

This project demonstrates how to interface an STM32 microcontroller (STM32F401RET) with a **LED** and a **switch**. The LED is toggled based on the state of the switch. The code uses the STM32 hardware registers to configure the GPIO pins and implement the functionality.

## Project Overview

- **MCU Used**: STM32F401RET
- **Peripheral Used**: GPIO (General Purpose Input/Output)
- **Hardware**: A simple circuit with a switch connected to GPIO pin A1 and an LED connected to GPIO pin A0.

### Key Features
- The code configures GPIO pins A0 (LED) and A1 (switch).
- The switch is used to control the state of the LED. If the switch is pressed, the LED will be turned ON; otherwise, the LED will be OFF.
- The LED status is controlled by reading the state of the switch and modifying the output on pin A0 accordingly.

## Directory Structure

- `src`: Contains the source code files (`main.c`, etc.).
- `simulations`: Contains Proteus simulation files for visual representation and simulation of the hardware.
- `build`: Contains compiled files like `.hex` or `.bin`.

## Code Explanation

The provided code is written in **Embedded C** for STM32 and uses direct register manipulation to control the GPIO pins. Here’s a breakdown of how the code works:

### Code:

```c
#include "stm32f401xe.h"

int main()
{
    _Bool flag;

    // Enable clock for GPIOA
    RCC->AHB1ENR = 0X0000001;

    // Configure GPIOA pins: A0 as output and A1 as input
    GPIOA->MODER &= ~0X0000000F;  // Clear mode for A0 and A1
    GPIOA->MODER |= 0X0000001;    // Set A0 as output
    GPIOA->PUPDR &= ~0X0000000C;  // Clear pull-up/pull-down for A1
    GPIOA->PUPDR |= 0X00000004;   // Set pull-down for A1

    while(1)
    {
        // Read the input from A1 (switch state)
        flag = GPIOA->IDR & 0X00000002;  // Check if switch is pressed

        if(!flag)
            GPIOA->ODR |= 0x00000001;  // Turn ON the LED (A0)
        else
            GPIOA->ODR &= ~0X0000001;  // Turn OFF the LED (A0)
    }
}
