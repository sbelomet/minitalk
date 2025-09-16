/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:28:04 by sbelomet          #+#    #+#             */
/*   Updated: 2023/10/11 12:59:12 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (dstsize > 0 && len_dst < dstsize - 1)
	{
		while (src[i] && i < dstsize - len_dst - 1)
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
	}
	if (len_dst >= dstsize)
		len_dst = dstsize;
	return (len_dst + len_src);
}

/*
int	main(void)
{
	char	dst[10] = "a";

	printf("result: %zu\n", ft_strlcat(dst, "lorem ipsum dolor sit amet", 0));
	printf("\ndst: %s", dst);
	write(1, dst, 15);
}*/
