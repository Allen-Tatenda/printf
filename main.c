#include <limits.h>
#include <stdio.h>
#include "main.h"

/**

_printf - function that produces output according to a format.
@format: a string with format specifiers
Return: the number of characters printed.
*/
int _printf(const char *format, ...) { va_list args; int i = 0, count = 0, formatCount = 0; char str; char string[1024]; if (format == NULL) return (-1); va_start(args, format); while (format[i] != '\0') { if (format[i] == '%') { formatCount = 1; switch (format[++i]) { case 'c': putchar(va_arg(args, int)); count++; break; case 's': str = va_arg(args, char); while (*str != '\0') { putchar(*str); count++; str++; } break; case 'd': case 'i': printf("%d", va_arg(args, int)); break; case '%': putchar('%'); count++; break; default: putchar('%'); putchar(format[i]); count += 2; break; } } else { putchar(format[i]); count++; } i++; } va_end(args); return (count);
}
