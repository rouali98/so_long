/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:56:00 by rouali            #+#    #+#             */
/*   Updated: 2023/02/18 17:56:15 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ############# Put Images E & 0 ###################### */
void	puteo(char **map, void *mlx, void *win)
{
	if (count_c(map))
	{
		mlx_put_image_to_window(mlx, win, img.i0, di.x * 50, di.y * 50);
		mlx_put_image_to_window(mlx, win, img.ec, di.x * 50, di.y * 50);
	}
	else
	{
		mlx_put_image_to_window(mlx, win, img.i0, di.x * 50, di.y * 50);
		mlx_put_image_to_window(mlx, win, img.eo, di.x * 50, di.y * 50);
	}
}

/* ############# Put Images C ###################### */
void	put_c(void *mlx, void *win)
{
	mlx_put_image_to_window(mlx, win, img.i0, di.x * 50, di.y * 50);
	mlx_put_image_to_window(mlx, win, img.c, di.x * 50, di.y * 50);
}

/* ############# Put Images P ###################### */
void	put_p(void *mlx, void *win)
{
	if ((mx.key == 2 || mx.key == 124) || (mx.key == 1 || mx.key == 125) \
	|| (mx.key == 13 || mx.key == 126))
	{
		mlx_put_image_to_window(mlx, win, img.i0, di.x * 50, di.y * 50);
		mlx_put_image_to_window(mlx, win, img.pl, di.x * 50, di.y * 50);
	}
	if ((mx.key == 0 || mx.key == 123) || (mx.key == 1 || mx.key == 125) \
	|| (mx.key == 13 || mx.key == 126))
	{
		mlx_put_image_to_window(mlx, win, img.i0, di.x * 50, di.y * 50);
		mlx_put_image_to_window(mlx, win, img.pr, di.x * 50, di.y * 50);
	}
}

/* ############# Put Images 1 ###################### */
void	put_1(void *mlx, void *win)
{
	mlx_put_image_to_window(mlx, win, img.i1, di.x * 50, di.y * 50);
}

/* ############# Put Images 0 ###################### */
void	put_0(void *mlx, void *win)
{
	mlx_put_image_to_window(mlx, win, img.i0, di.x * 50, di.y * 50);
}
