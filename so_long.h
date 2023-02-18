/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:56:25 by rouali            #+#    #+#             */
/*   Updated: 2023/02/18 21:29:10 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "./get_net_line/get_next_line.h"
# include <mlx.h>

/* ############### Mlx ############### */
struct s_mlx
{
	char	**map;
	void	*mlx;
	void	*win;
	int		key;

} mx;

/* ############### Display Windows ############### */
struct s_display_win
{
	int	w;
	int	h;

} ds;

/* ############### Direction X & Y ############### */
struct s_direction
{
	int	x;
	int	y;

} di;

/* ############### image ############### */
struct s_image
{
	void	*i1;
	void	*i0;
	void	*c;
	void	*ec;
	void	*eo;
	void	*p;

} img;

int		f_strlen(char **str);
int		count_line(char *argv);
char	**ft_rline(char *argv);
int		line_down(char **str);
int		line_up(char **str);
int		center_wall(char **str);
void	put_img(char **map, void *mlx, void *win);
void	move_p(void);
void	ft_image(char **map, void *mlx, void *win);
int		count_c(char **map);
int		ft_valid(void);
int		check_e(char **map);
int		check_p(char **map);
void	check_cpe(void);
int		ft_count(char **str);
void	check_mapi(void);
void	move_p(void);
void	ft_putstr(char *str);
int		ft_close(void);
void	ft_exitud(void);
void	ft_exitlr(void);
//void	valid_checkdoor(void);
//char	**ft_checkdoor(char **map);

/* image */

void	puteo(char **map, void *mlx, void *win);
void	put_c(char **map, void *mlx, void *win);
void	put_p(char **map, void *mlx, void *win);
void	put_1(char **map, void *mlx, void *win);
void	put_0(char **map, void *mlx, void *win);

#endif
