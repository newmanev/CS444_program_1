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
