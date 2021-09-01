#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int is_end(char car, char delim)
{
	if (car == delim || car == '\0')
		return (1);
	return (0);
}

char *get_word(int cur, const char *string, char delim)
{
	int i = 0;
	int len = 0;
	char *word = NULL;

	for (len = 0; is_end(string[cur + len], delim) != 1; len++);
	if (len < 0)
		return (NULL);
	word = malloc((sizeof(char) * len) + 1);
	for (int x = 0; x != len + 1; x++)
		word[x] = 0;
	if (word == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		word[i] = string[cur + i];
	word[i] = '\0';
	return (word);
}

char **my_str_to_arr(const char *string, char delim)
{
	int nb = 0;
	int pos = 0;
	char **arr = NULL;

	for (int i = 0; string[i] != '\0'; i++)
		if (string[i] != delim)
			nb++;
	arr = malloc(sizeof(char*) * (nb + 1));
	for (int i = 0; i < nb + 1; i++)
		arr[i] = 0;
	pos = 0;
	for (int i = 0; string[pos] != '\0'; i++) {
		arr[i] = get_word(pos, string, delim);
		pos += my_strlen(arr[i]);
		if (string[pos] == delim)
			pos++;
	}
	arr[nb] = NULL;
	return (arr);
}
