/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input_2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/14 16:59:25 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/14 17:09:44 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int         check_env(char *arg)
{
    if (arg[0] == 36)
        return (1);
    return (0);
}

void        substitute_env(t_minishell *sh, int i)
{
    char    *env;
    char    *result;

    env = ft_substr(sh->args[i], 1, ft_strlen(sh->args[i]) - 1);
    result = get_env(sh, env);
    free(sh->args[i]);
    free(env);
    sh->args[i] = result;
}

void        parse_env(t_minishell *sh)
{
    int     i;

    i = 0;
    while (i < sh->arg_count)
    {
        if (check_env(sh->args[i]) && !sh->bool[i])
            substitute_env(sh, i);
        i++;
    }
}