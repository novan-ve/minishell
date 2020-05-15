/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 17:00:39 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/15 16:26:32 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		length;
	char	*new;
	int		i;
	int		y;

	i = 0;
	y = 0;
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char*)malloc(sizeof(char) * length);
	if (!new)
		exit(EXIT_FAILURE);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			new[y] = s1[i];
			y++;
			i++;
		}
		i = 0;
	}
	if (s2)
	{
		while (s2[i] != '\0')
		{
			new[y] = s2[i];
			y++;
			i++;
		}
	}
	new[y] = '\0';
	return (new);
}

char	*ft_trim(char *src)
{
	char	*dst;
	int		i;
	int		y;
	int		length;

	length = ft_strlen(src) - 1;
	i = 0;
	y = 1;
	dst = (char*)malloc(sizeof(char) * length);
	if (!dst)
		exit(EXIT_FAILURE);
	while (y < length)
	{
		dst[i] = src[y];
		i++;
		y++;
	}
	dst[i] = '\0';
	free(src);
	return (dst);
}

int		quote_check(t_minishell *sh)
{
	int		i;
	int		quote;
	int		count;

	i = 0;
	quote = 0;
	count = 0;
	while (sh->line[i])
	{
		if (!quote && (sh->line[i] == 34 || sh->line[i] == 39))
		{
			quote = sh->line[i];
			count = 1;
		}
		else if (sh->line[i] == quote)
			count++;
		i++;
	}
	if (count % 2)
	{
		free(sh->line);
		ft_error("Missing quotes");
		return (0);
	}
	return (1);
}
