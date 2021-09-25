#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "server.h"

void    ft_putnbr_fd(int n, int fd);
void    ft_putstr_fd(char *s, int fd);
int     ft_isminus(char c, int *i);
int     ft_atoi(const char *str);
int     ft_strlen(const char *str);
char	*ft_strdup(const char *s1);

#endif