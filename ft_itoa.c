/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:34:44 by Loui :)           #+#    #+#             */
/*   Updated: 2022/04/01 20:40:13 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s)
{
	char	*dst_ptr;
	int		i;

	i = 0;
	dst_ptr = (char *)malloc(ft_strlen(s) + 1);
	if (dst_ptr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dst_ptr[i] = s[i];
		i++;
	}
	dst_ptr[i] = '\0';
	return (dst_ptr);
}

static int	ft_string_len(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_make_string(char *str, long nbr, int str_len)
{
	int	n_is_neg;

	n_is_neg = 0;
	if (nbr != 0)
		str = malloc(sizeof(char) * (str_len + 1));
	else
		return (str = ft_strdup("0"));
	if (!str)
		return (0);
	if (nbr < 0)
	{
		n_is_neg++;
		nbr = -nbr;
	}
	str[str_len] = '\0';
	while (--str_len)
	{
		str[str_len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n_is_neg == 1)
		str[0] = '-';
	else
		str[0] = (nbr % 10) + '0';
	return (str);
}

void	ft_itoa_mod(int n, t_vars *vars)
{
	int		str_len;
	char	*str;
	long	nbr;

	nbr = n;
	str_len = ft_string_len(nbr);
	str = 0;
	str = ft_make_string(str, nbr, str_len);
	if (!str)
	{
		ft_free(vars);
		exit(EXIT_FAILURE);
	}
	ft_putstr(str);
	free(str);
}
