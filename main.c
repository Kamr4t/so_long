/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:21:03 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/17 13:06:57 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

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
int	**ft_free_array(int **array, int hight)
{
	int	i;

	i = 0;
	while (i < hight)
	{
		free (array[i]);
		i++;
	}
	free (array);
	return (NULL);
}

int	*ft_map_store_line_int(int *map, size_t len)
{
	size_t	i;
	int		*array;

	 array = malloc(len * sizeof(int) + 1);
	 if (!array)
	 	return (NULL);
	 i = 0;
	 while (i < len)
	 {
		array[i] = map[i];
		i++;
	 }
	 array[i] = 0;
	 return (array);
}

int	*ft_map_store_line_char(char *map)
{
	size_t	len;
	size_t	i;
	int		*array;

	 len = ft_strlen(map);
	 array = malloc(len * sizeof(int) + 1);
	 if (!array)
	 	return (NULL);
	 i = 0;
	 
	 while (i < len)
	 {
		array[i] = map[i];
		i++;
	 }
	 array[i] = 0;
	 return (array);
}
int	**ft_map_array(char *map, int hight, int **source_array)
{
	int		**dest_array;
	int		i;
	size_t	len;

	len = ft_strlen(map);
	dest_array = malloc((hight + 1) * sizeof(int) + 1);
	if (!dest_array)
	{
		ft_free_array(source_array, hight);
		return (NULL);
	}
	i = 0;
	while (i < hight)
	{
		dest_array[i] = ft_map_store_line_int(source_array[i], len);
		if (!dest_array[i])
			return (NULL);
		free (source_array[i]);
		i++;
	}
	free (source_array);
	dest_array[i] = ft_map_store_line_char(map);
	dest_array[i + 1] = 0;
	return (dest_array);
}

int	**ft_map(int fd)
{
	int		**array;
	int		hight;
	char	*map;

	map = get_next_line(fd);
	hight = 1;
	array = malloc(hight * sizeof(int) + 1);
	if (!array)
		return (0);
	array[0] = ft_map_store_line_char(map);
	if (!array[0])
		return (NULL);
	array[1] = 0;
	map = get_next_line(fd);
	while (map != NULL)
	{
		array = ft_map_array(map, hight, array);
		if (!array)
			return (NULL);
		map = get_next_line(fd);
		hight++;
	}
	return (array);
}

int	ft_map_check(int **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (map[i][j + 1] != 0)
		j++;
	len = j;
	printf("%d\n", len);
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		i++;
	}
	return (0);
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

	map = ft_map(fd);
	ft_map_check(map);
	if (!map)
		return (0);
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
	vars.mlx_ptr = mlx_init();
	if (!vars.mlx_ptr)
	{
		printf("fail");
		return (0);
	}
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 4 * 128, 5 * 128, "test");
	img_ptr_wall = mlx_xpm_file_to_image(vars.mlx_ptr, "brick.xpm", &img_width, &img_height);
	img_ptr_floor = mlx_xpm_file_to_image(vars.mlx_ptr, "floor.xpm", &img_width, &img_height);
	//include fail check
	i = 0;
	// while (i < 4)
	// {
	// 	j = 0;
	// 	while (j < 5)
	// 	{
	// 		if (map[i][j] == 1)
	// 			mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img_ptr_wall, i * 128, j * 128);
	// 		if (map[i][j] == 2)
	// 			mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img_ptr_floor, i * 128, j * 128);
	// 		j++;
	// 	}
	// 	i++;
	// }
	mlx_key_hook(vars.win_ptr, ft_test, &vars);
	//mlx_mouse_hook(vars.win_ptr, ft_mouse, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
