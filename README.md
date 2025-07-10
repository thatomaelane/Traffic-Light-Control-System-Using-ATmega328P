# Traffic Light Control System Using ATmega328P
## Table of Contents

- [Project Overview](#project-overview)
- [Project Objectives](#project-objectives)
- [Prerequisites](#prerequisites)
- [Project Steps](#project-steps)
  - [1. Set Up the Circuit](#1-set-up-the-circuit)
  - [2. Configure the Microcontroller](#2-configure-the-microcontroller)
  - [3. Write and Upload Code](#3-write-and-upload-code)
  - [4. Test the Traffic Light System](#4-test-the-traffic-light-system)
  - [5. Enable Maintenance Mode](#5-enable-maintenance-mode)
  - [6. Document and Submit](#6-document-and-submit)
- [Expected Deliverables](#expected-deliverables)
- [Getting Started](#getting-started)
- [License](#license)
- [Contact](#contact)

# Project Overview
This project simulates a basic traffic light system using an ATmega328P microcontroller. The system uses three LEDs (red, yellow, and green), with each light turning on sequentially every 3 seconds. It also includes a maintenance switch to turn off the entire system when needed.

The project is ideal for beginners in embedded systems and microcontroller programming, offering real-world traffic system behavior in a simple and understandable form.

# Project Objectives
Simulate a real-world traffic light system using ATmega328P.

Use a physical switch to toggle the system for maintenance purposes.

Ensure only one LED is on at a time for accurate simulation.

Practice programming in embedded C using AVR-GCC or Atmel Studio.

# Prerequisites
ATmega328P microcontroller

Basic knowledge of C programming for microcontrollers

Breadboard and jumper wires

3x LEDs (Red, Yellow, Green)

3x 100Ω resistors

1x Pushbutton switch

5V power supply or USBasp programmer

(Optional) Proteus simulation software

# Project Steps
### 1. Set Up the Circuit
Connect:

PB2 → Red LED (with resistor)

PB3 → Yellow LED (with resistor)

PB4 → Green LED (with resistor)

PD2 → Pushbutton switch (with pull-up)

Use a pull-up resistor or enable internal pull-up via software.

### 2. Configure the Microcontroller
Set PB2, PB3, PB4 as output pins for LEDs.

Set PD2 as input pin with internal pull-up for the maintenance switch.

### 3. Write and Upload Code
c
Copy
Edit
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

int main(void)
{
    DDRB |= (1<<PB2) | (1<<PB3) | (1<<PB4);  // LEDs as output
    DDRD &= ~(1<<PD2);                       // Switch as input
    PORTD |= (1<<PD2);                       // Enable pull-up on PD2

    while (1)
    {
        if (PIND & (1<<PD2))
        {
            PORTB = (1<<PB2); // RED
            _delay_ms(3000);
            PORTB = (1<<PB3); // YELLOW
            _delay_ms(3000);
            PORTB = (1<<PB4); // GREEN
            _delay_ms(3000);
        }
        else
        {
            PORTB &= ~((1<<PB2) | (1<<PB3) | (1<<PB4)); // All OFF
        }
    }
}

### 4. Test the Traffic Light System
Power on the circuit.

LEDs should:

Red → 3s

Yellow → 3s

Green → 3s

Repeat

### 5. Enable Maintenance Mode
Press the switch connected to PD2.

All LEDs should turn off immediately.

Releasing the switch resumes normal operation.

### 6. Document and Submit
Include:

Schematic diagram (PNG or Proteus file)

Code file (main.c)

Explanation of system behavior

Screenshots (if simulated)

# Expected Deliverables
Fully working traffic light system on hardware or simulation

Source code with comments

Circuit diagram (Proteus or drawn)

Optional: short video demo of the working project

# Getting Started
To get started, ensure you have:

AVR-GCC or Atmel Studio installed

A way to flash code to ATmega328P (e.g., USBasp)

Proteus for simulation (optional)

Clone or download the repository and upload main.c to your microcontroller.

# License
This project is licensed under the MIT License — feel free to use, modify, and share it!

# Contact
For questions or collaboration opportunities, reach out:

📧 Email: thato6216@gmail.com
🔗 LinkedIn: https://www.linkedin.com/in/thatomaelane/
