Here’s the complete **README.md** file for your AVR Atmega32 Drivers project, with the added details about **Interrupt Management System** and all the other updates:

---

# **AVR Atmega32 Drivers Project** 🚀

This project includes a set of drivers for an **AVR Atmega32 microcontroller**. It features drivers for **Keypad**, **LCD**, **Stepper Motor**, **MDIO** (Microcontroller Digital I/O) driver, and additional interrupt management functionality for handling interrupts such as global interrupts, external interrupts, ADC conversions, and timer events. The drivers enable seamless control and communication with hardware components, providing easy-to-integrate solutions for common embedded system tasks.

---

## **Features** ✨

- **Keypad Driver**: Handle input from a keypad matrix.
- **LCD Driver**: Manage display output on a 16x2 LCD.
- **Stepper Motor Driver**: Control the movement of a stepper motor.
- **MDIO Driver**: Control and configure GPIO pins on the ATmega microcontroller.
- **Interrupt Management System**: Handle global interrupts, external interrupts, ADC conversions, and timer interrupts.
- **BIT Manipulation Macros**: Efficient bit-level operations on registers.
- **Standard Types**: Ensures consistent data types and error handling.
- **Easy Integration**: Modular architecture for easy integration into your AVR projects.

---

## **Table of Contents** 📑

1. [Introduction](#introduction)
2. [Project Structure](#project-structure)
3. [Keypad Driver](#keypad-driver)
4. [LCD Driver](#lcd-driver)
5. [Stepper Motor Driver](#stepper-motor-driver)
6. [MDIO Driver](#mdio-driver)
7. [Interrupt Management System](#interrupt-management-system)
8. [BIT Math and Standard Types](#bit-math-and-standard-types)
9. [Usage Example](#usage-example)
10. [Installation](#installation)
11. [License](#license)

---

## **Introduction** 📡

This project provides reusable and tested drivers for **AVR Atmega32** development, focusing on common hardware components like **Keypads**, **LCDs**, **Stepper Motors**, and GPIO management through the **MDIO driver**. Additionally, it includes an interrupt management system for handling global, external, ADC, and timer interrupts, making it suitable for real-time applications. The aim is to provide an organized framework for interfacing with these devices using clean and modular code.

---

## **Project Structure** 🏗️

```bash
/AVR-Atmega32-Drivers
|-- /BIT_MATH.h        # Contains macros for bit manipulation
|-- /STD_TYPES.h       # Contains standard data types and error handling
|-- /Keypad_Driver.c   # Keypad functionality
|-- /LCD_Driver.c      # LCD functionality
|-- /Stepper_Motor.c   # Stepper Motor driver
|-- /MDIO_Driver.c     # MDIO functionality for GPIO management
|-- /Interrupts.c      # Interrupt management system
|-- /Makefile          # Build instructions for AVR
|-- /README.md         # Project documentation (this file)
```

---

## **Keypad Driver** 🧮

### **Functionality**:
The Keypad driver allows you to interact with a **4x4 matrix keypad**. It scans rows and columns to detect which key is pressed and provides an interface to get the pressed key.

### **Keypad Code Example**:

```c
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Keypad_Interface.h"

void Keypad_Init(void) {
    // Initialize rows as input and columns as output
}

char Keypad_GetKey(void) {
    // Scan the keypad and return the pressed key
    return 'A'; // Example key
}
```

---

## **LCD Driver** 💡

### **Functionality**:
The LCD driver controls a **16x2 LCD display**, supporting text display, cursor positioning, clearing the screen, and writing integers and strings.

### **LCD Code Example**:

```c
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "HLCD_Interface.h"

void HLCD_VoidLcdInit(void) {
    // Initialize LCD with commands for display settings
    HLCD_VoidLcdWriteCmd(0x38);
    HLCD_VoidLcdWriteCmd(0x0f);
}

void HLCD_VoidLcdWriteChar(u8 Copy_u8Char) {
    // Write a character to the LCD
    MDIO_u8SetPortValue(HLCD_DATA_PORT, Copy_u8Char);
}
```

---

## **Stepper Motor Driver** 🛠️

### **Functionality**:
The Stepper Motor driver enables control of a **4-wire stepper motor**. It allows movement in both directions and provides functionality to step through individual coils in sequence.

### **Stepper Motor Code** Example:

```c
#include "Stepper_Motor_Interface.h"

void StepperMotor_Init(void) {
    // Initialize motor pins as output
}

void StepperMotor_StepForward(void) {
    // Activate coils in sequence to step motor forward
}

void StepperMotor_StepBackward(void) {
    // Activate coils in reverse sequence to step motor backward
}
```

---

## **MDIO Driver** 🔌

### **Functionality**:
The MDIO (Microcontroller Digital I/O) driver allows for efficient control of the microcontroller's GPIO pins. The driver abstracts low-level operations and provides simple functions for setting pin directions, values, and reading pin states.

### **MDIO Functions**:
- **Initialization**: Sets up the GPIO pins with configured directions and initial values.
- **Pin Direction Control**: Set pins to input or output mode.
- **Pin Value Control**: Set or clear pin values (HIGH/LOW).
- **Pin Value Reading**: Read the current state of pins.

### **MDIO Code Example**:

```c
#include "MDIO_Interface.h"

void MDIO_Init(void) {
    MDIO_IntialPins();
}

void MDIO_SetPin(u8 port, u8 pin, u8 value) {
    MDIO_u8SetPinValue(port, pin, value);
}
```

---

## **Interrupt Management System** ⚡

### **Global Interrupt Enable (MGIE)**

#### Purpose:
The global interrupt enable (MGIE) functionality controls whether interrupts are globally enabled or disabled in the system. It ensures that interrupt-based operations can be controlled centrally.

#### Key Functions:
- **Enable Interrupts**: `MGIE_voidEnable()`
- **Disable Interrupts**: `MGIE_voidDisable()`

---

### **External Interrupt 1 (MEXTI)**

#### Purpose:
External interrupts are triggered by external hardware, such as sensors or buttons. This module manages these interrupts and executes specific tasks when external events occur.

#### Key Functions:
- **Enable External Interrupt**: `MEXTI_u8Enable()`
- **Disable External Interrupt**: `MEXTI_u8Disable()`
- **Set Callback**: `MEXTI_u8Callback()`

---

### **Analog-to-Digital Converter (ADC) (MADC)**

#### Purpose:
The ADC converts analog signals (e.g., sensor readings) into digital form. The module supports both synchronous and asynchronous conversion modes.

#### Key Functions:
- **Initialize ADC**: `MADC_voidInit()`
- **Get ADC Value (Sync)**: `MADC_u8GetADCValueSync()`
- **Get ADC Value (Async)**: `MADC_u8GetADCValueAsync()`

---

### **Timer0 (TIMER0)**

#### Purpose:
The Timer0 module allows for time-based operations, such as generating periodic events or handling timeouts. The timer triggers interrupts at specific intervals or after a set delay.

#### Key Functions:
- **Initialize Timer0**: `TIMER0_voidInit()`
- **Start Timer**: `TIMER0_voidStart()`
- **Stop Timer**: `TIMER0_voidStop()`

---

## **BIT Math and Standard Types** 🧮

### **BIT Math Macros**:

These macros are used to manipulate individual bits in a register. This allows low-level control over microcontroller peripherals.

```c
// Macro to set a specific bit
#define SET_BIT(REG, BIT)    ((REG) |= (1 << (BIT)))

// Macro to clear a specific bit
#define CLEAR_BIT(REG, BIT)  ((REG) &= ~(1 << (BIT)))

// Macro to toggle a specific bit
#define TOGGLE_BIT(REG, BIT) ((REG) ^= (1 << (BIT)))

// Macro to check if a specific bit is set (returns 1 if the bit is set, 0 if not)
#define IS_BIT_SET(REG, BIT) (((REG) >> (BIT)) & 1)

// Macro to check if a specific bit is cleared (returns 1 if the bit is cleared, 0 if not)
#define IS_BIT_CLEAR(REG, BIT) (!(((REG) >> (BIT)) & 1))

// Macro to get the value of a specific bit (returns 0 or 1)
#define GET_BIT(REG, BIT) (((REG) >> (BIT)) & 0x01)
```

### **Standard Types**:

This header defines commonly used data types and error handling for more portable and readable code.

```c
#ifndef STD_TYPES_H
#define STD_TYPES_H

// Basic data types for portability and readability
typedef unsigned char u8;      // 8-bit unsigned
typedef signed char s8;        // 8-bit signed
typedef unsigned short int u16; // 16-bit unsigned
typedef signed short int s16;   // 16-bit signed
typedef unsigned int u32;     

 // 32-bit unsigned
typedef signed int s32;        // 32-bit signed
typedef unsigned long int u64;  // 64-bit unsigned
typedef signed long int s64;    // 64-bit signed

/* Error State */
#define STD_TYPE_OK  1           // Success state
#define STD_TYPE_NOK 0           // Failure state

/* Define NULL Pointer */
#define POINTER_NULL 0x00        // Represents NULL pointer (0x00)

#endif
```

---

## **Usage Example** 📝

Here’s an example of how to use the **Keypad** and **LCD** drivers together to display a key press on the LCD.

```c
#include "Keypad_Interface.h"
#include "HLCD_Interface.h"

int main(void) {
    char keyPressed;

    // Initialize Keypad and LCD
    Keypad_Init();
    HLCD_VoidLcdInit();

    while (1) {
        keyPressed = Keypad_GetKey();  // Get the key pressed
        if (keyPressed != 0) {
            HLCD_VoidLcdWriteChar(keyPressed);  // Display the key on the LCD
        }
    }

    return 0;
}
```

---

## **Installation** 🔧

1. **Clone the Repository**:

```bash
git clone https://github.com/yourusername/AVR-Atmega32-Drivers.git
```

2. **Include the Drivers** in your AVR project.

3. **Build** your project using a Makefile or your preferred AVR IDE (e.g., Atmel Studio, PlatformIO).

---

## **License** 📜

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

By using this project, you now have a **modular** set of drivers for **Keypad**, **LCD**, **Stepper Motor**, **MDIO**, **Interrupt Management**, and **low-level bit manipulation** capabilities, making embedded programming more efficient and manageable. Happy coding! 😄

---

Let me know if you need any more specific changes or additional sections!
