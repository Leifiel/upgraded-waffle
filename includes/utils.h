#pragma once

#include <glob.h>
#include <stdbool.h>

size_t env_get_size(char *ev[]);
char *env_get_value(char **ev, const char *name);
int env_get_entry_pos(char **ev, const char *name);
int replace(char *string, char from, char to);
bool contain(const char *string, char c);
bool is_space(unsigned char c);
char *clean(char *string);
char *concat(const char *string, const char *with);