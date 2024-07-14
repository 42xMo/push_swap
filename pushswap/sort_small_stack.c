/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:52:30 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/14 09:17:06 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_list **a)
{
	t_list	*temp;

	if (A_is_sorted(*a))
		return ;
	if ((*a)->content == ft_min(*a))
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if ((*a)->content == ft_max(*a))
	{
		rotate(a, 'a');
		if (!(A_is_sorted(*a)))
			swap(a, 'a');
	}
	else
	{
		temp = (*a)->next;
		if (temp->content < temp->next->content)
			swap(a, 'a');
		else
			reverse_rotate(a, 'a');
	}
}

void	sort_four(t_list **a, t_list **b)
{
	push(b, a, 'b');
	sort_three(a);
	if ((*b)->index == 0)
		push(a, b, 'a');
	else if ((*b)->index == 1)
	{
		push(a, b, 'a');
		swap(a, 'a');
	}
	else if ((*b)->index == 2)
	{
		rotate(a, 'a');
		push(a, b, 'a');
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
	else if ((*b)->index == 3)
	{
		push(a, b, 'a');
		rotate(a, 'a');
	}
}

void	sort_five(t_list **a, t_list **b)
{
	push(b, a, 'b');
	(*a)->index = -1;
	(*a)->next->index = -1;
	(*a)->next->next->index = -1;
	(*a)->next->next->next->index = -1;
	index_stack(a);
	sort_four(a, b);
	if ((*b)->index == 0)
		push(a, b, 'a');
	else if ((*b)->index == 1)
	{
		push(a, b, 'a');
		swap(a, 'a');
	}
	else if ((*b)->index == 2)
	{
		rotate(a, 'a');
		push(a, b, 'a');
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
	else
		sort_five_2(a, b);
}

void	sort_five_2(t_list **a, t_list **b)
{
	if ((*b)->index == 3)
	{
		reverse_rotate(a, 'a');
		push(a, b, 'a');
		rotate(a, 'a');
		rotate(a, 'a');
	}
	else if ((*b)->index == 4)
	{
		push(a, b, 'a');
		rotate(a, 'a');
	}
}

void	sort_small_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		swap(a, 'a');
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 4)
		sort_four(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
}
