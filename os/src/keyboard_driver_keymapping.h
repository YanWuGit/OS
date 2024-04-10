#ifndef KEYBOARD_DRIVER_H
#define KEYBOARD_DRIVER_H

#include <stdint.h> // For uint8_t type

// Declaration of the keycode to character function
char keycode_to_char(uint8_t keycode);

// You can also declare external variables here, if needed
extern volatile int shift_pressed;

#endif // KEYBOARD_DRIVER_H
