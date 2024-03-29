/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:55:32 by rouali            #+#    #+#             */
/*   Updated: 2023/04/30 19:23:45 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ############# Variables Images ###################### */
void	var(void *mlx)
{
	img.i1 = mlx_xpm_file_to_image(mlx, "img/1.xpm", &ds.h, &ds.w);
	img.i0 = mlx_xpm_file_to_image(mlx, "img/0.xpm", &ds.h, &ds.w);
	img.c = mlx_xpm_file_to_image(mlx, "img/c.xpm", &ds.h, &ds.w);
	img.ec = mlx_xpm_file_to_image(mlx, "img/E_close.xpm", &ds.h, &ds.w);
	img.eo = mlx_xpm_file_to_image(mlx, "img/E_open.xpm", &ds.h, &ds.w);
	img.pl = mlx_xpm_file_to_image(mlx, "img/p>.xpm", &ds.h, &ds.w);
	img.pr = mlx_xpm_file_to_image(mlx, "img/p<.xpm", &ds.h, &ds.w);
	if (img.i1 == NULL || img.i0 == NULL || img.c == NULL || \
	img.ec == NULL || img.eo == NULL || img.pl == NULL || img.pr == NULL)
		ft_print_error();
}

/* ############# Put Images ###################### */
void	put_img(char **map, void *mlx, void *win)
{
	var(mlx);
	di.y = 0;
	while (map[di.y])
	{
		di.x = 0;
		while (map[di.y][di.x])
		{
			if (map[di.y][di.x] != '1' && map[di.y][di.x] != '0' && \
			map[di.y][di.x] != 'C' && map[di.y][di.x] != 'P' \
			&& map[di.y][di.x] != 'E')
				ft_print_error();
			if (map[di.y][di.x] == '1')
				put_1(mlx, win);
			if (map[di.y][di.x] == 'P')
				put_p(mlx, win);
			if (map[di.y][di.x] == '0')
				put_0(mlx, win);
			if (map[di.y][di.x] == 'C')
				put_c(mlx, win);
			if (map[di.y][di.x] == 'E')
				puteco(map, mlx, win);
			di.x++;
		}
		di.y++;
	}
}
