#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
    pid_t pid, sid;
    // Fork parent process
    pid = fork();
    if (pid < 0)
    {
        exit(EXIT_FAILURE);
    }
    if (pid > 0)
    {
        exit(EXIT_SUCCESS);
    }
    sid = setsid();
    if (sid < 0)
    {
        exit(EXIT_FAILURE);
    }
  /* Close out the standard file descriptors */
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
    char *args[] = {"./my_daemon", "arg1", NULL};
    execvp(args[0], args);
}
