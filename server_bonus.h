/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:06:29 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/13 12:06:29 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include "libs/libft/libft.h"

void	handler(int n, siginfo_t *info, void *ucontext);

#endif