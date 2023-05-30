/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:52:52 by flcristi          #+#    #+#             */
/*   Updated: 2023/05/30 16:28:33 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	server_error(void)
{
	ft_putstr_fd("Invalid arguments\n", 1);
	exit(1);
}

static	void	print_pid(void)
{
	ft_putstr_fd ("Server PID: ", 1);
	ft_putnbr_fd (getpid(), 1);
	ft_putchar_fd ('\n', 1);
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	byte = 0;

	(void)context;
	if (signal == SIGUSR1)
		byte = byte | 128 >> bit;
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(byte, 1);
		bit = 0;
		byte = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	sigset_t			sigset;
	int					pid;

	(void)argv;
	print_pid();
	if (argc != 1)
	{
		server_error();
		exit(1);
	}
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	action.sa_handler = NULL;
	action.sa_mask = sigset;
	action.sa_sigaction = signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
