#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int fd;
    char buffer[100];
    struct stat fileStat;

    int pid = fork();

    if(pid == 0)   // Child Process
    {
        printf("Child Process Executing ls command\n");
        execl("/bin/ls","ls","-l",NULL);
    }
    else           // Parent Process
    {
        fd = open("sample.txt", O_RDONLY);

        if(fd < 0)
        {
            printf("File cannot be opened\n");
            exit(1);
        }

        read(fd, buffer, sizeof(buffer));
        printf("\nFile Content:\n%s\n", buffer);

        close(fd);

        stat("sample.txt",&fileStat);

        printf("\nFile Size: %ld bytes\n", fileStat.st_size);
    }

    return 0;
}
