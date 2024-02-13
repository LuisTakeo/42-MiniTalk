/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:49:36 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/12 10:49:36 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handler(int n, siginfo_t *info, void *ucontext)
{
	static int	i;
	static char	c;

	if (!ucontext)
		return ;
	if (n == SIGUSR1)
		c += 1 << i;
	else if (n == SIGUSR2)
		c += 0 << i;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	__pid_t				pid;
	struct sigaction	siga;

	pid = getpid();
	siga.sa_flags = SA_SIGINFO;
	siga.sa_sigaction = handler;
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
		pause();
	return (0);
}
