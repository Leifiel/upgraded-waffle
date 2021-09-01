#include <stdlib.h>
#include "my.h"

int my_strncmp(const char *string, const char *compare, size_t limit)
{
	if (string == NULL || compare == NULL)
		return (-1);
	for (size_t i = 0; string[i] != '\0' && i < limit; i++)
		if (string[i] != compare[i])
			return (-1);
	return (0);
}
