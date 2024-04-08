#!/bin/bash

cc -ffreestanding -c src/kernel.c -o build/kernel.o
ld -o build/kernel.bin -Ttext 0x1000 build/kernel.o --oformat binary