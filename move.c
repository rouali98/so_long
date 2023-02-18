/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:14:39 by rouali            #+#    #+#             */
/*   Updated: 2023/02/18 17:11:45 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

/* ############### Move Right ############### */
void	m_right(void)
{
	di.y = 0;
	while (mx.map[di.y] != '\0')
	{
		di.x = 0;
		while (mx.map[di.y][di.x])
		{
			if (mx.map[di.y][di.x] == 'P')
			{
				if (mx.key == 2 || mx.key == 124)
				{
					if (mx.map[di.y][di.x + 1] == 'C' \
					|| mx.map[di.y][di.x + 1] == '0')
					{
						mx.map[di.y][di.x] = '0';
						mx.map[di.y][di.x + 1] = 'P';
						break ;
					}
					if (mx.map[di.y][di.x + 1] == 'E' && count_c(mx.map) == 0)
						ft_exitlr();
				}
			}
			di.x++;
		}
		di.y++;
	}
}

/* ############### Move Left ############### */
void	m_left(void)
{
	di.y = 0;
	while (mx.map[di.y] != '\0')
	{
		di.x = 0;
		while (mx.map[di.y][di.x])
		{
			if (mx.map[di.y][di.x] == 'P')
			{
				if (mx.key == 0 || mx.key == 123)
				{
					if (mx.map[di.y][di.x - 1] == 'C' \
					|| mx.map[di.y][di.x - 1] == '0')
					{
						mx.map[di.y][di.x] = '0';
						mx.map[di.y][di.x - 1] = 'P';
						break ;
					}
					if (mx.map[di.y][di.x - 1] == 'E' && count_c(mx.map) == 0)
						ft_exitlr();
				}
			}
			di.x++;
		}
		di.y++;
	}
}

/* ############### Move Up ############### */
void	m_up(void)
{
	di.y = 0;
	while (mx.map[di.y] != '\0')
	{
		di.x = 0;
		while (mx.map[di.y][di.x])
		{
			if (mx.map[di.y][di.x] == 'P')
			{
				if (mx.key == 13 || mx.key == 126)
				{
					if (mx.map[di.y - 1][di.x] == 'C' \
					|| mx.map[di.y - 1][di.x] == '0')
					{
						mx.map[di.y][di.x] = '0';
						mx.map[di.y - 1][di.x] = 'P';
						break ;
					}
					if (mx.map[di.y - 1][di.x] == 'E' && count_c(mx.map) == 0)
						ft_exitud();
				}
			}
			di.x++;
		}
		di.y++;
	}
}

/* ############### Move Down ############### */
void	m_down(void)
{
	di.y = 0;
	while (mx.map[di.y] != '\0')
	{
		di.x = 0;
		while (mx.map[di.y][di.x])
		{
			if (mx.map[di.y][di.x] == 'P')
			{
				if (mx.key == 1 || mx.key == 125)
				{
					if (mx.map[di.y + 1][di.x] == 'C' \
					|| mx.map[di.y + 1][di.x] == '0')
					{
						mx.map[di.y][di.x] = '0';
						mx.map[di.y + 1][di.x] = 'P';
						return ;
					}
					if (mx.map[di.y + 1][di.x] == 'E' && count_c(mx.map) == 0)
						ft_exitud();
				}
			}
			di.x++;
		}
		di.y++;
	}
}

/* ############### Move Colectebels ############### */
void	move_p(void)
{
	di.y = 0;
	di.x = 0;
	while (mx.map[di.y] != '\0')
	{
		di.x = 0;
		while (mx.map[di.y][di.x])
		{
			if (mx.map[di.y][di.x] == 'P')
			{
				m_right();
				m_left();
				m_up();
				m_down();
				return ;
			}
			di.x++;
		}
		di.y++;
	}
}
