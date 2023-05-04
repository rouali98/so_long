/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:51:26 by rouali            #+#    #+#             */
/*   Updated: 2023/05/01 16:11:36 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ############# Print str ###################### */
int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

/* ############# Put chr ###################### */
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/* ############# Put nbr ###################### */
int	ft_putnbr(int n)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
		len += ft_putchar(nb + 48);
	return (len);
}

/* ############### Print Move ############### */
void	print_move(void)
{
	ft_putstr("Move -> ");
	ft_putnbr(++di.i);
	ft_putstr("\n");
}

/* ############### Count Move ############### */
void	count_moves(char **map, int y, int x)
{
	if (map[y][x + 1] == 'C' || map[y][x + 1] == '0')
	{
		print_move();
		return ;
	}
	if (map[y][x - 1] == 'C' || map[y][x - 1] == '0')
	{
		print_move();
		return ;
	}
	if (map[y - 1][x] == 'C' || map[y - 1][x] == '0')
	{
		print_move();
		return ;
	}
	if (map[y + 1][x] == 'C' || map[y + 1][x] == '0')
	{
		print_move();
		return ;
	}
}
