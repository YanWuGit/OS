#include "screen_driver.h"
#include <string.h>

void outb(unsigned short port, unsigned char val);
unsigned char inb(unsigned short port);

/* Print a char on the screen at col, row, or at cursor position */
void print_char(char character, int col, int row, char attribute_byte)
{
    unsigned char *vidmem = (unsigned char *)VIDEO_ADDRESS;
    if (!attribute_byte)
    {
        attribute_byte = WHITE_ON_BLACK;
    }

    int offset;
    if (col >= 0 && row >= 0)
    {
        offset = get_screen_offset(col, row);
    }
    else
    {
        offset = get_cursor();
    }

    if (character == '\n')
    {
        int rows = offset / (2 * MAX_COLS);
        offset = get_screen_offset(79, rows);
    }
    else
    {
        vidmem[offset] = character;
        vidmem[offset + 1] = attribute_byte;
    }
    offset += 2;
    offset = 0;
    set_cursor(offset);
}

/* Calculates screen offset for a given column and row */
int get_screen_offset(int col, int row)
{
    return 2 * (row * MAX_COLS + col);
}

/* Retrieves the current cursor position */
int get_cursor(void)
{
    outb(REG_SCREEN_CTRL, 14);
    int offset = inb(REG_SCREEN_DATA) << 8;
    outb(REG_SCREEN_CTRL, 15);
    offset += inb(REG_SCREEN_DATA);
    return offset * 2;
}

/* Sets the cursor position */
void set_cursor(int offset)
{
    offset /= 2;
    outb(REG_SCREEN_CTRL, 14);
    outb(REG_SCREEN_DATA, (unsigned char)(offset >> 8));
    outb(REG_SCREEN_CTRL, 15);
    outb(REG_SCREEN_DATA, (unsigned char)(offset & 0xFF));
}


/* Output a byte to a port */
void outb(unsigned short port, unsigned char val)
{
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

/* Input a byte from a port */
unsigned char inb(unsigned short port)
{
    unsigned char ret;
    asm volatile("inb %1, %0"
                 : "=a"(ret)
                 : "Nd"(port));
    return ret;
}
