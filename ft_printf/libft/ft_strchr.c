/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:52:28 by sbelomet          #+#    #+#             */
/*   Updated: 2023/10/10 16:22:18 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len + 1)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	str[] = "huntlow & lumity";
	int		to_find1 = 'u';
	int		to_find2 = '\0';
	int		to_find3 = 'z';
	int		to_find4 = 'y';

	printf("to_find1 : %p\n", ft_strchr(str, to_find1));
	printf("to_find2 : %p\n", ft_strchr(str, to_find2));
	printf("to_find3 : %p\n", ft_strchr(str, to_find3));
	printf("to_find4 : %p\n", ft_strchr(str, to_find4));
}*/
