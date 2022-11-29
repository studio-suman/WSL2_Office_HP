#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main ()
{
    unsigned int k = 0;
    int z = getppid();
    printf("pid = %d\n", z);
    signal(SIGINT,SIG_IGN); //ignore Ctrl+C
    perror("SIGINT");
    signal(SIGQUIT,SIG_IGN); //ignore Ctrl+C
    printf("program gets into infinite loop\n");

    z = fork();
    if(z == 0) {
        printf("entered Child Process:");
    printf("pid = %d\n", z);
    signal(SIGINT,SIG_IGN); //ignore Ctrl+C
    perror("SIGINT");
    signal(SIGQUIT,SIG_IGN); //ignore Ctrl+C
    printf("program gets into infinite loop\n");
        while (1)
    {
        /* code */
        //printf("k = %d\n", ++k); 
    }

    } else 
    {
        printf("entered Child Process:");
    printf("pid = %d\n", z);
    signal(SIGINT,SIG_IGN); //ignore Ctrl+C
    perror("SIGINT");
    signal(SIGQUIT,SIG_IGN); //ignore Ctrl+C
    printf("program gets into infinite loop\n");
        while (1)
    {
        /* code */
        //printf("k = %d\n", ++k); 
    }
    }
    
    return 0;
}