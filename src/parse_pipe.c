/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_pipe.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/26 15:42:45 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/26 19:35:26 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int		count_pipes(char **arg)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (arg[i] != 0)
	{
		if (!ft_strcmp(arg[i], "|"))
			count ++;
		i++;
	}
	return (count);	
}

int		*count_pipe_args(t_minishell *sh, int *arg_count, int i)
{
	int		j;
	int		y;
	int		x;

	j = 0;
	y = 0;
	while (y < i)
	{
		arg_count[j] = sh->arg_count[y];
		j++;
		y++;
	}
	x = 0;
	arg_count[j] = 0;
	while (sh->args[y][x] != 0)
	{
		if (!ft_strcmp(sh->args[y][x], "|"))
		{
			j++;
			arg_count[j] = 0;
		}
		else
			arg_count[j]++;
		x++;
	}
	y++;
	j++;
	while (y < sh->line_count)
	{
		arg_count[j] = sh->arg_count[y];
		j++;
		y++;
	}
	return (arg_count);
}

int		array_pipe_helper(t_minishell *sh, char ***arr, int i, int x)
{
	int		y;
	int		z;

	y = 0;
	z = 0;
	while (y < sh->arg_count[i])
	{
		if (!ft_strcmp(sh->args[i][y], "|"))
		{
			x++;
			z = 0;
		}
		else
		{
			arr[x][z] = ft_strdup(sh->args[i][y]);
			if (!arr[x][z])
				return (0);
			z++;
		}
		y++;
	}
	return (1);
}

char			***fill_pipe_array(t_minishell *sh, int line, int *arg, int i)
{
	int		y;
	int		x;
	char	***arr;

	arr = allocate_array(line, arg);
	if (!arr)
		return (0);
	y = 0;
	x = 0;
	while (y < i)
	{
		if (!array_helper(sh, arr, y, x))
		{
			put_error(strerror(errno));
			free_array(arr, line, arg);
			return (0);
		}
		x++;
		y++;
	}
	if (!array_pipe_helper(sh, arr, y, x))
	{
		put_error(strerror(errno));
		free_array(arr, line, arg);
		return (0);
	}
	x = x + count_pipes(sh->args[y]) + 1;
	y++;
	while (y < sh->line_count)
	{
		if (!array_helper(sh, arr, y, x))
		{
			put_error(strerror(errno));
			free_array(arr, line, arg);
			return (0);
		}
		x++;
		y++;
	}
	return (arr);
}

int		split_pipe_commands(t_minishell *sh, int i)
{
	char		***array;
	int			*arg_count;
	int			line_count;

	line_count = sh->line_count + count_pipes(sh->args[i]);
	arg_count = allocate_counter(line_count);
	if (!arg_count)
		return (0);
	arg_count = count_pipe_args(sh, arg_count, i);
	array = fill_pipe_array(sh, line_count, arg_count, i);
	if (!array)
		return (0);
	free_array(sh->args, sh->line_count, sh->arg_count);
	free(sh->arg_count);
	sh->args = array;
	sh->line_count = line_count;
	sh->arg_count = arg_count;
	return (1);
}

int		check_pipes(char **arg)
{
	int		i;
	
	i = 0;
	while (arg[i] != 0)
	{
		if (!ft_strcmp(arg[i], "|"))
			return (1);
		i++;
	}
	return (0);
}

int		split_pipes(t_minishell *sh)
{
	int		i;
	
	i = 0;
	while (i < sh->line_count)
	{
		if (check_pipes(sh->args[i]))
		{
			if (!split_pipe_commands(sh, i))
				return (0);
			else
			{
				i = 0;
				continue ;
			}
		}
		i++;
	}
	return (1);
}

int		parse_pipe(t_minishell *sh)
{
	free_data(sh->data, sh->line_count);
	sh->data = 0;
	if (!split_pipes(sh))
		return (0);
	return (1);
}