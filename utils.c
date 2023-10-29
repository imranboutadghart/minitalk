/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imbo <imbo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:02:20 by imbo              #+#    #+#             */
/*   Updated: 2023/10/29 19:41:00 by imbo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putnbr(int n)
{
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
		
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	result;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while (' ' == str[i] || '\f' == str[i] || '\n' == str[i]
		|| '\r' == str[i] || '\t' == str[i] || '\v' == str[i])
		i++;
	if ('+' == str[i] || '-' == str[i])
		if ('-' == str[i++])
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return ((int )(sign * result));
}