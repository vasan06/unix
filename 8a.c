//8a
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid = fork();

    if(pid > 0)   
    {
        printf("Parent exiting\n");
        exit(0);
    }
    else         
    {
        sleep(5);
        printf("Child becomes orphan\n");
    }

    return 0;
}


