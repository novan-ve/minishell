/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 15:50:21 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/13 04:21:34 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(t_minishell *sh)
{
	sh->arg_index = 0;
	while (sh->arg_index < sh->arg_count)
	{
		if (!ft_strcmp(sh->args[sh->arg_index], "cd"))
			builtin_cd(sh);
		else if (!ft_strcmp(sh->args[sh->arg_index], "exit"))
			builtin_exit(sh);
		else if (!ft_strcmp(sh->args[sh->arg_index], "pwd"))
			builtin_pwd(sh);
		else if (!ft_strcmp(sh->args[sh->arg_index], "echo"))
			builtin_echo(sh);
		else if (!ft_strcmp(sh->args[sh->arg_index], "env"))
			env_show(sh);
		else if (!ft_strcmp(sh->args[sh->arg_index], "export"))
			env_export(sh);
		else if (!ft_strcmp(sh->args[sh->arg_index], "unset"))
			env_unset(sh);
		//else
		//	launch(sh);
		sh->arg_index++;
	}
}
