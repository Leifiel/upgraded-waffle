#pragma once

#include "stack.h"

typedef struct pipe_s {
	int index;
	int stdin;
	int canal[2];
} pipe_t;


#define ERROR (-1)
#define SUCCESS 0

int exec_pipes(char **cmd[], char *ev[], int *sig);
int flush_commands(STACK **command_stack, char *env[], int *sig);
