/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:56:25 by rouali            #+#    #+#             */
/*   Updated: 2023/02/11 17:56:26 by rouali           ###   ########.fr       */
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

int		f_strlen(char **str);
int		ft_nline(char *argv);
char	**ft_rline(char *argv);
int		ft_cheklkher(char **str);
int		ft_cheklwel(char **str);
int		ft_wall(char **str);
void	ft_mlx(char **m);

#endif
