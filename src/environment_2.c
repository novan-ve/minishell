/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environment_2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/29 18:12:31 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/29 18:26:57 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void	print_environment_declare(t_vector *v)
{
	int		i;

	i = 0;
	while (i < v->total)
	{
		ft_printf("declare -x %s\n", v->data[i]);
		i++;
	}
}

int		export_3(t_minishell *sh)
{
	print_environment_declare(sh->env);
	return (0);
}

int		export_2(int ac, char **av, t_minishell *sh)
{
	int		i;
	int		exit;
	char	*identifier;

	i = 1;
	exit = 0;
	while (i < ac)
	{
		if (is_env(av[i]) == 1)
		{
			identifier = get_identifier(av[i]);
			if (!ft_strcmp("?", identifier))
				put_error("Not a valid identifier");
			else
				env_add(av[i], sh->env);
			exit = (!strcmp("?", identifier)) ? 1 : exit;
			if (identifier)
				free(identifier);
		}
		else if (is_env(av[i]) == -1)
			put_error("Not a valid identifier");
		i++;
	}
	return (exit);
}

void	export_1(int ac, char **av, t_minishell *sh)
{
	int		exit;

	exit = 0;
	if (ac > 1)
		exit = export_2(ac, av, sh);
	else
		exit = export_3(sh);
	if (exit == 1)
		env_add("?=1", sh->env);
	else
		env_add("?=0", sh->env);
}
