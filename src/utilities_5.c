/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_5.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 20:12:43 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/24 14:42:01 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\a');
}

int		is_redirect(char c)
{
	return (c == '>' || c == '<');
}

void	put_error(char *s)
{
	write(2, "Minishell: ", 11);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
}

char	*get_identifier(char *reference)
{
	int		i;
	char	*identifier;

	i = 0;
	while (reference[i] != '\0')
	{
		if (reference[i] == '=')
		{
			if (!(identifier = ft_substr(reference, 0, i)))
			{
				put_error(strerror(errno));
				return (0);
			}
			return (identifier);
		}
		i++;
	}
	return (0);
}
