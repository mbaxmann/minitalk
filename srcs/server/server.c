/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:37:38 by user42            #+#    #+#             */
/*   Updated: 2021/09/26 16:46:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"
#include "../../include/server.h"

int	ft_binary_to_char(int bool, int pid)
{
	static int	byte = 0;
	static char	*str = NULL;
	static char	c[2] = {0, 0};

	if (byte < 8)
		c[0] = (c[0] | (bool << (7 - byte++)));
	if (byte == 8)
	{
		byte = 0;
		if (c[0])
			str = ft_strjoin(str, ft_strdup(c));
		else
		{
			ft_putstr_fd(str, 1);
			free(str);
			str = NULL;
			kill(pid, SIGUSR2);
			write(1, "\n", 1);
			return (0);
		}
		c[0] = 0;
	}
	return (1);
}

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	int	err;
	int	ret;

	(void)context;
	ret = 0;
	err = 0;
	if (signum == SIGUSR1)
		ret = ft_binary_to_char(0, info->si_pid);
	else if (signum == SIGUSR2)
		ret = ft_binary_to_char(1, info->si_pid);
	usleep(5);
	if (ret)
	{
		err = kill(info->si_pid, SIGUSR1);
		if (err == -1)
			ft_putstr_fd("Warning! Comminication with client failed.", 1);
	}
}

int	main(void)
{
	struct sigaction	act;
	int					err;

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = &ft_handler;
	act.sa_flags = SA_SIGINFO | SA_NODEFER;
	ft_putstr_fd("[SEVRER] Pid: ", 1);
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
