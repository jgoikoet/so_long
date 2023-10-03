/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_utils_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:12:51 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/07/10 11:59:25 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free(t_data *d)
{
	mlx_destroy_window(d->mlx, d->mlx_win);
	ft_del(d->ar, ft_st_map('l', 0));
	exit(0);
	return (0);
}

int	ft_final_check(void)
{
	if (ft_st_map('k', 0) == ft_st_temp('k', 0) && ft_st_temp('e', 0) == 1)
		return (1);
	return (0);
}
