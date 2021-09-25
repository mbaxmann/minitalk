#include "../../include/minitalk.h"

void    ft_send_str(char *str, int pid)
{
    static char *stock = NULL;
    static int  i = 0;
    static int  byte = 0;

    if (str)
        stock = ft_strdup(str);
    if (stock)
        byte += ft_send_bit(stock[i], pid);
    if (stock && !stock[i] && byte == 8)
    {
        free(stock);
        stock = NULL;
    }
    if (byte == 8)
    {
        byte = 0;
        i++;
    }
}

int    ft_send_bit(char c, int pid)
{
    static int  i = 8;
    static int  pid_stock = 0;
    char    tmp;

    tmp = 0;
    if (pid)
        pid_stock = pid;
    if (i == 0)
        i = 8;
    tmp = c >> (i - 1);
    tmp = tmp & 00000001;
    if (tmp)
        kill(pid_stock, SIGUSR2);
    else
        kill(pid_stock, SIGUSR1);
    i--;
    return (1);
}

void    ft_client_handler(int signum)
{
    if (signum == SIGUSR1)
        ft_send_str(NULL, 0);
    else
        exit(1);
}

int main(int ac, char **av)
{
    struct sigaction    act;
    int i = 8;

    sigemptyset(&act.sa_mask);
    act.sa_handler = &ft_client_handler;
    ft_putnbr_fd(getpid(), 1);
    if (ac != 3)
        write(1, "Wrong argument number!\n", 23);
    else
    {   
        ft_send_str(av[2], ft_atoi(av[1]));
        sigaction(SIGUSR1, &act, NULL);
        sigaction(SIGUSR2, &act, NULL);
        while(1)
            usleep(10);
    }
    return (0);
}