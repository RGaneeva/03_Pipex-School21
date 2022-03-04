/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 12:18:03 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/08/29 12:18:06 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_struct
{
	char	**way;
	char	**cmd;
	char	*path_cmd;
	int		infile;
	int		outfile;
	pid_t	pid;
}				t_struct;

int		ft_pipex(t_struct *pipex, char **argv, char **environ);
void	child_proc(t_struct	*pipex, char **argv, char **environ, int *end);
void	parent_proc(t_struct *pipex, char **argv, char **environ, int *end);
void	ft_execve(t_struct	*pipex);
void	struct_init(t_struct *pipex);
void	ft_error(int err_num);
void	ft_putstr(char *str);
void	path_finder(char **environ, t_struct *pipex);
char	*path_cmd_finder(t_struct *pipex);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *prefstr, char const *sufstr);
char	**ft_split(char *str, char c);

#endif
