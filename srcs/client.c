/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:16:15 by sbelomet          #+#    #+#             */
/*   Updated: 2025/09/18 11:04:11 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_null(int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

static void	ft_send_message(int pid, char *message)
{
	int				i;
	int				j;
	unsigned char	octet;

	i = 0;
	while (message[i])
	{
		octet = message[i];
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
	ft_send_null(pid);
}

int	main(int ac, char **av)
{
	int	serv_pid;

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
	serv_pid = ft_atoi(av[1]);
	ft_printf("Sending to PID %d...\n", serv_pid);
	ft_send_message(serv_pid, av[2]);
}
