#ifndef CLIENT_H
# define CLIENT_H

int     main(int ac, char **av);
int     ft_send_bit(char c, int pid);
void    ft_client_handler(int signum);
void    ft_send_str(char *str, int pid);

#endif