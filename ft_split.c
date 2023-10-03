/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:04:32 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/07/05 16:34:39 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_del(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(array[i++]);
	free(array);
	return (NULL);
}

char	*ft_subsplit(char const *s, char c, int i)
{
	int		len;
	char	*str;
	int		start;

	start = i;
	len = 1;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	i = 0;
	str = (char *) malloc (sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	while (s[start] != c && s[start] != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int	ft_strcount(const char *s, char c)
{
	int	i;
	int	snbr;
	int	ok;

	i = 0;
	snbr = 0;
	ok = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && ok == 1)
		{
			snbr++;
			ok = 0;
		}
		if (s[i] == c)
			ok = 1;
		i++;
	}
	return (snbr);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (0);
	array = (char **) malloc (sizeof(char *) * ((ft_strcount(s, c)) + 1));
	if (array == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			str = ft_subsplit(s, c, i);
			if (!str)
				return (ft_del(array, j));
			array[j++] = str;
			i = i + ft_strlen(str) - 1;
		}
	}
	array[j] = 0;
	return (array);
}
