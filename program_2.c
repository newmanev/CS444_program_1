/***
 * Write a C program that calls fork(). 
 * Before calling fork(), have the parent process assign the value 100 to intcalled xx. 
 * Question: What value is the value of xx in the child process? 
 *
 * Answer: The value of xx in the child process is 100.
 *
 * Question: Have the parent process assign the value 999 to xx and 
 * have the child process assign the value 777 to xx. 
 * What happens to xx variable when both the child 
 * and parent change the value of xx? 
 *
 * Answer: the child and the parent each get their own copy of xx 
 * so they can't modify eachother's values. 
 * In this case xx starts off as 100 for both the parent and child and upon 
 * modifying becomes there specific value of xx 
 * but this change does not effect either of them.
 *
 * Have both processes print the value of xx. 
 * 
***/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    
    printf("start\n");

    __pid_t pid = fork();

    int xx = 100;

    if (pid == 0) {
        printf("Child before:\t%d\n", xx);

        xx = 777;

        printf("Child after:\t%d\n", xx);
    }
    else if (pid > 0) {
        printf("Parent before:\t%d\n", xx);

        xx = 999;

        printf("Parent after:\t%d\n", xx);
    }
    else {
        printf("failed fork\n");
    }

    printf("end\n");

    return 0;
}
