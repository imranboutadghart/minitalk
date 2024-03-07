/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imbo <imbo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:02:20 by imbo              #+#    #+#             */
/*   Updated: 2024/02/19 03:09:51 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_puterror(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
		return ;
	}
	c = n + '0';
	write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			exit(-1);
		result = result * 10 + str[i++] - '0';
		if (result > 2147483647)
			exit(-1);
	}
	return ((int )(result));
}

void	get_vars(int *av1, char **av2, int set)
{
	static int	arg_pid;
	static char	*arg_str;

	if (set)
	{
		arg_pid = *av1;
		arg_str = *av2;
	}
	else
	{
		*av1 = arg_pid;
		*av2 = arg_str;
	}
}
