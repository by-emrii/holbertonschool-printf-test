#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, j;
    int count = 0;

    printer_t types[] = {
        {'c', print_char},
        {'s', print_str},
        {'d', print_int},
        {'i', print_int},
        {'%', print_percent},
        {0, NULL} //end of array
    };

    if (!format) //check if format str == null
        return (-1); //return error

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++; //move to specifier character

            j = 0; //check from start of types array
            while (types[j].symbol)
            {
                if (types[j].symbol == format[i])
                {
                    count += types[j].f(args); //call function and add num of characters that fx printed to total count
                    break; //found match so stop checking for specifiers
                }
                j++;
            }
            
            if (types[j].symbol == 0) //no matching specifer found
            {
                count += _putchar('%'); //print literally
                count += _putchar(format[i]); //print the unknown specifier
            }
        }

        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }
    va_end(args);
    return (count); //return total number of characters printed
}
