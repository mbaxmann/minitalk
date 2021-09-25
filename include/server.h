#ifndef SERVER_H
# define SERVER_H

int main(void);
void    ft_handler(int signum, siginfo_t *info, void *context);
void    ft_binary_to_char(int   bool, int pid);

#endif