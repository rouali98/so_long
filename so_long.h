/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:56:25 by rouali            #+#    #+#             */
/*   Updated: 2023/02/20 19:40:15 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"
# include "mlx.h"

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
	int c;

} di;

/* ############### image ############### */
struct s_image
{
	void	*i1;
	void	*i0;
	void	*c;
	void	*ec;
	void	*eo;
	void	*pr;
	void	*pl;

} img;

/* check_cpe.c */
int		ft_close(void);
int		ft_valid(void);
void	count_cpe(void);
void	check_c(void);
void	check_e(void);

/* check_img.c */
void	puteo(char **map, void *mlx, void *win);
void	put_c(void *mlx, void *win);
void	put_p(void *mlx, void *win);
void	put_1(void *mlx, void *win);
void	put_0(void *mlx, void *win);

/* check_lines.c */
int		center_wall(char **str);
char	**ft_rline(char *argv);
void	check_lines(void);
int		line_up(char **str);
int		line_down(char **str);

/* count.c */
int		ft_count(char **str);
int		count_line(char *argv);
int		count_c(char **map);
int		count_e(char **map);
int		count_p(char **map);

/* exit.c */
void	ft_exitud(void);
void	ft_exitlr(void);

/* move.c */
void	m_right(void);
void	m_left(void);
void	m_up(void);
void	m_down(void);
void	move_p(void);

/* put_img.c */
void	var(void *mlx);
void	put_img(char **map, void *mlx, void *win);

/* so_long_utils.c */
int		f_strlen(char **str);
void	ft_putstr(char *str);

/* so_long.c */
char	**ft_path(char **map);

#endif
