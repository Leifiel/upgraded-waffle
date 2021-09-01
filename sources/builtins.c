#include <builtins.h>
#include <stdio.h>
#include <stdbool.h>
#include <my.h>
#include <utils.h>
#include <zconf.h>

int builtin_cd(char *ev[], char *path)
{
	if (path != NULL) {
		path = clean(path);
		if (my_strcmp(path, "-") == 0)
			my_printf("last path\n");
		else
			chdir(path);
	} else
		chdir(env_get_value(ev, "HOME"));
	return (true);
}