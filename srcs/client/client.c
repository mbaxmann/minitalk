/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:38:11 by user42            #+#    #+#             */
/*   Updated: 2021/09/26 16:54:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"
#include "../../include/client.h"

void	ft_send_str(char *str, int pid)
{
	static char	*stock = NULL;
	static int	i = 0;
	static int	byte = 0;

	if (str)
		stock = str;
	if (stock)
		byte += ft_send_bit(stock[i], pid);
	if (byte == -1)
		exit(1);
	if (byte == 8)
	{
		byte = 0;
		i++;
	}
}

int	ft_send_bit(char c, int pid)
{
	static int	i = 8;
	static int	pid_stock = 0;
	char		tmp;
	int			err;

	tmp = 0;
	if (pid)
		pid_stock = pid;
	if (i == 0)
		i = 8;
	tmp = c >> (i - 1);
	tmp = tmp & 00000001;
	usleep(5);
	if (tmp)
		err = kill(pid_stock, SIGUSR2);
	else
		err = kill(pid_stock, SIGUSR1);
	if (err == -1)
	{
		ft_putstr_fd("Error: invalid pid\n", 2);
		return (-1);
	}
	i--;
	return (1);
}

void	ft_client_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_send_str(NULL, 0);
	else
		exit(1);
}

int	main(int ac, char **av)
{
	struct sigaction	act;
	int					err;

	sigemptyset(&act.sa_mask);
	act.sa_handler = &ft_client_handler;
	if (ac != 3)
		ft_putstr_fd("Error: Wrong argument number!\n", 2);
	else
	{
		ft_send_str(av[2], ft_atoi(av[1]));
		err = sigaction(SIGUSR1, &act, NULL);
		err = sigaction(SIGUSR2, &act, NULL);
		if (err < 0)
			ft_putstr_fd("Error: sigaction failed\n", 2);
		while (1)
			usleep(10);
	}
	return (0);
}
