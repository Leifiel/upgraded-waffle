#include <malloc.h>
#include <memory.h>
#include <stdlib.h>
#include <my.h>
#include "stack.h"

STACK *__stack__create(char **command)
{
	int i = 0;
	STACK *init = malloc(sizeof(STACK));

	if (init == NULL)
		return (NULL);
	for (; command[i] != NULL; i++);
	if (i == 0)
		return (NULL);
	init->command = malloc(sizeof(char *) * (i + 1));
	for (int x = 0; x < i; x++) {
		init->command[x] = my_strdup(command[x]);
		if (init->command[x] == NULL)
			return (NULL);
	}
	init->command[i] = NULL;
	init->next = NULL;
	return (init);
}

STACK  *__stack__push(STACK *stack, char **command)
{
	int i = 0;
	STACK *current = stack;

	if (current == NULL)
		return (__stack__create(command));
	while (current->next != NULL)
		current = current->next;
	for (; command[i] != NULL; i++);
	if (i == 0)
		return (NULL);
	current->next = malloc(sizeof(STACK));
	if (current->next == NULL)
		return (NULL);
	current->next->command = malloc(sizeof(char *) * (i + 1));
	for (int x = 0; x < i; x++) {
		current->next->command[x] = my_strdup(command[x]);
		if (current->next->command[x] == NULL)
			return (NULL);
	}
	current->next->command[i] = NULL;
	current->next->next = NULL;
	return (stack);
}

STACK *__stack__pop(STACK **stack)
{
	STACK *temp = *stack;

	if (temp) {
		*stack = temp->next;
		temp->next = NULL;
	}
	return (temp);
}

int __stack__size(STACK *stack)
{
	int size = 1;
	STACK *current = stack;

	if (current == NULL)
		return (0);
	if (current->next == NULL)
		return (1);
	else
		while (current->next != NULL) {
			current = current->next;
			size++;
		}
	return (size);
}
