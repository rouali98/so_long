/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:37:20 by rouali            #+#    #+#             */
/*   Updated: 2022/11/08 13:37:44 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strchr(const char *str, int searChr)
{
	int				i;
	unsigned char	c;

	c = (char)searChr;
	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	if (str[i] == c)
		return (1);
	else
		return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = malloc(sizeof(char) * 1);
		left_str[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (left_str[i] != '\0')
	{
		str[i] = left_str[i];
		i++;
	}
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(left_str);
	return (str);
}

char	*read_newline(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[0] == 0)
		return (NULL);
	ret = malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	j = 0;
	while (str[j] != '\n' && str[j])
	{
		ret[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		ret[j] = '\n';
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*read_restline(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == 0)
	{
		free(str);
		return (NULL);
	}
	i++;
	s = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!s)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
		s[j++] = str[i++];
	s[j] = '\0';
	free(str);
	return (s);
}
