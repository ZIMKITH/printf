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
            if (*format == 'd')
            {
                int num = va_arg(args, int);
                printed += print_int(num);
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                printed += print_string(str);
            }
            else if (*format == 'u' || *format == 'o' ||
                     *format == 'x' || *format == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                printed += print_unsigned(num, *format);
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

int print_int(int num)
{
    char num_str[20];
    int num_len = 0;
    if (num == 0)
    {
        num_str[num_len++] = '0';
    }
    else
    {
        if (num < 0)
        {
            write(1, "-", 1);
            num = -num;
        }
        while (num > 0)
        {
            num_str[num_len++] = '0' + (num % 10);
            num /= 10;
        }
        reverse_string(num_str, num_len);
    }
    write(1, num_str, num_len);
    return num_len;
}

int print_string(char *str)
{
    int str_len = 0;
    while (str[str_len] != '\0')
        str_len++;
    write(1, str, str_len);
    return str_len;
}

int print_unsigned(unsigned int num, char format)
{
    char num_str[20];
    int num_len = 0;
    while (num > 0)
    {
        int digit = num % 16;
        num_str[num_len++] = (digit < 10) ? ('0' + digit) : ((format == 'x') ? ('a' + digit - 10) : ('A' + digit - 10));
        num /= 16;
    }
    if (num_len == 0)
    {
        num_str[num_len++] = '0';
    }
    reverse_string(num_str, num_len);
    write(1, num_str, num_len);
    return num_len;
}

void reverse_string(char *str, int length)
{
    int left = 0;
    int right = length - 1;
    while (left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}
