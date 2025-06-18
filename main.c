/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:28:45 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/18 09:26:59 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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
	//free (map);
	return (0);
}
