#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list arg_list;
    int printed_chars = 0;

    va_start(arg_list, format);

    for (; *format != '\0'; format++) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    printed_chars += printf("%c", va_arg(arg_list, int));
                    break;
                case 's':
                    printed_chars += printf("%s", va_arg(arg_list, char *));
                    break;
                case '%':
                    printed_chars += printf("%%");
                    break;
            }
        } else {
            putchar(*format);
            printed_chars++;
        }
    }

    va_end(arg_list);

    return printed_chars;
}
