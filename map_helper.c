/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:38:55 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/05 15:18:16 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_nl(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	ft_map_hight(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	ft_player_x(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P' || map[y][x] == 'u' || 
				map[y][x] == 'l' || map[y][x] == 'r')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_player_y(char **map)
{
	int	x;
	int	y;

	y = 1;
	while (map[y] != NULL)
	{
		x = 1;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P' || map[y][x] == 'u' || 
				map[y][x] == 'l' || map[y][x] == 'r')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

t_images	ft_tiles(t_display vars)
{
	t_images	tiles;
	int			img_width;
	int			img_height;

	tiles.img_ptr_col = mlx_xpm_file_to_image(vars.mlx_ptr, 
			"tiles/col.xpm", &img_width, &img_height);
	tiles.img_ptr_exit = mlx_xpm_file_to_image(vars.mlx_ptr, 
			"tiles/trapdoor.xpm", &img_width, &img_height);
	tiles.img_ptr_floor = mlx_xpm_file_to_image(vars.mlx_ptr, 
			"tiles/floor.xpm", &img_width, &img_height);
	tiles.img_ptr_player = mlx_xpm_file_to_image(vars.mlx_ptr, 
			"tiles/player_front.xpm", &img_width, &img_height);
	tiles.img_ptr_p_up = mlx_xpm_file_to_image(vars.mlx_ptr, 
			"tiles/player_back.xpm", &img_width, &img_height);
	tiles.img_ptr_p_left = mlx_xpm_file_to_image(vars.mlx_ptr, 
			"tiles/player_left.xpm", &img_width, &img_height);
	tiles.img_ptr_p_right = mlx_xpm_file_to_image(vars.mlx_ptr, 
			"tiles/player_right.xpm", &img_width, &img_height);
	tiles.img_ptr_wall = mlx_xpm_file_to_image(vars.mlx_ptr, 
			"tiles/wall.xpm", &img_width, &img_height);
	tiles.img_ptr_foe = mlx_xpm_file_to_image(vars.mlx_ptr, 
			"tiles/goblin.xpm", &img_width, &img_height);
	return (tiles);
}
