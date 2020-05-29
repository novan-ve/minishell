/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/22 14:05:37 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/29 12:08:01 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	ft_split_free_array(char **array, int j)
{
	j--;
	while (j >= 0)
	{
		if (array[j])
			free(array[j]);
		j--;
	}
	free(array);
}

int		ft_split_counter(char *str, char c)
{
	int i;
	int count;
	int traverse;

	i = 0;
	count = 0;
	traverse = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (!traverse)
				count++;
			traverse = 1;
		}
		else
			traverse = 0;
		i++;
	}
	return (count);
}

char	**ft_split_allocate_array(char **array, char *str, char c, int count)
{
	int	j;
	int	i;
	int length;

	j = 0;
	i = 0;
	while (j < count)
	{
		length = 0;
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			length++;
		}
		array[j] = (char*)malloc(sizeof(char) * (length + 1));
		if (!array[j])
		{
			ft_split_free_array(array, j);
			return (0);
		}
		j++;
	}
	return (array);
}

char	**ft_split_fill_array(char **array, char *str, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			start = i;
			while (str[i] != c && str[i] != '\0')
				i++;
			array[j] = ft_substr(str, start, i - start);
			if (!array[j])
			{
				ft_split_free_array(array, j);
				return (0);
			}
			j++;
		}
	}
	return (array);
}

char	**ft_split(char *str, char c)
{
	char	**array;
	int		count;

	if (!str)
		return (0);
	count = ft_split_counter(str, c);
	array = (char**)malloc(sizeof(char*) * count + 1);
	if (!array)
		return (0);
	array[count] = 0;
	array = ft_split_allocate_array(array, str, c, count);
	if (!array)
		return (0);
	return (ft_split_fill_array(array, str, c));
}
