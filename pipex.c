/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 12:14:18 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/08/29 12:14:21 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execve(t_struct	*pipex)
{
	if (execve(pipex->path_cmd, pipex->cmd, NULL) < 0)
		ft_error(5);
}

void	parent_proc(t_struct *pipex, char **argv, char **environ, int *end)
{
	wait(NULL);
	close(end[1]);
	pipex->pid = fork();
	if (!pipex->pid)
	{
		pipex->outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if (pipex->outfile < 0)
			ft_error(2);
		pipex->cmd = ft_split(argv[3], ' ');
		path_finder(environ, pipex);
		pipex->path_cmd = path_cmd_finder(pipex);
		if (dup2(end[0], STDIN_FILENO) < 0)
			ft_error(6);
		if (dup2(pipex->outfile, STDOUT_FILENO) < 0)
			ft_error(6);
		close(end[0]);
		close(pipex->outfile);
		if (pipex->path_cmd == 0)
			perror("No such command found");
		else
			ft_execve(pipex);
	}
	wait(NULL);
}

void	child_proc(t_struct	*pipex, char **argv, char **environ, int *end)
{
	close(end[0]);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		ft_error(1);
	pipex->cmd = ft_split(argv[2], ' ');
	path_finder(environ, pipex);
	pipex->path_cmd = path_cmd_finder(pipex);
	if (dup2(pipex->infile, STDIN_FILENO) < 0)
		ft_error(6);
	if (dup2(end[1], STDOUT_FILENO) < 0)
		ft_error(6);
	close(end[1]);
	close(pipex->infile);
	if (pipex->path_cmd == 0)
		perror("No such command found");
	else
		ft_execve(pipex);
}

int	ft_pipex(t_struct *pipex, char **argv, char **environ)
{
	int		end[2];

	if (pipe(end) < 0)
		ft_error(3);
	pipex->pid = fork();
	if (pipex->pid < 0)
		ft_error(4);
	if (pipex->pid == 0)
		child_proc(pipex, argv, environ, end);
	else
		parent_proc(pipex, argv, environ, end);
	free(pipex);
	exit(0);
}

int	main(int argc, char **argv, char **environ)
{
	t_struct	*pipex;

	if (argc != 5)
		ft_error(0);
	pipex = malloc(sizeof(t_struct));
	struct_init(pipex);
	ft_pipex(pipex, argv, environ);
}
