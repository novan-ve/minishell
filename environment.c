/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environment.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 00:53:59 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/13 04:39:03 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char        *get_home(t_minishell *sh)
{
    t_env   *list;

	list = sh->first_element;
	while (list)
    {
        if (!ft_envcmp("HOME=", list->data))
            return (ft_substr(list->data, 5, (ft_strlen(list->data) - 4)));
        list = list->next;
    }  
}

void        env_show(t_minishell *sh)
{
    t_env *list;

	list = sh->first_element;
	while (list)
    {
        if (list->data)
            ft_putendl(list->data);
		list = list->next;
    }
}

void        env_export(t_minishell *sh)
{
    char    *insert;
    int     i;

    i = 0;
    insert = ft_strdup(sh->args[sh->arg_index + 1]);
    while (insert[i] != '\0')
    {
        if (insert[i] == '=')
        {
            list_push_back(&sh->first_element, insert);
            return ;
        }
        i++;
    }
}

void    env_unset(t_minishell *sh)
{
    char    *data_ref;

    data_ref = sh->args[sh->arg_index + 1];
    list_remove_if(&sh->first_element, data_ref);
}
