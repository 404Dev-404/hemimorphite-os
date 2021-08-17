# Hemimorphite OS
An i386 compatible OS which I stole some of the code from [wiki.osdev.org](wiki.osdev.org "wiki.osdev.org").
## How to Compile
``` 
i686-elf-as boot.s -o boot.o
i686-elf-g++ -c kernel.cpp -o kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
i686-elf-g++ -T linker.ld -o (filename).bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc
```
## How to prepare for GRUB
¯\\\_(ツ)\_/¯