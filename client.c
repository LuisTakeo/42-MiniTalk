/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:07:47 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/13 12:07:47 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_is_received;

int	main(int argc, char *argv[])
{
	struct sigaction	siga;
	int					pid;

	if (argc != 3)
		return (ft_printf("Invalid number of arguments.\n"));
	if (ft_validate_pid(argv[1]))
		return (ft_printf("Invalid PID. Insert a valid PID.\n"));
	siga.sa_flags = 0;
	siga.sa_handler = ft_received;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	pid = ft_atoi(argv[1]);
	ft_send_message(pid, argv[2]);
	return (0);
}

int	ft_validate_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_signal(pid, str[i]);
		i++;
	}
	ft_send_signal(pid, '\n');
}

void	ft_send_signal(int pid, char c)
{
	static int	i;
	static char	bit;

	i = 0;
	bit = 0;
	while (i < 8)
	{
		g_is_received = 0;
		bit = c >> i & 1;
		if (bit)
			kill(pid, SIGUSR1);
		else if (bit == 0)
			kill(pid, SIGUSR2);
		while (!g_is_received)
			;
		i++;
	}
}

void	ft_received(int sig)
{
	if (sig == SIGUSR1)
		g_is_received = 1;
}
