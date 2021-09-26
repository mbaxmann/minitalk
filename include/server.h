/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:04:41 by user42            #+#    #+#             */
/*   Updated: 2021/09/26 17:05:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

int		main(void);
int		ft_binary_to_char(int bool, int pid);
void	ft_handler(int signum, siginfo_t *info, void *context);

#endif
