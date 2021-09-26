/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:03:39 by user42            #+#    #+#             */
/*   Updated: 2021/09/26 17:04:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isminus(char c, int *i);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_size(char const *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
