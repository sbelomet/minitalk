/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:16:14 by sbelomet          #+#    #+#             */
/*   Updated: 2025/09/18 11:17:05 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static int		i = 0;
	static char		byte = 0;
	static char		*message;
	char			*tmp;

	if (signum == SIGUSR1)
		byte += ft_pow(2, i);
	if (++i == 8)
	{
		if (byte == 0)
		{
			ft_printf("%s\n", message);
			free(message);
			message = NULL;
		}
		else
		{
			tmp = message;
			message = ft_strjoin(message, &byte);
			if (tmp)
				free(tmp);
		}
		i = 0;
		byte = 0;
	}
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
		pause();
}
