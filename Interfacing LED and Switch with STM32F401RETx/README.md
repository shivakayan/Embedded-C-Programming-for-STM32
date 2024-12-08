# Interfacing a Single LED with a Switch using STM32F401RETx  

This project demonstrates how to interface a single LED with a switch using the STM32F401RETx microcontroller. The LED turns on when the switch is pressed and turns off when the switch is released.

---

## 🚀 **Overview**  

In this project:  
- A **push-button switch** is used to control the state of an LED.  
- Direct register-level programming is used for precise control of GPIO pins on the STM32F401RETx microcontroller.  

This project avoids HAL libraries, providing a clear understanding of low-level microcontroller programming.

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
   - Contains the compiled hex file for flashing the STM32 microcontroller.  

2. **`docs/`**  
   - Includes a PowerPoint presentation (`tutorial.pptx`) explaining the project’s circuit design, code structure, and implementation steps.  

3. **`simulations/`**  
   - Contains the Proteus simulation file (`led_switch_control.pdsprj`) to test the design virtually before deploying to hardware.  

4. **`src/`**  
   - Includes the C source code (`main.c`) for controlling the LED and reading the switch input.  

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
   cd Embedded-C-Programming-for-STM32/Interfacing\ LED\ and\ Switch\ with\ STM32F401RETx

   ```  

2. Build the project:  
   - Open the `src/main.c` file in KEIL µVision.  
   - Compile the code, and the hex file will be generated in the `build/` folder.  

3. Load the Proteus simulation:  
   - Open the `.pdsprj` file in the `simulations/` folder using Proteus.  
   - Run the simulation to test the LED and switch functionality.  

4. Flash the hex file to STM32:  
   - Use ST-Link or another compatible programmer to upload the hex file from the `build/` folder.  

5. Connect hardware:  
   - Follow the circuit diagram provided in the `docs/` folder to connect the LED, switch, and STM32F401RETx microcontroller.  
   - Power on the circuit to test the functionality.  

---

## 📌 **Features**  

- **LED Control:** The LED turns on when the switch is pressed and turns off when released.  
- **Direct Register Access:** GPIOs are configured without HAL libraries for low-level programming.  
- **Simulation-First Approach:** Proteus simulation ensures correctness before moving to hardware.  

---

## 🛠️ **Future Improvements**  

- Add a debounce mechanism to handle switch bounce and prevent unintended LED toggling.  
- Expand the project to include multiple LEDs and switches for advanced control.  
- Implement power-saving modes to optimize energy consumption.  

---

## 🤝 **Contributing**  

Contributions are welcome! Fork this repository, make your changes, and submit a pull request. Let’s learn and innovate together! 🚀  

---

## 📜 **License**  

This project is licensed under the MIT License. See the `LICENSE` file for details.  

---

**Happy Coding and Innovating! 🚀**  
