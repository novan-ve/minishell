/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   launch.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 14:22:47 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/21 13:23:50 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

void	signal_catch()
{
}

void	waiting(pid_t pid)
{
	int		status;

	status = 1;
	while (1)
	{
		waitpid(pid, &status, 0);			/// UNTRACED PARENT PROCESS TO ESCAPE SIGNALS ????
		if (WIFEXITED(status) || WIFSIGNALED(status))
			break ;
	}
}

void	execute_bin(char **av, t_minishell *sh)
{
	pid_t	pid;
	char	*executable;

	if (!(executable = ft_strjoin("/bin/", av[0])))
		return ;
	pid = fork();
	signal(SIGINT, signal_catch);
	signal(SIGQUIT, signal_catch);
	if (pid < 0)
		put_error(strerror(errno));
	else if (pid == 0)
	{
		if (execve(executable, av, sh->env->data) < 0)
		{
			put_error(strerror(errno));
			exit(1);
		}
	}
	else
		waiting(pid);
}
