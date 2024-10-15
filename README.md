AVR ATmega32 Drivers
This repository contains drivers for AVR ATmega32 microcontroller, developed for keypad input, LCD output, and controlling a stepper motor. These drivers are structured in a layered architecture (MCAL, HAL, and LIB).

Features
LCD Driver: Controls a 16x2 LCD display for displaying text and integers.
Keypad Driver: Reads inputs from a 4x4 keypad matrix.
Stepper Motor Driver: Controls a unipolar stepper motor with adjustable speed and direction.
Project Structure
plaintext
Copy code
.
├── LIB
│   ├── STD_TYPES.h
│   └── BIT_MATH.h
├── MCAL
│   └── MDIO
│       ├── MDIO_Interface.h
│       └── MDIO_Program.c
├── HAL
│   ├── HLCD
│   │   ├── HLCD_interface.h
│   │   └── HLCD_program.c
│   ├── HKEYPAD
│   │   ├── HKEYPAD_interface.h
│   │   └── HKEYPAD_program.c
│   └── HSTEPM
│       ├── HSTEPM_interface.h
│       └── HSTEPM_program.c
└── README.md
Getting Started
Initialization: Start by including the necessary libraries and initializing the peripherals (LCD, keypad, and stepper motor).

LCD Module:

Initialize the LCD using HLCD_VoidLcdIint.
You can display text using HLCD_u8WriteStr, write individual characters using HLCD_VoidLcdWriteChar, and clear the screen using HLCD_VoidLcdClear.
Keypad Module:

Use the keypad to capture inputs from a 4x4 matrix with HKEYPAD_u8GetKey.
Stepper Motor Module:

Control the stepper motor using HSTEPM_u8RunStepperMotor. You can specify the angle of rotation, direction, and speed.
Example Code
LCD Example
c
Copy code
#include "HLCD_interface.h"

int main(void) {
    HLCD_VoidLcdIint(); // Initialize the LCD
    HLCD_u8WriteStr("Hello World"); // Display "Hello World"
    HLCD_VoidLcdWriteInt(123); // Display the integer 123
    while(1);
    return 0;
}
Stepper Motor Example
c
Copy code
#include "HSTEPM_interface.h"

int main(void) {
    u16 angle = 90;
    u8 direction = HSTEPM_CLOCK_WISE;
    u8 speed = 5; // Speed from 2 to 10
    
    HSTEPM_u8RunStepperMotor(angle, direction, speed); // Rotate stepper motor 90 degrees clockwise at speed 5
    while(1);
    return 0;
}
Drivers Overview
1. LCD Driver
The LCD driver allows for:

Initialization (HLCD_VoidLcdIint)
Writing text and numbers (HLCD_u8WriteStr, HLCD_VoidLcdWriteInt)
Clearing the display (HLCD_VoidLcdClear)
2. Stepper Motor Driver
The stepper motor driver offers:

Adjustable rotation angle
Clockwise and anti-clockwise direction control
Speed control from 2 to 10
3. Keypad Driver
The keypad driver provides:

Functionality to capture key inputs from a 4x4 matrix (HKEYPAD_u8GetKey)
Configuration
The configuration for pins and ports for each module is defined in the corresponding *_config.h files in the HAL layer.

LCD: Pin configurations for RS, RW, EN, and data pins.
Stepper Motor: Pin assignments for stepper motor coils.
Keypad: Row and column pin assignments.
Contributing
Feel free to submit issues or create pull requests for adding more features or improving the drivers.

License
This project is licensed under the MIT License.
