#pragma once

typedef struct stack_s {
	char **command;
	struct stack_s *next;
} STACK;

extern STACK *__stack__create(char **command);
extern STACK *__stack__push(STACK *stack, char **command);
extern STACK *__stack__pop(STACK **stack);
extern int __stack__size(STACK *stack);

static const struct {
	STACK *(*create)(char **command);
	STACK *(*push)(STACK *stack, char **command);
	STACK *(*pop)(STACK **stack);
	int (*size)(STACK *stack);
} stack = {
	__stack__create,
	__stack__push,
	__stack__pop,
	__stack__size
};