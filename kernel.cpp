#include "lib/stdio.h"
#include "lib/error.h"

extern "C" void kmain(void) {
	stdio_init();
	print("test");
	panic("Panic Test");
}