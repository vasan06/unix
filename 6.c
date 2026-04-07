#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int pid = fork();

    if(pid == 0)   
    {
        kill(getppid(), SIGKILL);  
        printf("Signal sent to parent\n");
    }
    else          
    {
        while(1)
        {
            printf("Parent running\n");
            sleep(1);
        }
    }

    return 0;
}
