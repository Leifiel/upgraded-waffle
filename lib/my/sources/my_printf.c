#include <stdarg.h>
#include <stdio.h>
#include <malloc.h>
#include "my.h"

int     f_val(char c)
{
	char *flags = "csSid";
	int flag_id = 0;

	if (c == '%')
		return (-2);
	while (flags[flag_id] != '\0') {
		if (flags[flag_id] == c)
			return (flag_id);
		flag_id++;
	}
	return (-1);
}

void	my_printf(char const *str, ...)
{
	void (*print[4])(void *);
	print[0] = (void *)&my_putchar;
	print[1] = (void *)&my_putstr;
	print[2] = (void *)&my_putstr_oct;
	print[3] = (void *)&my_put_nbr;
	print[4] = (void *)&my_put_nbr;

	int index = 0;
	va_list ap;
	va_start(ap, str);
	while (str[index] != '\0') {
		if (str[index] == '%' && f_val(str[index + 1]) == -2) {
			my_putchar(str[index + 1]);
			index++;
		} else if (str[index] == '%' && f_val(str[index + 1]) != -1) {
			print[f_val(str[index + 1])]((void*)va_arg(ap, void*));
			index++;
		} else
			my_putchar(str[index]);
		index++;
	}
	va_end(ap);
}
