/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:47:19 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/24 11:09:11 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_col_count(int add)
{
	static int	count = 0;

	count += add;
	return(count);
}

void	ft_game_end(t_display vars)
{
	size_t	i;
	size_t	j;
	int		count;

	count = 0;
	i = 0;
	while (vars.map[i] != NULL)
	{
		j = 0;
		while (vars.map[i][j] != '\0')
		{
			if (vars.map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
	{
		mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
		exit (0);
	}
}

void	ft_move_count(void)
{
	static int	count = 0;

	count++;
	printf("Movement Count: %d\n", count);
}
