#include "exec.h"
#include <fcntl.h>
#include <wait.h>
#include <zconf.h>
#include <stack.h>
#include <stdlib.h>

static int get_status(pid_t pid, int *status)
{
	pid_t w = waitpid(pid, status, WUNTRACED | WCONTINUED);
	if (w == -1)
		return (-1);
	if (WIFEXITED(*status))
		return (WEXITSTATUS(*status));
	if (WIFSIGNALED(*status))
		return (WTERMSIG(*status));
	if (WIFSTOPPED(*status))
		return (WSTOPSIG(*status));
	if (WIFCONTINUED(*status))
		return (WSTOPSIG(*status));
	return (ERROR);
}

static int execp(char **cmd[], char *ev[], pipe_t pipe, int pid)
{
	if (pid != 0)
		return (1);
	dup2(pipe.stdin, 0);
	if (cmd[pipe.index + 1] != NULL)
		dup2(pipe.canal[1], 1);
	close(pipe.canal[0]);
	if (execve(*cmd[pipe.index], cmd[pipe.index], ev) == -1)
		return (ERROR);
	return (SUCCESS);
}

int exec_pipes(char **cmd[], char *ev[], int *sig)
{
	int ret = 0;
	pid_t pid = 0;
	int signo = 0;
	pipe_t pipes = {0, 0, {0, 0}};

	while (cmd[pipes.index] != NULL) {
		pipe(pipes.canal);
		pid = fork();
		if (pid == -1)
			return (84);
		ret = execp(cmd, ev, pipes, pid);
		if (ret == 1) {
			close(pipes.canal[1]);
			pipes.stdin = pipes.canal[0];
			pipes.index++;
		} else if (ret == ERROR)
			return (ERROR);
	}
	*sig = get_status(pid, &signo);
	return (SUCCESS);
}

int flush_commands(STACK **command_stack, char *env[], int *sig)
{
	int i = 0;
	int size = 0;
	char ***cmd = NULL;

	if (command_stack == NULL)
		return (-1);
	size = stack.size(*command_stack);
	cmd = malloc(sizeof(char**) * (stack.size(*command_stack) + 1 ));
	if (cmd == NULL)
		return (-1);
	for (; i < size; i++)
		cmd[i] = stack.pop(command_stack)->command;
	cmd[i] = NULL;
	exec_pipes(cmd, env, sig);
	return (0);
}
