#include <stdlib.h>
#include <utils.h>
#include "env.h"
#include "my.h"

int env_update_entry(char **ev, const char *name, const char *val)
{
	int i = 0;
	char *new_val = NULL;

	if (ev == NULL || name == NULL || val == NULL)
		return (-1);
	i = env_get_entry_pos(ev, name);
	if (i == -1)
		return (-1);
	new_val = malloc(sizeof(char) * (my_strlen(name) + my_strlen(val) + 2));
	if (new_val != NULL) {
		my_strcpy(new_val, name);
		my_strcat(new_val, "=");
		my_strcat(new_val, val);
	}
	free(ev[i]);
	ev[i] = new_val;
	return (0);
}

char **env_add_entry(char **ev, const char *entry)
{
	char **new_env = NULL;

	if (entry == NULL)
		return (NULL);
	if (ev == NULL)
		new_env = malloc(sizeof(char*) * 2);
	else
		new_env = malloc(sizeof(char*) * (env_get_size(ev) + 2));
	if (env_get_size(ev) == 1)
		new_env[0] = my_strdup(entry);
	else {
		for (int i = 0; ev[i] != NULL; i++)
			new_env[i] = my_strdup(ev[i]);
		new_env[env_get_size(ev)] = my_strdup(entry);
		new_env[env_get_size(ev) + 1] = NULL;
		for (int i = 0; ev[i] != NULL; i++)
			free(ev[i]);
		free(ev);
	}
	return (new_env);
}

char *env_create_entry(const char *name, const char *value)
{
	size_t name_len = 0;
	size_t value_len = 0;
	char *env_val = NULL;

	if (name == NULL || value == NULL)
		return (NULL);
	name_len = (size_t) my_strlen(name);
	value_len = (size_t) my_strlen(value);
	if (name_len == 0 || value_len == 0)
		return (NULL);
	env_val = malloc(sizeof(char) * (name_len + value_len) + 2);
	for (size_t i = 0; i < (name_len + value_len + 2); i++)
		env_val[i] = 0;
	if (my_strcat(env_val, name) == -1)
		return (NULL);
	if (my_strcat(env_val, "=") == -1)
		return (NULL);
	if (my_strcat(env_val, value) == -1)
		return (NULL);
	return (env_val);
}

char **env_set(char **ev, const char *name, const char *val)
{
	int pos = 0;

	if (ev == NULL || name == NULL || val == NULL)
		return (NULL);
	pos = env_get_entry_pos(ev, name);
	if (pos == -2) {
		ev = env_add_entry(ev, env_create_entry(name, val));
		return (ev);
	} else if (pos != -1) {
		if (env_update_entry(ev, name, val) != 0)
			return (NULL);
		return (ev);
	} else
		return (NULL);
}

char **env_unset(char **ev, const char *name)
{
	int pos = 0;
	int x = 0;
	int y = 0;
	char **new_env = NULL;

	if (ev == NULL || name == NULL)
		return (NULL);
	pos = env_get_entry_pos(ev, name);
	if (pos == -1)
		return (NULL);
	if (pos == -2)
		return (ev);
	new_env = malloc(sizeof(char *) * (env_get_size(ev) + 1));
	if (new_env == NULL)
		return (NULL);
	for (; ev[x] != NULL; x++)
		if (my_strncmp(ev[x], name, (size_t) my_strlen(name)) != 0) {
			new_env[y] = my_strdup(ev[x]);
			y++;
		}
	new_env[y] = NULL;
	return (new_env);
}

