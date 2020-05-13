/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 17:00:39 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/13 17:04:45 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char        *ft_strjoin(char *s1, char *s2)
{
    int     length;
    char    *new;
    int     i;
    int     y;

    i = 0;
    y = 0;
    length = ft_strlen(s1) + ft_strlen(s2) + 1;
    new = (char*)malloc(sizeof(char) * length);
    if (!new)
        exit(EXIT_FAILURE);
    while (s1[i] != '\0')
    {
        new[y] = s1[i];
        y++;
        i++;
    }
    i = 0;
    while (s2[i] != '\0')
    {
        new[y] = s2[i];
        y++;
        i++;
    }
    new[y] = '\0';
    return (new);
}