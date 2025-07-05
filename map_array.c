/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:29:07 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/05 15:41:13 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map, int hight)
{
	int	i;

	i = 0;
	while (i < hight)
	{
		free (map[i]);
		i++;
	}
	free (map);
	return ;
}

int	ft_map_file_hight(int fd)
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

static char	*ft_map_line(int fd)
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
	if (map == NULL)
		return (NULL);
	while (i < len)
	{
		map[i] = line[i];
		i++;
	}
	free (line);
	map[i] = '\0';
	return (map);
}

char	**ft_map_array(int fd, int hight, char *map_dir)
{
	char	**map;
	int		i;

	close (fd);
	fd = open(map_dir, O_RDONLY);
	map = malloc((hight + 1) * sizeof(char *));
	if (!map)
	{
		free (map);
		ft_error_handle("map_array allocation failed");
	}
	map[hight] = NULL;
	i = 0;
	while (i < hight)
	{
		map[i] = ft_map_line(fd);
		if (map[i] == NULL)
		{
			ft_free_map(map, i);
			ft_error_handle("map_array allocation failed");
		}
		i++;
	}
	return (map);
}
