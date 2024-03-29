/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 15:37:31 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/28 19:37:30 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void	signal_catch(int signal)
{
	if (signal == SIGINT)
		ft_printf("\n%s", g_prompt);
}

void	signal_handler(void)
{
	if (signal(SIGINT, signal_catch) == SIG_ERR)
	{
		put_error(strerror(errno));
		exit(1);
	}
	if (signal(SIGQUIT, signal_catch) == SIG_ERR)
	{
		put_error(strerror(errno));
		exit(1);
	}
}
