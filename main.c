
#include <msp430.h>
#include <ctype.h>

#define RED_LED BIT0   // Red LED at P1.0
#define GREEN_LED BIT7 // Green LED at P9.7
#define BUZZER BIT3    // Buzzer at P1.3
#define NOTE 440       // Frequency for the buzzer

#define BUFFER_SIZE 100 // Max Buffer for String

void Initialize_UART(void);
void uart_write_char(unsigned char ch);
unsigned char uart_read_char(void);
void readStringUART(char *buffer, unsigned int max_length);
void stringForMorse(const char *str);
void Initialize_Buzzer(void);
void play_dot(void);
void play_dash(void);
void play_morse(char ch);

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // Stop the Watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       // Enable the GPIO pins

    // Configure LEDs and Buzzer
    P1DIR |= RED_LED | BUZZER;
    P1OUT &= ~RED_LED;
    P9DIR |= GREEN_LED;
    P9OUT &= ~GREEN_LED;

    // Initialize UART and Buzzer
    Initialize_UART();
    Initialize_Buzzer();

    char inputString[BUFFER_SIZE];

    while(1) {
       readStringUART(inputString, BUFFER_SIZE);
       stringForMorse(inputString);
    }
}

void Initialize_UART(void) {
    // Set UCSWRST (Software Reset) to allow configuration
    UCA1CTLW0 |= UCSWRST;

    // Configure UART pins, P3.4 = RX, P3.5 = TX
    P3SEL1 &= ~(BIT4 | BIT5);
    P3SEL0 |= (BIT4 | BIT5);

    // Use SMCLK for UART, SMCLK is 1MHz
    UCA1CTLW0 |= UCSSEL_2;

    // Configure baud rate
    // Values calculated for 9600 baud rate based on 1MHz SMCLK
    UCA1BRW = 6;
    UCA1MCTLW = UCBRF_8 | UCBRS5 | UCBRS1 | UCOS16;

    // Clear UCSWRST to activate the UART module (OUT SOFTWARE RST)
    UCA1CTLW0 &= ~UCSWRST;
}

// Transmit a byte via UART
void uart_write_char(unsigned char ch) {
    while (!(UCA1IFG & UCTXIFG)); // Wait for TX buffer to be ready
    UCA1TXBUF = ch; // Transmit the character
}

// Receive a byte via UART
unsigned char uart_read_char(void) {
    if (UCA1IFG & UCRXIFG) {
        return UCA1RXBUF; // Return the received character
    } else {
        return '\0'; // No character received
    }
}

void readStringUART(char *buffer, unsigned int max_length) {
    unsigned int i = 0;
    char received_char;

    while(i < max_length - 1) {
        received_char = uart_read_char();
        if (received_char == '\r' || received_char == '\n') { // Enter key
            break;
        } else if (received_char != '\0') {
            buffer[i++] = received_char;
        }
    }
    buffer[i] = '\0'; // Null-terminate the string
}

void stringForMorse(const char *str) {
    while(*str != '\0') {
        play_morse(*str); // Play Morse code for each character
        str++;
    }
}

// Initialize Buzzer
void Initialize_Buzzer(void) {
    // Timer A configuration for Buzzer
    TA1CCR0 = 0; // Initially turn off the buzzer
    TA1CCR2 = 0;
    TA1CCTL2 = OUTMOD_7; // Reset/Set mode
    TA1CTL = TASSEL_2 + ID_2 + MC_1; // SMCLK, divide by 8, up mode

    // Configure Buzzer pin
    P1DIR |= BUZZER; // Set as output
    P1SEL0 |= BUZZER; // Select Timer output
}

// Play a dot in Morse code (short buzz)
void play_dot(void) {
    P1OUT |= RED_LED; // Turn on RED LED
    TA1CCR0 = NOTE;
    TA1CCR2 = NOTE / 2;
    __delay_cycles(100000); // Short duration for dot
    TA1CCR0 = 0;
    TA1CCR2 = 0;
    P1OUT &= ~RED_LED; // Turn off RED LED
    __delay_cycles(100000); // Gap between signals
}

// Play a dash in Morse code (long buzz)
void play_dash(void) {
    P1OUT |= RED_LED; // Turn on RED LED
    TA1CCR0 = NOTE;
    TA1CCR2 = NOTE / 2;
    __delay_cycles(400000); // Long duration for dash
    TA1CCR0 = 0;
    TA1CCR2 = 0;
    P1OUT &= ~RED_LED; // Turn off RED LED
    __delay_cycles(100000); // Gap between signals
}

// Play Morse code for a given character
void play_morse(char ch) {
    char lowercase = tolower(ch);
    uart_write_char(lowercase);

    switch (lowercase) {
        case 'a':
            play_dot();
            play_dash();
            break;
        case 'b':
            play_dash();
            play_dot();
            play_dot();
            play_dot();
            break;
        case 'c':
            play_dash();
            play_dot();
            play_dash();
            play_dot();
            break;
        case 'd':
            play_dash();
            play_dot();
            play_dot();
            break;
        case 'e':
            play_dot();
            break;
        case 'f':
            play_dot();
            play_dot();
            play_dash();
            play_dot();
            break;
        case 'g':
            play_dash();
            play_dash();
            play_dot();
            break;
        case 'h':
            play_dot();
            play_dot();
            play_dot();
            play_dot();
            break;
        case 'i':
            play_dot();
            play_dot();
            break;
        case 'j':
            play_dot();
            play_dash();
            play_dash();
            play_dash();
            break;
        case 'k':
            play_dash();
            play_dot();
            play_dash();
            break;
        case 'l':
            play_dot();
            play_dash();
            play_dot();
            play_dot();
            break;
        case 'm':
            play_dash();
            play_dash();
            break;
        case 'n':
            play_dash();
            play_dot();
            break;
        case 'o':
            play_dash();
            play_dash();
            play_dash();
            break;
        case 'p':
            play_dot();
            play_dash();
            play_dash();
            play_dot();
            break;
        case 'q':
            play_dash();
            play_dash();
            play_dot();
            play_dash();
            break;
        case 'r':
            play_dot();
            play_dash();
            play_dot();
            break;
        case 's':
            play_dot();
            play_dot();
            play_dot();
            break;
        case 't':
            play_dash();
            break;
        case 'u':
            play_dot();
            play_dot();
            play_dash();
            break;
        case 'v':
            play_dot();
            play_dot();
            play_dot();
            play_dash();
            break;
        case 'w':
            play_dot();
            play_dash();
            play_dash();
            break;
        case 'x':
            play_dash();
            play_dot();
            play_dot();
            play_dash();
            break;
        case 'y':
            play_dash();
            play_dot();
            play_dash();
            play_dash();
            break;
        case 'z':
            play_dash();
            play_dash();
            play_dot();
            play_dot();
            break;
        case '0':
            play_dash();
            play_dash();
            play_dash();
            play_dash();
            play_dash();
            break;
        case '1':
            play_dot();
            play_dash();
            play_dash();
            play_dash();
            play_dash();
            break;
        case '2':
            play_dot();
            play_dot();
            play_dash();
            play_dash();
            play_dash();
            break;
        case '3':
            play_dot();
            play_dot();
            play_dot();
            play_dash();
            play_dash();
            break;
        case '4':
            play_dot();
            play_dot();
            play_dot();
            play_dot();
            play_dash();
            break;
        case '5':
            play_dot();
            play_dot();
            play_dot();
            play_dot();
            play_dot();
            break;
        case '6':
            play_dash();
            play_dot();
            play_dot();
            play_dot();
            play_dot();
            break;
        case '7':
            play_dash();
            play_dash();
            play_dot();
            play_dot();
            play_dot();
            break;
        case '8':
            play_dash();
            play_dash();
            play_dash();
            play_dot();
            play_dot();
            break;
        case '9':
            play_dash();
            play_dash();
            play_dash();
            play_dash();
            play_dot();
            break;
        default:  // For unknown characters
            play_dot();
            break;
    }
    __delay_cycles(600000); // Gap between characters
}
