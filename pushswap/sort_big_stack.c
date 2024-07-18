/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:17:46 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/18 18:02:31 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_big_stack(t_list **a, t_list **b)
{
	//if (ft_lstsize(*a) == ft_lstsize(*b) + 999)
	//	return ;
	if (ft_lstsize(*a) <= 100)
		sort_100(a, b);
	else
		sort_500(a, b);
}

void	sort_100(t_list **a, t_list **b)
{
	t_list	*temp;
	int		i;
	int		found;
	long	hold_first;
	long	hold_second;

	temp = *a;
	found = 0;
	while (temp)
	{
		if ((temp->index >= 0 && temp->index <= 19) && !found)
		{
			hold_first = temp->index;
			found = 1;
		}
		temp = temp->next;
	}
	temp = temp->prev;
	found = 0;
	while (temp)
	{
		if ((temp->index >= 0 && temp->index <= 19) && !found)
		{
			hold_second = temp->index;
			found = 1;
		}
		temp = temp->prev;
	}
	//either the variables are structures or we make a variable that gets the pos
	rotate_first = 0;
	if (hold_first->pos <= (lstsize(*a) / 2))
		number_of_moves_hold_first = hold_first->pos;
	else if (hold_first->pos > (lstsize(*a) / 2))
	{
		number_of_moves_hold_first = (lstsize(*a)) - hold_first->pos;
		rotate_first = 1;
	}
	rotate_second = 0;
	if (hold_second->pos <= (lstsize(*a) / 2))
		number_of_moves_hold_second = hold_second->pos;
	else if (hold_second->pos > (lstsize(*a) / 2))
	{
		number_of_moves_hold_second = (lstsize(*a)) - hold_second->pos;
		rotate_second = 1;
	}
	if (number_of_moves_hold_first <= number_of_moves_hold_second)
	{
		i = -1;
		if (!(rotate_first))
		{
			while (++i < number_of_moves_hold_first)
				rotate(a, 'a');
		}
		else
		{
			while (++i < number_of_moves_hold_first)
				reverse_rotate(a, 'a');
		}
	}
	else if (number_of_moves_hold_first > number_of_moves_hold_second)
	{
		i = -1;
		if (!(rotate_second))
		{
			while (++i < number_of_moves_hold_second)
				rotate(a, 'a');
		}
		else
		{
			while (++i < number_of_moves_hold_second)
				reverse_rotate(a, 'a');
		}
	}
	
}

void	sort_500(t_list **a, t_list **b)
{
}
