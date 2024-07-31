/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:17:46 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/31 17:55:16 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	scan_top(t_list **a, int *pos_first, int i, int j)
{
	t_list	*temp;
	int		found;

	found = 0;
	temp = *a;
	while (temp)
	{
		if ((temp->index >= i && temp->index <= j) && !found)
		{
			*pos_first = temp->pos;
			found = 1;
		}
		temp = temp->next;
	}
}

void	scan_bot(t_list **a, int *pos_second, int i, int j)
{
	t_list	*temp;
	int		found;

	found = 0;
	temp = ft_lstlast(*a);
	while (temp)
	{
		if ((temp->index >= i && temp->index <= j) && !found)
		{
			*pos_second = temp->pos;
			found = 1;
		}
		temp = temp->prev;
	}	
}

int		number_of_moves(t_list **a, int pos, int *rotate_x)
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

void	place_on_top(t_list **a, int mv_f, int mv_s, int rt_f, int rt_s)
{
	if (mv_f <= mv_s)
		rotate_optimally(a, rt_f, mv_f);
	else if (mv_f > mv_s)
		rotate_optimally(a, rt_s, mv_s);
}

int		chunk_still_exists(t_list **a, int i, int j)
{
	t_list	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->index >= i && temp->index <= j)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	compare_moves_and_push(t_list **a, t_list **b, int pos_fst, int pos_sec)
{
	int		rotate_first;
	int		rotate_second;
	int		moves_first;
	int		moves_second;

	rotate_first = 0;
	rotate_second = 0;
	moves_first = number_of_moves(a, pos_fst, &rotate_first);
	moves_second = number_of_moves(a, pos_sec, &rotate_second);
	place_on_top(a, moves_first, moves_second, rotate_first, rotate_second);
	push(b, a, 'b');
}

void	find_optimal_push(t_list **a, t_list **b, int start, int end)
{
	int		chunk_end;
	int		pos_first;
	int		pos_second;

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

void	sort_100(t_list **a, t_list **b)
{
	int	start;
	int end;

	start = 0;
	end = (ft_lstsize(*a) / 5) - 1;
	find_optimal_push(a, b, start, end);
	//now that a is emplty, find the biggest number in b and push it to a
	//repeat untill b is empty
	//maybe use this loop but change the condition and the start and end are replaced by 0 and full size
	//also place all this in a new function called sort_back to make it simple
	// while (chunk_still_exists(a, start, chunk_end))
	// {
	// 	scan_top(a, &pos_first, start, chunk_end);
	// 	scan_bot(a, &pos_second, start, chunk_end);
	// 	compare_moves_and_push(a, b, pos_first, pos_second);
	// }
}

//void	sort_250(t_list **a, t_list **b)
//{
//	start = 0;
//	end = (ft_lstsize(*a) / 7) - 1; //teste si c'est optimal
//	find_optimal_push(a, b, start, end);
//  ajoute le reste de la fonction quand c fini
//}

//void	sort_500(t_list **a, t_list **b)
//{
//	start = 0;
//	end = (ft_lstsize(*a) / 13) - 1; //teste si c'est optimal ou si 11 est mieux
//	find_optimal_push(a, b, start, end);
// ajoute le reste de la fonction quand c fini
//}

void	sort_big_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 100)
		sort_100(a, b);
	/*else if (ft_lstsize(*a) <= 250)
		sort_250(a, b);
	else
		sort_500(a, b);*/
}