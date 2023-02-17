/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ferst_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:55:47 by rouali            #+#    #+#             */
/*   Updated: 2023/02/11 17:55:48 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

//############# Count Line ######################//
int	f_strlen(char **map)
{
	int	y;

	y = 0;
	while (map[y] != '\0')
	{
		y++;
	}
	return (y);
}

//############# Count Line in file ######################//
int	count_line(char *argv)
{
	char	*map;
	int		fd;
	int		y;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("Error");
		return (0);
	}
	y = 0;
	while (1)
	{
		map = get_next_line(fd);
		if (map == NULL)
			break ;
		y++;
	}
	close(fd);
	return (y);
}

//############# Return Line ######################//
char	**ft_rline(char *argv)
{
	char	**m;
	char	*map;
	int		fd;
	int		y;

	m = malloc(sizeof(char *) * (count_line(argv) + 1));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("Error");
		return (0);
	}
	y = 0;
	while (1)
	{
		map = get_next_line(fd);
		if (map == NULL)
			break ;
		m[y] = map;
		y++;
	}
	m[y] = 0;
	return (m);
}

//############# Check Line Up ######################//
int	line_up(char **map)
{
	int	y;
	int	x;

	y = f_strlen(map) - 1;
	x = 0;
	while (map[y] != '\0')
	{
		if (y == 0)
		{
			while (map[y][x] != '\0')
			{
				if (map[y][x] != '1')
				{
					return (1);
				}
				x++;
			}
		}
		y--;
	}
	return (0);
}

//############# Check Line Down ######################//
int	line_down(char **map)
{
	int	y;
	int	x;

	y = f_strlen(map) - 1;
	x = 0;
	while (map[y] != '\0')
	{
		if (y == (f_strlen(map) - 1))
		{
			while (map[y][x] != '\0')
			{
				if (map[y][x] != '1')
				{
					return (1);
				}
				x++;
			}
		}
		y--;
	}
	return (0);
}
