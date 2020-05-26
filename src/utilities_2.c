/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 16:45:43 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/26 22:04:06 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void	free_file_descriptor(int **file_descriptor, int line_count)
{
	int		y;

	y = 0;
	while (y < line_count)
	{
		if (file_descriptor[y])
			free(file_descriptor[y]);
		y++;
	}
	free(file_descriptor);
}

int		**allocate_file_descriptor(int line_count)
{
	int		i;
	int		**file_descriptor;

	i = 0;
	file_descriptor = (int**)malloc(sizeof(int*) * line_count);
	if (!file_descriptor)
		return (0);
	while (i < line_count)
	{
		file_descriptor[i] = (int*)malloc(sizeof(int) * 4);
		if (!file_descriptor[i])
		{
			free_file_descriptor(file_descriptor, i);
			return (0);
		}
		file_descriptor[i][0] = 0;
		file_descriptor[i][1] = 0;
		file_descriptor[i][2] = 0;
		file_descriptor[i][3] = 0;
		i++;
	}
	return (file_descriptor);
}
