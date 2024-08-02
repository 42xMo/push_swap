/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:34:26 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/02 15:48:23 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	number_of_moves(t_list **a, int pos, int *rotate_x)
{
	int	number_moves;

	if (pos <= (ft_lstsize(*a) / 2))
		number_moves = pos;
	else
	{
		number_moves = (ft_lstsize(*a)) - pos;
		*rotate_x = 1;
	}
	return (number_moves);
}

void	rotate_optimally(t_list **a, int rotate_x, int number_moves)
{
	int	i;

	i = -1;
	if (!(rotate_x))
	{
		while (++i < number_moves)
			rotate(a, 'a');
	}
	else
	{
		while (++i < number_moves)
			reverse_rotate(a, 'a');
	}
}

void	compare_moves_and_push(t_list **a, t_list **b, int pos_st, int pos_sec)
{
	int	rotate_first;
	int	rotate_second;
	int	moves_first;
	int	moves_second;

	rotate_first = 0;
	rotate_second = 0;
	moves_first = number_of_moves(a, pos_st, &rotate_first);
	moves_second = number_of_moves(a, pos_sec, &rotate_second);
	if (moves_first <= moves_second)
		rotate_optimally(a, rotate_first, moves_first);
	else if (moves_first > moves_second)
		rotate_optimally(a, rotate_second, moves_second);
	push(b, a, 'b');
}

void	find_optimal_push(t_list **a, t_list **b, int start, int end)
{
	int	chunk_end;
	int	pos_first;
	int	pos_second;

	chunk_end = 0;
	pos_first = 0;
	pos_second = 0;
	while ((ft_lstsize(*a)) != 0)
	{
		while (chunk_still_exists(a, start, chunk_end))
		{
			scan_top(a, &pos_first, start, chunk_end);
			scan_bot(a, &pos_second, start, chunk_end);
			compare_moves_and_push(a, b, pos_first, pos_second);
		}
		start = chunk_end + 1;
		chunk_end += end + 1;
	}
}
