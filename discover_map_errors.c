/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discover_map_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:32:36 by Loui :)           #+#    #+#             */
/*   Updated: 2022/04/01 20:39:51 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(t_vars *vars)
{
	if (vars->map->x == vars->map->y)
	{
		ft_putstr("\nError: Eh mate, we don't want a square map!\n");
		ft_free(vars);
		exit (EXIT_FAILURE);
	}
}

static int	check_player(t_vars *vars)
{
	int		p;
	int		i;

	p = 0;
	i = 0;
	while (vars->buf[i] != '\0')
	{
		if (vars->buf[i] == 'P')
			p++;
		i++;
	}
	if (p < 1)
	{
		ft_putstr("Error: Need at least one player\n");
		return (1);
	}
	else if (p > 1)
	{
		ft_putstr("Error: This is not a multiplayer game!\n");
		return (1);
	}
	else
		return (0);
}

static int	check_collectible(t_vars *vars)
{
	int		i;

	i = 0;
	while (vars->buf[i] != '\0')
	{
		if (vars->buf[i] == 'C')
			vars->map->c++;
		i++;
	}
	if (vars->map->c < 1)
	{
		ft_putstr("Error: Map needs at least one collectible\n");
		return (1);
	}
	else
		return (0);
}

static int	check_exito(t_vars *vars)
{
	int		e;
	int		i;

	e = 0;
	i = 0;
	while (vars->buf[i] != '\0')
	{
		if (vars->buf[i] == 'E')
			e++;
		i++;
	}
	if (e < 1)
	{
		ft_putstr("Error: Map needs at least one exit\n");
		return (1);
	}
	else
		return (0);
}

void	check_p_c_e(t_vars *vars)
{
	if (check_player(vars) == 1 || check_collectible(vars) == 1 \
			|| check_exito(vars) == 1)
	{
		ft_free(vars);
		exit(EXIT_FAILURE);
	}
}
