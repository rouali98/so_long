/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:56:15 by rouali            #+#    #+#             */
/*   Updated: 2023/02/11 17:56:17 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "mlx.h"

// ############### Mlx ###############//
struct s_mlx
{
	char	**map;
	void	*mlx;
	void	*win;
	int		key;

} r_mlx;

// ############### Display Windows ###############//
struct s_display_win
{
	int	w;
	int	h;

} wind;
// ############### Direction X & Y ###############//
struct s_direction
{
	int	x;
	int	y;

} di;

// ############### Move Colectebels ###############//
void	move_p(void)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (r_mlx.map[y] != '\0')
	{
		x = 0;
		while (r_mlx.map[y][x])
		{
			if (r_mlx.map[y][x] == 'P')
			{
				if (r_mlx.key == 2 || r_mlx.key == 124)
				{
					if (r_mlx.map[y][x + 1] == 'C' || r_mlx.map[y][x + 1] == '0')
					{
						r_mlx.map[y][x] = '0';
						r_mlx.map[y][x + 1] = 'P';
						break ;
					}
					if (r_mlx.map[y][x + 1] == 'E' && count_c(r_mlx.map) == 0)
					{
						exit(1);
					}
				}
				if (r_mlx.key == 0 || r_mlx.key == 123)
				{
					if (r_mlx.map[y][x - 1] == 'C' || r_mlx.map[y][x - 1] == '0')
					{
						r_mlx.map[y][x] = '0';
						r_mlx.map[y][x - 1] = 'P';
						break ;
					}
					if (r_mlx.map[y][x - 1] == 'E' && count_c(r_mlx.map) == 0)
					{
						exit(1);
					}
				}
				if (r_mlx.key == 13 || r_mlx.key == 126)
				{
					if (r_mlx.map[y - 1][x] == 'C' || r_mlx.map[y - 1][x] == '0')
					{
						r_mlx.map[y][x] = '0';
						r_mlx.map[y - 1][x] = 'P';
						break ;
					}
					if (r_mlx.map[y - 1][x] == 'E' && count_c(r_mlx.map) == 0)
						exit(1);
				}
				if (r_mlx.key == 1 || r_mlx.key == 125)
				{
					if (r_mlx.map[y + 1][x] == 'C' || r_mlx.map[y + 1][x] == '0')
					{
						r_mlx.map[y][x] = '0';
						r_mlx.map[y + 1][x] = 'P';
					}
					if (r_mlx.map[y + 1][x] == 'E' && count_c(r_mlx.map) == 0)
						exit(1);
					return ;
				}
			}
			x++;
		}
		y++;
	}
}

// ############### Key_hook ###############//
int key_hook(int keycode)
{
	r_mlx.key = keycode;
	printf("press to : %d\n", keycode);
	move_p();
	put_img(r_mlx.map, r_mlx.mlx, r_mlx.win);
	return (0);
}

// ############### Count Char ###############//
int ft_count(char **str)
{
	int x;

	x = 0;
	while (str[0][x] != '\0')
	{
		x++;
	}
	return (x);
}

// ############# Check Path S01 ######################//
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
				if (r_mlx.map[y][x + 1] == '1' && r_mlx.map[y][x - 1] == '1' && r_mlx.map[y - 1][x] == '1' && r_mlx.map[y + 1][x] == '1')
					exit(1);
				while (map[y + 1][x] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
				{
					map[y + 1][x] = 'P';
					y++;
				}
				while (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
				{
					map[y][x + 1] = 'P';
					x++;
				}
				while (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
				{
					map[y - 1][x] = 'P';
					y--;
				}
				while (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
				{
					map[y][x - 1] = 'P';
					x--;
				}
			}
			x++;
		}
		y++;
	}
	return (map);
}

// ############# Check E ######################//
int	check_e(char **map)
{
	int	c;

	di.y = 0;
	c = 0;
	while (map[di.y] != '\0')
	{
		di.x = 0;
		while (map[di.y][di.x] != '\0')
		{
			if (map[di.y][di.x] == 'E')
			{
				c += 1;
			}
			di.x++;
		}
		di.y++;
	}
	return (c);
}

// ############# Check P ######################//
int	check_p(char **map)
{
	int	c;

	di.y = 0;
	c = 0;
	while (map[di.y] != '\0')
	{
		di.x = 0;
		while (map[di.y][di.x] != '\0')
		{
			if (map[di.y][di.x] == 'P')
			{
				c += 1;
			}
			di.x++;
		}
		di.y++;
	}
	return (c);
}

// ############# Check map error ######################//
int	check_mapi(void)
{
	di.y = 0;
	while (ft_path(r_mlx.map)[di.y])
	{
		di.x = 0;
		while (ft_path(r_mlx.map)[di.y][di.x])
		{
			if (ft_path(r_mlx.map)[di.y][di.x] == '0')
			{
				if (ft_path(r_mlx.map)[di.y + 1][di.x] == 'E' || ft_path(r_mlx.map)[di.y + 1][di.x] == 'C')
					exit(1);
				else if (ft_path(r_mlx.map)[di.y][di.x + 1] == 'E' || ft_path(r_mlx.map)[di.y][di.x + 1] == 'C')
					exit(1);
				else if (ft_path(r_mlx.map)[di.y - 1][di.x] == 'E' || ft_path(r_mlx.map)[di.y - 1][di.x] == 'C')
					exit(1);
				else if (ft_path(r_mlx.map)[di.y][di.x - 1] == 'E' || ft_path(r_mlx.map)[di.y][di.x - 1] == 'C')
					exit(1);
			}
			di.x++;
		}
		di.y++;
	}
	return (0);
}

/* ########### Check P & E & C Is Valid########### */
int	ft_valid(void)
{
	int	y;
	int	x;

	y = 0;
	while (r_mlx.map[y])
	{
		x = 0;
		while (r_mlx.map[y][x])
		{
			if (r_mlx.map[y][x] == 'P' || \
			r_mlx.map[y][x] == 'E' || r_mlx.map[y][x] == 'C')
			{
				if ((r_mlx.map[y][x + 1] == '1' && r_mlx.map[y][x - 1] == '1') \
				&& (r_mlx.map[y + 1][x] == '1' && r_mlx.map[y - 1][x] == '1'))
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

// ############### Count Char ###############//
void	sc(void)
{
	int	c;

	c = 0;
	while (ft_path(r_mlx.map)[c])
		c++;
}

// ############### Count C ###############//
int	count_c(char **map)
{
	int	y;
	int	x;
	int	c;

	y = 0;
	c = 0;
	while (map[y] != '\0')
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
			{
				c += 1;
			}
			x++;
		}
		y++;
	}
	return (c);
}

// ############ Check C & P & E ############//
void	check_cpe(void)
{
	if (check_p(r_mlx.map) != 1)
	{
		printf("Error Player");
		exit(1);
	}
	if (ft_valid() == 1)
	{
		exit(1);
	}
	if (check_e(r_mlx.map) != 1)
	{
		printf("Error Door");
		exit(1);
	}
}

// ############### main ###############//
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error");
		return (0);
	}
	r_mlx.map = ft_rline(argv[1]);
	check_cpe();
	wind.w = ft_count(r_mlx.map) * 50;
	wind.h = f_strlen(r_mlx.map) * 50;
	r_mlx.mlx = mlx_init();
	r_mlx.win = mlx_new_window(r_mlx.mlx, wind.w, wind.h, "Hello world!");
	if (line_up(r_mlx.map) == 1 || \
	line_down(r_mlx.map) == 1 || center_wall(r_mlx.map) == 1)
	{
		printf("Error Map");
		return (0);
	}
	check_mapi();
	sc();
	r_mlx.map = ft_rline(argv[1]);
	mlx_key_hook(r_mlx.win, key_hook, move_p);
	put_img(r_mlx.map, r_mlx.mlx, r_mlx.win);
	return (0);
}
