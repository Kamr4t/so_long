/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:38:57 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/05 15:42:23 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"
# include "mlx.h"

typedef struct s_display {
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
}	t_display;

typedef struct s_images {
	void	*img_ptr_floor;
	void	*img_ptr_wall;
	void	*img_ptr_player;
	void	*img_ptr_p_up;
	void	*img_ptr_p_left;
	void	*img_ptr_p_right;
	void	*img_ptr_exit;
	void	*img_ptr_col;
	void	*img_ptr_foe;
}	t_images;

//main.c
int			main(int argc, char **argv);

//map array.c
char		**ft_map_array(int fd, int hight, char *map_dir);
void		ft_free_map(char **map, int hight);
int			ft_map_file_hight(int fd);

//map check.c
int			ft_map_check(char **map);

//map valid
int			ft_map_dfs(int fd, char *map_dir);

//map screen.c
int			ft_build_win(char **map);
void		ft_put_on_screen(t_display vars, char *move_count);

//map helper.c
int			ft_strlen_nl(char *s);
int			ft_map_hight(char **map);
int			ft_player_x(char **map);
int			ft_player_y(char **map);
t_images	ft_tiles(t_display vars);

//error_handle
void		ft_error_handle(char *str);
void		ft_invalid_map(char *context);

//game move.c
void		ft_move_logic(int key, void *param);

//game logic.c
int			ft_col_count(int add);
void		ft_game_end(t_display vars, char *context);
char		*ft_move_count(void);
void		ft_free_images(t_display vars, t_images tiles);

#endif
