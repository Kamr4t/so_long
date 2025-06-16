/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:54:48 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/16 16:59:53 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	static char			buffer[BUFFER_SIZE + 1];
	char				*new_line;
	static ssize_t		bytes_read = 0;
	static int			start = 0;
	int					loop;

	if (start == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
	}
	if (bytes_read <= 0 || fd < 0)
		return (NULL);
	new_line = ft_build_str(buffer, start);
	loop = ft_strchr_int(new_line, buffer, bytes_read);
	while (loop == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		new_line = ft_memcat(new_line, buffer);
		loop = ft_strchr_int(new_line, buffer, bytes_read);
		start = 0;
	}
	start = ft_start(buffer, start);
	return (new_line);
}

// int	main(void)
// {
// 	int fd = open("read_error.txt", O_RDONLY);
// 	char	*test;	
// 	test = get_next_line(fd);
// 	while (test != NULL)
// 	{
// 		printf("%s", test);
// 		free (test);
// 		test = get_next_line(fd);
// 	}
// 	// printf("%s", test);
// 	// free (test);
// 	return (0);
// }
