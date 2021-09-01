#include <stdlib.h>
#include <utils.h>
#include <exec.h>
#include "env.h"
#include "my.h"

int env_check(char *ev[])
{
	if (env_get_size(ev) == 0)
		return (ERROR);
	return (SUCCESS);
}

char **env_copy(char *ev[])
{
	size_t i = 0;
	size_t size = env_get_size(ev);
	int current_len = 0;
	char **new_env = malloc(sizeof(char*) * (size + 1));

	if (new_env == NULL)
		return (NULL);
	for (; i < size; i++) {
		current_len = my_strlen(ev[i]);
		if (current_len != 0)
			new_env[i] = my_strdup(ev[i]);
		else
			return (NULL);
	}
	new_env[i] = NULL;
	return (new_env);
}

char **env_init(char *ev[])
{
	char **new_env = NULL;

	if (env_check(ev) != SUCCESS)
		return (NULL);
	new_env = env_copy(ev);
	return (new_env);
}
