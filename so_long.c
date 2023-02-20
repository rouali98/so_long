/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:56:15 by rouali            #+#    #+#             */
/*   Updated: 2023/02/20 20:47:19 by rouali           ###   ########.fr       */
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

//void	mo_p(void)
//{
//	int	c;

//	if (ft_path(mx.map)[di.y][di.x] == 'P')
//	{
//		printf("Number of pawn movements: %d\n", c);
//		c++;
//	}
//}

//int	ft_arg(char *argv)
//{
//	char *ber = ".ber";
//	char *s;
//	int i;
//	i = 0;
//	while(argv != '\0')
//	{
//		if (argv[i] == ".")
//		{
//			s = argv[i];
//			i++;
//		}
//		i++;
//	}
//	if(ber == s)
//		return (1);
//	else
//		return (0);
//}

/* ############### main ############### */
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Error");
		return (0);
	}
	//if (ft_arg(argv[1]) == 1)
	//	exit(1);
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
	if (ft_arg(argv[1]) == 1)
	{
		exit(1);
	}

	mx.map = ft_rline(argv[1]);
	mlx_key_hook(mx.win, key_hook, move_p);
	mlx_hook(mx.win, 17, 0, ft_close, move_p);
	mlx_mouse_hook(mx.win, key_hook, NULL);
	put_img(mx.map, mx.mlx, mx.win);
	mlx_loop(mx.mlx);
	return (0);
}
