/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   launch.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 14:22:47 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/13 04:19:42 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*	WUNTRACED: Also return if a child has stopped
	WIFEXITED: Returns true if child terminated normally
	WIFSIGNALED: Returns true if child was terminated by a signal */

#include "minishell.h"

void	launch(t_minishell *sh)
{
	pid_t	pid;
	pid_t	wpid;
	int		check;

	pid = fork();
	if (pid == 0)
	{
		if (execve(sh->args[0], sh->args, NULL) == -1)
			ft_putendl("Minikube: execve failed");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_putendl("Minikube: fork failed");
	else
	{
		while (1)
		{
			wpid = waitpid(pid, &check, WUNTRACED);
			if (WIFEXITED(check) || WIFSIGNALED(check))
				break ;
		}
	}
}
