#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char const *argv[])
{
    
    __pid_t pid = fork();

    if (pid == 0) {

        printf("hello\n");
    }
    else if (pid > 0) {

        wait(NULL);

        printf("goodbye\n");
    }
    else {
        printf("failed fork\n");
    }

    return 0;
}

