#include <utils.h>
#include <stddef.h>
#include <my.h>
#include <stack.h>
#include <exec.h>
#include <stdio.h>
#include <stdlib.h>
#include <command.h>
#include <builtins.h>
#include <env.h>

char **get_command(char *line, char *env[])
{
	char **arr = NULL;

	arr = my_str_to_arr(line, ' ');
	if (arr == NULL)
		return (0);
	arr[0] = get_full_command(arr[0], env);
	return (arr);
}

int built_switch(int instruction, char **ev[], const char *line)
{
	char **arr = my_str_to_arr(line, ' ');

	switch (instruction) {
	case 0:
		builtin_cd(*ev, arr[1]);
		break;
	case 1:
		*ev = env_set(*ev, arr[1], arr[2]);
		break;
	case 2:
		*ev = env_unset(*ev, arr[1]);
		break;
	case 3:
		env_print(*ev);
		break;
	case 4:
		exit (0);
	default:break;
	}
	return (true);
}

int is_builtin(char **ev[], const char *line)
{
	char **arr = NULL;
	char *builtins[] = {"cd", "setenv", "unsetenv", "env", "exit", NULL};

	if (line == NULL)
		return (false);
	arr = my_str_to_arr(line, ' ');
	if (arr == NULL)
		return (false);
	for (int i = 0; arr[i] != NULL; i++)
		arr[i] = clean(arr[i]);
	for (int i = 0; builtins[i] != NULL; i++)
		if (my_strncmp(builtins[i], arr[0], \
(size_t) my_strlen(builtins[i])) == 0) {
			built_switch(i, ev, line);
			return (true);
		}
	return (false);
}

int parse_pipe(const char *line, char **env[], int *sig)
{
	char **arr = NULL;
	int ret = 0;
	STACK *command = NULL;

	arr = my_str_to_arr(line, '|');
	for (int i = 0; arr[i] != NULL; i++) {
		arr[i] = clean(arr[i]);
		ret = is_builtin(env, arr[i]);
		if (!ret) {
			if (i == 0)
				command = stack.create(\
get_command(arr[i], *env));
			else
				command = stack.push(command,\
get_command(arr[i], *env));
		} else
			return (ret);
	}
	flush_commands(&command, *env, sig);
}

int parser(const char *line, char **env[])
{
	char **arr = NULL;
	int sig = 0;

	if (line == NULL)
		return (-1);
	if (contain(line, ';')) {
		arr = my_str_to_arr(line, ';');
		for (int i = 0; arr[i] != NULL; i++) {
			arr[i] = clean(arr[i]);
			if (parse_pipe(arr[i], env, &sig) == EXIT)
				return (EXIT);
		}
	}
	else
		if (parse_pipe(line, env, &sig) == EXIT)
			return (EXIT);
	return (0);
}
