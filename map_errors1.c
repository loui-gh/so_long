/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:43:55 by Loui :)           #+#    #+#             */
/*   Updated: 2022/04/01 20:55:37 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	north_wall(t_vars *vars)
{
	size_t	i;
	char	*north_wall;

	north_wall = vars->map->ptr_map[0];
	i = 0;
	while (north_wall[i] != '\0')
	{
		if (north_wall[i] != '1')
		{
			ft_putstr("Error: The north wall has a hole in it!\n");
			ft_free(vars);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

static void	south_wall(t_vars *vars)
{
	char	*south_wall;
	size_t	i;

	i = 0;
	south_wall = vars->map->ptr_map[vars->map->y - 1];
	while (south_wall[i] != '\0')
	{
		if (south_wall[i] != '1')
		{
			ft_putstr("Error: The south wall has a hole in it!\n");
			ft_free(vars);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

static void	east_wall(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map->y)
	{
		if (vars->map->ptr_map[i][vars->map->x - 1] != '1')
		{
			ft_putstr("Error: Your east wall has a hole in it!\n");
			ft_free(vars);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

static void	west_wall(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map->y)
	{
		if (vars->map->ptr_map[i][0] != '1')
		{
			ft_putstr("Error: Your west wall has a hole in it!\n");
			ft_free(vars);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

void	check_walls(t_vars *vars)
{
	north_wall(vars);
	south_wall(vars);
	west_wall(vars);
	east_wall(vars);
}
