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

//############### Mlx ###############//
struct s_mlx
{
	char	**st;
	int		key;
	void	*ml;
	void	*wi;

	char	**map;
	void	*mlx;
	void	*win;
}r_mlx;

//############### Display Windows ###############//
struct s_display_win
{
	int		w;
	int		h;
}wind;

//############### Move Up ###############//
void	ft_move_up(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (r_mlx.st[i] != '\0')
	{
		j = 0;
		while (r_mlx.st[i][j])
		{
			if (r_mlx.st[i][j] == 'P')
			{
				if (r_mlx.key == 13 || r_mlx.key == 126)
				{
					if (r_mlx.st[i - 1][j] != '1')
					{
						r_mlx.st[i][j] = '0';
						r_mlx.st[i - 1][j] = 'P';
						break ;
					}
				}
			}
		}
	}
}

//############### Move Colectebels ###############//
void	move_p(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (r_mlx.st[i] != '\0')
	{
		j = 0;
		while (r_mlx.st[i][j])
		{
			if (r_mlx.st[i][j] == 'P')
			{
				if (r_mlx.key == 2 || r_mlx.key == 124)
				{
					if (r_mlx.st[i][j + 1] != '1' && r_mlx.st[i][j + 1] != 'E' )
					{
						r_mlx.st[i][j] = '0';
						r_mlx.st[i][j + 1] = 'P';
						break ;
					}
				}
				if (r_mlx.key == 0 || r_mlx.key == 123)
				{
					if (r_mlx.st[i][j - 1] != '1' && r_mlx.st[i][j - 1] != 'E')
					{
						r_mlx.st[i][j] = '0';
						r_mlx.st[i][j - 1] = 'P';
						break ;
					}
				}
				if (r_mlx.key == 13 || r_mlx.key == 126)
				{
					if (r_mlx.st[i - 1][j] != '1' && r_mlx.st[i -1][j] != 'E')
					{
						r_mlx.st[i][j] = '0';
						r_mlx.st[i - 1][j] = 'P';
						break ;
					}
				}
				if (r_mlx.key == 1 || r_mlx.key == 125)
				{
					if (r_mlx.st[i + 1][j] != '1' && r_mlx.st[i + 1][j] != 'E')
					{
						r_mlx.st[i][j] = '0';
						r_mlx.st[i + 1][j] = 'P';
					}
					return ;
				}
			}
			j++;
		}
		i++;
	}
}

//############### Key_hook ###############//
int	key_hook(int keycode)
{
	r_mlx.key = keycode;
	printf("press to : %d\n", keycode);
	move_p();
	put_img(r_mlx.st, r_mlx.ml, r_mlx.wi);
	return (0);
}

//############### Count Char ###############//
int	ft_count(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[0][j] != '\0')
	{
		j++;
	}
	return (j);
}

//############# Check Path ######################//
char	**ft_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				if (map[i][j + 1] == '0' || map[i][j + 1] == 'C')
					map[i][j + 1] = 'P';
				if (map[i][j - 1] == '0' || map[i][j - 1] == 'C')
					map[i][j - 1] = 'P';
				if (map[i + 1][j] == '0' || map[i + 1][j] == 'C')
					map[i + 1][j] = 'P';
				if (map[i - 1][j] == '0' || map[i - 1][j] == 'C')
					map[i - 1][j] = 'P';
			}
			j++;
		}
		i++;
	}
	return (map);
}

//############### Count Char ###############//
void	sc(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

//############### Count Char ###############//
int	main(int argc, char **argv)
{
	r_mlx.map = ft_rline(argv[1]);
	wind.h = f_strlen(r_mlx.map);
	wind.w = ft_count(r_mlx.map);
	r_mlx.mlx = mlx_init();
	r_mlx.win = mlx_new_window(r_mlx.mlx, wind.w * \
	50, wind.h * 50, "Hello world!");
	if (argc != 2)
	{
		printf("Error");
		return (0);
	}
	r_mlx.st = r_mlx.map;
	if (line_up(r_mlx.map) == 1 || \
	line_down(r_mlx.map) == 1 || center_wall(r_mlx.map) == 1)
	{
		printf("error in map");
		return (0);
	}
	r_mlx.ml = r_mlx.mlx;
	r_mlx.wi = r_mlx.win;
	sc(ft_path(r_mlx.map));
	mlx_key_hook(r_mlx.win, key_hook, move_p);
	put_img(r_mlx.st, r_mlx.ml, r_mlx.wi);
	return (0);
}
