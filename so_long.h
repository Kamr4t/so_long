/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:38:57 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/19 10:07:05 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_display {
	void	*mlx_ptr;
	void	*win_ptr;
} t_display;

typedef struct s_images {
	void	*img_ptr_floor;
	void	*img_ptr_wall;
	void	*img_ptr_player;
	void	*img_ptr_exit;
	void	*img_ptr_col;
} t_images;

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "mlx.h"

//main.c
int		main(void);

//map array.c
char	**ft_map_array(int fd);
char	*ft_free_map(char **map, int hight);

//map check.c
int		ft_map_check(char **map);

//map screen.c
int		ft_build_win(char **map);

//map helper.c
int		ft_strlen_nl(char *s);
int		ft_map_hight(char **map);

#endif
