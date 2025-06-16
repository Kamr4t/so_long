/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:14:26 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/16 16:59:18 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_int(char *s, char *buffer, ssize_t read_bytes)
{
	if (buffer[read_bytes - 1] == '\0')
		return (1);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

int	ft_pos_nl(const char *str, size_t start)
{
	size_t	i;

	i = 0;
	while (str[i + start] != '\0')
	{
		if (str[i + start] == '\n')
		{
			return (i + 1);
		}
		i++;
	}
	return (i);
}

char	*ft_build_str(char *s, int start)
{
	char	*array;
	int		i;
	int		len;

	len = ft_pos_nl(s, start);
	i = 0;
	array = malloc(len * sizeof(char) + 1);
	while (i < len)
	{
		array[i] = s[i + start];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*ft_memcat(char *s1, char *s2)
{
	char	*array;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_pos_nl(s1, 0);
	len_s2 = ft_pos_nl(s2, 0);
	array = malloc((len_s1 + len_s2) * sizeof(char) + 1);
	i = 0;
	while (s1[i] != '\0')
	{
		array[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		array[i + j] = s2[j];
		j++;
	}
	array[i + j] = '\0';
	free (s1);
	return (array);
}

int	ft_start(char *s, int start)
{
	int	i;

	i = 0;
	while (s[i + start] != '\0')
	{
		if (s[i + start] == '\n' && s[i + start + 1] != '\0')
		{
			return (i + start + 1);
		}
		i++;
	}
	return (0);
}
