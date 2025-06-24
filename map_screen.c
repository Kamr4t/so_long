/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:17:45 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/24 13:03:30 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int ft_key_press(int key, void *param)
{
	t_display	*vars;

	vars = (t_display *)param;
	if (key == 65307)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit (0);
	}
	if (key == 119 || key == 115 || key == 97 | key == 100)
		ft_move_logic(key, param);
	if (key == 65362|| key == 65364 || key == 65361 | key == 65363)
		ft_move_logic(key, param);
	return (0);
}

t_images	ft_tiles(t_display vars)
{
	t_images	tiles;
	int			img_width;
	int			img_height;

	
	tiles.img_ptr_col = mlx_xpm_file_to_image(vars.mlx_ptr, "tiles/metal.xpm", &img_width, &img_height);
	tiles.img_ptr_exit = mlx_xpm_file_to_image(vars.mlx_ptr, "tiles/fence.xpm", &img_width, &img_height);
	tiles.img_ptr_floor = mlx_xpm_file_to_image(vars.mlx_ptr, "tiles/floor.xpm", &img_width, &img_height);
	tiles.img_ptr_player = mlx_xpm_file_to_image(vars.mlx_ptr, "tiles/player.xpm", &img_width, &img_height);
	tiles.img_ptr_wall = mlx_xpm_file_to_image(vars.mlx_ptr, "tiles/brick.xpm", &img_width, &img_height);
	return (tiles);
}

static void	ft_put_on_screen(char **map, t_display vars)
{
	t_images	tiles;
	size_t		i;
	size_t		j;
	
	tiles = ft_tiles(vars);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, tiles.img_ptr_wall, 128 * j, 128 * i);
			if (map[i][j] == '0')
				mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, tiles.img_ptr_floor, 128 * j, 128 * i);
			if (map[i][j] == 'E')
				mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, tiles.img_ptr_exit, 128 * j, 128 * i);
			if (map[i][j] == 'P')
				mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, tiles.img_ptr_player, 128 * j, 128 * i);
			if (map[i][j] == 'C')
				mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, tiles.img_ptr_col, 128 * j, 128 * i);
			j++;
		}
		i++;
	}
}

int	ft_build_win(char **map)
{
	t_display	display;
	int			len;
	int			hight;
	int			key;
	
	len = ft_strlen_nl(map[0]);
	hight = ft_map_hight(map);
	display.mlx_ptr = mlx_init();
	display.map = map;
	//if mlx init fails in returns NULL
	//include fail check
	display.win_ptr = mlx_new_window(display.mlx_ptr, len * 128, hight * 128, "MY GAME");
	//same as above
	ft_put_on_screen(map, display);
	key = mlx_key_hook(display.win_ptr, ft_key_press, &display);
	//ft_move_logic(key, display, map);
	mlx_loop(display.mlx_ptr);
	return (0);
}
