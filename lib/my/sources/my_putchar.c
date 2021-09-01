#include <unistd.h>
#include "my.h"

int	my_putchar(char c)
{
	return (write(1, &c, 1));
}
