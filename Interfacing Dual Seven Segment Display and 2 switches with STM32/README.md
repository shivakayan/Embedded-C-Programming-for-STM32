Here’s a **README.md** for your project on interfacing two seven-segment displays with STM32F401RETx for count display:

---

# Interfacing Two Seven-Segment Displays with STM32F401RETx  

This project demonstrates how to interface two seven-segment displays with the STM32F401RETx microcontroller. The displays are used to show a two-digit count, ranging from `00` to `99`, controlled by two switches for incrementing and decrementing the count.

---

## 🚀 **Overview**  

In this project:  
- Two **seven-segment displays** are connected to STM32 GPIOs for displaying digits.  
- Two **push-button switches** are used to increment or decrement the count.  
- A custom implementation is provided for driving the displays and handling button inputs.  

This project does not use any HAL libraries, allowing direct control over STM32 registers for maximum flexibility and performance.

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
   - Contains the compiled hex files for flashing the STM32 microcontroller.  

2. **`docs/`**  
   - Includes a PowerPoint presentation (`tutorial.pptx`) explaining the project setup, circuit design, and code logic.  

3. **`simulations/`**  
   - Contains the Proteus simulation file (`count_display.pdsprj`) for testing the design before deploying on hardware.  

4. **`src/`**  
   - Includes the C source code (`main.c`) for driving the seven-segment displays and handling button inputs.

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
   git clone https://github.com/yourusername/seven-segment-stm32.git
   cd seven-segment-stm32
   ```  

2. Build the project:  
   - Open the `src/main.c` file in KEIL µVision.  
   - Compile the code, and the hex file will be available in the `build/` folder.  

3. Load the Proteus simulation:  
   - Open the `.pdsprj` file in the `simulations/` folder using Proteus.  
   - Run the simulation to visualize the increment and decrement functionality.  

4. Flash the hex file to STM32:  
   - Use ST-Link or a similar debugger/programmer to upload the hex file from the `build/` folder.  

5. Connect hardware:  
   - Follow the circuit diagram provided in the `docs/` folder to connect the seven-segment displays, switches, and STM32F401RETx.  
   - Power on the circuit and test the functionality.  

---

## 📌 **Features**  

- **Dual Seven-Segment Display:** Displays a two-digit count (00-99).  
- **Increment and Decrement Control:**  
  - **Switch 1 (PA15):** Increments the count.  
  - **Switch 2 (PA14):** Decrements the count.  
- **Direct Register Manipulation:** GPIOs configured without HAL for precise control.  
- **Simulation-First Approach:** Proteus simulation ensures correctness before hardware implementation.  

---

## 🛠️ **Future Improvements**  

- Implement a debounce mechanism for the switches to prevent false triggers.  
- Add support for multiple modes (e.g., count up, count down, reset).  
- Enhance the project with additional displays or communication protocols (e.g., UART to transmit the count).  

---

## 🤝 **Contributing**  

Contributions are welcome! Fork this repository, make improvements, and submit a pull request. Let’s collaborate and innovate together. 🚀  

---

## 📜 **License**  

This project is licensed under the MIT License. See the `LICENSE` file for details.  

---

**Happy Coding and Innovating! 🚀**  
