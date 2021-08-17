#include "lib/stdio.h"

extern "C" void kmain(void) {
	stdio_init();
	print("Hello");
}