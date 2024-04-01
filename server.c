/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imbo <imbo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:45:18 by imbo              #+#    #+#             */
/*   Updated: 2024/03/12 18:16:45 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	s_error(const char *s)
{
	ft_puterror(s);
	exit(-1);
	return (-1);
}

void	put_buffer(char *s, int *i, int c)
{
	if (!c)
	{
		s[(*i)++] = '\n';
		write(1, s, *i);
		*i = 0;
		return ;
	}
	s[(*i)++] = c;
	write(1, s, *i);
	*i = 0;
}

int	receive_bit(int n)
{
	static char	bit = 0;
	static char	str[BUFFER_SIZE + 2];
	static char	c = 0;
	static int	i = 0;

	++bit;
	c = (c << 1) + (n == SIGUSR2);
	if (!(bit % 8))
	{
		if (c && i < BUFFER_SIZE)
			str[i++] = c;
		else
			return (put_buffer(str, &i, c), (!c));
		bit = 0;
		c = 0;
	}
	return (0);
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	s[] = "server to client error";
	static int	pid;

	if (!pid)
		pid = info->si_pid;
	if (info->si_pid != pid)
	{
		while (-1 != kill(info->si_pid, SIGUSR2))
			(void)ucontext;
		return ;
	}
	if (receive_bit(sig))
	{
		if (-1 == kill(info->si_pid, SIGUSR2) || \
				-1 == kill(info->si_pid, SIGUSR1))
			s_error(s);
		pid = 0;
	}
	else
		if (-1 == kill(info->si_pid, SIGUSR1))
			s_error(s);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "Server pid is: ", 16);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
