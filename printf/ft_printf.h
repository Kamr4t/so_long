/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancamara <ancamara@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:26:34 by ancamara          #+#    #+#             */
/*   Updated: 2025/05/30 08:41:54 by ancamara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_loop(int result, const char *str, va_list args);
int		ft_putstr(char *str);
char	*ft_checks(char c, va_list args);
int		ft_len(char *str, char *base, unsigned long long nbr);
char	*ft_hex_ptr(unsigned long long nbr);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_c_dup(char c);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_nb_len(int n);
char	*ft_itoa(int n);
char	*ft_hex_uplo(unsigned int nbr, char *base);
int		ft_get_print(char c, va_list args);
char	*ft_check_null(const char *s);

#endif
