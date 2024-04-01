/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imbo <imbo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:03:05 by imbo              #+#    #+#             */
/*   Updated: 2024/03/12 18:27:41 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# define BUFFER_SIZE 4096

int		ft_puterror(const char *str);
size_t	ft_strlen(const char *str);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);

#endif //MINITALK_H
