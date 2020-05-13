/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:43:26 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/13 03:00:05 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	t_minishell		sh;

	setup_list(&sh, env);
	//show_env(&sh); 							//UNCOMMENT FOR DEBUGGING
	while (1)
	{
		ft_putstr("minishell> ");
		read_input(&sh);
		split_input(&sh);
		//show_args(&sh);    				//UNCOMMENT FOR DEBUGGING
		execute(&sh);
		clean(&sh);
	}
	return (0);
}
