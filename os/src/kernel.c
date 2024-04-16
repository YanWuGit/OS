#include "screen_driver.h"

void main()
{
    // Create a pointer to a char , and point it to the first text cell of
    // video memory ( i . e . the top - left of the screen )
    char *video_memory = (char *)0xb8000;
    // At the address pointed to by video_memory , store the character ’X ’
    // ( i . e . display ’X ’ in the top - left of the screen ).
    *video_memory = 'X';

    char *message = "hello world";
    int col = 0;

    // Loop through each character in the message and print it
    while (*message) {
        print_char(*message++, col++, 0, WHITE_ON_BLACK);
    }
}