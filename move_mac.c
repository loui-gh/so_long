/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:22:24 by Loui :)           #+#    #+#             */
/*   Updated: 2022/04/01 21:26:33 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right(t_vars *vars)
{
	if (vars->map->ptr_map[vars->pos->y][vars->pos->x + 1] == '0')
	{
		num_moves(vars->map->point++, vars);
		vars->map->ptr_map[vars->pos->y][vars->pos->x] = '0';
		vars->map->ptr_map[vars->pos->y][vars->pos->x + 1] = 'P';
	}
	else if (vars->map->ptr_map[vars->pos->y][vars->pos->x + 1] == 'C')
	{
		num_moves(vars->map->point++, vars);
		score(vars);
		vars->map->ptr_map[vars->pos->y][vars->pos->x] = '0';
		vars->map->ptr_map[vars->pos->y][vars->pos->x + 1] = 'P';
	}
	else if (vars->map->ptr_map[vars->pos->y][vars->pos->x + 1] == 'E')
	{
		num_moves(vars->map->point++, vars);
		if (vars->map->bananas < vars->map->c)
			lose(vars);
		else
			winner(vars);
	}
	loadmap(vars);
}

void	left(t_vars *vars)
{
	if (vars->map->ptr_map[vars->pos->y][vars->pos->x - 1] == '0')
	{
		num_moves(vars->map->point++, vars);
		vars->map->ptr_map[vars->pos->y][vars->pos->x] = '0';
		vars->map->ptr_map[vars->pos->y][vars->pos->x - 1] = 'P';
	}
	else if (vars->map->ptr_map[vars->pos->y][vars->pos->x - 1] == 'C')
	{
		num_moves(vars->map->point++, vars);
		score(vars);
		vars->map->ptr_map[vars->pos->y][vars->pos->x] = '0';
		vars->map->ptr_map[vars->pos->y][vars->pos->x - 1] = 'P';
	}
	else if (vars->map->ptr_map[vars->pos->y][vars->pos->x - 1] == 'E')
	{
		num_moves(vars->map->point++, vars);
		if (vars->map->bananas < vars->map->c)
			lose(vars);
		else
			winner(vars);
	}
	loadmap(vars);
}

void	down(t_vars *vars)
{
	if (vars->map->ptr_map[vars->pos->y + 1][vars->pos->x] == '0')
	{
		num_moves(vars->map->point++, vars);
		vars->map->ptr_map[vars->pos->y][vars->pos->x] = '0';
		vars->map->ptr_map[vars->pos->y + 1][vars->pos->x] = 'P';
	}
	else if (vars->map->ptr_map[vars->pos->y + 1][vars->pos->x] == 'C')
	{
		num_moves(vars->map->point++, vars);
		score(vars);
		vars->map->ptr_map[vars->pos->y][vars->pos->x] = '0';
		vars->map->ptr_map[vars->pos->y + 1][vars->pos->x] = 'P';
	}
	else if (vars->map->ptr_map[vars->pos->y + 1][vars->pos->x] == 'E')
	{
		num_moves(vars->map->point++, vars);
		if (vars->map->bananas < vars->map->c)
			lose(vars);
		else
			winner(vars);
	}
	loadmap(vars);
}

void	up(t_vars *vars)
{
	if (vars->map->ptr_map[vars->pos->y - 1][vars->pos->x] == '0')
	{
		num_moves(vars->map->point++, vars);
		vars->map->ptr_map[vars->pos->y][vars->pos->x] = '0';
		vars->map->ptr_map[vars->pos->y - 1][vars->pos->x] = 'P';
	}
	else if (vars->map->ptr_map[vars->pos->y - 1][vars->pos->x] == 'C')
	{
		num_moves(vars->map->point++, vars);
		score(vars);
		vars->map->ptr_map[vars->pos->y][vars->pos->x] = '0';
		vars->map->ptr_map[vars->pos->y - 1][vars->pos->x] = 'P';
	}
	else if (vars->map->ptr_map[vars->pos->y - 1][vars->pos->x] == 'E')
	{
		num_moves(vars->map->point++, vars);
		if (vars->map->bananas < vars->map->c)
			lose(vars);
		else
			winner(vars);
	}
	loadmap(vars);
}

int	move(int keycode, t_vars *vars)
{
	find_player(vars);
	if (keycode == 53)
	{
		ft_free(vars);
		ft_putstr("See you next time :)\n");
		exit(EXIT_SUCCESS);
	}
	if (keycode == 2)
		right(vars);
	if (keycode == 0)
		left(vars);
	if (keycode == 1)
		down(vars);
	if (keycode == 13)
		up(vars);
	return (0);
}
