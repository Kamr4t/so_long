/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:29:07 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/18 09:28:45 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*ft_free_map(char **map, int hight)
{
	int	i;

	i = 0;
	while (i < hight)
	{
		free (map[i]);
		i++;
	}
	free (map);
	return (NULL);
}

int	ft_map_hight(int fd)
{
	int		hight;
	char	*line;

	line = get_next_line(fd);
	hight = 0;
	while (line != NULL)
	{
		hight++;
		free (line);
		line = get_next_line(fd);
	}
	return (hight);
}

int	ft_strlen_nl(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_map_line(int fd)
{
	int		len;
	int		i;
	char	*map;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen_nl(line);
	i = 0;
	map = malloc(len * sizeof(char) + 1);
	while (i < len)
	{
		map[i] = line[i];
		i++;
	}
	free (line);
	map[i] = '\0';
	return (map);
}

char	**ft_map_array(int fd)
{
	char	**map;
	int		hight;
	int		fd2;
	int		i;

	hight = ft_map_hight(fd);
	fd2 = open("map1.ber", O_RDONLY);
	map = malloc((hight + 1) * sizeof(char *));
	if (!map)
		return (0);
	map[hight] = NULL;
	i = 0;
	while (i < hight)
	{
		map[i] = ft_map_line(fd2);
		if (map[i] == NULL)
		{
			ft_free_map(map, i);
			return (NULL);
		}
		i++;
	}
	return (map);
}
