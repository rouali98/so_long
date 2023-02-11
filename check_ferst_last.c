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

int	f_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_nline(char *argv)
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

char	**ft_rline(char *argv)
{
	char	**m;
	char	*str;
	int		fd;
	int		i;

	m = malloc(sizeof(char *) * (ft_nline(argv) + 1));
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

int	ft_cheklkher(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = f_strlen(str) - 1;
	while (str[j] != '\0')
	{
		if (j == (f_strlen(str) - 1))
		{
			while (str[j][i] != '\0')
			{
				if (str[j][i] != '1')
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

int	ft_cheklwel(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = f_strlen(str) - 1;
	while (str[j] != '\0')
	{
		if (j == 0)
		{
			while (str[j][i] != '\0')
			{
				if (str[j][i] != '1')
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
