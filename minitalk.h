/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imbo <imbo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:03:05 by imbo              #+#    #+#             */
/*   Updated: 2023/10/29 19:41:12 by imbo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int	ft_putstr(const char *str);
void ft_putchar(char c);
size_t ft_strlen(const char *str);
void ft_putnbr(int n);
int	ft_atoi(const char *str);

#endif //MINITALK_H