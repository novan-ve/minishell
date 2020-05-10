/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:43:26 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/10 12:12:47 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	t_minishell	sh;

	sh.status = 1;
	while (sh.status)
	{
		write(1, "> ", 2);
		ft_read_line(&sh);
		ft_split_line(&sh);
		ft_execute(&sh);
		free(sh.line);
		free(sh.args);
	}
	return (0);
}
