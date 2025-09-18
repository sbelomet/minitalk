/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:58:03 by sbelomet          #+#    #+#             */
/*   Updated: 2025/09/18 10:13:27 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		tlen;
	int		i;
	char	*res;

	len_s1 = ft_strlen(s1);
	tlen = len_s1 + ft_strlen(s2);
	res = (char *)malloc(tlen * sizeof(char) + 1);
	if (!res)
		return (NULL);
	i = -1;
	if (s1)
	{
		while (s1[++i])
			res[i] = s1[i];
	}
	i = -1;
	if (s2)
	{
		while (s2[++i])
			res[len_s1 + i] = s2[i];
	}
	res[len_s1 + i] = '\0';
	return (res);
}

/*
int	main(void)
{
	printf("result: |%s|\n", ft_strjoin("simon ", "petrikov"));
}*/
