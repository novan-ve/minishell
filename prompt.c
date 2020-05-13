/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 15:49:50 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/13 16:26:12 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *read_host(int fd)
{
  	int		bufsize;
	int		i;
	char	ch;
    char    *host;
    int     check;

	bufsize = 128;
	i = 0;
	host = (char*)malloc(sizeof(char) * bufsize);
	if (!host)
		exit(EXIT_FAILURE);
	while (1)
	{
		if (read(fd, &ch, 1) < 0)
			exit(EXIT_FAILURE);
		if (ch == '\n')
		{
			host[i] = '\0';
			return (host);
		}
		else
			host[i] = ch;
		i++;
		if (i == bufsize)
		{
			bufsize += 128;
			host = ft_reallocate(host, bufsize - 128, bufsize);
        }
	}
}

char    *get_host(void)
{
    int     fd;
    char    *host;

    fd = open("/proc/sys/kernel/hostname", O_RDONLY);
    host = read_host(fd);
    close (fd);
    return (host);
}

void    print_prompt(t_minishell *sh)
{
    char    *host;
    char    work_dir[128];

    host = get_host();
    getcwd(work_dir, 1024);
    ft_putstr(get_env(sh, "USER"));
    ft_putstr("@");
    ft_putstr(host);
    free(host);
    ft_putstr(":");
    ft_putstr(work_dir);
    ft_putstr("$ ");
}