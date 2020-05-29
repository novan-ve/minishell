/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins_1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 15:44:26 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/29 17:07:08 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void	echo(int ac, char **av, t_minishell *sh)
{
	int		newline;
	int		i;

	newline = 1;
	i = 1;
	if (ac > 1)
	{
		if (!ft_strcmp(av[i], "-n"))
		{
			newline = 0;
			i++;
		}
		while (i < ac)
		{
			ft_printf("%s", av[i]);
			if (i + 1 != ac)
				ft_printf(" ");
			i++;
		}
	}
	if (newline == 1)
		ft_printf("\n");
	env_add("?=0", sh->env);
}

void	pwd(t_minishell *sh)
{
	char	path[1024];

	if (!getcwd(path, 1024))
	{
		put_error(strerror(errno));
		env_add("?=1", sh->env);
	}
	else
	{
		ft_printf("%s\n", (path));
		env_add("?=0", sh->env);
	}
}

void	ft_exit(int arg_count, char **args, t_minishell *sh)
{
	int		i;
	int		ret;

	ft_printf("exit\n");
	if (arg_count == 1)
		exit(0);
	i = 0;
	while (args[1][i])
	{
		if (ft_isalpha(args[1][i]) && !(args[1][i] == '-' && i == 0))
		{
			ft_printf("Minishell: ");
			ft_printf("exit: %s: numeric argument required\n", args[1]);
			exit(2);
		}
		if (!(args[1][i] == '-' && i == 0))
			ret = ret * 10 + args[1][i] - 48;
		i++;
	}
	if (args[1][0] == '-' && (int)(ret / 256) % 2 && arg_count < 3)
		exit(256 - ret % 256);
	if (arg_count < 3)
		exit(ret % 256);
	put_error("exit: too many arguments");
	env_add("?=1", sh->env);
}
