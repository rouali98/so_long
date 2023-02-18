/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:51:26 by rouali            #+#    #+#             */
/*   Updated: 2023/02/18 21:28:41 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

/* ############# Count Line ###################### */
int	f_strlen(char **map)
{
	int	y;

	y = 0;
	while (map[y] != '\0')
	{
		y++;
	}
	return (y);
}

/* ############# Print str ###################### */
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

//char	**ft_checkdoor(char **map)
//{
//	int	y;
//	int	x;

//	di.y = 0;
//	while (map[y])
//	{
//		x = 0;
//		while (map[y][x])
//		{
//			if (map[y][x] == 'E')
//			{
//				if (map[y + 1][x] == '0' && map[y + 1][x] == '1')
//					map[y + 1][x] = 'E';
//				if (map[y][x + 1] == '0' && map[y][x + 1] == '1')
//					map[y][x + 1] = 'E';
//				if (map[y - 1][x] == '0' && map[y - 1][x] == '1')
//					map[y - 1][x] = 'E';
//				if (map[y][x - 1] == '0' && map[y][x - 1] == '1')
//					map[y][x - 1] = 'E';
//			}
//			x++;
//		}
//		y++;
//	}
//	return (map);
//}

//void	valid_checkdoor(void)
//{
//	di.y = 0;
//	while (ft_checkdoor(mx.map)[di.y])
//	{
//		di.x = 0;
//		while (ft_checkdoor(mx.map)[di.y][di.x])
//		{
//			if (ft_checkdoor(mx.map)[di.y][di.x] == 0)
//			{
//				ft_putstr("Eroor Door C");
//				exit(0);
//			}
//			di.x++;
//		}
//		di.y++;
//	}
//}
