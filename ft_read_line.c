/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_line.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:55:19 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/09 13:34:18 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_read_line(t_minishell *sh)
{
	int		bufsize;
	int		position;
	char	ch;
	int		check;

	bufsize = 1024;
	position = 0;
	sh->line = malloc(sizeof(char) * bufsize);
	if (!sh->line)
		exit(EXIT_FAILURE);
	while (1)
	{
		check = read(0, &ch, 1);
		if (check == -1)
		{
			free(sh->line);
			exit(EXIT_FAILURE);
		}
		if (ch == EOF || ch == '\n')
		{
			sh->line[position] = '\0';
			break ;
		}
		else
			sh->line[position] = ch;
		position++;
		if (position >= bufsize)
		{
			bufsize += 1024;
			sh->line = ft_realloc(sh->line, bufsize - 1024, bufsize);
			if (!sh->line)
				exit(EXIT_FAILURE);
		}
	}
}
