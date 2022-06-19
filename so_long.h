/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:32:21 by Loui :)           #+#    #+#             */
/*   Updated: 2022/04/01 21:27:40 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>

typedef struct s_map
{
	char	**ptr_map;
	int		x;
	int		y;
	int		point;
	int		c;
	int		bananas;
}	t_map;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	*buf;
	t_img	*img;
	t_map	*map;
	t_pos	*pos;
}	t_vars;

int		mouse_click(t_vars *vars);
int		esc(int keycode, t_vars *vars);
void	free_array(char **array);
void	ft_free(t_vars *vars);

void	ft_putstr(char *s);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_itoa_mod(int n, t_vars *vars);

void	create_map_array(t_vars *vars, char *map_path);
void	loadmap(t_vars *vars);
int		move(int keycode, t_vars *vars);
void	num_moves(int n, t_vars *vars);
void	find_player(t_vars *vars);
void	winner(t_vars *vars);
void	lose(t_vars *vars);
void	score(t_vars *vars);
void	num_moves(int n, t_vars *vars);

void	check_args(int argc, char *map);
void	check_rectangle(t_vars *vars);
void	check_element(t_vars *vars);
void	check_walls(t_vars *vars);
void	check_p_c_e(t_vars *vars);

#endif