//parent.c
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
int main(int argc,char *argv[])
{
    int i;
    pid_t pid;
    int k;
    int n1,n2,n3;
    const int SIZE = 4096;
        int shm_fd;
    void *ptr;
    if (argc > 1)
    {
        sscanf(argv[1], "%d", &i);
        if (i < 1)
        {
            printf("Error input: %d\n", i);
            return 0;
        }
    }
    else
    {
      printf("Error: not passing N in command line\n");
      exit(0);
    }
    pid = fork();
    if (pid == 0)// CHILD
    {   
        execlp("./fib","fib",argv[1],NULL);
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("\nPARENT: child completed\n");

        shm_fd = shm_open("VSS", O_RDONLY, 0666);
        ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
        printf("Parent printing:\n");
        printf("%s ", (char *)ptr);
        shm_unlink("VSS");
    }
    return 0;
}
