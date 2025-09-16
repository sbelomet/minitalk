/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:26:28 by sbelomet          #+#    #+#             */
/*   Updated: 2025/09/16 13:40:04 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_printstr(char *s);
int		ft_printptr(unsigned long long a);
int		ft_printhex(unsigned long long a, char isupper);
char	ft_converthex(int a, char isupper);
char	*ft_uitoa(unsigned int n);
int		ft_printformat(va_list args, char format);

#endif
