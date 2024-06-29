/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:28:45 by mabdessm          #+#    #+#             */
/*   Updated: 2024/06/29 12:43:41 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (no_error(argv, argc) && no_duplicates(argv, argc))
		{
			ft_printf("No_Error\n");
		}
		else
			ft_printf("Error\n");
	}
}
