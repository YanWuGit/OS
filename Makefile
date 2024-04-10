all: os-image.img 

os-image.img: bootloader/build/main.bin os/build/kernel.bin
	cat $^ > $@
	truncate -s 1440k $@

os/build/kernel.bin: os/build/kernel.o
	ld -o $@ -Ttext 0x1000 os/build/kernel.o --oformat binary

os/build/kernel.o: os/src/kernel.c
	cc -ffreestanding -c os/src/kernel.c -o $@

clean:
	rm -fr *.img os/build/*.bin os/build/*.o