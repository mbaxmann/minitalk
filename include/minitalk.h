#ifndef MINITALK_H
# define MINITALK_H

#include "client.h"
#include "server.h"

void    ft_putnbr_fd(int n, int fd);
void    ft_putstr_fd(char *s, int fd);
int     ft_isminus(char c, int *i);
int     ft_atoi(const char *str);

#endif