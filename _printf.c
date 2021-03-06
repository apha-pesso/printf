#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - return the argument character
 * @c: input character
 * Return: char
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - print the string given
 * @format: string to be printed
 * @i: i is an integer
 * @j: j is an integer
 * @k: k is an integer
 * @dest: pointer
 * @s: pointer
 * Return: Always 0 (success)
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, j = 0, k = 0;
	char *dest;
	char *s;

	dest = malloc(sizeof(char) * 1500);

	va_start(ap, format);

	if (format == NULL)
		return (j);

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
			else if (format[i] == 's')
			{
				s = va_arg(ap, char*);
				if (s  == NULL)
				{
					s = "(null)";
				}
				k = 0;
				while (s[k])
				{
					dest[j] = s[k];
					j++;
					k++;
				}
			}
			else if (format[i] == '\0')
				return (-1);
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
	return (--j);
}
