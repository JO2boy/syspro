#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(pipefd[1]);
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Recv : [%d] %s\n", getpid(), buffer);
        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    } else {
        close(pipefd[0]);
        const char *message = "Hello from PID ";
        sprintf(buffer, "%s%d", message, getpid());
        write(pipefd[1], buffer, strlen(buffer) + 1);
        printf("Send : [%d] %s\n", getpid(), buffer);
        close(pipefd[1]);
        wait(NULL);
    }

    return 0;
}

