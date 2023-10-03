/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_set_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:14:03 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/07/07 11:30:28 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_enemy_setc(t_data *d)
{
	char	**arr;
	int		x;
	int		y;
	int		set;

	arr = d->ar2;
	set = 0;
	x = 1;
	while (x < ft_st_map('l', 0) - 1 && !set)
	{
		y = ft_st_map('c', 0) - 1;
		while (y > 0 && !set)
		{
			if (arr[x][y] == '-' && (d->ar[x][y] == '0' || d->ar[x][y] == 'C'))
			{
				d->pcx = x;
				d->pcy = y;
				set = 1;
			}
			y--;
		}
		x++;
	}
}

void	ft_enemy_setb(t_data *d)
{
	char	**arr;
	int		x;
	int		y;
	int		set;

	arr = d->ar2;
	set = 0;
	x = ft_st_map('l', 0) - 1;
	while (x > 0 && !set)
	{
		y = ft_st_map('c', 0) - 1;
		while (y > 0 && !set)
		{
			if (arr[x][y] == '-' && (d->ar[x][y] == '0' || d->ar[x][y] == 'C'))
			{
				d->pbx = x;
				d->pby = y;
				set = 1;
			}
			y--;
		}
		x--;
	}
	ft_enemy_setc(d);
}

void	ft_enemy_set(t_data *d)
{
	char	**arr;
	int		x;
	int		y;
	int		set;

	arr = d->ar2;
	set = 0;
	x = 1;
	while (x < ft_st_map('l', 0) - 1 && !set)
	{
		y = 1;
		while (y < ft_st_map('c', 0) - 1 && !set)
		{
			if (arr[x][y] == '-' && (d->ar[x][y] == '0' || d->ar[x][y] == 'C'))
			{
				d->pax = x;
				d->pay = y;
				set = 1;
			}
			y++;
		}
		x++;
	}
	ft_enemy_setb(d);
}

void	ft_change(char **array, int x, int y)
{
	if (array[x][y] != '-')
	{
		ft_st_map('b', 1);
		array[x][y] = '-';
	}
}

char	**enemy_ar(char *str)
{
	int		x;
	int		y;
	char	**arr;

	arr = ft_split(str, '\n');
	arr[ft_st_temp('x', 0)][ft_st_temp('y', 0)] = '-';
	ft_st_map('b', 1);
	while (ft_st_map('b', -1))
	{
		ft_st_map('b', 0);
		x = 1;
		while (x < ft_st_map('l', 0) - 1)
		{
			y = 1;
			while (y < ft_st_map('c', 0) - 1)
			{
				if (arr[x][y] != '1' && (arr[x + 1][y] == '-' || arr[x - 1][y] \
					== '-' || arr[x][y + 1] == '-' || arr[x][y - 1] == '-'))
					ft_change(arr, x, y);
				y++;
			}
			x++;
		}
	}
	return (free(str), arr);
}
