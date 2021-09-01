#include <stdlib.h>
#include "my.h"

int my_strcmp(const char *string, const char *compare)
{
	if (string == NULL || compare == NULL)
		return (-1);
	if (my_strlen(string) != my_strlen(compare))
		return (-1);
	for (int i = 0; string[i] != '\0'; i++)
		if (string[i] != compare[i])
			return (-1);
	return (0);
}
