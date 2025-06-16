/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:21:03 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/16 17:21:46 by ancamara         ###   ########.fr       */
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
	ft_printf("%d\n", key);
	return (0);
}
size_t	ft_map_hight(int fd)
{
	char	*map;
	size_t	i;
	int		len;

	map = get_next_line(fd);
	len = ft_strlen(map);
	i = 0;
	while(map != NULL)
	{
		map = get_next_line(fd);
		if (ft_strlen(map) != len)
			return (0);
		i++;
	}
	return (i);
}

int	**ft_map_array(int fd)
{
	size_t	hight;
	size_t	len;
	size_t	i;
	int		**array;

	hight = ft_map_hight(fd);
	if (hight == 0)
		return (0);
	*array = malloc(hight * sizeof(char) + 1);
	if (!array)
	{
		//free stuff
		return (NULL);
	}
	*array[hight] = '\0';
	len = ft_strlen(get_next_line(fd));
	i = 0;
	while (i < len)
	{
		ft_save_map(fd);
	}
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
	
	ft_map_hight(fd, &vars);
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
