/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:28:34 by codespace         #+#    #+#             */
/*   Updated: 2025/07/03 12:24:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void    ft_flood_fill(char **map, int y, int x)
{
    if (map[y][x] == '1')
        return ;
    map[y][x] = '1';
    ft_flood_fill(map, y + 1, x);
    ft_flood_fill(map, y - 1, x);
    ft_flood_fill(map, y, x + 1);
    ft_flood_fill(map, y, x - 1);
}

static int ft_valid_check(char **map)
{
    int x;
    int y;

    y = 0;
    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x] != '\0')
        {
            if (map[y][x] == 'C' || map[y][x] == 'E')
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}

int ft_map_dfs(int fd)
{
    char    **map;
    int     x;
    int     y;
    int     isValid;
    int     fd3;

    close(fd);
    fd = open("map1.ber", O_RDONLY);
    map = ft_map_array(fd);
    x = ft_player_x(map);
    y = ft_player_y(map);
    ft_flood_fill(map, y, x);
    isValid = ft_valid_check(map);
    free(map);
    if (isValid == 1)
        return (1);
    return (0);
}