#include "common.h"

void sighandler(int sig) {
    printf("recieved signal = %d\n", sig);
}

int main(void)
{
    struct sigaction action = {sighandler };

    sigaction(SIGINT, &action, NULL);

    while(1)
    {}

}