/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:59:47 by rouali            #+#    #+#             */
/*   Updated: 2023/02/24 17:21:51 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ############### Free ############### */
void	freed(char **map)
{
	int	c;

	c = 0;
	while (ft_path(map)[c])
	{
		free(map[c]);
		c++;
	}
}

/* ########### Exit Up && Down ############# */
void	ft_exitud(void)
{
	di.y = 0;
	while (mx.map[di.y] != '\0')
	{
		di.x = 0;
		while (mx.map[di.y][di.x])
		{
			if (mx.map[di.y][di.x] == 'P')
			{
				if (mx.map[di.y - 1][di.x] == 'E' && count_c(mx.map) == 0)
				{
					ft_putstr("You Win");
					exit(1);
				}
				if (mx.map[di.y + 1][di.x] == 'E' && count_c(mx.map) == 0)
				{
					ft_putstr("You Win");
					exit(1);
				}
			}
			di.x++;
		}
		di.y++;
	}
}

/* ########### Exit Left && Right ############# */
void	ft_exitlr(void)
{
	di.y = 0;
	while (mx.map[di.y] != '\0')
	{
		di.x = 0;
		while (mx.map[di.y][di.x])
		{
			if (mx.map[di.y][di.x] == 'P')
			{
				if (mx.map[di.y][di.x + 1] == 'E' && count_c(mx.map) == 0)
				{
					ft_putstr("You Win");
					exit(1);
				}
				if (mx.map[di.y][di.x - 1] == 'E' && count_c(mx.map) == 0)
				{
					ft_putstr("You Win");
					exit(1);
				}
			}
			di.x++;
		}
		di.y++;
	}
}
