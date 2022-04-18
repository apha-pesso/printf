#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"


int _putchar(char c)
{
	return (write(1, &c, 1));
}


int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, j = 0;
	char *dest;
	char *s;
	int k;


	dest = malloc(sizeof(char) * 1500);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				dest[j] = (char)va_arg(ap, int);
				j++;
			}
			else if (format[i] == '%')
			{

				dest[j] = format[i];
				j++;
			}
			else if(format[i] == 's')
			{
				s = va_arg(ap, char*);
				k = 0;
				while (s[k])
				{
					dest[j] = s[k];
					j++;
					k++;
				}
				j++;
			}
		}
		else
		{
			dest[j] = format[i];
			j++;
		}
		i++;
	}
	write(1, dest, j++);
	va_end(ap);
	free(dest);
	return (i);
}
