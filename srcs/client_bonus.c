/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:16:15 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/24 12:20:24 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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

void	ft_confirm(int signum)
{
	(void)signum;
	ft_printf("Message sent successfully!\n");
	exit(0);
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
	signal(SIGUSR1, ft_confirm);
	ft_printf("Sending to PID %d...\n", ft_atoi(av[1]));
	ft_send_message(ft_atoi(av[1]), av[2]);
	pause();
}
