#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        
        printf("Parent process, PID: %d\n", getpid());
        printf("Parent process exiting\n");
        exit(0); 
    } else if (pid == 0) {
        sleep(5);
        printf("Child process, PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
