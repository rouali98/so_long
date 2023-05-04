/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:14:39 by rouali            #+#    #+#             */
/*   Updated: 2023/05/01 16:10:48 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ############### Move Right ############### */
void	m_right(char **map, int y, int x)
{
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				if (mx.key == 2 || mx.key == 124)
				{
					if (map[y][x + 1] == 'C' || map[y][x + 1] == '0')
					{
						count_moves(map, y, x);
						map[y][x] = '0';
						map[y][x + 1] = 'P';
						break ;
					}
					if (map[y][x + 1] == 'E' && count_c(map) == 0)
						ft_exitlr();
				}
			}
			x++;
		}
		y++;
	}
}

/* ############### Move Left ############### */
void	m_left(char **map, int y, int x)
{
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				if (mx.key == 0 || mx.key == 123)
				{
					if (map[y][x - 1] == 'C' || map[y][x - 1] == '0')
					{
						count_moves(map, y, x);
						map[y][x] = '0';
						map[y][x - 1] = 'P';
						break ;
					}
					if (map[y][x - 1] == 'E' && count_c(map) == 0)
						ft_exitlr();
				}
			}
			x++;
		}
		y++;
	}
}

/* ############### Move Up ############### */
void	m_up(char **map, int y, int x)
{
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				if (mx.key == 13 || mx.key == 126)
				{
					if (map[y - 1][x] == 'C' || map[y - 1][x] == '0')
					{
						count_moves(map, y, x);
						map[y][x] = '0';
						map[y - 1][x] = 'P';
						break ;
					}
					if (map[y - 1][x] == 'E' && count_c(map) == 0)
						ft_exitud();
				}
			}
			x++;
		}
		y++;
	}
}

/* ############### Move Down ############### */
void	m_down(char **map, int y, int x)
{
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				if (mx.key == 1 || mx.key == 125)
				{
					if (map[y + 1][x] == 'C' || map[y + 1][x] == '0')
					{
						count_moves(map, y, x);
						map[y][x] = '0';
						map[y + 1][x] = 'P';
						return ;
					}
					if (map[y + 1][x] == 'E' && count_c(map) == 0)
						ft_exitud();
				}
			}
			x++;
		}
		y++;
	}
}

/* ############### Move Colectebels ############### */
void	move_p(void)
{
	di.y = 0;
	while (mx.map[di.y] != '\0')
	{
		di.x = 0;
		while (mx.map[di.y][di.x])
		{
			if (mx.map[di.y][di.x] == 'P')
			{
				m_right(mx.map, di.y, di.x);
				m_left(mx.map, di.y, di.x);
				m_up(mx.map, di.y, di.x);
				m_down(mx.map, di.y, di.x);
				return ;
			}
			di.x++;
		}
		di.y++;
	}
}
