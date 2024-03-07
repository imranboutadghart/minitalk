/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imbo <imbo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:45:13 by imbo              #+#    #+#             */
/*   Updated: 2024/02/28 00:05:32 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#define GET 0
#define SET 1

int valid;

void	handler(int sig);
void	get_vars(int *av1, char **av2, int set);

int	c_error(const char *str)
{
	ft_puterror(str);
	return (-1);
}

int	send_bit(const char *str, int pid)
{
	static size_t	bit = 0;
	static size_t	len = (size_t)-1;
	char			state;

	if (len == (size_t)-1)
		len = (ft_strlen(str) + 1) * 8;
	if (bit < len)
	{
		state = str[bit / 8] & (0b10000000 >> (bit % 8));
		if (kill(pid, SIGUSR2 * !!state + SIGUSR1 * !state) == -1)
			exit (c_error("Client to server error!\n"));
		bit++;
	}
	return (0);
}

void	handler(int sig)
{
	static char	success[] = "Message sent successfuly\n";
	static char	error[] = "Message was not sent successfuly\n";
	static int	receiving = 1;
	int			pid;
	char		*str;

	if (!valid)
		valid = 1;
	get_vars(&pid, &str, GET);
	if (!receiving)
	{
		if (SIGUSR1 == sig)
			exit(write(1, success, sizeof(success)));
		else if (SIGUSR2 == sig)
			exit(write(1, error, sizeof(error)));
	}	
	if (SIGUSR1 == sig)
		send_bit(str, pid);
	else if (SIGUSR2 == sig)
		receiving = 0;
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					pid;
	char				*str;

	valid = 0;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc < 3)
		return (c_error("Not enough arguments!\n"));
	if (argc > 3)
		return (c_error("Too many arguments!\n"));
	pid = ft_atoi(argv[1]);
	str = argv[2];
	get_vars(&pid, &str, SET);
	send_bit(str, pid);
	while (1)
	{
		sleep(3);
		if (!valid)
			exit (c_error("client to server error\n"));
		valid = 0;
	}
	return (0);
}
