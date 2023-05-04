/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:56:15 by rouali            #+#    #+#             */
/*   Updated: 2023/05/03 14:57:44 by rouali           ###   ########.fr       */
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
		exit(1);
	}
	move_p();
	put_img(mx.map, mx.mlx, mx.win);
	return (0);
}

/* ############# Count Line ###################### */
int	f_strlen(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
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

/* ############### check if .ber ############### */
int	check_ber(char *argv)
{
	int	c;

	c = 0;
	while (argv[c])
		c++;
	if (argv[c - 1] != 'r' \
	&& argv[c - 2] != 'e' \
	&& argv[c - 3] != 'b' \
	&& argv[c - 4] != '.')
		return (1);
	else
		return (0);
}

/* ############### main ############### */
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Error\narg");
		return (0);
	}
	mx.map = ft_rline(argv[1]);
	check_lines();
	print_error();
	check_c();
	check_e();
	if (check_ber(argv[1]) == 1)
		ft_print_error();
	freed(mx.map);
	mx.map = ft_rline(argv[1]);
	ds.w = ft_count(mx.map) * 50;
	ds.h = f_strlen(mx.map) * 50;
	mx.mlx = mlx_init();
	if (ds.w > 2550 || ds.h > 1400)
		exit(1);
	mx.win = mlx_new_window(mx.mlx, ds.w, ds.h, "Game of LEET");
	mlx_key_hook(mx.win, key_hook, move_p);
	mlx_hook(mx.win, 17, 0, ft_close, move_p);
	put_img(mx.map, mx.mlx, mx.win);
	mlx_loop(mx.mlx);
	return (0);
}
