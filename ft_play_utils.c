/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:12:48 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/07/06 17:57:59 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_move(t_data *d, int x, int y)
{
	int	i;

	i = ft_st_temp('k', 0);
	if (d->ar[x][y] == '1')
		return (0);
	d->count = d->count + 1;
	ft_printf("Numero de movimientos = %i\n", d->count);
	if (d->ar[x][y] == 'C')
	{
		if (ft_st_temp('k', 0) == 1)
			ft_st_temp('q', 0);
		ft_st_temp('k', i - 1);
		d->ar[x][y] = '0';
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
	if (keycode == 13)
		ft_move(d, x - 1, y);
	if (keycode == 1)
		ft_move(d, x + 1, y);
	if (keycode == 0)
		ft_move(d, x, y - 1);
	if (keycode == 2)
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
	return (0);
}
