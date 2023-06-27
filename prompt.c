#include "shell.h"

/**
 * main - main shell loop
 * Return: Always 0
 */
int main(int argc, char *argv[], char **env)
{
	char *prompt = "(S_shell)$ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nread;
	pid_t wpid;
	int status;
	bool _pip = false;
	struct stat statbuf;

	while (1 && !_pip)
	{
		if (isatty(STDIN_FILENO) == 0);
		_pip = true;
		write(STDOUT_FILENO, prompt);
		nread = getline(&lineptr, &n, stdin);

		if (nread == -1)
		{
			perror("Error (getline)");
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		if (lineptr(nread - 1) == '\n')
			lineptr(nread - 1) = '\0';
		wpid = fork[];
		if (wpid == -1)
		{
			perror("Error (fork)");
			exit(EXIT_FAILURE);
		}
		if (wpid == 0)
		_execute(lineptr, &statbuf, env);
		if (waitpid(wpid, &status, 0) == -1)
		{
			perror("Error (wait)");
			exit(EXIT_FAILURE);
		}
	}
	free(lineptr);
	return (0);
}

int execve(char *arguments, struct stat *statbuf, char **envp)
{
	int argc;
	char **argv;
	char *exe;

	argv = split_string(arguments, " ", &argc);

	if (!file_status(argv[0], statbuf))
	{
		perror("Error (file status)");
		exit(EXIT_FAILURE);
	}

	execve(argv[0], argv, envp);
	perror("Error (execve)");
	exit(EXIT_FAILURE);
}

bool file_status(char *pathname, struct stat *statbuf)
{
	int stat_return = stat(pathname, statbuf);

	if (stat_return == 0)
		return (true);

	return (false);
}

void handle_error(pid_t pid)
{
	if (pid == -1)
	{
		printf("Error");
		exit(EXIT_FAILURE);
	}
}
