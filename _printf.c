#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - implementation of the inbuilt printf
 * @format: the format specifier
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    int printed = 0;

    va_list args;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            (format, args, printed);
            format++;
        }
        else
        {
            write(1, format, 1);
            printed++;
            format++;
        }
    }

    va_end(args);
    return printed;
}
