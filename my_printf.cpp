#include <unistd.h> //unix standard for write() 
#include <stdarg.h> //argument list for va_list, va_start, va_arg, va_end

void my_putchar(char c) {
    write(1, &c, 1); //First argument 1 is file descriptor -> Write to terminal 
}

void my_putstr(const char* s) {
    while (*s) {
        my_putchar(*s);
        s++; 
    }
}

void my_printf(const char* fmt, ...) {
    //TODO
}

int main() {
    my_printf("Hello, world!\n");
    my_printf("Number: %d\n", 42);
    my_printf("Hex: %x\n", 255);
    my_printf("String: %s\n", "systems");
    my_printf("Char: %c\n", 'A');
    return 0;
}