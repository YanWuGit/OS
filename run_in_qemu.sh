#!/bin/bash

qemu-system-x86_64 -drive file=build/main.bin,format=raw,index=0,if=floppy -nographic