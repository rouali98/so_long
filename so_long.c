/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:56:15 by rouali            #+#    #+#             */
/*   Updated: 2023/02/21 16:07:08 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ############### Key_hook ############### */
int	key_hook(int keycode)
{
	mx.key = keycode;
	if (mx.key == 53)
	{
		ft_putstr("You Close with ESC");
		exit(0);
	}
	move_p();
	put_img(mx.map, mx.mlx, mx.win);
	return (0);
}

/* ############# Check Path ###################### */
char	**ft_path(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
					map[y + 1][x] = 'P';
				if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
					map[y][x + 1] = 'P';
				if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
					map[y - 1][x] = 'P';
				if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
					map[y][x - 1] = 'P';
			}
			x++;
		}
		y++;
	}
	return (map);
}

/* ############### Count Char ############### */
void	sc(void)
{
	int	c;

	c = 0;
	while (ft_path(mx.map)[c])
		c++;
}

/* ############### main ############### */
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Error");
		return (0);
	}
	mx.map = ft_rline(argv[1]);
	count_cpe();
	ds.w = ft_count(mx.map) * 50;
	ds.h = f_strlen(mx.map) * 50;
	mx.mlx = mlx_init();
	mx.win = mlx_new_window(mx.mlx, ds.w, ds.h, "Game");
	check_lines();
	check_c();
	check_e();
	sc();
	mx.map = ft_rline(argv[1]);
	mlx_key_hook(mx.win, key_hook, move_p);
	mlx_hook(mx.win, 17, 0, ft_close, move_p);
	mlx_mouse_hook(mx.win, key_hook, NULL);
	put_img(mx.map, mx.mlx, mx.win);
	mlx_loop(mx.mlx);
	return (0);
}
