/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:52:30 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/12 16:55:53 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	A_is_sorted(t_list *a)
{
	long	tmp;
	
	while (a && a->next)
	{
		tmp = a->content;
		a = a->next;
		if (tmp > a->content)
			return (0);
	}
	return (1);
}

void	sort_three(t_list **a)
{
	t_list	*temp;

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
	else if ((*b)->index == 3)
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
	index_stack(a);
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
