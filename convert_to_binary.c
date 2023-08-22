#include "main.h"
#include <stdarg.h>
#include <unistd.h>


int _printf(const char *format, ...);
int print_binary(unsigned int num);
// Other function prototypes

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
            switch (*format)
            {
                
                case 'b':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    printed += print_binary(num);
                    break;
                }
                default:
                    write(1, format, 1);
                    printed++;
            }
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

int print_binary(unsigned int num)
{
    char binary_str[33]; // 32 bits + '\0'
    int binary_len = 0;
    
    if (num == 0)
    {
        binary_str[binary_len++] = '0';
    }
    else
    {
        while (num > 0)
        {
            binary_str[binary_len++] = (num % 2) + '0';
            num /= 2;
        }
        reverse_string(binary_str, binary_len);
    }
    
    write(1, binary_str, binary_len);
    return binary_len;
}
