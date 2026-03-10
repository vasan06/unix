#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int pid = fork();

    if(pid == 0)  
    {
        while(1)
        {
            printf("Child running...\n");
            sleep(1);
        }
    }
    else           
    {
        sleep(5);
        kill(pid, SIGSTOP);   
        printf("Child suspended\n");

        sleep(5);
        kill(pid, SIGCONT);   
        printf("Child resumed\n");

        sleep(5);
        kill(pid, SIGKILL);  
    }

    return 0;
}
