/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:26:34 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/17 17:39:47 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>

int	ft_test(int key, void *param);
int	ft_i_array_len(int *array);
int	ft_i_array_hight(int **array);
int	ft_map_object_count(int c);
int	ft_map_wall(int **map);
int	ft_map_check(int **map);
int	**ft_map(int fd);
int	**ft_map_array(char *map, int hight, int **source_array, size_t len);
int	*ft_map_store_line_char(char *map);
int	*ft_map_store_line_int(int *map);
int	**ft_free_array(int **array, int hight);
int	main(void);

#endif
