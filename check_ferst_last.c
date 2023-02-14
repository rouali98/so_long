/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ferst_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:55:47 by rouali            #+#    #+#             */
/*   Updated: 2023/02/11 17:55:48 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

//############# Count Line ######################//
int	f_strlen(char **map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		i++;
	}
	return (i);
}

//############# Count Line in file ######################//
int	count_line(char *argv)
{
	char	*str;
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("Error");
		return (0);
	}
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		i++;
	}
	close(fd);
	return (i);
}

//############# Return Line ######################//
char	**ft_rline(char *argv)
{
	char	**m;
	char	*str;
	int		fd;
	int		i;

	m = malloc(sizeof(char *) * (count_line(argv) + 1));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("Error");
		return (0);
	}
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		m[i] = str;
		i++;
	}
	m[i] = 0;
	return (m);
}

//############# Check Line Up ######################//
int	line_up(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = f_strlen(map) - 1;
	while (map[j] != '\0')
	{
		if (j == 0)
		{
			while (map[j][i] != '\0')
			{
				if (map[j][i] != '1')
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

//############# Check Line Down ######################//
int	line_down(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = f_strlen(map) - 1;
	while (map[j] != '\0')
	{
		if (j == (f_strlen(map) - 1))
		{
			while (map[j][i] != '\0')
			{
				if (map[j][i] != '1')
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
