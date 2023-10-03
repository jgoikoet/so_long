/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playability.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:16:35 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/07/06 18:53:26 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_st_map(char x, int i)
{
	static int	l = 0;
	static int	c = 0;
	static int	k = 0;
	static int	b = 1;

	if (x == 'l' && i != 0)
		l = i;
	if (x == 'c' && i != 0)
		c = i;
	if (x == 'k' && i != 0)
		k = i;
	if (x == 'b' && i != -1)
		b = i;
	if (x == 'l')
		return (l);
	if (x == 'c')
		return (c);
	if (x == 'k')
		return (k);
	if (x == 'b')
		return (b);
	return (0);
}

int	ft_st_temp(char c, int i)
{
	static int	x = 0;
	static int	y = 0;
	static int	k = 0;
	static int	e = 0;

	if (c == 'x' && i != 0)
		x = i;
	if (c == 'y' && i != 0)
		y = i;
	if (c == 'k' && i != 0)
		k = i;
	if (c == 'e' && i != 0)
		e = i;
	if (c == 'x')
		return (x);
	if (c == 'y')
		return (y);
	if (c == 'k')
		return (k);
	if (c == 'e')
		return (e);
	if (c == 'q')
		k = 0;
	return (0);
}

void	ft_player_pos(char	**array)
{
	int	i;
	int	j;
	int	lin;
	int	col;

	i = 1;
	while (i < ft_lines(array) - 1)
	{
		j = 1;
		while (j < ft_strlen(array[0]))
		{
			if (array[i][j++] == 'P')
			{
				lin = i;
				col = j - 1;
				i = ft_lines(array);
				j = ft_strlen(array[0]);
			}
		}
		i++;
	}
	ft_st_temp('x', lin);
	ft_st_temp('y', col);
}

void	ft_swept(char **arr)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (x < ft_st_map('l', 0) - 1)
	{
		y = 1;
		while (y < ft_st_map('c', 0) - 1)
		{
			if (arr[x][y] != '1' && (arr[x + 1][y] == '-' || \
				arr[x - 1][y] == '-' || arr[x][y + 1] == '-' || \
				arr[x][y - 1] == '-'))
				ft_check_pos(arr, x, y);
			y++;
		}
		x++;
	}
}

int	ft_playability(char *str)
{
	char	**array_cpy;

	array_cpy = ft_split(str, '\n');
	free(str);
	ft_st_map('c', ft_strlen(array_cpy[0]));
	ft_player_pos(array_cpy);
	array_cpy[ft_st_temp('x', 0)][ft_st_temp('y', 0)] = '-';
	while (ft_st_map('b', -1))
	{
		ft_st_map('b', 0);
		ft_swept(array_cpy);
	}
	ft_del(array_cpy, ft_st_map('l', 0));
	return (ft_final_check());
}
