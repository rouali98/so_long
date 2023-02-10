#include "so_long.h"

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

int	main(int argc, char **argv)
{
	char	**str;
	int		i;
	int		j;

	i = 0;

	if (argc != 2)
	{
		printf("Error");
		return (0);
	}
	str = ft_rline(argv[1]);
	j = f_strlen(str) - 1;
	printf("j = %d\n", j);
	while (str[j][i] != '\0')
	{
		if (str[j][i] != '1' && str[j][i] != '\n')
		{
			printf("error");
			return (0);
		}
		i++;
		printf("%c", str[j - j][i]);
		if (str[j - 7][i] != '1')
		{
			printf("error");
			return (0);
		}
		i++;
	}

	//i = 0;
	//while (1)
	//{
	//	str = ft_rline(argv[1]);
	//	if (str[i] == NULL)
	//		break ;
	//	printf("%s", str[i]);
	//	i++;
	//}
	return (0);
}
