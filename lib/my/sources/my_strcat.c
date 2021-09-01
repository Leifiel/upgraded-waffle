#include <stdlib.h>

int my_strcat(char *dest, const char *src)
{
	int x = 0;

	if (dest == NULL || src == NULL)
		return (-1);
	for (; dest[x] != '\0'; x++);
	for (int i = 0; src[i] != '\0'; i++, x++)
		dest[x] = src[i];
	dest[x] = '\0';
	return (0);
}
