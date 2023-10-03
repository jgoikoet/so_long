/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:57:27 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/07/10 11:28:43 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_lines(char	**array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	ft_st_map('l', i);
	return (i);
}

char	*ft_stract(char *map, int i)
{
	char	*str;
	int		fd;

	str = (char *) malloc (sizeof(char) * i + 1);
	if (!str)
		return (0);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nNose pudo abrir el archivo"), NULL);
	read (fd, str, i);
	str[i] = '\0';
	close(fd);
	return (str);
}

int	ft_map_len(char *map)
{
	int		fd;
	int		i;
	char	buffer[1];

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nNose pudo abrir el archivo"), 0);
	while (read(fd, buffer, 1))
		i++;
	if (i < 1)
		return (close(fd), ft_printf("Error\nMapa vacio.\n"), 0);
	return (i);
}

int	ft_char_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C' && \
		str[i] != 'E' && str[i] != 'P' && str[i] != '\n')
		{
			ft_printf("Error\nEl mapa contiene caracteres prohibidos payaso.");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**array;

	array = NULL;
	if (argc != 2)
		return (ft_printf("Error\nNumero de argumentos incorrecto.\n"), -1);
	if (!ft_format(argv[1]))
		return (ft_printf("Error\nFormato de mapa incorrecto MERLUZO\n"), -1);
	if (ft_map_len(argv[1]) == 0)
		return (-1);
	str = ft_stract(argv[1], ft_map_len(argv[1]));
	if (!ft_char_check(str))
		return (free (str), -1);
	if (str)
		array = ft_split(str, '\n');
	if (!ft_error(array, str))
		return (free(str), ft_del(array, ft_lines(array)), -1);
	if (ft_playability(str))
		ft_play(array, str);
	else
	{
		ft_printf("Error\n----------\nmapa irresoluble PAYASO\n----------\n");
		return (free (str), ft_del(array, ft_lines(array)), 0);
	}
	return (0);
}
