/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:28:45 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/05 15:42:42 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		fd;
	int		map_check;

	if (argc != 2)
		ft_invalid_map("Wrong Input");
	fd = open(argv[1], O_RDONLY);
	map = ft_map_array(fd, ft_map_file_hight(fd), argv[1]);
	map_check = ft_map_check(map);
	if (map_check == 0)
		ft_invalid_map("The map does not follow the Rules!");
	map_check = ft_map_dfs(fd, argv[1]);
	if (map_check == 0)
		ft_invalid_map("Not possible to reach all Objects!");
	ft_build_win(map);
	return (0);
}
