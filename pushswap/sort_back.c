/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:35:44 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/02 15:38:05 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_optimally_back(t_list **a, int rotate_x, int number_moves)
{
	int	i;

	i = -1;
	if (!(rotate_x))
	{
		while (++i < number_moves)
			rotate(a, 'b');
	}
	else
	{
		while (++i < number_moves)
			reverse_rotate(a, 'b');
	}
}

void	push_biggest(t_list **a, t_list **b, int pos_biggest)
{
	int	rotate_biggest;
	int	moves;

	rotate_biggest = 0;
	moves = number_of_moves(a, pos_biggest, &rotate_biggest);
	rotate_optimally_back(a, rotate_biggest, moves);
	push(b, a, 'a');
}

void	sort_back(t_list **a, t_list **b)
{
	int	i;
	int	pos_biggest;

	i = ft_lstsize(*b) - 1;
	pos_biggest = 0;
	while ((ft_lstsize(*b)) != 0)
	{
		scan_for_biggest(b, &pos_biggest, i);
		push_biggest(b, a, pos_biggest);
		--i;
	}
}
