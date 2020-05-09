/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/09 13:35:35 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/09 13:35:38 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (d == 0 && s == 0 && n != 0)
		return (NULL);
	while (n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}

void	*ft_realloc(void *ptr, size_t prev, size_t new)
{
	void	*result;

	if (new == 0)
	{
		free(ptr);
		return (0);
	}
	result = malloc(new);
	if (!result)
	{
		if (!ptr)
			free(ptr);
		return (0);
	}
	if (!ptr)
		return (result);
	ft_memcpy(result, ptr, prev);
	free(ptr);
	return (result);
}
