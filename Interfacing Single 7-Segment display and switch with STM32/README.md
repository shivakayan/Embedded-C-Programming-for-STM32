# STM32F401RETx Seven Segment Display and Increment Switch Interface

This project demonstrates how to interface a **Seven Segment Display** and an **Increment Switch** with the **STM32F401RETx** microcontroller. The switch is used to increment a number displayed on the Seven Segment Display.

## Project Overview

- **MCU Used**: STM32F401RETx
- **Peripheral Used**: GPIO (General Purpose Input/Output)
- **Hardware**: A simple circuit with an increment switch connected to GPIO pin A8 and a Seven Segment Display connected to GPIO pins of STM32.

### Key Features
- The Seven Segment Display shows a decimal number (0-9).
- The increment switch is used to increment the displayed number on the Seven Segment Display each time it is pressed.
- The code uses STM32 hardware registers to configure the GPIO pins and implement the functionality.

## Directory Structure

- **`src`**: Contains the source code files (`main.c`, etc.).
- **`build`**: Contains compiled files like `.hex` or `.bin`.
- **`docs`**: Documentation files (if any).
- **`simulations`**: Contains Proteus simulation files for visual representation and simulation of the hardware.

## Code Explanation

The provided code is written in **Embedded C** for STM32 and uses direct register manipulation to control the GPIO pins. Here’s a breakdown of how the code works:

### Code:

```c
#include "stm32f401xe.h"

int main()
{
    int count = 0;
    int num[10] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F};

    // Enable clock for GPIOA
    RCC->AHB1ENR = 0X00000001;

    // Configure GPIOA pins for Seven Segment Display (A0-A7) as output
    GPIOA->MODER &= ~0X00033FFF;   // Clear mode for A0-A7
    GPIOA->MODER |= 0x00001555;    // Set A0-A7 as output

    // Configure GPIOA pin A8 for input (switch)
    GPIOA->PUPDR &= ~0X00030000;   // Clear pull-up/pull-down for A8
    GPIOA->PUPDR |= 0X00010000;    // Set pull-down for A8

    while(1)
    {
        // Check if the switch is pressed (A8)
        if ((GPIOA->IDR & 0X00000100) == 0)
        {
            while ((GPIOA->IDR & 0X00000100) == 0); // Wait until the switch is released
            count++;
            count %= 10;  // Ensure the count stays between 0 and 9
            GPIOA->ODR = num[count];  // Update Seven Segment Display with the new number
        }
    }
}
