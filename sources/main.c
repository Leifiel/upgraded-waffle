#include <stddef.h>
#include <stdio.h>
#include <utils.h>
#include <parse.h>
#include <zconf.h>
#include <my.h>
#include <env.h>
#include <builtins.h>
#include <malloc.h>

void prompt(char *ev[])
{
	char buff[256];
	char *home = env_get_value(ev, "HOME");

	if (getcwd(buff, 256) == NULL || home == NULL)
		return;
	if (my_strncmp(buff, home, (size_t) my_strlen(home)))
		my_printf("[~]$ ");
	else
		my_printf("[%s]$ ", buff);
	free(home);
}
int main(int ac, char *av[], char *env[])
{
	char *line = NULL;
	int ret = 0;
	char **new_env = env_init(env);
	size_t len = 0;

	if (new_env == NULL)
		return (84);
	if (isatty(0))
		prompt(new_env);
	while (getline(&line, &len, stdin) != -1) {
		replace(line, '\n', '\0');
		ret = parser(line, &new_env);
		if (ret == -1)
			return (84);
		if (ret == EXIT)
			return (0);
		if (isatty(0))
			prompt(new_env);
	}
	return (0);
}