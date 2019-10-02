/***
 * Question: What happens when they are writing to the file concurrently, i.e.,
 * at the same time?
 *
 * Answer: Only one processes may write to a file at a time.
 * If one processes is trying to write to the file while another
 * is already writing to it that processes is locked out
 * and are only allowed access once the other process has 
 * finished writing to the file.
***/


#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

    printf("start\n");

    FILE *fp;
    fp = fopen("JUNK.txt", "w+");

    fprintf(fp, "before fork\n");

    __pid_t pid = fork();

    if (pid == 0) {

        int i = 0;
        for ( i = 0; i < 10; i++)
        {
            fprintf(fp, "child\n");
        }
        
    }
    else if (pid > 0) {

        int j = 0;
        for ( j = 0; j < 10; j++)
        {
            fprintf(fp, "parent\n");
        }
        
    }
    else {
        printf("failed fork\n");
    }
    
    printf("end\n");

    return 0;
}
