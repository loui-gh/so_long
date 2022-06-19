/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map_imgs_to_win.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/24 15:23:04 by Loui :)		   #+#	#+#			 */
/*   Updated: 2022/04/01 07:06:06 by Loui :)		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

static void	choose_element(t_vars *vars, int i, int j)
{
	int	img_width;
	int	img_height;

	img_width = 60;
	img_height = 60;
	if (vars->map->ptr_map[i][j] == '1')
		vars->img->img = mlx_xpm_file_to_image(vars->mlx, "./img/tree.xpm", \
			&img_width, &img_height);
	if (vars->map->ptr_map[i][j] == '0')
		vars->img->img = mlx_xpm_file_to_image(vars->mlx, "./img/floor.xpm", \
				&img_width, &img_height);
	if (vars->map->ptr_map[i][j] == 'C')
		vars->img->img = mlx_xpm_file_to_image(vars->mlx, "./img/banana.xpm", \
			&img_width, &img_height);
	if (vars->map->ptr_map[i][j] == 'E')
		vars->img->img = mlx_xpm_file_to_image(vars->mlx, "./img/exit.xpm", \
			&img_width, &img_height);
	if (vars->map->ptr_map[i][j] == 'P')
		vars->img->img = mlx_xpm_file_to_image(vars->mlx, "./img/monkey.xpm", \
			&img_width, &img_height);
	vars->img->addr = mlx_get_data_addr(vars->img->img, \
			&vars->img->bits_per_pixel, \
			&vars->img->line_length, &vars->img->endian);
}

void	loadmap(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map->y)
	{
		j = 0;
		while (j < vars->map->x)
		{
			choose_element(vars, i, j);
			mlx_put_image_to_window(vars->mlx, \
				vars->win, vars->img->img, 60 * j, 60 * i);
			if (vars->img->img)
				mlx_destroy_image(vars->mlx, vars->img->img);
			j++;
		}
		i++;
	}
}
