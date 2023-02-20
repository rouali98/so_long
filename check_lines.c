/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ferst_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:55:47 by rouali            #+#    #+#             */
/*   Updated: 2023/02/18 17:52:10 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ############# Check Center Line ###################### */
int	center_wall(char **map)
{
	int	x;
	int	y;
	int	xx;

	y = f_strlen(map) - 1;
	x = 0;
	xx = ft_strlen(map[x]);
	while (map[y] != '\0')
	{
		x = 0;
		if (y >= 0 && xx != ft_strlen(map[y]))
			return (1);
		if (y >= 1)
		{
			while (map[y][x] != '\0')
			{
				if (map[y][0] != '1' || map[y][xx - 1] != '1')
					return (1);
				x++;
			}
		}
		y--;
	}
	return (0);
}

/* ############# Return Line ###################### */
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
		ft_putstr("Error");
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
	close(fd);
	return (m);
}

void	check_lines(void)
{
	if (line_up(mx.map) == 1 || \
	line_down(mx.map) == 1 || center_wall(mx.map) == 1)
	{
		ft_putstr("Error Map");
		exit(1);
	}
}

/* ############# Check Line Up ###################### */
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

/* ############# Check Line Down ###################### */
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
