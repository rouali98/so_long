#include "so_long.h"
#include "mlx.h"

char	**g_st;
int		g_key;
void	*ml;
void	*wi;

void	move_p(void)
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
					if (g_st[i][j + 1] != '1')
					{
						g_st[i][j] = '0';
						g_st[i][j + 1] = 'P';
						break ;
					}
				}
				if (g_key == 0 || g_key == 123)
				{
					if (g_st[i][j - 1] != '1')
					{
						g_st[i][j] = '0';
						g_st[i][j - 1] = 'P';
						break ;
					}
				}
				if (g_key == 13 || g_key == 126)
				{
					if (g_st[i - 1][j] != '1')
					{
						g_st[i][j] = '0';
						g_st[i - 1][j] = 'P';
						break ;
					}
				}
				if (g_key == 1 || g_key == 125)
				{
					if (g_st[i + 1][j] != '1')
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