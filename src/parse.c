/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/14 16:16:35 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/26 20:20:52 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		parse(t_minishell *sh)
{
	if (!parse_read(sh))
		return (0);
	if (!parse_split(sh))
		return (0);
	if (!parse_validate(sh))
		return (0);
	if (!parse_quotes(sh))
		return (0);
	if (!parse_expand(sh))
		return (0);
	if (!parse_validate(sh))
		return (0);
	if (!parse_pipe(sh))
		return (0);
	if (!parse_redirect(sh))
		return (0);
	return (1);
}
