#include <unistd.h>
#include <stdio.h>

int main() {
    int i;
    for (i = 0; i < 100; i++) {
        sleep(6);
    }
    printf("It's been 10 minutes; time to die\n");
    return 0;
}
