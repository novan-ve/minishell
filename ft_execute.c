/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_execute.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 15:50:21 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/11 13:00:01 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute(t_minishell *sh)
{
	if (sh->args[0] == NULL)
		sh->status = 1;
	else if (ft_strcmp(sh->args[0], "cd") == 0)
		ft_cd(sh);
	else if (ft_strcmp(sh->args[0], "exit") == 0)
		ft_exit(sh);
	else if (ft_strcmp(sh->args[0], "pwd") == 0)
		ft_pwd(sh);
	else if (ft_strcmp(sh->args[0], "echo") == 0)
		ft_echo(sh);
	else if (ft_strcmp(sh->args[0], "env") == 0)
		ft_env(sh);
	else if (ft_strcmp(sh->args[0], "export") == 0)
		ft_export(sh);
	else if (ft_strcmp(sh->args[0], "unset") == 0)
		ft_unset(sh);
	else
		ft_launch(sh);
}
