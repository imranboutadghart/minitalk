/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imbo <imbo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:45:13 by imbo              #+#    #+#             */
/*   Updated: 2023/10/29 19:39:25 by imbo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	c_error(const char *str)
{
	ft_putstr(str);
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
		if (state)
		{
			if (kill(pid, SIGUSR2) == -1)
				return (c_error("Client to server error!\n"));
		}
		else if (kill(pid, SIGUSR1) == -1)
			return (c_error("Client to server error!\n"));
		bit++;
		usleep(500);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc < 3)
		return (c_error("Not enough arguments!\n"));
	send_bit(argv[2], ft_atoi(argv[1]));
	return (0);
}
