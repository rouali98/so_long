/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:51:26 by rouali            #+#    #+#             */
/*   Updated: 2023/02/21 15:55:57 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

/* ############### Count Move ############### */
void	count_moves(char **map, int y, int x)
{
	if (map[y][x + 1] == 'C' || map[y][x + 1] == '0')
	{
		printf("Move -> %d\n", di.i++);
		return ;
	}
	if (map[y][x - 1] == 'C' || map[y][x - 1] == '0')
	{
		printf("Move -> %d\n", di.i++);
		return ;
	}
	if (map[y - 1][x] == 'C' || map[y - 1][x] == '0')
	{
		printf("Move -> %d\n", di.i++);
		return ;
	}
	if (map[y + 1][x] == 'C' || map[y + 1][x] == '0')
	{
		printf("Move -> %d\n", di.i++);
		return ;
	}
}
