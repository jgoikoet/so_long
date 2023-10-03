/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_ia_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:23:06 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/07/07 11:30:35 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_enemy_movb(t_data *d)
{
	int	i;
	int	j;
	int	k;
	int	l;

	k = ft_st_temp('x', 0);
	l = ft_st_temp('y', 0);
	i = k - d->pbx;
	j = l - d->pby;
	if (i < 0)
		i = -i;
	if (j < 0)
		j = -j;
	if (i + j > 2 && l > d->pby && d->ar[d->pbx][d->pby + 1] != '1')
		d->pby = d->pby + 1;
	if (i + j > 2 && l < d->pby && d->ar[d->pbx][d->pby - 1] != '1')
		d->pby = d->pby - 1;
	j = l - d->pby;
	if (j < 0)
		j = -j;
	if (i + j > 2 && k > d->pbx && d->ar[d->pbx + 1][d->pby] != '1')
		d->pbx = d->pbx + 1;
	if (i + j > 2 && k < d->pbx && d->ar[d->pbx - 1][d->pby] != '1')
		d->pbx = d->pbx - 1;
}

void	ft_enemy_iab(t_data *d)
{
	static size_t	c = 1;

	d->dor2 = 0;
	c++;
	if (c % 12 == 0 && d->pby >= ft_st_temp('y', 0))
		d->p2 = mlx_xpm_file_to_image(d->mlx, "i/p_i_d.xpm", &d->res, &d->res);
	if (c % 24 == 0 && d->pby >= ft_st_temp('y', 0))
		d->p2 = mlx_xpm_file_to_image(d->mlx, "i/p_i_u.xpm", &d->res, &d->res);
	if (c % 12 == 0 && d->pby < ft_st_temp('y', 0))
		d->p2 = mlx_xpm_file_to_image(d->mlx, "i/p_d_d.xpm", &d->res, &d->res);
	if (c % 24 == 0 && d->pby < ft_st_temp('y', 0))
		d->p2 = mlx_xpm_file_to_image(d->mlx, "i/p_d_u.xpm", &d->res, &d->res);
	if (c > 600 && c < 1000)
	{
		d->p2 = mlx_xpm_file_to_image(d->mlx, "i/per_lo.xpm", &d->res, &d->res);
		d->dor2 = 1;
	}
	if (d->dor2 == 0 && c % 20 == 0)
		ft_enemy_movb(d);
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->p2, \
	d->pby * 64, d->pbx * 64);
	c++;
	if (c > 1800)
		c = 1;
}

void	ft_enemy_mova(t_data *d)
{
	int	i;
	int	j;
	int	k;
	int	l;

	k = ft_st_temp('x', 0);
	l = ft_st_temp('y', 0);
	i = k - d->pax;
	j = l - d->pay;
	if (i < 0)
		i = -i;
	if (j < 0)
		j = -j;
	if (i + j > 2 && k > d->pax && d->ar[d->pax + 1][d->pay] != '1')
		d->pax = d->pax + 1;
	if (i + j > 2 && k < d->pax && d->ar[d->pax - 1][d->pay] != '1')
		d->pax = d->pax - 1;
	i = ft_st_temp('x', 0) - d->pax;
	if (i < 0)
		i = -i;
	if (i + j > 2 && l > d->pay && d->ar[d->pax][d->pay + 1] != '1')
		d->pay = d->pay + 1;
	if (i + j > 2 && l < d->pay && d->ar[d->pax][d->pay - 1] != '1')
		d->pay = d->pay - 1;
}

void	ft_enemy_iaa(t_data *d)
{
	static size_t	c = 1;

	d->dor = 0;
	c++;
	if (c % 12 == 0 && d->pay >= ft_st_temp('y', 0))
		d->p1 = mlx_xpm_file_to_image(d->mlx, "i/p_i_d.xpm", &d->res, &d->res);
	if (c % 24 == 0 && d->pay >= ft_st_temp('y', 0))
		d->p1 = mlx_xpm_file_to_image(d->mlx, "i/p_i_u.xpm", &d->res, &d->res);
	if (c % 12 == 0 && d->pay < ft_st_temp('y', 0))
		d->p1 = mlx_xpm_file_to_image(d->mlx, "i/p_d_d.xpm", &d->res, &d->res);
	if (c % 24 == 0 && d->pay < ft_st_temp('y', 0))
		d->p1 = mlx_xpm_file_to_image(d->mlx, "i/p_d_u.xpm", &d->res, &d->res);
	if (c > 500 && c < 1000)
	{
		d->p1 = mlx_xpm_file_to_image(d->mlx, "i/per_lo.xpm", &d->res, &d->res);
		d->dor = 1;
	}
	if (d->dor == 0 && c % 22 == 0)
		ft_enemy_mova(d);
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->p1, \
	d->pay * 64, d->pax * 64);
	c++;
	if (c > 1500)
		c = 1;
}

void	ft_enemy_ia(t_data *d)
{
	ft_enemy_iaa(d);
	ft_enemy_iab(d);
	ft_enemy_iac(d);
	if ((ft_st_temp('x', 0) == d->pax && \
	ft_st_temp('y', 0) == d->pay && d->dor == 0) || \
	(ft_st_temp('x', 0) == d->pbx && \
	ft_st_temp('y', 0) == d->pby && d->dor2 == 0) || \
	(ft_st_temp('x', 0) == d->pcx && \
	ft_st_temp('y', 0) == d->pcy && d->dor3 == 0))
		ft_free(d);
}
