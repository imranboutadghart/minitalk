/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imbo <imbo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:45:18 by imbo              #+#    #+#             */
/*   Updated: 2023/10/29 19:38:05 by imbo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


int	s_error(void)
{
	ft_putstr("Server error!\n");
	return (-1);
}

void	receive_bit(int n)
{
	static size_t	bit = -1;
	static char		c = 0;
	static int		busy = 0;

	if (busy)
		exit(s_error());
	busy = 1;
	++bit;
	c = c * 2 + (n == SIGUSR2);
	if((bit % 8) == 7)
	{
		if (c)
			ft_putchar(c);
		else
			ft_putchar('\n');
		bit = -1;
		c = 0;
	}
	busy = 0;
}

int	main(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, receive_bit);
	signal(SIGUSR2, receive_bit);
	while (1)
		pause();
	return (0);
}
