/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:21:36 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/07/07 11:30:24 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_border_check(char **array, int lin, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (array[0][i] != '1' || array[lin - 1][i] != '1')
			return (ft_printf("Error\nMuro exterior abierto gañan."), 0);
		i++;
	}
	i = 0;
	while (i < lin)
	{
		if (array[i][0] != '1' || array[i][col - 1] != '1')
			return (ft_printf("Error\nMuro exterior abierto lerdo."), 0);
		i++;
	}
	return (1);
}

int	ft_player_exit_colect_check(char *str)
{
	int	i;
	int	p;
	int	e;
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P')
			p = p + 1;
		if (str[i] == 'E')
			e = e + 1;
		if (str[i++] == 'C')
			c = c + 1;
	}
	ft_st_map('k', c);
	if (p != 1 || e != 1 || c < 1)
	{
		ft_printf("Error\nNº de players, salidas o coleccionables erroneo.");
		return (0);
	}
	return (1);
}

int	ft_rect_check(char **array)
{
	int	i;
	int	j;

	i = (ft_lines(array));
	if (i < 3)
	{
		ft_printf("Error\nEn este mapa no cabe ni un alfiler payaso.");
		return (0);
	}
	j = 0;
	while (j < i - 1)
	{
		if (ft_strlen(array[j]) != ft_strlen(array[j + 1]))
			return (ft_printf("Error\nEl mapa no es rectangular payaso."), 0);
		j++;
	}
	return (1);
}

int	ft_format(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i < 5)
		return (0);
	if (str[i-- - 1] != 'r')
		return (0);
	if (str[i-- - 1] != 'e')
		return (0);
	if (str[i-- - 1] != 'b')
		return (0);
	if (str[i-- - 1] != '.')
		return (0);
	return (1);
}

int	ft_error(char **array, char *str)
{
	if (!ft_rect_check(array))
		return (0);
	if (!ft_player_exit_colect_check(str))
		return (0);
	if (!ft_border_check(array, ft_lines(array), ft_strlen(array[0])))
		return (0);
	return (1);
}
