/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:14:48 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/03 11:48:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	ft_player_x(char **map)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (map[y] != NULL)
// 	{
// 		x = 0;
// 		while (map[y][x] != '\0')
// 		{
// 			if (map[y][x] == 'P')
// 				return (x);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }

// static int	ft_player_y(char **map)
// {
// 	int	x;
// 	int	y;

// 	y = 1;
// 	while (map[y] != NULL)
// 	{
// 		x = 1;
// 		while (map[y][x] != '\0')
// 		{
// 			if (map[y][x] == 'P')
// 				return (y);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }

static void	ft_switch_pos_x(t_display vars, int x, int y, int direction)
{
	t_images	tiles;

	tiles = ft_tiles(vars);
	if (vars.map[y][x + direction] == 'C')
		ft_col_count(-1);
	if (vars.map[y][x  + direction] == 'E')
		if (ft_col_count(0) != 0)
			return ;
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, tiles.img_ptr_player, 128 * (x + direction), 128 * y);
	vars.map[y][x + direction] = 'P';
	vars.map[y][x] = '0';
	//does it only overwrite it or also delete the old picture?
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, tiles.img_ptr_floor, 128 * x, 128 * y);
	ft_move_count();
	ft_game_end(vars);
}

static void	ft_switch_pos_y(t_display vars, int x, int y, int direction)
{
	t_images	tiles;

	tiles = ft_tiles(vars);
	if (vars.map[y + direction][x] == 'C')
		ft_col_count(-1);
	if (vars.map[y + direction][x] == 'E')
		if (ft_col_count(0) != 0)
			return ;
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, tiles.img_ptr_player, 128 * x, 128 * (y + direction));
	vars.map[y + direction][x] = 'P';
	vars.map[y][x] = '0';
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, tiles.img_ptr_floor, 128 * x, 128 * y);
	ft_move_count();
	ft_game_end(vars);
}

void	ft_move_logic(int key, void *param)
{
	int		x;
	int		y;
	t_display	*vars_ptr;
	t_display	vars;

	vars_ptr = (t_display *)param;
	vars.map = vars_ptr->map;
	vars.mlx_ptr = vars_ptr->mlx_ptr;
	vars.win_ptr = vars_ptr->win_ptr;
	x = ft_player_x(vars.map);
	y = ft_player_y(vars.map);
	if (key == 119 || key == 65362)
		if (vars.map[y - 1][x] != '1')
			ft_switch_pos_y(vars, x, y, -1);
	if (key == 115 || key == 65364)
		if (vars.map[y + 1][x] != '1')
			ft_switch_pos_y(vars, x, y, 1);
	if (key == 97 || key == 65361)
		if (vars.map[y][x - 1] != '1')
			ft_switch_pos_x(vars, x, y, -1);
	if (key == 100 || key == 65363)
		if (vars.map[y][x + 1] != '1')
			ft_switch_pos_x(vars, x, y, 1);
}
