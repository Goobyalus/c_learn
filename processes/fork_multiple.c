#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof(*arr))

void print_info(pid_t* children) {
    printf("pid(%d), ppid(%d), [%d %d %d %d]\n", getpid(), getppid(),
        children[0], children[1], children[2], children[3]);
}

int main() {
    
    pid_t children[4] = {};
    int i = 0;
    
    printf("\n");
    
    for(i = ARRAY_LEN(children)-1; i >=0; i--) {
        children[i] = fork();
        
        // Children:
        if (0 == children[i]) {
            
            // Print this to show what memory state the child has inherited
            print_info(children);
            
            switch(i){
            case 3: 
            case 2: 
            case 1: 
            case 0: 
                // Child replaces its memory space here
                execl("print_pid", "print_pid", NULL);
                printf("Failure to exec. Exiting.\n");
                return 1;
                break;
            default: return 1; // Unimplemented process
            }
        }
    }
    
    // Wait for all children
    for(i = 0; i < ARRAY_LEN(children); i++) {
        wait(NULL);
    }

    return 0;
}
