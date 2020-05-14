/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 14:28:55 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/14 16:43:09 by abobas        ########   odam.nl         */
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

void	split_input(t_minishell *sh)
{
	count(sh);
	sh->args = (char**)malloc(sizeof(char *) * sh->arg_count + 1);
	if (sh->args == 0)
		exit(EXIT_FAILURE);
	split(sh);
}
