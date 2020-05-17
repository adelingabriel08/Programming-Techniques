#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void _printf(const char *format, ...)
{
    va_list valist;
    va_start(valist, format);

    for (int i = 0; i <= strlen(format); i++)
    {
        if (format[i] == '%')
        {

            switch (format[i + 1])
            {
            case 'd':
            {
                printf("%d", va_arg(valist, int));
                i++;
                break;
            }
            case 's':
            {
                fputs(va_arg(valist, char *), stdout);
                i++;
                break;
            }
            case 'c':
            {
                putchar(va_arg(valist, int));
                i++;
                break;
            }

            case 'p':
            {

                printf("%p", va_arg(valist, void *));
                i++;
                break;
            }

            case 'f':
            {
                printf("%f", va_arg(valist, double));
                i++;
                break;
            }

            case 'u':
            {
                printf("%u ", va_arg(valist, unsigned int));
                i++;
                break;
            }

            case 'x':
            {
                printf("%x", va_arg(valist, int));
                i++;
                break;
            }

            switch (format[i + 1])
            {
            case 'l':
            {
                if (format[i + 2] == 'l')
                {
                    if (format[i + 3] == 'd')
                        printf("%lld", va_arg(valist, long long int));
                    if (format[i + 3] == 'u')
                        printf("%lld", va_arg(valist, long long unsigned));

                    i = i + 3;
                }

                else
                {
                    if (format[i + 2] == 'd')
                        printf("%ld", va_arg(valist, long int));
                    if (format[i + 2] == 'u')
                        printf("%ld", va_arg(valist, long unsigned));
                    i = i + 2;
                }
                break;
            }
            }
            }
        }
        else
            putchar(format[i]);
    }

    va_end(valist);
}

int main(void)
{
    _printf("%d %u %f %x \n A Random String Here\n %s %p\n", 2.983, 3, 3, 6, "Hey, im a string :)", "Hey, im a string too :)");
    return 0;
}
