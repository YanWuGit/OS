
#include <stdint.h>

#include "keyboard_driver_keymapping.h"

// Global variable to track shift key status
extern volatile int shift_pressed;

// Function to convert keycode to ASCII character
char keycode_to_char(uint8_t keycode) {
    switch(keycode) {
        case 0x02: return shift_pressed ? '!' : '1';
        case 0x03: return shift_pressed ? '@' : '2';
        case 0x04: return shift_pressed ? '#' : '3';
        case 0x05: return shift_pressed ? '$' : '4';
        case 0x06: return shift_pressed ? '%' : '5';
        case 0x07: return shift_pressed ? '^' : '6';
        case 0x08: return shift_pressed ? '&' : '7';
        case 0x09: return shift_pressed ? '*' : '8';
        case 0x0A: return shift_pressed ? '(' : '9';
        case 0x0B: return shift_pressed ? ')' : '0';
        // English characters
        case 0x1E: return shift_pressed ? 'A' : 'a';
        case 0x30: return shift_pressed ? 'B' : 'b';
        case 0x2E: return shift_pressed ? 'C' : 'c';
        case 0x20: return shift_pressed ? 'D' : 'd';
        case 0x12: return shift_pressed ? 'E' : 'e';
        case 0x21: return shift_pressed ? 'F' : 'f';
        case 0x22: return shift_pressed ? 'G' : 'g';
        case 0x23: return shift_pressed ? 'H' : 'h';
        case 0x17: return shift_pressed ? 'I' : 'i';
        case 0x24: return shift_pressed ? 'J' : 'j';
        case 0x25: return shift_pressed ? 'K' : 'k';
        case 0x26: return shift_pressed ? 'L' : 'l';
        case 0x32: return shift_pressed ? 'M' : 'm';
        case 0x31: return shift_pressed ? 'N' : 'n';
        case 0x18: return shift_pressed ? 'O' : 'o';
        case 0x19: return shift_pressed ? 'P' : 'p';
        case 0x10: return shift_pressed ? 'Q' : 'q';
        case 0x13: return shift_pressed ? 'R' : 'r';
        case 0x1F: return shift_pressed ? 'S' : 's';
        case 0x14: return shift_pressed ? 'T' : 't';
        case 0x16: return shift_pressed ? 'U' : 'u';
        case 0x2F: return shift_pressed ? 'V' : 'v';
        case 0x11: return shift_pressed ? 'W' : 'w';
        case 0x2D: return shift_pressed ? 'X' : 'x';
        case 0x15: return shift_pressed ? 'Y' : 'y';
        case 0x2C: return shift_pressed ? 'Z' : 'z';
        // Space and Enter
        case 0x39: return ' '; // Space
        case 0x1C: return '\n'; // Enter
        default: return 0; // No mapping found
    }
}
