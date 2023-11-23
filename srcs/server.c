/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:16:14 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/23 15:23:57 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("1\n");
	else if (signum == SIGUSR2)
		ft_printf("0\n");
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("HERE IS THE PID >>>> %d <<<<\n", getpid());
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
}
