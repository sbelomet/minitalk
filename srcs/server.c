/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:16:14 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/24 12:19:45 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	byte = 0;
	int						pid_client;

	(void)context;
	pid_client = info->si_pid;
	if (signum == SIGUSR1)
		byte += ft_pow(2, i);
	i++;
	if (i == 8)
	{
		if (byte == 0)
		{
			ft_printf("\n");
			kill(pid_client, SIGUSR1);
		}
		else
			ft_printf("%c", byte);
		i = 0;
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("HERE IS THE PID >>>> %d <<<<\n", getpid());
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
}
