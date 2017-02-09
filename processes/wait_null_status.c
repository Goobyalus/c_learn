#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    
    int rv = fork();
    if (rv == 0) {
        printf("Child exiting\n");
        return 0;
    } else if (rv == -1) {
        printf("Error forking\n");
        return 1;
    }
        
    pid_t child = wait(NULL); //allowed to pass null; wait will not write
    // status information in this case. See man page (or below) for detail.
    
    // Wait returns -1.
    printf("Returned from wait. child(%d)\n", child);
    return 0;
}
/* From the wait manual - what the status argument does.
 
 If wstatus is not NULL, wait() and waitpid() store status information
       in the int to which it points.  This integer can be inspected with
       the following macros (which take the integer itself as an argument,
       not a pointer to it, as is done in wait() and waitpid()!):

       WIFEXITED(wstatus)
              returns true if the child terminated normally, that is, by
              calling exit(3) or _exit(2), or by returning from main().

       WEXITSTATUS(wstatus)
              returns the exit status of the child.  This consists of the
              least significant 8 bits of the status argument that the child
              specified in a call to exit(3) or _exit(2) or as the argument
              for a return statement in main().  This macro should be
              employed only if WIFEXITED returned true.

       WIFSIGNALED(wstatus)
              returns true if the child process was terminated by a signal.

       WTERMSIG(wstatus)
              returns the number of the signal that caused the child process
              to terminate.  This macro should be employed only if
              WIFSIGNALED returned true.

       WCOREDUMP(wstatus)
              returns true if the child produced a core dump.  This macro
              should be employed only if WIFSIGNALED returned true.

              This macro is not specified in POSIX.1-2001 and is not
              available on some UNIX implementations (e.g., AIX, SunOS).
              Therefore, enclose its use inside #ifdef WCOREDUMP ... #endif.

       WIFSTOPPED(wstatus)
              returns true if the child process was stopped by delivery of a
              signal; this is possible only if the call was done using
              WUNTRACED or when the child is being traced (see ptrace(2)).

       WSTOPSIG(wstatus)
              returns the number of the signal which caused the child to
              stop.  This macro should be employed only if WIFSTOPPED
              returned true.

       WIFCONTINUED(wstatus)
              (since Linux 2.6.10) returns true if the child process was
              resumed by delivery of SIGCONT.
*/
