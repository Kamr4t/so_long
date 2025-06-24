/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 08:35:30 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/24 09:50:23 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_map_object_count(int c)
{
	static int	count_col = 0;
	static int	count_player = 0;
	static int	count_exit = 0;

	if (c == 'C')
	{
		count_col++;
		ft_col_count(1);
	}
	if (c == 'P')
		count_player++;
	if (c == 'E')
		count_exit++;
	if (c == 1)
	{
		if (count_col == 0)
			return (0);
		if (count_player != 1)
			return (0);
		if (count_exit != 1)
			return (0);
	}
	return (1);
}

static int	ft_map_valid(int c)
{
	if (c == '0')
		return (1);
	if (c == '1')
		return (1);
	if (c == 'C')
		return (1);
	if (c == 'P')
		return (1);
	if (c == 'E')
		return (1);
	return (0);
}

static int	ft_map_rec(char **map)
{
	int		len_base;
	int		len_tmp;
	int		i;

	len_base = ft_strlen_nl(map[0]);
	i = 1;
	while (map[i] != NULL)
	{
		len_tmp = ft_strlen_nl(map[i]);
		if (len_base != len_tmp)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_map_wall_check(char **map)
{
	int		len;
	int		hight;
	int		i;

	hight = ft_map_hight(map);
	len = ft_strlen_nl(map[0]);
	i = 0;
	while (i < len)
	{
		if (map[0][i] != '1' || map[hight - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < hight)
	{
		if (map[i][0] != '1')
			return (0);
		if (map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_map_check(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_map_rec(map) == 0)
		return (0);
	if (ft_map_wall_check(map) == 0)
		return (0);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			ft_map_object_count(map[i][j]);
			if (ft_map_valid(map[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (ft_map_object_count(1) == 0)
		return (0);
	return (1);
}
