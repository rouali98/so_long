/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:54:05 by rouali            #+#    #+#             */
/*   Updated: 2023/02/18 09:55:27 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

/* ############### Key_hook ############### */
int	ft_close(void)
{
	ft_putstr("You Close with X");
	exit(0);
}

/* ############### Count Char ############### */
int	ft_count(char **str)
{
	int	x;

	x = 0;
	while (str[0][x] != '\0')
	{
		x++;
	}
	return (x);
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
			{
				c += 1;
			}
			x++;
		}
		y++;
	}
	return (c);
}
