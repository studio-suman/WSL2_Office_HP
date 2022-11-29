#include "common.h"

int main (void)

{

    printf("setting alarm - %d\n", getpid());
    alarm(5);
    printf("alarm set");
    printf(("process paused"));
    pause();

    return 0;
}