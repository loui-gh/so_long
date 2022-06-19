/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:05:31 by Loui :)           #+#    #+#             */
/*   Updated: 2022/04/01 21:17:32 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	num_moves(int n, t_vars *vars)
{
	ft_putstr("Number of moves = ");
	ft_itoa_mod(n, vars);
	ft_putstr("\n");
}

void	score(t_vars *vars)
{
	vars->map->bananas++;
	ft_putstr("Omnomnomnom banana!\n");
}

void	lose(t_vars *vars)
{
	ft_putstr("You lose! (You did not collect all the bananas)\n");
	ft_free(vars);
	exit(EXIT_FAILURE);
}

void	winner(t_vars *vars)
{
	ft_putstr("Winner!");
	ft_free(vars);
	exit(EXIT_FAILURE);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	final_size;
	int		i;

	final_size = count * size;
	ptr = malloc(final_size);
	if (!ptr)
		return (0);
	i = 0;
	while (final_size)
	{
		ptr[i] = 0;
		i++;
		final_size--;
	}
	return (ptr);
}
