/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:14:48 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/19 15:50:26 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_player_x(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

static int	ft_player_y(char **map)
{
	int	x;
	int	y;

	y = 1;
	while (map[y] != NULL)
	{
		x = 1;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

static void	ft_switch_pos_y(t_display vars, int x, int y, int direction)
{
	t_images	tiles;
	char		tmp;

	tiles = ft_tiles(vars);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, tiles.img_ptr_player, 0, 0);
	tmp = vars.map[y + direction][x];
	vars.map[y + direction][x] = vars.map [y][x];
	vars.map[y][x] = tmp;
	
}

void	ft_move_logic(int key, void *param)
{
	int		x;
	int		y;
	t_display	*vars_ptr;
	t_display	vars;

	vars_ptr = (t_display *)param;
	vars.map = vars_ptr->map;
	vars.mlx_ptr = vars_ptr->map;
	vars.win_ptr = vars_ptr->map;

	x = ft_player_x(vars.map);
	y = ft_player_y(vars.map);
	printf("key: %d\n", key);
	if (key == 119)
	{
		if (vars.map[y][x - 1] != '1')
		{
			ft_switch_pos_y(vars, x, y, -1);
			x--;
		}
	}
}
