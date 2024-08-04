#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 

int main() {
    pid_t pid = fork();

    if (pid > 0) {
       
        printf("Parent process, PID: %d\n", getpid());
        sleep(10); 
    } else if (pid == 0) {
       
        printf("Child process, PID: %d\n", getpid());
        printf("Child process exiting\n");
        exit(0); 
    } else {
      
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
