#include "common.h"

int main (int argc, char *argv[])

{
    int pipefds[2];
            int fd, k, n;
        char buf[100];
        struct rlimit rlim = {100,100};
        setrlimit(RLIMIT_FSIZE, &rlim);
        char readmsg[20];
    int PA = fork();
    int PB = fork();
    int PC = fork();

    if (PA == 0) {
        printf("Pid: %d\n",getpid());
        fd = open(argv[1], O_CREAT | O_TRUNC | O_RDONLY, 0600);
    } else if (PB == 0) {
        printf("Pid: %d\n",getpid());
        n=read(fd,buf,strlen(buf));
    } else if (PC == 0) {
        printf("Pid: %d\n",getpid());
        write(1, buf,n);
    } else {
    sleep(3);    
    close(fd);
    printf("\nProgram Terminated\n");
    }
    
}