#include <stdlib.h>
#include "utils.h"
#include "my.h"

size_t env_get_size(char *ev[])
{
	size_t size = 0;

	for (; ev[size] != NULL; size++);
	return (size);
}

int env_get_entry_pos(char **ev, const char *name)
{
	size_t pos = 0;
	size_t name_len = 0;

	if (ev == NULL || name == NULL)
		return (-1);
	name_len = (size_t) my_strlen(name);
	if (name_len <= 0)
		return (-1);
	for (; ev[pos] != NULL; pos++)
		if (my_strncmp(ev[pos], name, name_len) == 0)
			break;
	if (pos == env_get_size(ev))
		return (-2);
	return (int) (pos);
}

char *env_get_value(char **ev, const char *name)
{
	int position = 0;
	char **arr = NULL;

	if (ev == NULL || name == NULL)
		return (NULL);
	position = env_get_entry_pos(ev, name);
	if (position == -1 || position == -2 || position < 0)
		return (NULL);
	arr = my_str_to_arr(ev[position], '=');
	if (arr == NULL)
		return (NULL);
	return (arr[1]);
}

int env_print(char **ev)
{
	if (ev != NULL) {
		for (int i = 0; ev[i] != NULL; i++)
			my_printf("%s\n", ev[i]);
	} else
		return (-1);
	return (0);
}