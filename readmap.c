/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:01:48 by Loui :)           #+#    #+#             */
/*   Updated: 2022/04/01 21:15:35 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_strlen_mod(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	set_x_y(t_vars *vars)
{
	vars->map->x = ft_strlen_mod(vars->map->ptr_map[0]);
	vars->map->y = 0;
	while (vars->map->ptr_map[vars->map->y])
		vars->map->y++;
}

void	create_map_array(t_vars *vars, char *map_path)
{
	ssize_t		rc;
	int			fd;

	vars->buf = ft_calloc(sizeof(char), 1000);
	fd = open(map_path, O_RDONLY);
	rc = read(fd, vars->buf, 1000);
	if (rc < 1)
	{
		ft_free(vars);
		close(fd);
		exit(EXIT_FAILURE);
	}
	vars->map->ptr_map = ft_split(vars->buf, '\n');
	if (vars->map->ptr_map == NULL)
	{
		ft_free(vars);
		exit(EXIT_FAILURE);
	}
	check_p_c_e(vars);
	set_x_y(vars);
	check_element(vars);
	check_rectangle(vars);
	check_walls(vars);
	close(fd);
}
