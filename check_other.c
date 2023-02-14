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
	int	i;
	int	j;
	int	ii;

	i = 0;
	j = f_strlen(map) - 1;
	ii = ft_strlen(map[i]);
	while (map[j] != '\0')
	{
		i = 0;
		if (j >= 0 && ii != ft_strlen(map[j]))
			return (1);
		if (j >= 1)
		{
			while (map[j][i] != '\0')
			{
				if (map[j][0] != '1' || map[j][ii - 1] != '1')
					return (1);
				i++;
			}
		}
		j--;
	}
	return (0);
}

////############# check coin ######################//
//int	ft_coin(char **map)
//{
//	int	i;
//	int	j;
//	int	st;

//	i = 0;
//	j = 0;
//	while (map[i])
//	{
//		while (map[i][j])
//		{
//			if (map[i][j] == 'C')
//			{
//				st = map[j];
//			}
//			j++;
//		}
//		i++;
//	}
//	return (st);
//}

//############# Put Images ######################//
void	put_img(char **map, void *mlx, void *win)
{
	int	a;
	int	i;
	int	w;
	int	h;

	a = 0;
	i = 0;
	while (map[a])
	{
		i = 0;
		while (map[a][i])
		{
			if (map[a][i] == '1')
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/1.xpm", &w, &h), i * 50, a * 50);
			if (map[a][i] == 'P')
			{
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/0.xpm", &w, &h), i * 50, a * 50);
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/p.xpm", &w, &h), i * 50, a * 50);
			}
			if (map[a][i] == '0')
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/0.xpm", &w, &h), i * 50, a * 50);
			if (map[a][i] == 'C')
			{
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/0.xpm", &w, &h), i * 50, a * 50);
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/c.xpm", &w, &h), i * 50, a * 50);
			}
			if (map[a][i] == 'E')
			{
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/0.xpm", &w, &h), i * 50, a * 50);
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, "img/E_open.xpm", &w, &h), i * 50, a * 50);
			}
			i++;
		}
		a++;
	}
	mlx_loop(mlx);
}
