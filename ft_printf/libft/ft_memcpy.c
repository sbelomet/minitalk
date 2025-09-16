/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:29:49 by sbelomet          #+#    #+#             */
/*   Updated: 2023/10/11 15:44:45 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src && n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

/*
int	main(void)
{
	char str[] = "ABCDEF";
	char *one, *two;

	one = str;
	two = one + 1;

	puts(str);

	printf("returned memcpy: %s\n", ft_memcpy(two, one, 3));
	puts(str);
	write(1, one, 6);
	puts("");
	write(1, two, 5);
	puts("");
}*/
