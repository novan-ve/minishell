/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:43:26 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/14 18:11:59 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	t_minishell		sh;

	setup_list(&sh, env);
	while (1)
	{
		print_prompt(&sh);
		read_input(&sh);
		split_input(&sh);
		parse_input(&sh);
		///show_args(&sh);    					//UNCOMMENT FOR DEBUGGING
		execute(&sh);
		clean(&sh);
	}
	return (0);
	av[0][0] = ac;
}
