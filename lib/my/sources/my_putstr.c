#include "my.h"

void	my_putstr(char const *str)
{
	while (*str)
		my_putchar(*str++);
}
