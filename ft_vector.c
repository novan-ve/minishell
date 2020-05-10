/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vector.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/10 12:19:14 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/10 12:36:33 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_vector_init(t_minishell *sh)
{
	sh->capacity = VECTOR_INIT_CAPACITY;
	sh->total = 0;
	sh->env = malloc(sizeof(void *) * sh->capacity);
}

int			ft_vector_total(t_minishell *sh)
{
	return (sh->total);
}

static void	ft_vector_resize(t_minishell *sh, int x)
{
	void	**items;

	items = ft_realloc(sh->env, sh->capacity, sizeof(void *) * x);
	if (!items)
	{
		ft_putendl("Minishell: vector resize failed");
		exit(EXIT_FAILURE);
	}
	sh->env = items;
	sh->capacity = x;
}

void		ft_vector_add(t_minishell *sh, void *s)
{
	if (sh->capacity == sh->total)
		ft_vector_resize(sh, sh->capacity * 2);
	sh->total++;
	sh->env[sh->total] = s;
}

void		ft_vector_set(t_minishell *sh, int index, void *s)
{
	if (index >= 0 && index < sh->total)
		sh->env[index] = s;
}

void		*ft_vector_get(t_minishell *sh, int index)
{
	if (index >= 0 && index < sh->total)
		return (sh->env[index]);
	return (NULL);
}

void		ft_vector_delete(t_minishell *sh, int index)
{
	int		i;

	if (index > 0 && index <= sh->total)
	{
		sh->env[index] = NULL;
		i = 0;
		while (i < sh->total - 1)
		{
			sh->env[i] = sh->env[i + 1];
			sh->env[i + 1] = NULL;
			i++;
		}
		sh->total--;
		if (sh->total > 0 && sh->total == sh->capacity / 4)
			ft_vector_resize(sh, sh->capacity / 2);
	}
}

void		ft_vector_free(t_minishell *sh)
{
	free(sh->env);
}
