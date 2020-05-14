/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:55:19 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/13 16:11:11 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_input(t_minishell *sh)
{
	int		bufsize;
	int		i;
	char	ch;

	bufsize = 1024;
	i = 0;
	sh->line = (char*)malloc(sizeof(char) * bufsize);
	if (!sh->line)
		exit(EXIT_FAILURE);
	while (1)
	{
		if (read(0, &ch, 1) < 0)
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
			sh->line = ft_reallocate(sh->line, bufsize - 1024, bufsize);
		}
	}
}
