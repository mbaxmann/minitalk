#include "../../include/minitalk.h"

void    ft_binary_to_char(int   bool)
{
    static int  byte = 0;
    static char     c = 0;
    char test;

    if (byte < 8)
    {
        test = '0' + bool;
        write(1, &test, 1);
        c = (c | (bool << (8 - byte)));
        byte++;
    }
    if (byte == 8)
    {
        byte = 0;
        //write(1, "   ", 3);
        //ft_putnbr_fd((int)c, 1);
        //write(1, "\n", 1);
        c = 0;
    }
}

void    ft_handler(int signum, siginfo_t *info, void *context)
{
    static int i = 0;

    if (i == 8)
    {
        i = 0;
    }
    ft_putnbr_fd(info->si_pid, 1);
    i++;
    if (signum == SIGUSR1)
    {
        ft_binary_to_char(0);
        kill(info->si_pid, SIGUSR1);
    }
    else if (signum == SIGUSR2)
    {
        ft_binary_to_char(1);
        kill(info->si_pid, SIGUSR1);
    }
}

int main()
{
    struct sigaction    act;
    int         err;

    act.sa_sigaction = &ft_handler;
    act.sa_flags = SA_SIGINFO | SA_NODEFER;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGUSR1);
    ft_putnbr_fd(getpid(), 1);
    write(1, "\n", 1);
    while (1)
    {
        err = sigaction(SIGUSR1, &act, NULL);
        err = sigaction(SIGUSR2, &act, NULL);
        if (err < 0)
            ft_putstr_fd("Error: sigaction failed\n", 1);
        write(1, "\n", 1);
        pause();
    }
    return (0);
}