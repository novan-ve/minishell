/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 03:49:40 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/26 22:06:41 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

t_vector	init_env(char **env)
{
	t_vector		v;

	if (!vector_init(&v))
	{
		put_error(strerror(errno));
		exit(1);
	}
	if (!vector_populate(&v, env))
	{
		put_error(strerror(errno));
		exit(1);
	}
	if (!v.data)
	{
		put_error(strerror(errno));
		exit(1);
	}
	env_add("?=0", &v);
	return (v);
}

t_minishell	init_minishell(void)
{
	t_minishell		sh;

	sh.env = 0;
	sh.line = 0;
	sh.args = 0;
	sh.data = 0;
	sh.file_descriptor = 0;
	sh.line_count = 0;
	sh.arg_count = 0;
	sh.saved_stdin = dup(0);
	if (sh.saved_stdin < 0)
	{
		put_error(strerror(errno));
		exit(1);
	}
	sh.saved_stdout = dup(1);
	if (sh.saved_stdout < 0)
	{
		put_error(strerror(errno));
		exit(1);
	}
	return (sh);
}
