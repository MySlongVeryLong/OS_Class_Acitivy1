#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child process running ls:\n");
        execlp("ls", "ls","-la", NULL);

        // Only runs if exec fails
        perror("exec failed");
    }
    else
    {
        // Parent process
        wait(NULL);
        printf("Parent process finished.\n");
    }

    return 0;
}
