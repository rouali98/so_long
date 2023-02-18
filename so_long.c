/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:56:15 by rouali            #+#    #+#             */
/*   Updated: 2023/02/18 21:43:02 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

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

/* ############# Check Path S01 ###################### */
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

int	ft_testksh(int i, int b, char **s)
{
	if (s[i][b] == 'E' || s[i][b] == 'C')
	{
		if (ft_path(mx.map)[i + 1][b] == 'P' || \
		ft_path(mx.map)[i - 1][b] == 'P' || ft_path(mx.map)[i][b + 1] \
		== 'P' || ft_path(mx.map)[i][b - 1] == 'P')
		{
			return (0);
		}
	}
	return (1);
}

/* ############# Check map error ###################### */
void	check_mapi(void)
{
	di.y = 0;
	while (ft_path(mx.map)[di.y])
	{
		di.x = 0;
		while (ft_path(mx.map)[di.y][di.x])
		{

			if (ft_path(mx.map)[di.y][di.x] == '0')
			{
				if ((ft_path(mx.map)[di.y + 1][di.x] == 'E' || ft_path(mx.map)[di.y + 1][di.x] == 'C') && ft_testksh(di.y + 1, di.x, ft_path(mx.map)))
					exit(0);
				else if ((ft_path(mx.map)[di.y][di.x + 1] == 'E' || ft_path(mx.map)[di.y][di.x + 1] == 'C') && ft_testksh(di.y, di.x + 1, ft_path(mx.map)))
					exit(0);
				else if ((ft_path(mx.map)[di.y - 1][di.x] == 'E' || ft_path(mx.map)[di.y - 1][di.x] == 'C') &&  ft_testksh(di.y - 1, di.x, ft_path(mx.map)))
					exit(0);
				else if ((ft_path(mx.map)[di.y][di.x - 1] == 'E' || ft_path(mx.map)[di.y][di.x - 1] == 'C') && ft_testksh(di.y, di.x - 1, ft_path(mx.map)))
					exit(0);
			}
			di.x++;
		}
		di.y++;
	}
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
	check_cpe();
	ds.w = ft_count(mx.map) * 50;
	ds.h = f_strlen(mx.map) * 50;
	mx.mlx = mlx_init();
	mx.win = mlx_new_window(mx.mlx, ds.w, ds.h, "Game");
	if (line_up(mx.map) == 1 || \
	line_down(mx.map) == 1 || center_wall(mx.map) == 1)
	{
		ft_putstr("Error Map");
		return (0);
	}
	check_mapi();
	sc();
	mx.map = ft_rline(argv[1]);
	mlx_key_hook(mx.win, key_hook, move_p);
	mlx_hook(mx.win, 17, 0, ft_close, move_p);
	put_img(mx.map, mx.mlx, mx.win);
	mlx_loop(mx.mlx);
	return (0);
}
