#include "my.h"

int my_get_nbr(char *nbr)
{
	int n = 1;
	int i = my_strlen(nbr) - 1;;
	int res = 0;

	while (i >= 0) {
		res = res + (n * (nbr[i] - '0'));
		n = n * 10;
		i--;
	}
	return (res);
}
