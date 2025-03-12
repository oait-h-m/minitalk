/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:41:27 by oait-h-m          #+#    #+#             */
/*   Updated: 2025/03/10 03:02:03 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler_sig(int sig, siginfo_t *info, void *other)
{
	static int	bits = 0;
	static char	c = 0;
	static int	client_pid;

	(void)other;
	(void)info;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		bits = 0;
		c = 0;
	}
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1);
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
			kill(client_pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		bits = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_putstr("Error: ./server\n");
		exit(1);
	}
	sa.sa_sigaction = handler_sig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
}
