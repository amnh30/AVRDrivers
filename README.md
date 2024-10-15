---

# AVR ATmega32 Drivers 📟🔢🔧

This repository provides drivers for the **AVR ATmega32** microcontroller, focusing on managing a **keypad**, **LCD**, and **stepper motor**. The project is structured in a modular, layered architecture, ensuring clean separation between hardware abstraction and microcontroller access.

## Features ✨
- **LCD Driver**: Display text, numbers, and custom characters on a 16x2 LCD screen.
- **Keypad Driver**: Capture inputs from a 4x4 keypad matrix.
- **Stepper Motor Driver**: Control a unipolar stepper motor with adjustable speed and rotation direction.

---

## Project Structure 🗂️
```plaintext
.
├── LIB          # Common utilities and macros
├── MCAL         # Microcontroller abstraction layer
│   └── MDIO     # Digital input/output driver
├── HAL          # High-level drivers
│   ├── HLCD     # LCD driver
│   ├── HKEYPAD  # Keypad driver
│   └── HSTEPM   # Stepper motor driver
└── README.md
```

---

## Getting Started 🚀

1. **Initialization**: Import the required headers and initialize the modules (LCD, keypad, stepper motor).
2. **LCD**: Initialize and control a 16x2 LCD display for text and integer output.
3. **Keypad**: Read keypresses from the 4x4 matrix.
4. **Stepper Motor**: Adjust motor rotation angle, speed, and direction.

---

## Example Code 🖥️

### LCD Example 📺
```c
#include "HLCD_interface.h"

int main(void) {
    HLCD_VoidLcdIint();                // Initialize LCD
    HLCD_u8WriteStr("Hello World");    // Display text
    HLCD_VoidLcdWriteInt(123);         // Display integer
    while(1);
    return 0;
}
```

### Stepper Motor Example ⚙️
```c
#include "HSTEPM_interface.h"

int main(void) {
    u16 angle = 90;                      // Desired angle (e.g., 90 degrees)
    u8 direction = HSTEPM_CLOCK_WISE;    // Clockwise direction
    u8 speed = 5;                         // Speed from 2 to 10
    
    HSTEPM_u8RunStepperMotor(angle, direction, speed); // Rotate motor 90° clockwise at speed 5
    while(1);
    return 0;
}
```

### Keypad Example ⌨️
```c
#include "HKEYPAD_interface.h"

int main(void) {
    u8 key;
    
    HKEYPAD_VoidInit();                // Initialize keypad
    
    while(1) {
        key = HKEYPAD_u8GetKey();      // Get keypress
        if (key != KEYPAD_NO_PRESS) {
            // Process key press (e.g., display on LCD)
            HLCD_VoidLcdWriteChar(key);
        }
    }
    return 0;
}
```

---

## Drivers Overview 🔍

### 1. LCD Driver 📺
- **Initialization**: `HLCD_VoidLcdIint()`
- **Display Text**: `HLCD_u8WriteStr()`
- **Display Integer**: `HLCD_VoidLcdWriteInt()`
- **Clear Screen**: `HLCD_VoidLcdClear()`

### 2. Stepper Motor Driver ⚙️
- **Control**: `HSTEPM_u8RunStepperMotor()`
- **Adjustable Parameters**: Rotation angle, direction (clockwise/anti-clockwise), speed (range: 2-10).
- **Example**: Rotate the motor 90° clockwise with speed 5.

### 3. Keypad Driver ⌨️
- **Initialization**: `HKEYPAD_VoidInit()`
- **Capture Input**: `HKEYPAD_u8GetKey()` reads keypresses from the 4x4 keypad matrix.
- **Handling Keypress**: Process keypresses (e.g., display on LCD or store data).

---

## Configuration ⚙️

The drivers are fully configurable via `*_config.h` files. Adjust pin and port assignments to match your hardware setup:

- **LCD**: Define RS, RW, EN, and data pins.
- **Stepper Motor**: Set pin assignments for the motor coils.
- **Keypad**: Configure row and column pin connections.

---

## Hardware Requirements 🛠️

- **AVR ATmega32** microcontroller
- 16x2 LCD display
- 4x4 Keypad matrix
- Unipolar stepper motor
- Proper wiring and power connections

---

## Contributing 🤝

We welcome contributions! Feel free to submit issues, suggest improvements, or create pull requests to enhance the drivers or add new functionality.

---

## License 📄

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

This updated `README.md` integrates the **Stepper Motor** and **Keypad** functionality, provides clear examples for each, and uses emojis to make it more visually engaging. Let me know if you need more modifications or additions!
