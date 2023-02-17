/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:56:00 by rouali            #+#    #+#             */
/*   Updated: 2023/02/11 17:56:01 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

//############# Check Center Line ######################//
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

//############# Put Images ######################//
void	put_img(char **map, void *mlx, void *win)
{
	int	y;
	int	x;
	int	h;
	int	w;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/1.xpm", &h, &w), x * 50, y * 50);
			if (map[y][x] == 'P')
			{
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/0.xpm", &h, &w), x * 50, y * 50);
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/p.xpm", &h, &w), x * 50, y * 50);
			}
			if (map[y][x] == '0')
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/0.xpm", &h, &w), x * 50, y * 50);
			if (map[y][x] == 'C')
			{
					mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/0.xpm", &h, &w), x * 50, y * 50);
					mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/c.xpm", &h, &w), x * 50, y * 50);
			}
			if (map[y][x] == 'E')
			{
				if (count_c(map))
				{
					mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/0.xpm", &h, &w), x * 50, y * 50);
					mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/E_close.xpm", &h, &w), x * 50, y * 50);
				}
				else
				{
					mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/0.xpm", &h, &w), x * 50, y * 50);
					mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/E_open.xpm", &h, &w), x * 50, y * 50);
				}
			}
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
}
