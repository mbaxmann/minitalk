#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


void    handler(int num)
{
    printf("I do not die!\n");
}

int main()
{
    signal(SIGINT, handler);
    while (1)
    {
        printf("mon pid: %d\n", getpid());
        sleep(1);
    }
    return (0);
}