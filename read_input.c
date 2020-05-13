/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:55:19 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/12 23:19:42 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char 	*reallocate(char *line, int prev, int new)
{
	char	*dest;
	int		i;

	dest = (char*)malloc(sizeof(char) * new);
	if (!dest)
		exit(EXIT_FAILURE);
	i = 0;
	while (prev > 0)
	{
		dest[i] = line[i];
		i++;
		prev--;	
	}
	free(line);
	return (dest);
}

void	read_input(t_minishell *sh)
{
	int		bufsize;
	int		i;
	char	ch;
	int		check;

	bufsize = 1024;
	i = 0;
	sh->line = (char*)malloc(sizeof(char) * bufsize);
	if (!sh->line)
		exit(EXIT_FAILURE);
	while (1)
	{
		if (check = read(0, &ch, 1) < 0)
			exit(EXIT_FAILURE);
		if (ch == '\n')
		{
			sh->line[i] = '\0';
			return ;
		}
		else
			sh->line[i] = ch;
		i++;
		if (i == bufsize)
		{
			bufsize += 1024;
			sh->line = reallocate(sh->line, bufsize - 1024, bufsize);
		}
	}
}
