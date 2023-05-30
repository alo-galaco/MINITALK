/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:52:49 by flcristi          #+#    #+#             */
/*   Updated: 2023/05/30 14:43:25 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit;

static	void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		g_bit++;
	else if (sig == SIGUSR2)
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
	ft_putstr_fd("./client <server PID> <message>\n", 1);
	exit(1);
}

void	bit_by_bit(int server_pid, char c)
{
	while (g_bit < 8)
	{
		if ((128 >> g_bit) & c)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
		if (g_bit == 8)
		{
			g_bit = 0;
			return ;
		}
	}
}

int	main(int argc, char **argv)
{
	size_t	i;
	int		server_pid;

	if (argc != 3)
		client_error();
	g_bit = 0;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	i = 0;
	server_pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		bit_by_bit(server_pid, argv[2][i]);
		i++;
	}
}
