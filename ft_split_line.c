/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 14:28:55 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/09 13:36:01 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	char	*str;
	void	*ptr;
	size_t	i;

	i = 0;
	if (s == 0 || len <= 0)
		return (0);
	ptr = (char*)malloc(sizeof(char) * (len + 1));
	if (ptr == 0)
		return (0);
	str = ptr;
	while (s[i] != '\0' && i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[len] = '\0';
	return (str);
}

int		ft_count(char *s)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		if (!ft_isspace(s[index]))
		{
			while (s[index] != '\0' && !ft_isspace(s[index]))
				index++;
			count++;
		}
		else
			index++;
	}
	return (count);
}

void	ft_free(char *line, char **s, int i)
{
	while (i >= 0)
	{
		if (s[i])
			free(s[i]);
		i--;
	}
	if (s)
		free(s);
	if (line)
		free(line);
	exit(EXIT_FAILURE);
}

char	**ft_splitloop(char *s, char **result)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (s[i] != '\0' && ft_count(s) > 0)
	{
		if (ft_isspace(s[i]))
			i++;
		else
		{
			start = i;
			while (s[i] != '\0' && !ft_isspace(s[i]))
				i++;
			result[j] = ft_substr2(s, start, i - start);
			if (result[j] == 0)
				ft_free(s, result, j);
			j++;
		}
	}
	result[j] = 0;
	return (result);
}

void	ft_split_line(t_minishell *sh)
{
	sh->args = (char**)malloc(sizeof(char *) * (ft_count(sh->line) + 1));
	if (sh->args == 0)
	{
		free(sh->line);
		exit(EXIT_FAILURE);
	}
	if (ft_splitloop(sh->line, sh->args) == NULL)
		sh->args = NULL;
	else
		sh->args = ft_splitloop(sh->line, sh->args);
}
