/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:22:07 by mabdessm          #+#    #+#             */
/*   Updated: 2024/04/26 12:39:47 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signe;
	int	x;

	i = 0;
	x = 0;
	signe = 1;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		&& nptr[i] != '\0')
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signe = signe * -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i] != '\0')
	{
		x = x * 10 + (nptr[i] - '0');
		i++;
	}
	return (x * signe);
}
