/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 15:44:26 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/13 15:20:57 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(t_minishell *sh)
{
	int		newline;
	int		i;

	newline = 1;
	i = sh->arg_index + 1;
	if (!ft_strcmp(sh->args[sh->arg_index + 1], "-n"))
	{
		newline = 0;
		i++;
	}
	while (i < sh->arg_count)
	{
		ft_putstr(sh->args[i]);
		write(1, " ", 1);
		i++;
	}
	if (newline)
		write(1, "\n", 1);
}

void	builtin_cd(t_minishell *sh)
{
	if (sh->args[sh->arg_index + 1] == 0)
	{
		if (chdir(get_env(sh, "HOME")))
		{
			ft_error(strerror(errno));
		}
	}
	else if (sh->args[sh->arg_index + 2] != 0)
	{
		ft_error("too many arguments");
		return ;
	}
	else if (chdir(sh->args[sh->arg_index + 1]))
		ft_error(strerror(errno));
}

void	builtin_exit(void)
{
	exit(EXIT_SUCCESS);
}

void	builtin_pwd(void)
{
	char	path[1024];

	if (!getcwd(path, 1024))
		ft_error(strerror(errno));
	else
		ft_putendl(path);
}