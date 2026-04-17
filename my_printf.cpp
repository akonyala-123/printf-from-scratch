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

void my_print_int(int n) {
    if (n < 0) {
        my_putchar('-');
        n = -n; 
    }
    if (n == 0) {
        my_putchar('0');
        return; 
    }

    char buf[20];
    int i = 0; 
    while (n > 0) {
        buf[i] = '0' + (n % 10);
        i++; 
        n /= 10;  
    }
    for (int j = i - 1; j >= 0; j--) {
        my_putchar(buf[j]);
    }
}

void my_printf(const char* fmt, ...) {
    va_list args;           
    va_start(args, fmt);   
    while (*fmt) {
        if (*fmt == '%') {
            fmt++; 
            switch (*fmt) {
                case 'd':
                    my_print_int(va_arg(args, int));
                    break; 
                case 's': 
                    my_putstr(va_arg(args, char*)); 
                    break; 
                /*
                case 'x':
                    my_print_hex(va_arg(args, unsigned int));
                    break; 
                */
                case 'c': 
                    my_putchar((char) va_arg(args, int));
                    break; 
            }
        } else { 
            my_putchar(*fmt);
        }
        fmt++; 
    } 
}

int main() {
    my_printf("Hello, world!\n");
    my_printf("Number: %d\n", 42);
    my_printf("Hex: %x\n", 255);
    my_printf("String: %s\n", "systems");
    my_printf("Char: %c\n", 'A');
    return 0;
}