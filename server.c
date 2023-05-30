/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:52:52 by flcristi          #+#    #+#             */
/*   Updated: 2023/05/29 21:05:18 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void server_error(void)
{
	ft_putstr_fd("Invalid arguments\n", 1);
	ft_putstr_fd("HELP", 1);
}

int main(int argc, char **argv)
{
    struct sigaction	action;
	sigset_t			sigset;

	(void)argv;
	if (argc != 3)
	{
		server_error();
		exit(1);
	}
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	action.sa_handler = NULL;
	
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
}
