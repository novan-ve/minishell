/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_expand.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 23:45:04 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/18 15:45:21 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>
#include <stdio.h>

int		is_envchar(char c)
{
	return (c != ';' && c != '$' && c != 39 && !is_space(c) && c);
}

int		check_env(char *arg)
{
	int		i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == 36)
			return (i + 1);
		i++;
	}
	return (0);
}

int		substitute_len(t_minishell *sh, char *s)
{
	int		i;
	int		len;
	int		start;
	char	*tmp;

	i = 0;
	len = 0;
	while (s[i])
	{
		i++;
		if (s[i - 1] != '$')
			len++;
		else
		{
			start = i;
			while (is_envchar(s[i]))
				i++;
			tmp = ft_substr(s, start, i - start);
			if (!tmp)
				return (-1);
			len += ft_strlen(get_env(sh, tmp));
		}
	}
	return (len);
}

int		substitute_env2(t_minishell *sh, char *arg, char *tmp, int len)
{
	int		i;
	int		j;
	int		start;
	char	*tmp2;
	char	*result;

	i = 0;
	j = 0;
	while (i < len)
	{
		j++;
		if (tmp[j - 1] != '$')
		{
			arg[i] = tmp[j - 1];
			i++;
		}
		else
		{
			start = j;
			while (is_envchar(tmp[j]))
				j++;
			tmp2 = ft_substr(tmp, start, j - start);
			if (!tmp2)
				return (0);
			result = get_env(sh, tmp2);
			free(tmp2);
			start = 0;
			if (result)
				while (result[start])
				{
					arg[i] = result[start];
					i++;
					start++;
				}
			if (result)
				free(result);
		}
	}
	arg[i] = '\0';
	return (1);
}

char	*substitute_env(t_minishell *sh, char *arg)
{
	char	*tmp;
	int		len;

	tmp = ft_strdup(arg);
	if (!tmp)
		return (0);
	len = substitute_len(sh, arg);
	if (len == -1)
		return (0);
	free(arg);
	arg = malloc(sizeof(char) * len + 1);
	if (!arg)
		return (0);
	if (!substitute_env2(sh, arg, tmp, len))
		return (0);
	return (arg);
}

int		parse_expand(t_minishell *sh)
{
	int		i;
	int		j;

	i = 0;
	while (i < sh->line_count)
	{
		j = 0;
		while (j < sh->arg_count[i])
		{
			if (check_env(sh->args[i][j]) > 0 && sh->data[i][j] != 1)
			{
				sh->args[i][j] = substitute_env(sh, sh->args[i][j]);
				if (!sh->args[i][j])
					return (0);
			}
			j++;
		}
		i++;
	}
	if (!parse_sanitize(sh))
		return (0);
	return (1);
}
