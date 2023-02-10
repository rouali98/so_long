/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:38:11 by rouali            #+#    #+#             */
/*   Updated: 2022/11/04 17:38:19 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_file(int fd, char *str)
{
	char		*buffer;
	int			c;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	c = read(fd, buffer, BUFFER_SIZE);
	while (c != 0)
	{
		if (c < 0)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[c] = '\0';
		str = ft_strjoin(str, buffer);
		if ((ft_strchr(str, '\n')))
			break ;
		c = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_file(fd, str);
	if (!str)
		return (NULL);
	newline = read_newline(str);
	str = read_restline(str);
	return (newline);
}

//int main()
//{
//	int fd = open("text.txt", O_RDONLY);
//	char *str;

//	while (1)
//	{
//		str = get_next_line(fd);
//		printf("%s", str);
//		if(str == NULL)
//			break;
//	}
//	return (0);
//}
