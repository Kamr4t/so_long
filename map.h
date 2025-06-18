/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:38:57 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/18 11:22:18 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_vars {
    void *mlx_ptr;
    void *win_ptr;
} t_vars;

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

//main.c
int		main(void);

//map array.c
int		ft_map_hight(int fd);
char	**ft_map_array(int fd);
char	*ft_map_line(int fd);
char	*ft_free_map(char **map, int hight);
int		ft_strlen_nl(char *s);

//map check.c
int		ft_map_check(char **map);
int		ft_map_object_count(int c);
int		ft_map_valid(int c);
int		ft_map_wall_check(char **map);
int		ft_map_rec(char **map);
#endif
