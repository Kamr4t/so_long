/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:14:48 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/06 11:53:23 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_player_death(t_display vars, t_images tiles)
{
	ft_free_images (vars, tiles);
	ft_game_end(vars, "You died to the Goblin! Try Again!");
}

static void	ft_switch_pos_x(t_display vars, int x, int y, int direction)
{
	t_images	tiles;
	int			game_end;

	game_end = 0;
	tiles = ft_tiles(vars);
	if (vars.map[y][x + direction] == 'C')
		ft_col_count(-1);
	if (vars.map[y][x + direction] == 'E')
	{
		if (ft_col_count(0) != 0)
			return ;
		else
			game_end = 1;
	}
	if (vars.map[y][x + direction] == 'F')
		ft_player_death(vars, tiles);
	if (direction < 0)
		vars.map[y][x + direction] = 'l';
	else
		vars.map[y][x + direction] = 'r';
	vars.map[y][x] = '0';
	ft_put_on_screen(vars, ft_move_count());
	ft_free_images(vars, tiles);
	if (game_end == 1)
		ft_game_end(vars, "You escaped the Dungeon!");
}

static void	ft_switch_pos_y(t_display vars, int x, int y, int direction)
{
	t_images	tiles;
	int			game_end;

	game_end = 0;
	tiles = ft_tiles(vars);
	if (vars.map[y + direction][x] == 'C')
		ft_col_count(-1);
	if (vars.map[y + direction][x] == 'E')
	{
		if (ft_col_count(0) != 0)
			return ;
		else
			game_end = 1;
	}
	if (vars.map[y + direction][x] == 'F')
		ft_game_end(vars, "You died to the Goblin!");
	if (direction < 0)
		vars.map[y + direction][x] = 'u';
	else
		vars.map[y + direction][x] = 'P';
	vars.map[y][x] = '0';
	ft_put_on_screen(vars, ft_move_count());
	ft_free_images(vars, tiles);
	if (game_end == 1)
		ft_game_end(vars, "You escaped the Dungeon!");
}

void	ft_move_logic(int key, void *param)
{
	int			x;
	int			y;
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
