#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    
    int status = 0; // still unsure what this argument to wait does
    pid_t rv = wait(&status);
    
    // Wait returns -1.
    printf("Returned from wait. rv(%d), status(%d)\n", rv, status);
    return 0;
}
