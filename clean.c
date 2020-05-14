/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 14:10:32 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/14 14:36:44 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_args(t_minishell *sh)
{
    int     i;

    i = 0;
    while (i < sh->arg_count)
    {
        free(sh->args[i]);
        i++;
    }
}

void    clean(t_minishell *sh)
{
    free(sh->line);
	free(sh->bool);
    free_args(sh);
}