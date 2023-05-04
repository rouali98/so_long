/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:54:05 by rouali            #+#    #+#             */
/*   Updated: 2023/05/01 15:39:46 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ############### Count Char ############### */
int	ft_count(char **str)
{
	int	x;

	x = 0;
	while (str[0][x] != '\0')
		x++;
	return (x);
}

/* ############# Count Line in file ###################### */
int	count_line(char *argv)
{
	char	*map;
	int		fd;
	int		y;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_print_error();
	y = 0;
	while (1)
	{
		map = get_next_line(fd);
		if (map == NULL)
			break ;
		y++;
		free(map);
	}
	close(fd);
	return (y);
}

/* ############### Count C ############### */
int	count_c(char **map)
{
	int	y;
	int	x;
	int	c;

	y = 0;
	c = 0;
	while (map[y] != '\0')
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				c += 1;
			x++;
		}
		y++;
	}
	return (c);
}

/* ############# Count E ###################### */
int	count_e(char **map)
{
	int	e;

	di.y = 0;
	e = 0;
	while (map[di.y] != '\0')
	{
		di.x = 0;
		while (map[di.y][di.x] != '\0')
		{
			if (map[di.y][di.x] == 'E')
				e += 1;
			di.x++;
		}
		di.y++;
	}
	return (e);
}

/* ############# Count P ###################### */
int	count_p(char **map)
{
	int	p;

	di.y = 0;
	p = 0;
	while (map[di.y] != '\0')
	{
		di.x = 0;
		while (map[di.y][di.x] != '\0')
		{
			if (map[di.y][di.x] == 'P')
				p += 1;
			di.x++;
		}
		di.y++;
	}
	return (p);
}
