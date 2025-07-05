/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 08:24:54 by ancamara          #+#    #+#             */
/*   Updated: 2025/07/05 15:04:18 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_handle(char *context)
{
	ft_printf("[ERROR] %s: %s\n", context, strerror(errno));
	exit (EXIT_FAILURE);
}

void	ft_invalid_map(char *context)
{
	ft_printf("%s\n", context);
	exit (EXIT_FAILURE);
}
