# Interfacing 16X2 LCD with STM32  

Welcome to the **16X2 LCD Interfacing** project! This repository demonstrates how to interface a 16X2 LCD with the STM32F401RETx microcontroller, including GPIO setup, initializing the LCD, and displaying custom messages.

---

## 🚀 **Overview**  

This project includes:  
- Configuring STM32 GPIOs to drive a **16X2 LCD** in 8-bit mode.  
- Writing efficient **Embedded C code** to initialize and control the LCD.  
- Simulating the design in **Proteus** for validation.  
- Building and generating the final executable hex file for microcontroller programming.  

For a detailed walkthrough of this project, watch the video here:  
[📺 Interfacing 16X2 LCD with STM32](https://youtu.be/OjIxOUQvCFs)  

The project is implemented using **KEIL µVision** without HAL libraries, ensuring direct control over hardware.

---

## 📂 **Folder Structure**  

```plaintext
├── build/          # Contains the compiled hex files.
├── docs/           # Tutorial PowerPoint presentation.
├── simulations/    # Proteus simulation files for testing.
├── src/            # C source code for the project.
└── README.md       # Project documentation.
```

### Folder Descriptions:  

1. **`build/`**  
   - Contains the compiled hex files to program the STM32 microcontroller.  

2. **`docs/`**  
   - Includes a PowerPoint presentation (`tutorial.pptx`) explaining the project, including circuit setup and code implementation.

3. **`simulations/`**  
   - Contains Proteus simulation files to test the LCD interface before hardware deployment.  

4. **`src/`**  
   - Contains the C source code (`main.c`) to initialize the LCD and display custom messages.  

---

## 🔧 **Tools Used**  

- **Microcontroller:** STM32F401RETx  
- **IDE:** KEIL µVision (without HAL)  
- **Debugger/Programmer:** ST-Link  
- **Simulation Software:** Proteus Design Suite  

---

## 📑 **How to Run**  

1. Clone the repository:  
   ```bash
   git clone https://github.com/shivakayan/Embedded-C-Programming-for-STM32.git
   cd Embedded-C-Programming-for-STM32/Interfacing\ 16X2\ LCD\ with\ STM32
   ```  

2. Build the project:  
   - Open the `src/main.c` file in KEIL µVision.  
   - Compile the code and locate the hex file in the `build/` folder.  

3. Load the Proteus simulation:  
   - Open the `.pdsprj` file in the `simulations/` folder using Proteus.  
   - Run the simulation and observe the LCD functionality.  

4. Flash the hex file to STM32:  
   - Use ST-Link or a similar debugger/programmer to upload the hex file from the `build/` folder.  

5. Connect hardware:  
   - Follow the circuit diagram provided in the `docs/` folder to connect the LCD and STM32F401RETx.  
   - Power on the circuit and test the LCD functionality.  

---

## 📌 **Features**  

- **LCD Initialization:** Configures the LCD for 8-bit mode, enabling robust display control.  
- **Custom Message Display:** Demonstrates how to send strings and characters to the LCD.  
- **Simulation-First Workflow:** Ensures the project works in simulation before hardware deployment.  
- **Flexible Design:** Easily adaptable for other LCD sizes and configurations.  

---

## 🛠️ **Future Improvements**  

- Add support for 4-bit mode operation to reduce GPIO usage.  
- Interface the LCD with a keypad or other input devices.  
- Display real-time data such as sensor readings on the LCD.  

---

## 🤝 **Contributing**  

Contributions are welcome! Fork this repository, make improvements, and submit a pull request. Let’s innovate together. 🚀  

---

## 📜 **License**  

This project is licensed under the MIT License. See the `LICENSE` file for details.  

---

**Happy Coding and Innovating! 🚀**  
