#pragma once

int env_update_entry(char **ev, const char *name, const char *val);
char **env_set(char **ev, const char *name, const char *val);
char **env_unset(char **ev, const char *name);
char **env_init(char *ev[]);
int env_print(char **ev);
