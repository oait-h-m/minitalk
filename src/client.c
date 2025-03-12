/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:08:52 by oait-h-m          #+#    #+#             */
/*   Updated: 2025/03/10 04:38:43 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(int pid, char byte)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (byte >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

void	send_msg(int pid, char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		send_byte(pid, av[i]);
		i++;
	}
	send_byte(pid, '\0');
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr("Error: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		ft_putstr("Error Invalid PID\n");
		exit(1);
	}
	send_msg(pid, av[2]);
	return (0);
}
