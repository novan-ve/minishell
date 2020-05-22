/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 02:38:51 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/18 02:42:11 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		env_cmp(char *reference, char *data)
{
	int		i;

	i = 0;
	if (!reference || !data)
		return (1);
	while (reference[i] != '\0' && data[i] != '\0')
	{
		if (reference[i] != data[i])
			return (1);
		i++;
	}
	if (reference[i] == '\0' && data[i] == '=')
		return (0);
	else
		return (1);
}
