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

/* ############### Key_hook ############### */
int	ft_close(void)
{
	ft_putstr("You Close with X");
	exit(0);
}

/* ########### Check P & E & C Is Valid ########### */
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

/* ############ Count C & P & E ############ */
void	count_cpe(void)
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

/* ############# Check C ###################### */
void	check_c(void)
{
	di.y = 0;
	while (ft_path(mx.map)[di.y])
	{
		di.x = 0;
		while (ft_path(mx.map)[di.y][di.x])
		{
			if (ft_path(mx.map)[di.y][di.x] == '0')
			{
				if (ft_path(mx.map)[di.y + 1][di.x] == 'C')
					exit(1);
				else if (ft_path(mx.map)[di.y][di.x + 1] == 'C')
					exit(1);
				else if (ft_path(mx.map)[di.y - 1][di.x] == 'C')
					exit(1);
				else if (ft_path(mx.map)[di.y][di.x - 1] == 'C')
					exit(1);
			}
			di.x++;
		}
		di.y++;
	}
}

/* ############# Check E ###################### */
void	check_e(void)
{
	di.y = 0;
	while (ft_path(mx.map)[di.y])
	{
		di.x = 0;
		while (ft_path(mx.map)[di.y][di.x])
		{
			if (ft_path(mx.map)[di.y][di.x] == 'E')
			{
				if (ft_path(mx.map)[di.y + 1][di.x] == 'P')
					return ;
				else if (ft_path(mx.map)[di.y - 1][di.x] == 'P')
					return ;
				else if (ft_path(mx.map)[di.y][di.x + 1] == 'P')
					return ;
				else if (ft_path(mx.map)[di.y][di.x - 1] == 'P')
					return ;
				else
					exit(1);
			}
			di.x++;
		}
		di.y++;
	}
}
