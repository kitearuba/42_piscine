//
// Created by christian on 17/04/24.
//
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move to the next character to check the specifier
            switch (*format) {
                case 's': { // String
                    char *str = va_arg(args, char*);
                    printf("%s", str);
                    break;
                }
                case 'd': { // Integer
                    int i = va_arg(args, int);
                    printf("%d", i);
                    break;
                }
                case 'f': { // Double, use %lf for printf
                    double d = va_arg(args, double);
                    printf("%lf", d);
                    break;
                }
                default:
                    putchar('%');
                    putchar(*format); // Print the unknown specifier as is
            }
        } else {
            putchar(*format); // Print the current character
        }
        format++;
    }

    va_end(args);
}

int main() {
    my_printf("Hello, %s! You have %d apples and your score is %f.\n", "Alice", 5, 92.5);
    return 0;
}
