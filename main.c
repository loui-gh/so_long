/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:02:42 by Loui :)           #+#    #+#             */
/*   Updated: 2022/04/01 20:50:23 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc, char *map)
{
	size_t	len;
	int		c;

	if (argc != 2)
	{
		ft_putstr("Error: command is ./solong maps/map.ber\n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(map);
	if (len != ft_strlen("maps/map.ber"))
	{
		ft_putstr("Need ./solong + maps/map.ber\n");
		exit(EXIT_FAILURE);
	}
	c = ft_strncmp("maps/map.ber", map, len);
	if (c != 0)
	{
		ft_putstr("Need ./solong + maps/map.ber\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_initialize(t_vars *vars)
{
	vars->win = NULL;
	vars->mlx = NULL;
	vars->buf = NULL;
	vars->pos->y = 0;
	vars->pos->x = 0;
	vars->map->point = 1;
	vars->map->bananas = 0;
	vars->map->c = 0;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	check_args(argc, argv[1]);
	vars.img = malloc(sizeof(t_img));
	vars.map = malloc(sizeof(t_map));
	vars.pos = malloc(sizeof(t_pos));
	if (!vars.img || !vars.map)
	{
		ft_free(&vars);
		exit(EXIT_FAILURE);
	}
	ft_initialize(&vars);
	create_map_array(&vars, argv[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map->x * 60, \
			vars.map->y * 60, "Loui's game");
	loadmap(&vars);
	mlx_hook(vars.win, 2, 27, move, &vars);
	mlx_hook(vars.win, 17, (1L << 17), mouse_click, &vars);
	mlx_loop(vars.mlx);
}
