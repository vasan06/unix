#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int pid = fork();

    if(pid == 0)   // Child process
    {
        kill(getppid(), SIGKILL);   // send signal to parent
        printf("Signal sent to parent\n");
    }
    else           // Parent process
    {
        while(1)
        {
            printf("Parent running\n");
            sleep(1);
        }
    }

    return 0;
}
