#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    
    printf("Program beginning.\n");
    
    int status; // Unsure what this argument to wait does!
    
    pid_t child_pid = fork();
    
    if (-1 == child_pid) {
        printf("There was an error when forking.\n");
    } else if (0 == child_pid) {
        printf("\nI am the child. My pid is %d, and my parent's is %d.\n", getpid(), getppid());
    } else {
        printf("\nI am the parent. My pid is %d, and my child's pid is %d. My parent is %d.\n", getpid(), child_pid, getppid());
        printf("\nFinished waiting for %d. Status: %d.\n\n", wait(&status), status);
    }
    
    return 0;
}
