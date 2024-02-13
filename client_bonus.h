/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:06:29 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/13 12:06:29 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include "libs/libft/libft.h"

void	ft_send_message(int pid, char *str);
void	ft_send_signal(int pid, char c);
void	ft_received(int sig);

#endif