#ifndef SCREEN_DRIVER_H
#define SCREEN_DRIVER_H

#define VIDEO_ADDRESS 0xb8000 // Base address for video memory
#define MAX_ROWS 25           // Number of rows in video display
#define MAX_COLS 80           // Number of columns in video display
#define WHITE_ON_BLACK 0x0f   // Default text color

// Port addresses for screen control
#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5

/**
 * Prints a character at a specified location on the screen or at the cursor's current position.
 * If the attribute byte is zero, the default style (white on black) is assumed.
 *
 * @param character The character to print.
 * @param col Column to print the character at, or -1 to use the current cursor position.
 * @param row Row to print the character at, or -1 to use the current cursor position.
 * @param attribute_byte The attribute byte (color) to use.
 */
void print_char(char character, int col, int row, char attribute_byte);

/**
 * Calculates the memory offset for the specified column and row.
 *
 * @param col The column number.
 * @param row The row number.
 * @return The calculated offset.
 */
int get_screen_offset(int col, int row);

/**
 * Retrieves the current cursor position from the video hardware.
 *
 * @return The offset of the cursor within video memory.
 */
int get_cursor(void);

/**
 * Sets the cursor's position on the screen.
 *
 * @param offset The offset in video memory where the cursor should be placed.
 */
void set_cursor(int offset);

#endif // SCREEN_DRIVER_H
