/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:05:58 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/30 08:41:57 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_checks(char c, va_list args)
{
	char	*print;

	print = NULL;
	if (c == 'd' || c == 'i')
		print = ft_itoa(va_arg(args, int));
	if (c == 'u')
		print = ft_unsigned_itoa(va_arg(args, unsigned int));
	if (c == '%')
		print = ft_c_dup('%');
	if (c == 's')
		print = ft_check_null(va_arg(args, const char *));
	if (c == 'p')
		print = ft_hex_ptr(va_arg(args, unsigned long long));
	if (c == 'x')
		print = ft_hex_uplo(va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		print = ft_hex_uplo(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (print);
}

int	ft_putstr(char *str)
{
	int	i;
	int	fail_check;

	i = 0;
	while (str[i] != '\0')
	{
		fail_check = write(1, &str[i], 1);
		if (fail_check == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_get_print(char c, va_list args)
{
	char	*print;
	int		arg_c;
	int		tmp;
	int		result;

	result = 0;
	print = ft_checks(c, args);
	if (c == 'c')
	{
		arg_c = va_arg(args, int);
		tmp = write(1, &arg_c, 1);
		if (tmp == -1)
			return (tmp);
		result += tmp;
	}
	if (print != NULL)
	{
		tmp = ft_putstr(print);
		if (tmp == -1)
			return (tmp);
		result += tmp;
		free (print);
	}
	return (result);
}

int	ft_loop(int result, const char *str, va_list args)
{
	int	i;
	int	tmp;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			tmp = ft_get_print(str[i + 1], args);
			if (tmp == -1)
				return (tmp);
			result += tmp;
			i += 2;
		}
		if (str[i] != '\0' && str[i] != '%')
		{
			tmp = write(1, &str[i], 1);
			if (tmp == -1)
				return (tmp);
			result += tmp;
			i++;
		}
	}
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;

	va_start (args, str);
	result = ft_loop(0, str, args);
	va_end(args);
	return (result);
}

// int	main(void)
// {
// 	char	*c = "Hello World!";
// 	void	*test = &c;
// 	unsigned long long nbr = (unsigned long long) test;
// 	int	i;

// 	//printf("%x\n", nbr);
// 	i = ft_printf("%c", 'a');
// 	ft_printf("\nLetter: %i\n", i);
// 	return (0);
// }
