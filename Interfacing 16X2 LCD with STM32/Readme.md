Embedded-C-Programming-for-STM32
Interfacing 16x2 LCD with STM32
Welcome to the "Interfacing 16x2 LCD with STM32" project repository! 🎉 This project demonstrates how to interface a 16x2 character LCD module with the STM32F401RE microcontroller using Embedded C programming. The project includes all essential files for development, simulation, and testing, making it an excellent resource for embedded system enthusiasts.

📂 Repository Structure
The repository is organized into the following folders for better accessibility:

docs/
Contains a detailed presentation explaining the project.

project-presentation.pptx
build/
Contains the compiled hex file for the project.

lcd_project.hex
src/
Contains the Embedded C source code for the project.

lcd_project.c
simulations/
Contains the Proteus simulation files for testing the project virtually.

lcd_project.pdsprj
✨ Features
Efficient interfacing of a 16x2 LCD with STM32F401RE microcontroller.
Includes GPIO configuration for LCD control and data pins.
Implements key LCD commands like initialization, sending data, and clearing the display.
Proteus simulation for validating functionality before hardware implementation.
Beginner-friendly, with clear and reusable Embedded C code.
🔧 How to Use
Clone the Repository:

bash
Copy code
git clone https://github.com/shivakayan/Embedded-C-Programming-for-STM32.git  
cd Embedded-C-Programming-for-STM32/Interfacing 16X2 LCD with STM32  
Required Tools:

STM32CubeIDE or KEIL µVision (for code development).
Proteus Design Suite (for simulation).
Steps to Run:

Open the source code from the src/ folder in your preferred IDE.
Load the lcd_project.hex file into Proteus simulation from the build/ folder.
Connect the LCD and STM32 model as per the schematic in the Proteus file.
🖥️ Code Overview
Here’s the core C code for this project:

c
Copy code
#include "stm32f401xe.h"  
void MSDelay(unsigned int);  
void lcdprint(char);  
void lcdinit(void);  
void sendcmd(char);  
void printstr(char*);  

void MSDelay(unsigned int Times) {  
    unsigned int i, j;  
    for (i = 0; i < Times; i++) {  
        for (j = 0; j < 1400; j++);  
    }  
}  

void lcdprint(char ch) {  
    GPIOA->ODR &= ~0XFF03;  
    GPIOA->ODR |= ch << 8;  
    GPIOA->ODR |= 0x01;  // RS high for data  
    GPIOA->ODR |= 0x02;  // Enable high  
    MSDelay(5);  
    GPIOA->ODR &= ~0x0002;  // Enable low  
}  

void sendcmd(char ch) {  
    GPIOA->ODR &= ~0XFF03;  
    GPIOA->ODR |= ch << 8;  
    GPIOA->ODR &= ~0x01;  // RS low for command  
    GPIOA->ODR |= 0x02;  // Enable high  
    MSDelay(5);  
    GPIOA->ODR &= ~0x0002;  // Enable low  
}  

void lcdinit(void) {  
    sendcmd(0x38);  // 16x2 mode  
    sendcmd(0x0F);  // Display on, cursor blinking  
    sendcmd(0x06);  // Auto increment  
    sendcmd(0x01);  // Clear display  
}  

void printstr(char *ch) {  
    int i;  
    for (i = 0; ch[i] != '\0'; i++) {  
        lcdprint(ch[i]);  
    }  
}  

int main() {  
    RCC->AHB1ENR = 1;  
    GPIOA->MODER &= ~0XFFFF000F;  
    GPIOA->MODER |= 0X55550005;  
    lcdinit();  
    sendcmd(0x80);  
    printstr("   Welcome to   ");  
    sendcmd(0xc0);  
    printstr("   TechTalks!   ");  
    while (1);  
}  
🎥 Video Tutorial
For a step-by-step explanation of this project, check out my YouTube video:
Interfacing 16x2 LCD with STM32

🌟 Contribution
Feel free to contribute to this repository by creating pull requests for improvements or additional features.

📬 Contact
Have questions or suggestions? Drop a comment on the YouTube video or reach out via GitHub.

Happy Coding! 🚀
