#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char const *argv[])
{
    
    char *args[] = {"-l", "-F", "-h"};

    __pid_t pid1, pid2, pid3, pid4;
    
    if ((pid1 = fork()) == 0) {

        if ((pid2 = fork()) == 0) {

            if ((pid3 = fork()) == 0) {

                if ((pid4 = fork()) == 0) {

                    execvp("ls", args);

                } else if (pid4 > 0) {
                    wait(NULL);
                } else {
                    printf("failed fork");
                }

                execv("/bin/ls", args);
                
            } else if (pid3 > 0) {
                wait(NULL);
            } else {
                printf("failed fork");
            }

            execlp("ls", "ls", "-l", "-F", "-h", (char *) NULL);

        } else if (pid2 > 0) {
            wait(NULL);
        } else {
            printf("failed fork");
        }

        execl("/bin/ls", "/bin/ls", "-l", "-F", "-h", (char *) NULL);

    }
    else if (pid1> 0) {

        wait(NULL);

        printf("goodbye\n");
    }
    else {
        printf("failed fork\n");
    }

    return 0;
}


