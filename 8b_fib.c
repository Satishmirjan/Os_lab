//using shm_open and mmap
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

//child.c

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
         int k=2,n1,n2,n3;
         void*ptr;
         int shm_fd = shm_open("VSS", O_CREAT | O_RDWR, 0666);
         ftruncate(shm_fd,4096);
         ptr = mmap(0,4096,PROT_WRITE, MAP_SHARED, shm_fd, 0);
         printf("CHILD:\n");
         int i=atoi(argv[1]);
         n1=0;
         n2=1;
         sprintf(ptr,"%d ",n1);
         ptr+=strlen(ptr);
         printf("%d ",n1);
         sprintf(ptr,"%d ",n2);
         ptr+=strlen(ptr);
         printf("%d ",n2);
         while (k!=i)
         {
                n3=n1+n2;
                sprintf(ptr,"%d ", n3);
                printf("%d ", n3);
                n1=n2;
                n2=n3;
                ptr += strlen(ptr);
                k++;
	}
}
	

Output:
$ gcc parent.c -lrt
$ gcc child.c -o fib -lrt
$ ./a.out 5
CHILD:
0 1 1 2 3
PARENT: child completed
Parent printing:
0 1 1 2 3

