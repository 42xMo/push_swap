/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:40:32 by mabdessm          #+#    #+#             */
/*   Updated: 2024/04/25 19:43:59 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
	{
		return ((char *)big);
	}
	while (i < len && (big[i] != '\0'))
	{
		j = 0;
		while (little[j] == big[i + j] && (little[j] != '\0'))
		{
			j++;
		}
		if (j == ft_strlen(little) && j + i <= len)
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
