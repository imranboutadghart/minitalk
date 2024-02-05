/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imbo <imbo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:45:13 by imbo              #+#    #+#             */
/*   Updated: 2024/01/26 12:41:38 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig);

int	c_error(const char *str)
{
	ft_puterror(str);
	return (-1);
}

int send_bit(const char *str, int pid)
{
	size_t	bit;
	size_t	len;
	char	state;
	
	len = (ft_strlen(str) + 1) * 8;
	bit = 0;
	while (bit < len)
	{
		state = str[bit / 8] & (0b10000000 >> (bit % 8));
		if (kill(pid, SIGUSR2 * !!state + SIGUSR1 * !state) == -1)
				return (c_error("Client to server error!\n"));
		bit++;
		usleep(500);
	}
	sleep(2);
	handler(SIGUSR2);
	return (0);
}

void	handler(int sig)
{
	static char success[] = "Message sent successfuly\n";
	static char error[] = "Message was not sent successfuly\n";

	if (SIGUSR1 == sig)
		write(1, success, sizeof(success));
	else if (SIGUSR2 == sig)
		exit(c_error(error));
	exit(0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc < 3)
		return (c_error("Not enough arguments!\n"));
	if (argc > 3)
		return (c_error("Too many arguments!\n"));
	send_bit(argv[2], ft_atoi(argv[1]));
	return (0);
}
