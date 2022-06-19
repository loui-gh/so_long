/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_mac.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:10:36 by Loui :)           #+#    #+#             */
/*   Updated: 2022/04/01 20:26:43 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	ft_free(t_vars *vars)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	free_array(vars->map->ptr_map);
	if (vars->buf)
		free(vars->buf);
	if ((vars->map))
		free(vars->map);
	if (vars->pos)
		free(vars->pos);
	if (vars->img)
		free(vars->img);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	if (vars->mlx)
		free(vars->mlx);
}

int	mouse_click(t_vars *vars)
{
	ft_putstr("See you next time :)\n");
	ft_free(vars);
	exit(EXIT_SUCCESS);
	return (0);
}

int	esc(int keycode, t_vars *ptr)
{
	if (keycode == 65307)
	{
		ft_putstr("See you next time :)\n");
		ft_free(ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
