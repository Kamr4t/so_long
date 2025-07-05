/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:28:34 by codespace         #+#    #+#             */
/*   Updated: 2025/07/05 15:43:03 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = '1';
	ft_flood_fill(map, y + 1, x);
	ft_flood_fill(map, y - 1, x);
	ft_flood_fill(map, y, x + 1);
	ft_flood_fill(map, y, x - 1);
}

static int	ft_valid_check(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_map_dfs(int fd, char *map_dir)
{
	char	**map;
	int		x;
	int		y;
	int		isvalid;

	close(fd);
	fd = open(map_dir, O_RDONLY);
	map = ft_map_array(fd, ft_map_file_hight(fd), map_dir);
	x = ft_player_x(map);
	y = ft_player_y(map);
	ft_flood_fill(map, y, x);
	isvalid = ft_valid_check(map);
	ft_free_map(map, ft_map_hight(map));
	if (isvalid == 1)
		return (1);
	return (0);
}
