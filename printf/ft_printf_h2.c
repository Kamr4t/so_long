/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_h2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:09:24 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/30 08:35:44 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(char *str, char *base, unsigned long long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		str[0] = '0';
		count++;
	}
	while (nbr > 0)
	{
		str[count] = base[nbr % 16];
		nbr /= 16;
		count++;
	}
	str[count] = '\0';
	return (count);
}

char	*ft_hex_ptr(unsigned long long nbr)
{
	char	*result;
	char	tmp[20];
	int		i;
	int		j;

	if (!nbr)
		return (ft_strdup("(nil)"));
	i = ft_len(tmp, "0123456789abcdef", nbr);
	tmp[i] = '\0';
	result = malloc(i * sizeof(char) + 3);
	if (result == NULL)
		return (NULL);
	j = 2;
	result[0] = '0';
	result[1] = 'x';
	while (i-- > 0)
	{
		result[j] = tmp[i];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*ft_check_null(const char *s)
{
	char	*result;

	if (s == NULL)
	{
		result = ft_strdup("(null)");
		return (result);
	}
	result = ft_strdup(s);
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*array;
	size_t	i;

	array = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (array == NULL)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*ft_c_dup(char c)
{
	char	*array;

	array = malloc(2 * sizeof(char));
	if (array == NULL)
		return (0);
	array[0] = c;
	array[1] = '\0';
	return (array);
}
