/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:21:03 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/17 17:28:29 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

typedef struct s_vars {
    void *mlx_ptr;
    void *win_ptr;
} t_vars;

// int	ft_mouse(int mouse, void *param)
// {
// 	t_vars	*vars;

// 	vars = (t_vars *)param;
// 	printf("%d\n", mouse);
// 	return (0);
// }


int	ft_test(int key, void *param)
{
	t_vars	*vars;
	
	vars = (t_vars *)param;
	if (key == 65307)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit (0);
	}
	return (0);
}

int	ft_i_array_len(int *array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
		i++;
	return (i);
}

int	ft_i_array_hight(int **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
		i++;
	return (1);
}

int	ft_map_object_count(int c)
{
	static int	count_col = 0;
	static int	count_player = 0;
	static int	count_exit = 0;

	if (c == 'C')
		count_col++;
	if (c == 'P')
		count_player++;
	if (c == 'E')
		count_exit++;
	if (c == 1)
	{
		printf("Col %d\nPlayer: %d\nExit: %d\n", count_col, count_player, count_exit);
		if (count_col == 0)
			return (0);
		if (count_player != 1)
			return (0);
		if (count_exit != 1)
			return (0);
	}
	return (1);
}

// int	ft_map_wall(int **map)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	int		hight;
	
// 	i = 0;
// 	j = 0;
// 	len = ft_i_array_len(map[0]);
// 	ft_printf("%d\n", len);
// 	hight = ft_i_array_hight(map);
// 	while (i < len)
// 	{
// 		if (map[0][i] != '1')
// 			return (0);
// 		if (map[hight - 1][i] != '1')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

int	ft_map_check(int **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (map[i][j + 1] != 0)
		j++;
	// if (ft_map_wall(map) == 0)
	// 	return (0);
	len = j;
		while (map[i] != 0)
	{
		j = 0;
		while (map[i][j])
		{
			ft_map_object_count(map[i][j]);
			j++;
		}
		if (j - 1 != len)
			return (0);
		i++;
	}
	if (ft_map_object_count(1) == 0)
		return (0);
	printf("map check end\n");
	return (1);
}

int	main(void)
{
	t_vars	vars;
	size_t	i;
	size_t	j;
	void	*img_ptr_wall;
	void	*img_ptr_floor;
	int		img_width;
	int		img_height;
	int		fd = open("map1.ber", O_RDONLY);
	int		**map;
	int		test;

	map = ft_map(fd);
	test = ft_map_check(map);
	ft_printf("MAP CHECK: %d\n", test);
	// if (!map)
	// 	return (0);
	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j + 1] != 0)
		{
			printf("%c ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	
	if (!map)
		return (0);
	// vars.mlx_ptr = mlx_init();
	// if (!vars.mlx_ptr)
	// {
	// 	printf("fail");
	// 	return (0);
	// }
	// vars.win_ptr = mlx_new_window(vars.mlx_ptr, 4 * 128, 5 * 128, "test");
	// img_ptr_wall = mlx_xpm_file_to_image(vars.mlx_ptr, "brick.xpm", &img_width, &img_height);
	// img_ptr_floor = mlx_xpm_file_to_image(vars.mlx_ptr, "floor.xpm", &img_width, &img_height);
	// //include fail check
	// i = 0;
	// // while (i < 4)
	// // {
	// // 	j = 0;
	// // 	while (j < 5)
	// // 	{
	// // 		if (map[i][j] == 1)
	// // 			mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img_ptr_wall, i * 128, j * 128);
	// // 		if (map[i][j] == 2)
	// // 			mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img_ptr_floor, i * 128, j * 128);
	// // 		j++;
	// // 	}
	// // 	i++;
	// // }
	// mlx_key_hook(vars.win_ptr, ft_test, &vars);
	// //mlx_mouse_hook(vars.win_ptr, ft_mouse, &vars);
	// mlx_loop(vars.mlx_ptr);
	return (0);
}
