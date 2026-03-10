#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    int fd;
    char buffer[50];
    struct stat info;

    if (access("demo.txt", F_OK) == 0)
        printf("File exists\n");
    else
        printf("File does not exist\n");

    fd = open("demo.txt", O_CREAT | O_RDWR, 0644);

    write(fd, "Hello UNIX\n", 11);

    lseek(fd, 0, SEEK_SET);

    read(fd, buffer, 11);
    buffer[11] = '\0';

    printf("Data read: %s\n", buffer);

    stat("demo.txt", &info);
    printf("Last access time: %s", ctime(&info.st_atime));

    close(fd);
    return 0;
}
