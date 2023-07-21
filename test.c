#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[], char *envp[])
{
	pid_t pid;
	size_t i;
	char *arg[] = {"insertion", NULL};
	int status;

	(void) argc, (void) argv;
	for (i = 0; i < 10; i++)
	{
		pid = fork();
		if (pid)
			waitpid(pid, &status, 0);
		else
		{
			execve(arg[0], arg, envp);
		}

	}
	return 0;
}

