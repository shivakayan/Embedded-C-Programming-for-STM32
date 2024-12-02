# **Interfacing 2 Seven Segment Displays with STM32F401RET for Count Display**

This project demonstrates how to interface two 7-segment displays with the **STM32F401RET** microcontroller to display a 2-digit count. The count can be incremented and decremented using two switches. The count is shown in the **tens** and **ones** place, with each place represented by a 7-segment display.

## **Project Overview**

- **MCU Used**: STM32F401RET
- **Displays Used**: 2 x 7-segment displays
- **Switches Used**: 2 switches for incrementing and decrementing the count
- **Functionality**: The first display shows the tens digit, while the second displays the ones digit. The switches allow the user to increment and decrement the count, which is updated in real-time on the displays.

### **Key Features:**
- **Increment and Decrement:** Use the switches to increment or decrement the 2-digit count.
- **Real-time Display:** The 7-segment displays update immediately based on the switch actions.
- **Direct GPIO Control:** The code directly manipulates GPIO registers to interface with the hardware, with no external libraries (i.e., no HAL).

## **Directory Structure**


## **Code Explanation**

This project is written in **Embedded C** for STM32 and utilizes direct register manipulation for GPIO control. Here's a breakdown of the code:

### **Code:**

```c
#include "stm32f401xe.h"

int main()
{
    int count = 0;
    int num[10] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F};

    // Enable the clock for GPIOA
    RCC->AHB1ENR = 0X00000001;

    // Configure GPIO pins for 7-segment display and switches
    GPIOA->MODER &= ~0XFFFFFFFF;  // Clear mode for all pins
    GPIOA->MODER |= 0x05555555;   // Set alternate pins for 7-segment display

    // Configure pull-up/down resistors for switches
    GPIOA->PUPDR &= ~0XF0000000;
    GPIOA->PUPDR |= 0X50000000;

    while (1)
    {
        // Check for increment switch (PA15)
        if ((GPIOA->IDR & 0X00008000) == 0)
        {
            while ((GPIOA->IDR & 0X00008000) == 0);  // Wait until button is released
            count++;
            count %= 100;  // Keep count within 0-99
            // Display count on 7-segment displays
            GPIOA->ODR = num[(count / 10) % 10] << 7 | num[count % 10];
        }

        // Check for decrement switch (PA14)
        if ((GPIOA->IDR & 0X00004000) == 0)
        {
            while ((GPIOA->IDR & 0X00004000) == 0);  // Wait until button is released
            count = (count == 0) ? 0 : (count - 1);  // Prevent count from going negative
            count %= 100;  // Keep count within 0-99
            // Display updated count on 7-segment displays
            GPIOA->ODR = num[(count / 10) % 10] << 7 | num[count % 10];
        }
    }
}
