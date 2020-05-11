/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bin.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 15:44:26 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/11 13:23:24 by novan-ve      ########   odam.nl         */
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

void	ft_echo(t_minishell *sh)
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

void	ft_env(t_minishell *sh)
{
	int		i;

	if (sh->env)
	{
		i = 0;
		while (i < sh->total)
		{
			ft_putendl(sh->env[i]);
			i++;
		}
	}
}

void	ft_export(t_minishell *sh)
{
	int		i;

	i = 1;
	if (!sh->env)
		ft_vector_init(sh);
	while (sh->args[i])
	{
		ft_vector_add(sh, sh->args[i]);
		i++;
	}
}

void	ft_unset(t_minishell *sh)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	while (sh->args[i])
	{
		j = 0;
		while (j < sh->total)
		{
			k = 0;
			while (sh->args[i][k] == ((char*)ft_vector_get(sh, j))[k])
			{
				if (sh->args[i][k + 1] == '\0' && ((char*)ft_vector_get(sh, j))[k + 1] == '=')
				{
					ft_vector_delete(sh, j);
					break;
				}
				if (sh->args[i][k + 1] == '\0' && ((char*)ft_vector_get(sh, j))[k + 1] == '\0')
				{
					ft_vector_delete(sh, j);
					break;
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
