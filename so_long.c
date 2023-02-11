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

int	main(int argc, char **argv)
{
	char	**str;
	int		i;
	int		r;
	int		j;


	i = 0;
	if (argc != 2)
	{
		printf("Error");
		return (0);
	}
	str = ft_rline(argv[1]);
	if (ft_cheklwel(str) == 1 || ft_cheklkher(str) == 1 || ft_wall(str) == 1)
	{
		printf("error in map");
		return (0);
	}
	ft_mlx(str);
	return (0);
}
