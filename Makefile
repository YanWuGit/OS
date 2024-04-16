all: os-image.img

os-image.img: bootloader/build/main.bin os/build/kernel.bin
	cat $^ > $@
	truncate -s 1440k $@

os/build/kernel.bin: os/build/kernel.o os/build/screen_driver.o
	ld -o $@ -Ttext 0x1000 $^ --oformat binary

os/build/kernel.o: os/src/kernel.c os/src/screen_driver.h
	cc -ffreestanding -c os/src/kernel.c -o $@

os/build/screen_driver.o: os/src/screen_driver.c os/src/screen_driver.h
	cc -ffreestanding -c os/src/screen_driver.c -o $@

clean:
	rm -fr *.img os/build/*.bin os/build/*.o
