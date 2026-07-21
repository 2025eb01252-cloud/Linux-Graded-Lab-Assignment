#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child Process Started. PID=%d\n", getpid());

        sleep(15);

        printf("Child Process Completed\n");
        exit(0);
    }
    else {
        printf("Parent Monitoring Child PID=%d\n", pid);

        sleep(5);

        if (kill(pid, 0) == 0) {
            printf("Child is unresponsive. Terminating...\n");
            kill(pid, SIGKILL);
        }

        waitpid(pid, &status, 0);

        printf("Child Process Cleaned Up.\n");
    }

    return 0;
}
