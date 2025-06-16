/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:26:34 by ancamara          #+#    #+#             */
/*   Updated: 2025/06/16 16:59:30 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_strchr_int(char *s, char *buffer, ssize_t read_bytes);
int		ft_pos_nl(const char *str, size_t start);
char	*ft_build_str(char *s, int start);
char	*ft_memcat(char *s1, char *s2);
int		ft_start(char *s, int start);
char	*get_next_line(int fd);

#endif
