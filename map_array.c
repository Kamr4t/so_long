/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:58:40 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/17 17:16:27 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**ft_free_array(int **array, int hight)
{
	int	i;

	i = 0;
	while (i < hight)
	{
		free (array[i]);
		i++;
	}
	free (array);
	return (NULL);
}

int	*ft_map_store_line_int(int *map)
{
	size_t	i;
	size_t	len;
	int		*array;
	
	len = ft_i_array_len(map);
	 array = malloc(len * sizeof(int) + 1);
	 if (!array)
	 	return (NULL);
	 i = 0;
	 while (i < len)
	 {
		array[i] = map[i];
		i++;
	 }
	 array[i] = 0;
	 //free (map);
	 return (array);
}

int	*ft_map_store_line_char(char *map)
{
	size_t	i;
	size_t	len;
	int		*array;

	len = ft_strlen(map);
	array = malloc(len * sizeof(int) + 1);
	if (!array)
		return (NULL);
	i = 0;
	
	while (i < len)
	{
		array[i] = map[i];
		i++;
	}
	array[i] = 0;
	free (map);
	return (array);
}
int	**ft_map_array(char *map, int hight, int **source_array, size_t len)
{
	int		**dest_array;
	int		i;

	dest_array = malloc((hight + 1) * sizeof(int) + 1);
	if (!dest_array)
	{
		ft_free_array(source_array, hight);
		return (NULL);
	}
	i = 0;
	while (i < hight)
	{
		dest_array[i] = ft_map_store_line_int(source_array[i]);
		if (!dest_array[i])
			return (NULL);
		i++;
	}
	free (source_array);
	dest_array[i] = ft_map_store_line_char(map);
	dest_array[i + 1] = 0;
	return (dest_array);
}

int	**ft_map(int fd)
{
	int		**array;
	int		hight;
	size_t	len;
	char	*map;

	map = get_next_line(fd);
	len = ft_strlen(map);
	hight = 1;
	array = malloc(hight * sizeof(int) + 1);
	if (!array)
		return (0);
	array[0] = ft_map_store_line_char(map);
	if (!array[0])
		return (NULL);
	array[1] = 0;
	map = get_next_line(fd);
	while (map != NULL)
	{
		array = ft_map_array(map, hight, array, len);
		if (!array)
			return (NULL);
		map = get_next_line(fd);
		hight++;
	}
	return (array);
}
