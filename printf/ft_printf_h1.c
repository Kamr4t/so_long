/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_h1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:10:37 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/30 08:35:43 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsigned_itoa(unsigned int n)
{
	char			*array;
	unsigned int	tmp;
	size_t			i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	array = (char *)malloc((i + 1) * sizeof(char));
	if (array == NULL)
		return (0);
	array[i] = '\0';
	while (n > 0)
	{
		i--;
		array[i] = '0' + n % 10;
		n /= 10;
	}
	return (array);
}

int	ft_nb_len(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*array;
	size_t	i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_nb_len(n);
	if (n < 0)
		n = -n;
	array = (char *)malloc((i + 1) * sizeof(char));
	if (array == NULL)
		return (0);
	array[i] = '\0';
	while (n > 0)
	{
		i--;
		array[i] = '0' + n % 10;
		n /= 10;
	}
	if (i > 0)
		array[0] = '-';
	return (array);
}

char	*ft_hex_uplo(unsigned int nbr, char *base)
{
	char	*result;
	char	tmp[20];
	int		i;
	int		j;

	i = ft_len(tmp, base, nbr);
	result = malloc(i * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	j = 0;
	while (i > 0)
	{
		i--;
		result[j] = tmp[i];
		j++;
	}
	result[j] = '\0';
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
