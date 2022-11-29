#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define BUFSIZ 10

void printmsg(char *msg)

{
    int len;
    len = strlen(msg);
    write(1,msg, len);
}
int main ()

{

    int fd, n, pid;
    char buf[BUFSIZ];
    fd = open("sample.txt",O_RDONLY);

    n = read(fd, buf, BUFSIZ);
    write(1, buf, n);

    pid = fork();

    if(pid == 0) {
        
        printmsg("in child: ");
        n = read(fd, buf, BUFSIZ);
        write(1, buf, n);
        sleep(1);
        printmsg("in child: ");
        n = read(fd, buf, BUFSIZ);
        write(1, buf, n);
    }
    else {
        sleep(3);
        printmsg("in parent: ");
        n = read(fd, buf, BUFSIZ);
        write(1, buf, n);
        //sleep(3);
        printmsg("parent terminted");
    }

    return 0;
}