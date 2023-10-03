/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_utils_b_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:12:51 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/08/03 16:47:58 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_free(t_data *d)
{
	mlx_destroy_window(d->mlx, d->mlx_win);
	ft_del(d->ar, ft_st_map('l', 0));
	ft_del(d->ar2, ft_st_map('l', 0));
	system ("leaks so_long_bonus");
	exit(0);
	return (0);
}

int	ft_final_check(void)
{
	if (ft_st_map('k', 0) == ft_st_temp('k', 0) && ft_st_temp('e', 0) == 1)
		return (1);
	return (0);
}

int	ft_clos(t_data *d)
{
	int				i;
	int				j;
	static int		f = 0;
	static size_t	c = 1;

	d->fin = 1;
	d->risitas = mlx_xpm_file_to_image(d->mlx, "i/ri0.xpm", &d->res, &d->res);
	ft_start(d);
	i = ft_st_temp('x', 0);
	j = ft_st_temp('y', 0);
	if (c % 5 == 0)
		d->cobete = mlx_xpm_file_to_image(d->mlx, "i/cobete_onb1.xpm", \
		&d->res, &d->res);
	if (c % 10 == 0)
		d->cobete = mlx_xpm_file_to_image(d->mlx, "i/cobete_onb2.xpm", \
		&d->res, &d->res);
	c++;
	if (c > 100 && c % 4 == 0)
		f++;
	if (i - f >= 0)
		mlx_put_image_to_window(d->mlx, d->mlx_win, d->cobete, \
		j * 64, (i - f) * 64);
	if (i - f == -2)
		return (system("afplay sound/Risitas.mp3"), ft_free(d), 0);
	return (0);
}

void	ft_count(t_data *d)
{
	static char	num[] = "i/0.xpm";
	int			x;
	int			y;
	int			n;

	x = 32;
	y = 58;
	n = d->count;
	num[2] = n % 10 + '0';
	n = n / 10;
	d->d_uni = mlx_xpm_file_to_image(d->mlx, num, &d->res, &d->res);
	num[2] = n % 10 + '0';
	n = n / 10;
	d->d_dec = mlx_xpm_file_to_image(d->mlx, num, &d->res, &d->res);
	num[2] = n % 10 + '0';
	n = n / 10;
	d->d_cen = mlx_xpm_file_to_image(d->mlx, num, &d->res, &d->res);
	num[2] = n % 10 + '0';
	n = n / 10;
	d->d_mil = mlx_xpm_file_to_image(d->mlx, num, &d->res, &d->res);
	ft_printf("Numero de movimientos = %i\n", d->count);
}
