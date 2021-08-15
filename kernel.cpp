#include "lib/terminal.h"

extern "C" void kmain(void) {
	term_init();
	print("Hello");
}