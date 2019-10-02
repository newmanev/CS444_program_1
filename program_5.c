/***
 * Describe the difference of the exec functions
 *
 * For the most part all of the exec calls differences really only rely on
 * what you can pass into them.
 *
 * execl(): You must specify the path to the program. 
 * Each argument to the executable needs to have it's own argument to the function
 *
 * execlp(): Searches in PATH for the program so you don't need to specify it. 
 * Each argument to the executable has it's own argument to the function
 *
 * execv(): You must specify the path to the program. 
 * You can use an array for arguments
 *
 * execvp(): Searches in PATH for the program so you don't need to specify it. 
 * You can use an array for argument
***/


#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char const *argv[])
{
    
    char *args[] = {"ls", "-l", "-F", "-h"};

    __pid_t pid1, pid2, pid3, pid4;
    
    if ((pid1 = fork()) == 0) {

        if ((pid2 = fork()) == 0) {

            if ((pid3 = fork()) == 0) {

                if ((pid4 = fork()) == 0) {

					printf("execvp\n");
                    execvp("/bin/ls", args);

                } else if (pid4 > 0) {
                    wait(NULL);
                } else {
                    printf("failed fork");
                }

				printf("execv\n");
                execv("/bin/ls", args);
                
            } else if (pid3 > 0) {
                wait(NULL);
            } else {
                printf("failed fork");
            }

			printf("execlp\n");
            execlp("ls", "ls", "-l", "-F", "-h", (char *) NULL);

        } else if (pid2 > 0) {
            wait(NULL);
        } else {
            printf("failed fork");
        }

		printf("execl\n");
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


