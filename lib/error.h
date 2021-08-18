void panic(const char* error) {
	stdio_color(vga_entry_color(RED, BLACK));
	column = row = 0;
	clear();
	print("####    #   #   # #  ###  #");
	newline();
	print("#   #  # #  ##  # # #   # #");
	newline();
	print("####  ##### # # # # #     #");
	newline();
	print("#     #   # #  ## # #   # ");
	newline();
	print("#     #   # #   # #  ###  #");
	newline();
	newline();
	print("Panic Message: ");
	print(error);
	// will add ram dumping later
	for (;;);
}