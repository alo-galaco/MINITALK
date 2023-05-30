/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:52:49 by flcristi          #+#    #+#             */
/*   Updated: 2023/05/30 16:28:42 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit;

static	void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_bit++;
	else if (signal == SIGUSR2)
		g_bit++;
	else
	{
		ft_putstr_fd("\tError", 1);
		exit(1);
	}
}

static	void	client_error(void)
{
	ft_putstr_fd("Invalid arguments\n", 1);
	ft_putstr_fd("How to run:\n", 1);
	ft_putstr_fd("./client <server PID> <message>\n", 1);
	exit(1);
}

static void	bit_by_bit(int server_pid, char byte)
{
	int		signal;
	while (g_bit < 8)
	{
		if (byte << g_bit & 128)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		while(kill(g_bit, signal))
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	size_t	i;
	int		server_pid;

	g_bit = 0;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	i = 0;
	server_pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		while (argv[2][i] != '\0')
		{
			bit_by_bit(server_pid, argv[2][i]);
			i++;
		}
	}
	else
		client_error();
}
