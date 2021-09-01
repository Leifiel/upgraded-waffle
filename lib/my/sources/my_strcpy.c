#include <stdlib.h>

int my_strcpy(char *dest, const char *src)
{
	int x = 0;

	if (dest == NULL || src == NULL)
		return (-1);
	for (; src[x] != '\0'; x++)
		dest[x] = src[x];
	dest[x] = '\0';
	return (0);
}
