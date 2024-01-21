**Morse Code Communicator: UART-Based LED and Sound Signaling System**

Description

This project implements a Morse code translator using the MSP430FR6989 microcontroller. It receives text input through UART and translates it into Morse code. The Morse code is represented both visually, using LEDs, and audibly, with a buzzer.

Features:


_UART Communication: Receives text input from a connected device._

_LED Indication: Utilizes a red LED to visually represent Morse code signals._

_Buzzer Output: Plays Morse code audibly using a buzzer._

_Supports Alphabets and Numbers: Translates both letters (a-z) and numbers (0-9) into Morse code._

_Customizable Parameters: Allows modifications of the buzzer frequency and the buffer size for input strings._

Hardware Setup

Red LED: Connect to P1.0.

Green LED: Connect to P9.7.

Buzzer: Connect to P1.3.

UART Pins: Connect P3.4 (RX) and P3.5 (TX) for UART communication.


Software Requirements

Code Composer Studio or similar IDE for MSP430 development.

A terminal program for UART communication (e.g., PuTTY, Tera Term, or you can use CCS built in terminal).

Usage

Compile and Flash: Compile the code and flash it to the MSP430FR6989 microcontroller.

UART Connection: Connect the MSP430FR6989 to a computer or another UART-enabled device.

Open Terminal: Open a terminal program and configure it for **9600 baud, 8 data bits, no parity, 1 stop bit.**

Send Text: Type text into the terminal. The MSP430FR6989 will translate and output the text as Morse code using the LED and buzzer.

Functions

Initialize_UART(): Initializes UART communication.

uart_write_char(): Transmits a character via UART.

uart_read_char(): Receives a character via UART.

readStringUART(): Reads a string from UART input.

stringForMorse(): Converts a string to Morse code.

Initialize_Buzzer(): Initializes the buzzer.

play_dot(): Plays a dot in Morse code.

play_dash(): Plays a dash in Morse code.

play_morse(): Plays Morse code for a given character.

Important Notes

**Ensure that the MSP430FR6989 microcontroller is properly connected and powered.
The UART communication settings must match between the microcontroller and the terminal program.
The Morse code translation is case-insensitive and supports basic error handling for unknown characters.**
