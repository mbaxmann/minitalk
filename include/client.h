/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:03:08 by user42            #+#    #+#             */
/*   Updated: 2021/09/26 17:03:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

int		main(int ac, char **av);
int		ft_send_bit(char c, int pid);
void	ft_client_handler(int signum);
void	ft_send_str(char *str, int pid);

#endif
