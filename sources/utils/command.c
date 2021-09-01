#include <sys/stat.h>
#include <utils.h>
#include <stddef.h>
#include <my.h>
#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

char *get_full_command(char *line, char *env[])
{
	struct stat s;
	char *path = env_get_value(env, "PATH");
	char *exe = NULL;
	char **arr = NULL;

	if (path == NULL)
		return (NULL);
	arr = my_str_to_arr(path, ':');
	if (arr == NULL)
		return (NULL);
	for (int i = 0; arr[i] != NULL; i++) {
		exe = concat(arr[i], "/");
		exe = concat(exe, line);
		if (lstat(exe, &s) == 0 && s.st_mode & S_IXUSR)
			return (exe);
		else
			continue;
	}
	exe = concat("./", line);
	if (lstat(exe, &s) == 0 && s.st_mode & S_IXUSR)
		return (exe);
	return (NULL);
}
