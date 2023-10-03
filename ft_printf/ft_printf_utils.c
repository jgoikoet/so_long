/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:00:24 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/06/09 13:05:31 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_p_x(unsigned long long int n)
{
	int						i;
	int						res;
	int						dig;
	char					nb[16];

	if (!n)
		return (write (1, "0x0", 3), 3);
	i = 0;
	res = write(1, "0x", 2);
	while (n)
	{
		dig = n % 16;
		if (dig > 9)
			nb[i++] = dig -10 + 'a';
		else
			nb[i++] = dig + '0';
		n = n / 16;
	}
	while (i > 0)
		res = res + write (1, &nb[i-- - 1], 1);
	return (res);
}

int	ft_write_p(va_list args)
{
	char			*str;
	long long int	n;

	str = va_arg(args, char *);
	n = (unsigned long long int)str;
	return (ft_write_p_x(n));
}

int	ft_write_x(va_list args, int x)
{
	unsigned int	n;
	int				i;
	int				res;
	int				dig;
	char			nb[11];

	n = va_arg(args, unsigned int);
	i = 0;
	res = 0;
	if (n == 0)
		res = write(1, "0", 1);
	while (n)
	{
		dig = n % 16;
		if (dig > 9)
			nb[i++] = dig -10 + 'A' + x;
		else
			nb[i++] = dig + '0';
		n = n / 16;
	}
	while (i > 0)
		res = res + write (1, &nb[i-- - 1], 1);
	return (res);
}

int	ft_write_u(va_list args)
{
	unsigned int	n;
	int				i;
	int				res;
	char			nb[10];

	n = va_arg(args, unsigned int);
	i = 0;
	res = 0;
	if (n == 0)
		res = write (1, "0", 1);
	while (n)
	{
		nb[i++] = n % 10 + '0';
		n = n / 10;
	}
	while (i > 0)
		res = res + write (1, &nb[i-- -1], 1);
	return (res);
}

int	ft_write_id(va_list args)
{
	int		n;
	int		i;
	int		res;
	int		sign;
	char	nb[10];

	n = va_arg(args, int);
	i = 0;
	res = 0;
	sign = 1;
	if (n == 0)
		res = write (1, "0", 1);
	if (n < 0)
	{
		res = res + write(1, "-", 1);
		sign = -sign;
	}
	while (n)
	{
		nb[i++] = (n % 10 * sign) + '0';
		n = n / 10;
	}
	while (i > 0)
		res = res + write (1, &nb[i-- - 1], 1);
	return (res);
}
