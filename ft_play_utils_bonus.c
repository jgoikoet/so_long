/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:12:48 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/07/07 16:33:38 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_pos(char **array, int x, int y)
{
	if (array[x][y] == 'C')
		ft_st_temp('k', ft_st_temp('k', 0) + 1);
	if (array[x][y] == 'E')
		ft_st_temp('e', 1);
	if (array[x][y] != '-')
	{
		ft_st_map('b', 1);
		array[x][y] = '-';
	}
}

void	ft_anime(t_data *d)
{
	static size_t	c = 1;

	c++;
	if (c % 10 == 0)
		d->risitas = mlx_xpm_file_to_image(d->mlx, "i/risitas.xpm", \
		&d->res, &d->res);
	if (c % 20 == 0)
		d->risitas = mlx_xpm_file_to_image(d->mlx, "i/risitas2.xpm", \
		&d->res, &d->res);
	if (c % 10 == 0)
		d->birra = mlx_xpm_file_to_image(d->mlx, "i/birra.xpm", \
		&d->res, &d->res);
	if (c % 20 == 0)
		d->birra = mlx_xpm_file_to_image(d->mlx, "i/birra2.xpm", \
		&d->res, &d->res);
	if (c % 30 == 0)
		d->birra = mlx_xpm_file_to_image(d->mlx, "i/birra3.xpm", \
		&d->res, &d->res);
	if (c % 5 == 0 && ft_st_temp('k', 0) == 0)
		d->cobete = mlx_xpm_file_to_image(d->mlx, "i/cobete_on1.xpm", \
		&d->res, &d->res);
	if (c % 10 == 0 && ft_st_temp('k', 0) == 0)
		d->cobete = mlx_xpm_file_to_image(d->mlx, "i/cobete_on2.xpm", \
		&d->res, &d->res);
}

int	ft_move(t_data *d, int x, int y)
{
	int	i;

	i = ft_st_temp('k', 0);
	if (d->ar[x][y] == '1')
		return (0);
	d->count = d->count + 1;
	ft_count(d);
	if (d->ar[x][y] == 'C')
	{
		if (ft_st_temp('k', 0) == 1)
			ft_st_temp('q', 0);
		ft_st_temp('k', i - 1);
		d->ar[x][y] = '0';
		d->eru = 3;
	}
	if (d->eru == 3 || d->eru == 2)
	{
		d->risitas = mlx_xpm_file_to_image(d->mlx, "i/riseru.xpm", \
		&d->res, &d->res);
		d->risitas2 = mlx_xpm_file_to_image(d->mlx, "i/riseru.xpm", \
		&d->res, &d->res);
	}
	ft_st_temp('x', x);
	ft_st_temp('y', y);
	return (0);
}

int	key_hook(int keycode, t_data *d)
{
	int	x;
	int	y;

	x = ft_st_temp('x', 0);
	y = ft_st_temp('y', 0);
	if (keycode == 53)
		ft_free(d);
	if (keycode == 13 && d->fin == 0)
		ft_move(d, x - 1, y);
	if (keycode == 1 && d->fin == 0)
		ft_move(d, x + 1, y);
	if (keycode == 0 && d->fin == 0)
		ft_move(d, x, y - 1);
	if (keycode == 2 && d->fin == 0)
		ft_move(d, x, y + 1);
	return (0);
}

int	ft_start(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (d->ar[i])
	{
		j = 0;
		while (d->ar[i][j] != '\0')
		{
			if (d->ar[i][j] != '1')
				mlx_put_image_to_window(d->mlx, d->mlx_win, 
					d->suelo, j * 64, i * 64);
			else
				mlx_put_image_to_window(d->mlx, d->mlx_win, 
					d->pared, j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->d_mil, 3, 3);
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->d_cen, 38, 3);
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->d_dec, 73, 3);
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->d_uni, 108, 3);
	ft_enemy_ia(d);
	return (0);
}
