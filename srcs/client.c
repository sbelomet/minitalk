/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:16:15 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/23 15:02:14 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	print_bits(char octet)
{
	int		i;
	char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		ft_printf("%c", bit);
	}
	ft_printf("\n");
}

char	reverse_bits(char octet)
{
	int		i;
	char	res;

	i = 8;
	res = 0;
	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

static void	ft_send_message(int pid, char *message)
{
	int				i;
	int				j;
	unsigned char	octet;

	i = 0;
	while (message[i])
	{
		print_bits(message[i]);
		octet = reverse_bits(message[i]);
		j = 8;
		while (j--)
		{
			if (octet % 2)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			octet /= 2;
			usleep(100);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("ERROR: ./client <PID> <MESSAGE>\n");
		exit(0);
	}
	if (!is_numerical(av[1]))
	{
		ft_printf("ERROR: Invalid PID\n");
		exit(0);
	}
	ft_printf("Sending to PID %d...\n", ft_atoi(av[1]));
	ft_send_message(ft_atoi(av[1]), av[2]);
}
