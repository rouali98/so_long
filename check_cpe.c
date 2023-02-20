/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:36:46 by rouali            #+#    #+#             */
/*   Updated: 2023/02/18 17:53:04 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

/* ############# Count E ###################### */
int	count_e(char **map)
{
	int	c;

	di.y = 0;
	c = 0;
	while (map[di.y] != '\0')
	{
		di.x = 0;
		while (map[di.y][di.x] != '\0')
		{
			if (map[di.y][di.x] == 'E')
			{
				c += 1;
			}
			di.x++;
		}
		di.y++;
	}
	return (c);
}

/* ############# Count P ###################### */
int	count_p(char **map)
{
	int	c;

	di.y = 0;
	c = 0;
	while (map[di.y] != '\0')
	{
		di.x = 0;
		while (map[di.y][di.x] != '\0')
		{
			if (map[di.y][di.x] == 'P')
			{
				c += 1;
			}
			di.x++;
		}
		di.y++;
	}
	return (c);
}

/* ########### Check P & E & C Is Valid########### */
int	ft_valid(void)
{
	int	y;
	int	x;

	y = 0;
	while (mx.map[y])
	{
		x = 0;
		while (mx.map[y][x])
		{
			if (mx.map[y][x] == 'P' || \
			mx.map[y][x] == 'E' || mx.map[y][x] == 'C')
			{
				if ((mx.map[y][x + 1] == '1' && mx.map[y][x - 1] == '1') \
				&& (mx.map[y + 1][x] == '1' && mx.map[y - 1][x] == '1'))
				{
					return (1);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

/* ############ Check C & P & E ############ */
void	check_cpe(void)
{
	if (count_p(mx.map) != 1)
	{
		ft_putstr("Error Player");
		exit(0);
	}
	if (ft_valid() == 1)
	{
		exit(0);
	}
	if (count_e(mx.map) != 1)
	{
		ft_putstr("Error Door");
		exit(0);
	}
}
