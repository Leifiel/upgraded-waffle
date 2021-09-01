#include <stdlib.h>
#include "my.h"

char *my_strdup(const char *string)
{
	int len = 0;
	char *new_string = NULL;

	if (string == NULL)
		return (NULL);
	len = my_strlen(string);
	new_string = malloc(sizeof(char) * (len + 1));
	if (new_string == NULL)
		return (NULL);
	if (my_strcpy(new_string, string) != 0)
		return (NULL);
	return (new_string);
}
