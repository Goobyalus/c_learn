#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof(*arr))
#define DIG_TO_INT(digit) (digit-48)
#define CHILD_PROC_FILE "wait_for_death"

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
                execl(CHILD_PROC_FILE, CHILD_PROC_FILE, NULL);
                printf("Failure to exec. Exiting.\n");
                return 1;
                break;
            default: return 1; // Unimplemented process
            }
        }
    }
    
    char in = '0';
    do {
        printf("\ne: exit\n");
        printf("1: child info\n");
        printf("2: restart child\n");
        in = getchar();
        if ('\n' != in){ getchar();} // Get rid of newline
        switch(in) {
        case 'e':
            printf("Exiting.\n");
            break;
            
        case '1':
            printf("[%d %d %d %d]", children[0], children[1],
                        children[2], children[3]);
            break;
            
        case '2':
            printf("which child (0-3)?: ");
            in = getchar();
            if ('\n' != in){ getchar();} // Get rid of newline
            
            printf("You entered %d\n", DIG_TO_INT(in));
            
            if (DIG_TO_INT(in) > 3) {
                printf("Invalid\n");
            }
            kill(children[DIG_TO_INT(in)], SIGKILL);
            children[DIG_TO_INT(in)] = fork();
            if (0 == children[DIG_TO_INT(in)]) {
                execl(CHILD_PROC_FILE, CHILD_PROC_FILE, NULL);
            } //else (child//TODO: error checking
            break;
            
        default: printf("Invalid\n");
        }
    } while (in != 'e');

    return 0;
}
