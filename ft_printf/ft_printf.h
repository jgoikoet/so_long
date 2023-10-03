/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:20:44 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/06/13 12:38:55 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(char const *str, ...);
int	ft_stract_str(const char *str, va_list args);
int	ft_select(const char *str, int i, va_list args);
int	ft_write_c(va_list args);
int	ft_write_s(va_list args);
int	ft_write_id(va_list args);
int	ft_write_u(va_list args);
int	ft_write_x(va_list args, int x);
int	ft_write_p(va_list args);
int	ft_write_p_x(unsigned long long int n);
int	ft_bonus(const char *str, int i, va_list args);
int	ft_minus(const char *str, int i, va_list args);
int	ft_cero(const char *str, int i, va_list args);
int	ft_numlen(int i);
int	ft_write_id_bonus(int i);
int	ft_point(const char *str, int i, va_list args);
int	ft_cero_extra(const char *str, int i, int spc, va_list args);
int	ft_cero_print(int spc);
int	ft_cero_extra_x(va_list args, int x, int spc);
int	ft_point_s(const char *str, int i, va_list args);
int	ft_hash(const char *str, int i, va_list args);
int	ft_space_plus(const char *str, int i, va_list args);
int	ft_numlen_u(unsigned int i);
int	ft_cero_dot(const char *str, int i, va_list args);
int	ft_static(int i);

#endif