#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/*prototypes for my funcs and _putchar*/
int _putchar(char c);
int _printf(const char *format, ...);

/**
 * struct printer - format specifier to function mapping
 * @type: format specifier character (e.g. 'c', 's', 'd')
 * @f: pointer to function that handles the specifier
 */
typedef struct printer
{
    char symbol;
    int (*f)(va_list args);
} printer_t;

int print_char(va_list args);
int print_str(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
#endif
