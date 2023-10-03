/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:34:56 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/07/07 11:30:20 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_player(t_data *d)
{
	int		i;
	int		j;

	i = ft_st_temp('x', 0);
	j = ft_st_temp('y', 0);
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->risitas, j * 64, i * 64);
	if (!d->fin)
		ft_anime(d);
	if (d->eru == 2)
		d->eru = 1;
	if (d->eru == 3)
		d->eru = 2;
	if (d->eru == 1)
	{
		d->eru = 0;
		system("afplay sound/eructo.mp3");
	}
}

void	ft_items_print(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (d->ar[i])
	{
		j = 0;
		while (d->ar[i][j] != '\0')
		{
			if (d->ar[i][j] == 'C')
				mlx_put_image_to_window(d->mlx, d->mlx_win, \
				d->birra, j * 64, i * 64);
			if (d->ar[i][j] == 'E' && !d->fin)
				mlx_put_image_to_window(d->mlx, d->mlx_win, \
				d->cobete, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int	ft_items(t_data *d)
{
	int		i;
	int		j;

	i = ft_st_temp('x', 0);
	j = ft_st_temp('y', 0);
	if (!ft_st_temp('k', 0) && d->ar[i][j] == 'E')
		ft_clos(d);
	else
		ft_start(d);
	ft_items_print(d);
	ft_player(d);
	return (0);
}

void	ft_image(t_data *d)
{
	int	res;
	int	x;
	int	y;

	res = 64;
	x = 32;
	y = 58;
	d->pared = mlx_xpm_file_to_image(d->mlx, "i/pared.xpm", &res, &res);
	d->suelo = mlx_xpm_file_to_image(d->mlx, "i/hierba2.xpm", &res, &res);
	d->birra = mlx_xpm_file_to_image(d->mlx, "i/birra.xpm", &res, &res);
	d->cobete = mlx_xpm_file_to_image(d->mlx, "i/cobete_off.xpm", &res, &res);
	d->p1 = mlx_xpm_file_to_image(d->mlx, "i/p_i_d.xpm", &d->res, &d->res);
	d->p2 = mlx_xpm_file_to_image(d->mlx, "i/p_i_d.xpm", &d->res, &d->res);
	d->p3 = mlx_xpm_file_to_image(d->mlx, "i/d_i_d.xpm", &d->res, &d->res);
	d->d_uni = mlx_xpm_file_to_image(d->mlx, "i/0.xpm", &x, &y);
	d->d_dec = mlx_xpm_file_to_image(d->mlx, "i/0.xpm", &x, &y);
	d->d_cen = mlx_xpm_file_to_image(d->mlx, "i/0.xpm", &x, &y);
	d->d_mil = mlx_xpm_file_to_image(d->mlx, "i/0.xpm", &x, &y);
}

void	ft_play(char **array, char *str)
{
	t_data	d;
	int		x;
	int		y;
	size_t	c;

	c = 0;
	c++;
	d.fin = 0;
	d.res = 64;
	d.eru = 0;
	d.count = 0;
	d.ar = array;
	d.ar2 = enemy_ar(str);
	ft_enemy_set(&d);
	x = ft_st_map('c', 0);
	y = ft_st_map('l', 0);
	d.mlx = mlx_init();
	d.mlx_win = mlx_new_window(d.mlx, x * 64, y * 64, "- Er bideojuebo -");
	d.img = mlx_new_image(d.mlx, x * 64, y * 64);
	ft_image(&d);
	mlx_loop_hook(d.mlx, ft_items, &d);
	mlx_key_hook(d.mlx_win, key_hook, &d);
	mlx_hook(d.mlx_win, 17, 0, ft_free, &d);
	mlx_loop(d.mlx);
}
