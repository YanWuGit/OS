#!/bin/bash

cat bootloader/build/main.bin os/build/kernel.bin > os-image.img
truncate -s 1440k os-image.img