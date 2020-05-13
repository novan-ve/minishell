/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 13:15:15 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/13 13:29:21 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_strdup(char *str)
{
    char    *dst;
    char    i;

    i = 0;
    dst = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
    if (!dst)
        exit(EXIT_FAILURE);
    while (str[i] != '\0')
    {
        dst[i] = str[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = (char*)malloc(sizeof(char) * (len + 1));
	if (ptr == 0)
		exit(EXIT_FAILURE);
	str = ptr;
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[len] = '\0';
	return (str);
}

void    ft_error(char *s)
{
    write(2, "Minishell: ", 11);
    write(2, s, ft_strlen(s));
    write(2 , "\n", 1);
}

int		ft_envcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s1[i] != '=')
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (s1[i - 1] - s2[i - 1]);
}
