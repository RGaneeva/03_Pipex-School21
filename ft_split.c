/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:04:34 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/08/28 14:04:58 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	w_count(char *str, char c)
{
	int	i;
	int	w_count;

	i = 0;
	w_count = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			w_count++;
		i++;
	}
	return (w_count);
}

static int	w_len(char *str, char c)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		lenght++;
	}
	return (lenght);
}

static char	**split(char *str, char c, char **res, int w_count)
{
	int	i;
	int	j;
	int	w_lenght;

	while (*str == c)
		str++;
	i = -1;
	while (++i < w_count)
	{
		while (*str == c)
			str++;
		j = 0;
		w_lenght = w_len(str, c);
		res[i] = (char *)malloc(sizeof(char) * (w_lenght + 1));
		if (!(res[i]))
			return (NULL);
		while (j < w_lenght)
		{
			res[i][j] = *str;
			str++;
			j++;
		}
		res[i][j] = '\0';
	}
	return (res);
}

char	**ft_split(char *str, char c)
{
	char	**res;
	int		w_counted;

	if (!str)
		return (NULL);
	w_counted = w_count(str, c);
	res = (char **)malloc(sizeof(char *) * (w_counted + 1));
	if (!(res))
		return (NULL);
	res = split(str, c, res, w_counted);
	res[w_counted] = NULL;
	return (res);
}
