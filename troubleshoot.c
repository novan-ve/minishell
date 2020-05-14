/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   troubleshoot.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 13:41:10 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/14 17:57:18 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void        show_args(t_minishell *sh)
{
    int i = 0;

    printf("arg_count = %d\n", sh->arg_count);
    while (i < sh->arg_count)
    {
        if (sh->args[i] != 0)
            printf("%s\n", sh->args[i]);
        i++;
    }
}