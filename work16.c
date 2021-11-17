#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    printf("About to fork\n");
    int w, status;
    int f = fork();
    if (f) {
        f = fork();
        if (f) {
            w = wait(&status);
            printf("Child PID: %d\tTime asleep: %d\tparent is done\n", w, WEXITSTATUS(status));
            return 0;
        }
    }
    if (!f) {
        srand(getpid());
        printf("PID: %d\n", getpid());
        int x = rand() % 3 + 2;
        printf("%d\n", x);
        sleep(x);
        printf("Child %d Finished!\n", getpid());
        return x;
    }
    return 0;
}