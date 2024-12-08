# Interfacing a Single Seven-Segment Display with STM32F401RETx  

This project demonstrates how to interface a single seven-segment display with the STM32F401RETx microcontroller. The display shows a single-digit count (`0` to `9`), which increments each time a connected switch is pressed.

---

## 🚀 **Overview**  

In this project:  
- A **seven-segment display** is used to display numbers (`0` to `9`).  
- A **push-button switch** increments the displayed number when pressed.  
- Direct manipulation of STM32 registers ensures efficient and precise control.  

For a detailed explanation of this project, watch the video here:  
[📺 Interfacing a Single Seven-Segment Display with STM32](https://www.youtube.com/watch?v=xv7Q4BSADHU)  

This project avoids HAL libraries, allowing a deeper understanding of low-level microcontroller programming.

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
   - Contains the Proteus simulation file (`seven_segment_single_switch.pdsprj`) to test the design virtually before deploying to hardware.  

4. **`src/`**  
   - Includes the C source code (`main.c`) for driving the seven-segment display and reading the switch input.  

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
   cd Embedded-C-Programming-for-STM32/Interfacing\ Single\ 7-Segment\ display\ and\ switch\ with\ STM32

   ```  

2. Build the project:  
   - Open the `src/main.c` file in KEIL µVision.  
   - Compile the code, and the hex file will be generated in the `build/` folder.  

3. Load the Proteus simulation:  
   - Open the `.pdsprj` file in the `simulations/` folder using Proteus.  
   - Run the simulation to test the switch-controlled increment functionality.  

4. Flash the hex file to STM32:  
   - Use ST-Link or another compatible programmer to upload the hex file from the `build/` folder.  

5. Connect hardware:  
   - Follow the circuit diagram provided in the `docs/` folder to connect the seven-segment display, switch, and STM32F401RETx microcontroller.  
   - Power on the circuit to test the functionality.  

---

## 📌 **Features**  

- **Single Seven-Segment Display:** Displays numbers `0` to `9`.  
- **Increment Functionality:** The count increments by `1` every time the switch is pressed.  
- **Direct Register Access:** GPIOs are configured without HAL libraries for fine control.  
- **Simulation-First Approach:** Proteus simulation ensures correctness before moving to hardware.  

---

## 🛠️ **Future Improvements**  

- Add debounce logic for the switch to prevent unintended multiple increments.  
- Expand the project to include decrement functionality with an additional switch.  
- Implement power-saving modes to reduce energy consumption.  

---

## 🤝 **Contributing**  

Contributions are welcome! Fork this repository, make your changes, and submit a pull request. Let’s learn and innovate together! 🚀  

---

## 📜 **License**  

This project is licensed under the MIT License. See the `LICENSE` file for details.  

---

**Happy Coding and Innovating! 🚀**  
