/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:07:23 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/07/05 13:01:18 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_static(int j)
{
	static int	i = 0;

	i = i + j;
	return (i);
}

int	ft_numlen(int i)
{
	int	nlen;

	if (i == 0)
		return (1);
	nlen = 0;
	if (i < 0)
		nlen = 1;
	while (i)
	{
		nlen++;
		i = i / 10;
	}
	return (nlen);
}

int	ft_numlen_u(unsigned int i)
{
	int	nlen;

	if (i == 0)
		return (1);
	nlen = 0;
	if (i < 0)
		nlen = 1;
	while (i)
	{
		nlen++;
		i = i / 10;
	}
	return (nlen);
}

int	ft_cero_dot(const char *str, int i, va_list args)
{
	int	spc;
	int	res;
	int	n;

	spc = 0;
	res = 0;
	ft_static(-ft_static(0));
	while (str[i] >= '0' && str[i] <= '9')
	{
		spc = spc * 10;
		spc = spc + str[i++] - '0';
		ft_static(1);
	}
	if (str[i] == '%' || str[i] == 'x' || str[i] == 'X' || str[i] == 'u')
		return (ft_cero_extra(str, i, spc, args));
	n = va_arg(args, int);
	if (n < 0)
	{
		res = res + write(1, "-", 1);
		spc++;
	}
	while ((spc-- - ft_numlen(n)) > 0)
		res = res + write(1, "0", 1);
	res = res + ft_write_id_bonus(n);
	return (ft_static(1), res);
}

int	ft_bonus(const char *str, int i, va_list args)
{
	int	res;

	res = 0;
	ft_static(1);
	if (str[i] == '-')
		res = ft_minus(str, i + 1, args);
	if (str[i] == '0')
		res = ft_cero(str, i + 1, args);
	if (str[i] == '.')
		res = ft_point(str, i + 1, args);
	if (str[i] == '#')
		res = ft_hash(str, i + 1, args);
	if (str[i] == ' ' || str[i] == '+')
		res = ft_space_plus(str, i + 1, args);
	return (res);
}
