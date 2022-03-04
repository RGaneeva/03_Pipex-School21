/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 12:13:38 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/08/29 12:13:42 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

void	ft_error(int err_num)
{
	if (err_num == 0)
		ft_putstr("Check the number of arguments\n");
	else if (err_num == 1)
		ft_putstr("An error with opening file 1\n");
	else if (err_num == 2)
		ft_putstr("An error with opening file 2\n");
	else if (err_num == 3)
		ft_putstr("Pipe wasn't created\n");
	else if (err_num == 4)
		ft_putstr("An error with fork\n");
	else if (err_num == 5)
		ft_putstr("An error with excve\n");
	else if (err_num == 6)
		ft_putstr("An error with duplication\n");
	exit(0);
}

void	struct_init(t_struct *pipex)
{
	pipex->way = 0;
	pipex->cmd = 0;
	pipex->path_cmd = 0;
}

void	path_finder(char **environ, t_struct *pipex)
{
	int		i;
	char	*path;

	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i];
			pipex->way = ft_split(path, ':');
		}
		i++;
	}
}

char	*path_cmd_finder(t_struct *pipex)
{
	int		i;
	int		cmd;
	char	*result;

	i = -1;
	while (pipex->way[++i])
	{
		pipex->cmd[0] = ft_strjoin("/", pipex->cmd[0]);
		result = ft_strjoin(pipex->way[i], pipex->cmd[0]);
		cmd = open(result, O_RDONLY);
		if (cmd != -1)
			break ;
		free(result);
	}
	if (cmd == -1)
		return (0);
	else
		return (result);
}
