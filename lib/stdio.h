#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

enum vga {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GREY = 7,
	DARK_GREY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	LIGHT_BROWN = 14,
	WHITE = 15,
};

static inline uint8_t vga_entry_color(enum vga fg, enum vga bg) {
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t c) {
	return (uint16_t) uc | (uint16_t) c << 8;
}

size_t strlen(const char* str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t row;
size_t column;
uint8_t color;
uint16_t* buffer;

void stdio_init(void) {
	column = row = 0;
	color = vga_entry_color(WHITE, BLUE);
	buffer = (uint16_t*)0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH +x;
			buffer[index] = vga_entry(' ', color);
		}
	}
}

void stdio_color(uint8_t c) {
	color = c;
}

void putat(char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	buffer[index] = vga_entry(c, color);
}

void putchar(char c) {
	putat(c, color, column, row);
	if (++column == VGA_WIDTH) {
		column = 0;
		if (++row == VGA_HEIGHT)
			row = 0;
	}
}

void write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
			putchar(data[i]);
}

void print(const char* data) {
	write(data, strlen(data));
}