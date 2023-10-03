/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_crazy_iabonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:01:43 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/07/07 11:30:39 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_enemy_movc_b(t_data *d, int n)
{
	int			i;
	int			j;
	int			k;
	int			l;

	k = ft_st_temp('x', 0);
	l = ft_st_temp('y', 0);
	i = k - d->pcx;
	j = l - d->pcy;
	if (i < 0)
		i = -i;
	if (j < 0)
		j = -j;
	if (n % 2 == 0 && i + j > 1 && l > d->pcy && \
	d->ar[d->pcx][d->pcy + 1] != '1')
		d->pcy = d->pcy + 1;
	if (n % 2 == 0 && i + j > 1 && l < d->pcy && \
		d->ar[d->pcx][d->pcy - 1] != '1')
		d->pcy = d->pcy - 1;
}

void	ft_enemy_movc(t_data *d)
{
	int			i;
	int			j;
	int			k;
	int			l;
	static int	n = 0;

	ft_enemy_movc_b(d, n);
	k = ft_st_temp('x', 0);
	l = ft_st_temp('y', 0);
	i = k - d->pcx;
	j = l - d->pcy;
	if (i < 0)
		i = -i;
	if (j < 0)
		j = -j;
	if (n % 2 != 0 && i + j > 1 && k > d->pcx && \
	d->ar[d->pcx + 1][d->pcy] != '1')
		d->pcx = d->pcx + 1;
	if (n % 2 != 0 && i + j > 1 && k < d->pcx && \
	d->ar[d->pcx - 1][d->pcy] != '1')
		d->pcx = d->pcx - 1;
	n++;
}

void	ft_enemy_iac(t_data *d)
{
	static size_t	c = 1;

	d->dor3 = 0;
	c++;
	if (c % 12 == 0 && d->pcy >= ft_st_temp('y', 0))
		d->p3 = mlx_xpm_file_to_image(d->mlx, "i/d_i_d.xpm", &d->res, &d->res);
	if (c % 24 == 0 && d->pcy >= ft_st_temp('y', 0))
		d->p3 = mlx_xpm_file_to_image(d->mlx, "i/d_i_u.xpm", &d->res, &d->res);
	if (c % 12 == 0 && d->pcy < ft_st_temp('y', 0))
		d->p3 = mlx_xpm_file_to_image(d->mlx, "i/d_d_d.xpm", &d->res, &d->res);
	if (c % 24 == 0 && d->pcy < ft_st_temp('y', 0))
		d->p3 = mlx_xpm_file_to_image(d->mlx, "i/d_d_u.xpm", &d->res, &d->res);
	if (c > 1000 && c < 1200)
	{
		d->p3 = mlx_xpm_file_to_image(d->mlx, "i/d_lo.xpm", &d->res, &d->res);
		d->dor3 = 1;
	}
	if (d->dor3 == 0 && c % 4 == 0)
		ft_enemy_movc(d);
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->p3, \
	d->pcy * 64, d->pcx * 64);
	c++;
	if (c > 1800)
		c = 1;
}
