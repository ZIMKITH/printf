#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFF_SIZE 1024

typedef struct {
    bool left_justify;
    bool show_sign;
    bool space_for_positive;
    bool alternate_form;
    bool zero_padding;
} FormatFlags;

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    va_list args;
    va_start(args, format);

    char buffer[BUFF_SIZE];
    int buff_ind = 0;
    int printed_chars = 0;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
            {
                print_buffer(buffer, &buff_ind);
                printed_chars += buff_ind;
            }
        }
        else
        {
            FormatFlags flags = {false, false, false, false, false};
            
            int printed = handle_print(format, &i, args, buffer, &flags);
            if (printed == -1)
            {
                va_end(args);
                return -1;
            }
            printed_chars += printed;
        }
    }

    print_buffer(buffer, &buff_ind);
    printed_chars += buff_ind;

    va_end(args);
    return printed_chars;
}

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
        *buff_ind = 0;
    }
}
