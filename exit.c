/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:59:47 by rouali            #+#    #+#             */
/*   Updated: 2023/02/18 17:02:00 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

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
					exit(0);
				}
				if (mx.map[di.y + 1][di.x] == 'E' && count_c(mx.map) == 0)
				{
					ft_putstr("You Win");
					exit(0);
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
					exit(0);
				}
				if (mx.map[di.y][di.x - 1] == 'E' && count_c(mx.map) == 0)
				{
					ft_putstr("You Win");
					exit(0);
				}
			}
			di.x++;
		}
		di.y++;
	}
}
