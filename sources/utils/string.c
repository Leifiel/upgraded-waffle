#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

int replace(char *string, char from, char to)
{
	int i = 0;

	if (string == NULL || from == 0)
		return (-1);
	for (; string[i] != '\n'; i++);
	if (string[i] == from)
		string[i] = to;
	else
		return (-1);
	return (0);
}

bool contain(const char *string, char c)
{
	while (*string++)
		if (*string == c)
			return (true);
	return (false);
}

bool is_space(unsigned char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

char *clean(char *string)
{
	int i = 0;
	char *end = NULL;

	if (string == NULL)
		return (NULL);
	while (is_space((unsigned char)string[i]))
		string++;
	end = string + my_strlen(string) - 1;
	while (end > string && is_space((unsigned char)*end))
		end--;
	*(end+1) = 0;
	return (string);
}

char *concat(const char *string, const char *with)
{
	char *end = NULL;

	if (string == NULL || with == NULL)
		return (NULL);
	end = malloc(sizeof(char) * (my_strlen(string) + my_strlen(with) + 1));
	for (int i = 0; i < my_strlen(string) + my_strlen(with) + 1; i++)
		end[i] = 0;
	if (my_strcat(end, string) != 0 || my_strcat(end, with) != 0)
		return (NULL);
	return (end);
}
