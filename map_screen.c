/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:17:45 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/05 15:18:08 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_key_press(int key, void *param)
{
	t_display	*vars_type_cast;
	t_display	vars;

	vars_type_cast = (t_display *)param;
	vars.map = vars_type_cast->map;
	vars.mlx_ptr = vars_type_cast->mlx_ptr;
	vars.win_ptr = vars_type_cast->win_ptr;
	if (key == 65307)
	{
		ft_game_end(vars, "Thanks for playing!");
	}
	if (key == 119 || key == 115 || key == 97 || key == 100)
		ft_move_logic(key, param);
	if (key == 65362 || key == 65364 || key == 65361 || key == 65363)
		ft_move_logic(key, param);
	return (0);
}

static void	ft_mlx_image_objects(t_display vars, t_images tiles, int i, int j)
{
	if (vars.map[i][j] == '1')
		mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, 
			tiles.img_ptr_wall, 128 * j, 128 * i);
	if (vars.map[i][j] == '0')
		mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, 
			tiles.img_ptr_floor, 128 * j, 128 * i);
	if (vars.map[i][j] == 'E')
		mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, 
			tiles.img_ptr_exit, 128 * j, 128 * i);
	if (vars.map[i][j] == 'C')
		mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, 
			tiles.img_ptr_col, 128 * j, 128 * i);
	if (vars.map[i][j] == 'F')
		mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, 
			tiles.img_ptr_foe, 128 * j, 128 * i);
}

static void	ft_mlx_image_player(t_display vars, t_images tiles, int i, int j)
{
	if (vars.map[i][j] == 'P')
		mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, 
			tiles.img_ptr_player, 128 * j, 128 * i);
	if (vars.map[i][j] == 'u')
		mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, 
			tiles.img_ptr_p_up, 128 * j, 128 * i);
	if (vars.map[i][j] == 'l')
		mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, 
			tiles.img_ptr_p_left, 128 * j, 128 * i);
	if (vars.map[i][j] == 'r')
		mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, 
			tiles.img_ptr_p_right, 128 * j, 128 * i);
}

//Player direction
//P = Default (looking down)
//u = Looking up
//l = Looking left
//r = Looking right
void	ft_put_on_screen(t_display vars, char *move_count)
{
	t_images	tiles;
	size_t		i;
	size_t		j;

	tiles = ft_tiles(vars);
	i = 0;
	mlx_clear_window(vars.mlx_ptr, vars.win_ptr);
	while (vars.map[i] != NULL)
	{
		j = 0;
		while (vars.map[i][j] != '\0')
		{
			ft_mlx_image_objects(vars, tiles, i, j);
			ft_mlx_image_player(vars, tiles, i, j);
			j++;
		}
		i++;
	}
	mlx_string_put(vars.mlx_ptr, vars.win_ptr, 30, 20, 0xFF00FF, move_count);
	free (move_count);
	ft_free_images(vars, tiles);
}

int	ft_build_win(char **map)
{
	t_display	display;
	int			len;
	int			hight;

	len = ft_strlen_nl(map[0]);
	hight = ft_map_hight(map);
	display.mlx_ptr = mlx_init();
	display.map = map;
	if (display.mlx_ptr == NULL)
		ft_error_handle("mlx_init Failed!");
	display.win_ptr = mlx_new_window(display.mlx_ptr, 
			len * 128, hight * 128, "MY GAME");
	if (display.win_ptr == NULL)
		ft_error_handle("mlx_new_window Failed!");
	ft_put_on_screen(display, ft_move_count());
	mlx_key_hook(display.win_ptr, ft_key_press, &display);
	mlx_loop(display.mlx_ptr);
	return (0);
}
