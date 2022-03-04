/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 12:12:30 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/08/29 12:12:40 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	i = 0;
	while ((str1[i] || str2[i]) && i < num)
	{
		if (str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result++;
		str++;
	}
	return (result);
}

char	*ft_strjoin(char const *prefstr, char const *sufstr)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!prefstr || !sufstr)
		return (NULL);
	result = (char *)malloc(ft_strlen(prefstr) + ft_strlen(sufstr) + 1);
	if (result == NULL)
		return (NULL);
	while (prefstr[i])
	{
		result[i] = prefstr[i];
		i++;
	}
	while (sufstr[j])
	{
		result[i] = sufstr[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
