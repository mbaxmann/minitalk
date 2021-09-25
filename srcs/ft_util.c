#include "../include/minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	tr;

	tr = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * (-1);
		}
		if (n < 10)
		{
			n = 48 + n;
			write(fd, &n, 1);
		}
		else
		{
			tr = n / 10;
			n = n % 10;
			ft_putnbr_fd(tr, fd);
			ft_putnbr_fd(n, fd);
		}
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			write(fd, &s[i++], 1);
	}
}

int	ft_isminus(char c, int *i)
{
	if (c == '-')
	{
		(*i)++;
		return (-1);
	}
	else
	{
		(*i)++;
		return (1);
	}
}

int	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long int	res;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
			minus = ft_isminus(str[i], &i);
		while (str[i] >= '0' && str[i] <= '9' && res * 10 < 2147483648)
			res = res * 10 + (str[i++] - '0');
		if ((res > 2147483648 || (str[i] >= '0' && str[i] <= '9')) && minus == -1)
			return (0);
		if ((res > 2147483647 || (str[i] >= '0' && str[i] <= '9')) && minus == 1)
			return (-1);
		return (res * minus);
	}
	return (res * minus);
}

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(ft_strlen((char *)s1) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen((char *)s1))
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}