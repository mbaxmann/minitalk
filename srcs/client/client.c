#include "../../include/minitalk.h"
void    ft_client_handler(int signum)
{
    if (signum == SIGUSR1)
    {
        ft_putstr_fd("\nWaiting", 1);
    }
}

int main(int ac, char **av)
{
    char    a;
    char    tmp;
    struct sigaction    act;
    int i = 8;

    a = 'a';
    act.sa_handler = &ft_client_handler;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGUSR1);
    ft_putnbr_fd(getpid(), 1);
    if (ac != 3)
        write(1, "Wrong argument number!\n", 23);
    else
    {   
        sigaction(SIGUSR1, &act, NULL);
        while (i)
        {
            tmp = a >> (i - 1);
            tmp = tmp & 00000001;
            if (tmp)
            {
                kill(ft_atoi(av[1]), SIGUSR2);
            }
            else
            {
                kill(ft_atoi(av[1]), SIGUSR1);
            }
            pause();
            i--;
        }
    }
    return (0);
}