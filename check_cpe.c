/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cpe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:36:46 by rouali            #+#    #+#             */
/*   Updated: 2023/05/03 15:36:41 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(void)
{
	ft_putstr("You Close with X\n");
	exit(1);
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
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/* ############ print_error ############ */
void	print_error(void)
{
	if (count_p(mx.map) != 1)
		ft_print_error();
	if (ft_valid() == 1)
		ft_print_error();
	if (count_e(mx.map) != 1)
		ft_print_error();
	if (count_c(mx.map) < 1)
		exit(1);
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
			if (ft_path(mx.map)[di.y][di.x] == '0' \
			|| ft_path(mx.map)[di.y][di.x] == 'C')
			{
				if (ft_path(mx.map)[di.y + 1][di.x] == 'C')
					ft_print_error();
				else if (ft_path(mx.map)[di.y][di.x + 1] == 'C')
					ft_print_error();
				else if (ft_path(mx.map)[di.y - 1][di.x] == 'C')
					ft_print_error();
				else if (ft_path(mx.map)[di.y][di.x - 1] == 'C')
					ft_print_error();
				else if (ft_path(mx.map)[di.y][di.x] == 'C')
					ft_print_error();
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
			if (ft_path(mx.map)[di.y][di.x] == 'E' \
			|| ft_path(mx.map)[di.y][di.x] == 'C')
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
					ft_print_error();
			}
			di.x++;
		}
		di.y++;
	}
}
