# Makefile for Linux Command Mimic Program
CC = gcc
CFLAGS = -Wall -Werror
TARGET = minimal_kernel

SRC = minimal_kernel.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
