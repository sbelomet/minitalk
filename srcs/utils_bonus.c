/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:21:42 by sbelomet          #+#    #+#             */
/*   Updated: 2025/09/18 10:20:27 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_pow(int base, int exp)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	if (exp == 0)
		return (1);
	while (i < exp)
	{
		res *= base;
		i++;
	}
	return (res);
}

int	is_numerical(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] > 47 && s[i] < 58)
	{
		i++;
	}
	if (i != ft_strlen(s))
		return (0);
	return (1);
}
