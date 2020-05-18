/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environment.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 00:53:59 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/18 16:53:42 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>

int			vector_search_env(t_vector *v, char *reference)
{
	int		index;

	index = 0;
	while (index < v->total)
	{
		if (!env_cmp(reference, v->data[index]))
			return (index);
		index++;
	}
	return (-1);
}

char		*get_env(t_minishell *sh, char *env)
{
	char	*tmp;
	
	if (!(tmp = vector_get(sh->env, vector_search_env(sh->env, env))))
		return (0);
	if (!(tmp = ft_substr(tmp, ft_strlen(env) + 1, ft_strlen(tmp) - ft_strlen(env))))
	{
		put_error(strerror(errno));
		return (0);
	}
	return (tmp);
}

void		export(int ac, char **av, t_minishell *sh)
{
	int		i;
	char	*insert;
	
	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (is_env(av[i]))
			{
				if (!(insert = ft_strdup(av[i])))
					put_error(strerror(errno));
				else
					vector_add(sh->env, insert);
			}
			i++;
		}
	}
}

void	unset(int ac, char **av, t_minishell *sh)
{
	int		delete;
	int		i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (is_env(av[i]))
				put_error("Not a valid identifier");
			delete = vector_search_env(sh->env, av[i]);
			if (delete > 0)
				vector_delete(sh->env, delete);
			i++;
		}
	}
}
