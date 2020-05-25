/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_expand.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 23:45:04 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/24 17:18:05 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int		expand(int j, char *dst, char *env, t_minishell *sh)
{
	int		i;
	char	*src;

	if (!env)
	{
		put_error(strerror(errno));
		free(dst);
		return (-1);
	}
	src = get_env(sh, env);
	free(env);
	if (src)
	{
		i = 0;
		while (src[i] != '\0')
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		free(src);
	}
	return (j);
}

char	*expand_arg(t_minishell *sh, char *dst, char *src, int i)
{
	int		j;
	int		start;

	j = 0;
	while (src[i] != '\0')
	{
		i++;
		if (src[i - 1] == '$' && is_var_char(src[i]))
		{
			start = i;
			while (is_var_char(src[i]))
				i++;
			j = expand(j, dst, ft_substr(src, start, i - start), sh);
			if (j < 0)
				return (0);
		}
		else
		{
			dst[j] = src[i - 1];
			j++;
		}
	}
	dst[j] = '\0';
	return (dst);
}

char	*expand_var(t_minishell *sh, char *src)
{
	char	*dst;
	int		length;
	int		i;

	length = expand_length(sh, src);
	if (length < 0)
		return (0);
	dst = (char*)malloc(sizeof(char) * length + 1);
	if (!dst)
	{
		free(src);
		put_error(strerror(errno));
		return (0);
	}
	i = 0;
	dst = expand_arg(sh, dst, src, i);
	free(src);
	return (dst);
}

int		parse_expand_loop(t_minishell *sh)
{
	int		i;
	int		j;

	i = 0;
	while (i < sh->line_count)
	{
		j = 0;
		while (j < sh->arg_count[i])
		{
			if (is_var(sh->args[i][j]) > 0 && sh->data[i][j] != 1)
			{
				sh->args[i][j] = expand_var(sh, sh->args[i][j]);
				if (!sh->args[i][j])
					return (0);
				if (ft_strlen(sh->args[i][j]) == 0 && sh->data[i][j] == 0)
				{
					free(sh->args[i][j]);
					sh->args[i][j] = 0;
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		parse_expand(t_minishell *sh)
{
	if (!parse_expand_loop(sh))
		return (0);
	if (!parse_sanitize(sh))
		return (0);
	return (1);
}
