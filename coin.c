#include "so_long.h"

int	ft_coin(char **str)
{
	int	i;
	int	j;
	int	st;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == 'C')
			{
				st = str[j];
			}
			j++;
		}
		i++;
	}
	return (st);
}