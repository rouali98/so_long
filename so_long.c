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

char	**g_st;
int		g_key;
void	*g_ml;
void	*g_wi;

void	ft_move_up(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_st[i] != '\0')
	{
		j = 0;
		while (g_st[i][j])
		{
			if (g_st[i][j] == 'P')
			{
				if (g_key == 13 || g_key == 126)
				{
					if (g_st[i - 1][j] != '1')
					{
						g_st[i][j] = '0';
						g_st[i - 1][j] = 'P';
						break ;
					}
				}
			}
		}
	}
}

void	ft_move_p(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_st[i] != '\0')
	{
		j = 0;
		while (g_st[i][j])
		{
			if (g_st[i][j] == 'P')
			{
				if (g_key == 2 || g_key == 124)
				{
					if (g_st[i][j + 1] != '1' && g_st[i][j + 1] != 'E' )
					{
						g_st[i][j] = '0';
						g_st[i][j + 1] = 'P';
						break ;
					}
				}
				if (g_key == 0 || g_key == 123)
				{
					if (g_st[i][j - 1] != '1' && g_st[i][j - 1] != 'E')
					{
						g_st[i][j] = '0';
						g_st[i][j - 1] = 'P';
						break ;
					}
				}
				if (g_key == 13 || g_key == 126)
				{
					if (g_st[i - 1][j] != '1' && g_st[i -1][j] != 'E')
					{
						g_st[i][j] = '0';
						g_st[i - 1][j] = 'P';
						break ;
					}
				}
				if (g_key == 1 || g_key == 125)
				{
					if (g_st[i + 1][j] != '1' && g_st[i + 1][j] != 'E')
					{
						g_st[i][j] = '0';
						g_st[i + 1][j] = 'P';
					}
					return ;
				}
			}
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode)
{
	g_key = keycode;
	printf("press to : %d\n", keycode);
	ft_move_p();
	ft_mlx(g_st, g_ml, g_wi);
	return (0);
}

int	ft_count(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i][j] != '\0')
		{
			j++;
		}
		i++;
	}
	return (i);
}

//	//###################################//
//int	ft_coin(char **str)
//{
//	int	i;
//	int	j;
//	int	st;

//	i = 0;
//	j = 0;
//	while (str[i])
//	{
//		while (str[i][j])
//		{
//			if (str[i][j] == 'C')
//			{
//				printf("kayna");
//				return (0);
//			}
//			j++;
//		}
//		i++;
//	}
//	return (0);
//}
//	//###################################//

//int	ft_path(char **str)
//{
//	int	i;
//	int	j;
//	int	c;
//	int	e;
//	char *ss;

//	i = 0;
//	j = 0;
//	while (str[i] != '\0')
//	{
//		while (str[i][j] == 'P')
//		{
//			if (str[i][j + 1] == '0')
//			{
//				str[i][j] = 'P';
//				str[i][j + 1] = '1';
//				j++;
//			}
//			if (str[i][j] == 'C')
//			{
//				str[i][j] = 'C';
//				str[i][j + 1] = '1';
//				c++;
//				return (c);
//			}
//			if (str[i][j] == 'E')
//			{
//				str[i][j] = 'E';
//				str[i][j + 1] = '1';
//				e++;
//				return (e);
//			}
//			if (str[i][j] == '1')
//			{
//				break ;
//			}
//		}
//		i++;
//	}
//	return (44);
//}

//void ft_co(char **str)
//{
//	int	i;
//	int j;
//	char *e;
//	char *c;

//	i = 0;
//	j = 0;
//	while (str[i])
//	{
//		while (str[i][j])
//		{
//			if (str[i][j] == '1')
//				i++;
//			if (str[i][j] == '0')
//			{
//				str[i][j] = 1;
//				i++;
//			}
//			if (str[i][j] == 'E')
//			{
//				e[i] = str[i][j];
//				str[i][j] = 1;
//				i++;
//			}
//			if (str[i][j] == 'C')
//			{
//				c[i] = str[i][j];
//				str[i][j] = 1;
//				i++;
//			}
//			j++;
//		}
//		i++;
//	}
//	printf("%s", e);
//	printf("%s", c);
//}

int	main(int argc, char **argv)
{
	char	**str;
	void	*mlx;
	void	*win;
	int		w;
	int		h;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1700, 350, "Hello world!");
	if (argc != 2)
	{
		printf("Error");
		return (0);
	}
	str = ft_rline(argv[1]);
	g_st = str;
	if (ft_cheklwel(str) == 1 || ft_cheklkher(str) == 1 || ft_wall(str) == 1)
	{
		printf("error in map");
		return (0);
	}
	g_ml = mlx;
	g_wi = win;
	//ft_co(str);
	mlx_key_hook(win, key_hook, ft_move_p);
	ft_mlx(g_st, g_ml, g_wi);
	return (0);
}
