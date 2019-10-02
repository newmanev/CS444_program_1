/***
 * Question: Can you do this without the parent calling wait() in the parent
 * (and NOT using some big loop in the parent)?
 *
 * Answer: Yes you can you can use the command sleep(10) in the parent processes
 * to ensure that the child executes first before the parent has a chance to
 * do anything 10 seconds is a bit overkill but should be enough.
***/


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

