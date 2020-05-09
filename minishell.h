/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:46:12 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/09 13:37:43 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define EXIT_SUCCES 0
# define EXIT_FAILURE 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/errno.h>
# include <string.h>

typedef	struct	s_minishell
{
	char		*line;
	char		**args;
	int			status;
}				t_minishell;

void			ft_read_line(t_minishell *sh);
void			ft_split_line(t_minishell *sh);
void			ft_execute(t_minishell *sh);
void			ft_launch(t_minishell *sh);

void			ft_cd(t_minishell *sh);
void			ft_exit(t_minishell *sh);
void			ft_pwd(t_minishell *sh);
int				ft_echo(t_minishell *sh);

void			*ft_realloc(void *ptr, size_t prev, size_t new);
int				ft_isspace(char c);
size_t			ft_strlen(const char *s);
void			ft_putstr(char *s);
void			ft_putendl(char *s);
int				ft_strcmp(const char *s1, const char *s2);

#endif
