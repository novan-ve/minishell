/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bin.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 15:44:26 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/09 13:31:04 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_minishell *sh)
{
	if (sh->args[1] == NULL)
		ft_putendl("Minikube: cd requires an argument");
	else if (chdir(sh->args[1]))
		ft_putendl(strerror(errno));
	sh->status = 1;
}

void	ft_exit(t_minishell *sh)
{
	sh->status = 0;
}

void	ft_pwd(t_minishell *sh)
{
	char	path[128];

	if (!getcwd(path, sizeof(path)))
		ft_putstr(strerror(errno));
	else
		ft_putstr(path);
	write(1, "\n", 1);
	sh->status = 1;
}

int		ft_echo(t_minishell *sh)
{
	int		i;

	if (ft_strcmp(sh->args[1], "-n"))
		i = 1;
	else
		i = 2;
	while (sh->args[i])
	{
		ft_putstr(sh->args[i]);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	sh->status = 1;
}
