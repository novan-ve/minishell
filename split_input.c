/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 14:28:55 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/14 14:40:35 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count(t_minishell *sh)
{
	int		i;

	i = 0;
	sh->arg_count = 0;
	while (sh->line[i] != '\0')
	{
		if (ft_isspace(sh->line[i]))
			i++;
		else if (sh->line[i] == ';')
		{
			sh->arg_count++;
			i++;
		}
		else
		{
			while (sh->line[i] != '\0' && !ft_isspace(sh->line[i]) && sh->line[i] != ';')
				i++;
			sh->arg_count++;
		}
	}
}

void	split(t_minishell *sh)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	if (sh->line[i] == '\0')
	{
		sh->args[j] = ft_strdup("");
		return ;
	}
	while (sh->line[i] != '\0')
	{
		if (ft_isspace(sh->line[i]))
			i++;
		else if (sh->line[i] == ';')
		{
			sh->args[j] = ft_strdup(";");
			sh->arg_index++;
			j++;
			i++;
		}
		else
		{
			start = i;
			while (sh->line[i] != '\0' && !ft_isspace(sh->line[i]) && sh->line[i] != ';')
				i++;
			sh->args[j] = ft_substr(sh->line, start, i - start);
			j++;
		}
	}
	sh->args[j] = 0;
}

void	init_bool(t_minishell *sh)
{
	int		i;

	sh->bool = (int*)malloc(sizeof (int) * sh->arg_count);
	if (sh->bool == 0)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < sh->arg_count)
	{
		sh->bool[i] = 0;
		i++;
	}
	// for(i = 0; i < sh->arg_count; ++i){printf("bool[%d] = %d\n", i, sh->bool[i]);}	//UNCOMMENT FOR DEBUGGING
}

void	split_input(t_minishell *sh)
{
	count(sh);
	init_bool(sh);
	sh->args = (char**)malloc(sizeof(char *) * sh->arg_count + 1);
	if (sh->args == 0)
		exit(EXIT_FAILURE);
	split(sh);
}
