/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:28:45 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/03 12:22:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char	**map;
	int		fd;
	size_t	i;
	size_t	j;

	fd = open("map1.ber", O_RDONLY);
	map = ft_map_array(fd);
	if (map == NULL)
		return (0);
	int test = ft_map_check(map);
	printf("%d\n", test);
	i = 0;
	while (map[i] != NULL)
	{
		//free (map[i]);
		j = 0;
		while (map[i][j] != '\0')
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	test = ft_map_dfs(fd);
	printf("valid: %d\n", test);
	//free (map);
	// if (test == 1)
	// 	ft_build_win(map);
	return (0);
}
