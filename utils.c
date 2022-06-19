/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:11:08 by Loui :)           #+#    #+#             */
/*   Updated: 2022/04/01 21:17:27 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_element(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map->y)
	{
		j = 0;
		while (j < vars->map->x)
		{
			if (vars->map->ptr_map[i][j] != 'P' && \
					vars->map->ptr_map[i][j] != 'C' && \
					vars->map->ptr_map[i][j] != 'E' && \
					vars->map->ptr_map[i][j] != '1' && \
					vars->map->ptr_map[i][j] != '0')
			{
				ft_putstr("Error! Map elements can be either 0,1,P,C,E\n");
				ft_free(vars);
				exit (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	find_player(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map->y)
	{
		j = 0;
		while (j < vars->map->x)
		{
			if ((vars->map->ptr_map[i][j] == 'P'))
			{
				vars->pos->y = i;
				vars->pos->x = j;
			}
			j++;
		}
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i = write(2, &s[i], 1) + i;
	}
}
