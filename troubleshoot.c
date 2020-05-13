/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   troubleshoot.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 13:41:10 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/13 02:17:59 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void        show_args(t_minishell *sh)
{
    int i = 0;

    printf("arg_count = %d\n", sh->arg_count);
    while (i < sh->arg_count)
    {
        printf("%s\n", sh->args[i]);
        i++;
    }
}

void        show_env(t_minishell *sh)
{
    t_env *list;

	list = sh->first_element;
	while (list)
    {
        printf("%s\n", list->data);
		list = list->next;
    }
}