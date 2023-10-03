/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:43:35 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/06/13 13:38:47 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_minus(const char *str, int i, va_list args)
{
	int	spc;
	int	res;

	spc = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		spc = spc * 10;
		spc = spc + str[i++] - '0';
		ft_static(1);
	}
	res = ft_select(str, i, args);
	while (res++ < spc)
		write (1, " ", 1);
	return (res - 1);
}

int	ft_point_s(const char *str, int i, va_list args)
{
	int		spc;
	int		res;
	char	*s;

	s = va_arg(args, char *);
	spc = 0;
	res = 0;
	if (!s)
		return (write(1, "(null)", 6), 6);
	ft_static(-ft_static(0));
	while (str[i] >= '0' && str[i] <= '9')
	{
		spc = spc * 10;
		spc = spc + str[i++] - '0';
		ft_static(1);
	}
	i = 0;
	while (i < spc && s[i] != '\0')
		res = res + write (1, &s[i++], 1);
	return (res);
}

int	ft_point(const char *str, int i, va_list args)
{
	int	spc;
	int	res;

	spc = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		spc = spc * 10;
		spc = spc + str[i++] - '0';
		ft_static(1);
	}
	if (str[i] == 'i' || str[i] == 'u' || \
		str[i] == 'd' || str[i] == 'x' || str[i] == 'X')
		res = ft_cero_dot(str, i - ft_static(0) + 1, args);
	if (str[i] == 's')
	{
		res = ft_point_s(str, i - ft_static(0) + 1, args);
		ft_static(1);
	}
	return (res);
}

int	ft_hash(const char *str, int i, va_list args)
{
	int		res;
	int		n;
	va_list	args_copy;

	va_copy(args_copy, args);
	n = va_arg(args_copy, unsigned int);
	if (n == 0)
		return (write(1, "0", 1));
	if (str[i] == 'x')
		res = write(1, "0x", 2);
	else
		res = write(1, "0X", 2);
	res = res + ft_write_x(args, -88 + str[i]);
	return (res);
}

int	ft_space_plus(const char *str, int i, va_list args)
{
	int		res;
	int		j;
	va_list	args_copy;
	char	c;

	c = str[i - 1];
	res = 0;
	j = 0;
	va_copy(args_copy, args);
	if (str[i] == 'i' || str[i] == 'd')
	{
		j = va_arg(args, int);
		if (j > -1)
			res = res + write(1, &c, 1);
		res = res + ft_write_id(args_copy);
	}
	if (str[i] == '1')
	{
		res = write(1, " ", 1);
		ft_static(1);
	}
	if (str[i] == 's')
		res = res + ft_write_s(args);
	return (res);
}
