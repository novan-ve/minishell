/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 00:25:13 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/22 17:47:39 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void	waiting(pid_t pid, t_minishell *sh)
{
	int		status;

	status = 1;
	while (1)
	{
		waitpid(pid, &status, WUNTRACED);			/// UNTRACED PARENT PROCESS TO ESCAPE SIGNALS ????
		if (WIFEXITED(status))
		{					
			ft_printf("exit status = %d\n", WEXITSTATUS(status));					////WEXITSTATUS(status) for process exit status // 1, 0 zijn program exit status
			env_add("?=0", sh->env);
			return ;
		}
		//if (WIFSIGNALED(status))					/// SIGNAL STOP ??
		//{
		//	env_delete("?", sh->env);
		//	env_add("?=2", sh->env);
		//	return ;
		//}
	}
}

void	execute(char **av, t_minishell *sh)
{
	pid_t	pid;

	if (!(av[0] = get_executable(av[0], sh)))
		return ;
	pid = fork();
	if (pid < 0)
		put_error(strerror(errno));
	else if (pid == 0)
	{
		if (execve(av[0], av, sh->env->data) < 0)
		{
			env_add("?=1", sh->env);
			put_error(strerror(errno));
			exit(1);
		}
	}
	else
		waiting(pid, sh);
}
