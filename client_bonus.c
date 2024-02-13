/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:07:47 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/13 12:07:47 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int	g_is_received;

void	ft_received(int sig)
{
	if (sig == SIGUSR1)
		g_is_received = 1;
	if (sig == SIGUSR2)
		ft_printf("Received.\n");
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

int	main(int argc, char *argv[])
{
	struct sigaction	siga;
	int					pid;
	int					i;

	if (argc != 3)
		return (ft_printf("Quantidade de argumentos inválida."));
	siga.sa_flags = 0;
	siga.sa_handler = ft_received;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		ft_send_signal(pid, argv[2][i]);
		i++;
	}
	ft_send_signal(pid, '\n');
	ft_send_signal(pid, '\0');
	return (0);
}
