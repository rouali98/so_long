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

int	ft_wall(char **str)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	j = f_strlen(str) - 1;
	r = ft_strlen(str[i]);
	while (str[j] != '\0')
	{
		i = 0;
		if (j >= 1)
		{
			while (str[j][i] != '\0')
			{
				if (str[j][0] != '1' || str[j][r - 1] != '1')
				{
					return (1);
				}
				i++;
			}
		}
		j--;
	}
	return (0);
}


void	ft_mlx(char **map)
{
	int		withe;
	int		hight;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		a = 0;
	int		i = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1700, 350, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, "img/zellige-maroc.xpm", &withe, &hight);
	while (map[a])
	{
		i = 0;
		while (map[a][i])
		{
			if (map[a][i] == '1')
			{
				mlx_put_image_to_window(mlx, mlx_win, img, i * 50, a * 50);
			}
			i++;
		}
		a++;
	}
	mlx_loop(mlx);
}
