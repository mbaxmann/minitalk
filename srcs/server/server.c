#include "../../include/minitalk.h"

void    ft_binary_to_char(int   bool, int pid)
{
    static int  byte = 0;
    static char     c = 0;
    char test;

    if (byte < 8)
    {
        c = (c | (bool << (7 - byte)));
        byte++;
    }
    if (byte == 8)
    {
        byte = 0;
        if (c)
            write(1, &c, 1);
        else
        {
            kill(pid, SIGUSR2);
            write(1, "\n", 1);
        }
        c = 0;
    }
}

void    ft_handler(int signum, siginfo_t *info, void *context)
{
    if (signum == SIGUSR1)
        ft_binary_to_char(0, info->si_pid);
    else if (signum == SIGUSR2)
        ft_binary_to_char(1, info->si_pid);
    usleep(5);
    kill(info->si_pid, SIGUSR1);
}

int main()
{
    struct sigaction    act;
    int         err;

    sigemptyset(&act.sa_mask);
    act.sa_sigaction = &ft_handler;
    act.sa_flags = SA_SIGINFO | SA_NODEFER;
    ft_putnbr_fd(getpid(), 1);
    write(1, "\n", 1);
    err = sigaction(SIGUSR1, &act, NULL);
    err = sigaction(SIGUSR2, &act, NULL);
    if (err < 0)
        ft_putstr_fd("Error: sigaction failed\n", 1);
    write(1, "\n", 1);
    while (1)
        sleep(10);
    return (0);
}