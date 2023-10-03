/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:45:41 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/06/13 11:59:59 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_id_bonus(int n)
{
	int		i;
	int		res;
	int		sign;
	char	nb[10];

	i = 0;
	res = 0;
	sign = 1;
	if (n == 0)
		res = write (1, "0", 1);
	if (n < 0)
		sign = -sign;
	while (n)
	{
		nb[i++] = (n % 10 * sign) + '0';
		n = n / 10;
	}
	while (i > 0)
		res = res + write (1, &nb[i-- - 1], 1);
	return (res);
}

int	ft_cero_print(int spc)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i++ < spc)
		res = res + write(1, "0", 1);
	return (res);
}

int	ft_cero_extra_x(va_list args, int x, int spc)
{
	unsigned int	n;
	int				i;
	int				res;
	int				dig;
	char			nb[11];

	n = va_arg(args, unsigned int);
	i = 0;
	res = 0;
	while (n)
	{
		dig = n % 16;
		if (dig > 9)
			nb[i++] = dig -10 + 'A' + x;
		else
			nb[i++] = dig + '0';
		n = n / 16;
	}
	res = res + ft_cero_print(spc - i);
	while (i > 0)
		res = res + write (1, &nb[i-- - 1], 1);
	return (res);
}

int	ft_cero_extra(const char *str, int i, int spc, va_list args)
{
	int				j;
	int				res;
	unsigned int	u;
	va_list			args_copy;

	j = 0;
	res = 0;
	va_copy(args_copy, args);
	if (str[i] == '%')
	{
		res = res + ft_cero_print(spc - 1);
		return (res = res + write(1, "%", 1));
	}
	if (str[i] == 'u')
	{
		u = va_arg(args, unsigned int);
		res = res + ft_cero_print(spc - ft_numlen_u(u));
		ft_static(1);
		return (res = res + ft_write_u(args_copy));
	}
	res = res + ft_cero_extra_x(args, -88 + str[i], spc);
	ft_static(1);
	return (res);
}

int	ft_cero(const char *str, int i, va_list args)
{
	int	spc;
	int	res;
	int	n;
	int	ncero;

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
	ncero = spc - ft_numlen(n);
	if (n < 0)
		res = res + write(1, "-", 1);
	while (ncero-- > 0)
		res = res + write(1, "0", 1);
	res = res + ft_write_id_bonus(n);
	ft_static(1);
	return (res);
}
