/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:47:19 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/05 16:05:20 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <limits.h>

void	ft_free_images(t_display vars, t_images tiles)
{
	mlx_destroy_image(vars.mlx_ptr, tiles.img_ptr_col);
	mlx_destroy_image(vars.mlx_ptr, tiles.img_ptr_floor);
	mlx_destroy_image(vars.mlx_ptr, tiles.img_ptr_player);
	mlx_destroy_image(vars.mlx_ptr, tiles.img_ptr_p_up);
	mlx_destroy_image(vars.mlx_ptr, tiles.img_ptr_p_right);
	mlx_destroy_image(vars.mlx_ptr, tiles.img_ptr_p_left);
	mlx_destroy_image(vars.mlx_ptr, tiles.img_ptr_exit);
	mlx_destroy_image(vars.mlx_ptr, tiles.img_ptr_wall);
	mlx_destroy_image(vars.mlx_ptr, tiles.img_ptr_foe);
}

int	ft_col_count(int add)
{
	static int	count = 0;

	count += add;
	return (count);
}

void	ft_game_end(t_display vars, char *context)
{
	ft_printf("%s\n", context);
	mlx_destroy_display(vars.mlx_ptr);
	mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
	ft_free_map(vars.map, ft_map_hight(vars.map));
	exit (0);
}

char	*ft_move_count(void)
{
	static int	count = 0;
	char		*move_count;
	char		*nbr;

	nbr = ft_itoa(count);
	move_count = ft_strjoin("Movemnt Count: ", nbr);
	count++;
	free (nbr);
	return (move_count);
}

int	ft_win_close(void *param)
{
	(void)param;
	ft_printf("Window close, thanks for playing!");
	exit (0);
	return (0);
}
