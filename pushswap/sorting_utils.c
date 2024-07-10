/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:52:30 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/10 18:01:57 by mabdessm         ###   ########.fr       */
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

int	ft_min(t_list *a)
{
	long		i;

	i = a->content;
	while (a)
	{
		if (a->content < i)
			i = a->content;
		a = a->next;
	}
	return (i);
}

int	ft_max(t_list *a)
{
	long	i;

	i = a->content;
	while (a)
	{
		if (a->content > i)
			i = a->content;
		a = a->next;
	}
	return (i);
}

void	sort_three(t_list **a)
{
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
		*a = (*a)->next;
		if ((*a)->content < (*a)->next->content)
			swap(a, 'a');
		else
			reverse_rotate(a, 'a');
	}
}

void	sort_small_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		swap(a, 'a');
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	// else if (ft_lstsize(*a) == 4)
	//{
	//}
	else if (ft_lstsize(*a) == 5)
	{
	}
	/*{
		push(b, a, 'b');
		push(b, a, 'b');
		sort_three(a);
		if (1 2 or 2 1 or 3 1)
		{
			if (3 1)
				swap(b , 'b');
			push(a, b, 'a');
			if (3 1)
				swap(a, 'a');
			push(a, b, 'a');
			if (!(A_is_sorted(*a)))
				swap(a, 'a');
		}
		else if (1 3 or 2 3 or 3 2 or 2 4)
		{
			rotate(a, 'a');
			push(a, b, 'a');
			if (1 3)
				reverse_rotate(a, 'a');
			if (1 3 or 2 3 or 3 2)
				push(a, b, 'a');
			if (2 3 or 3 2 or 2 4)
			{
				if (3 2 or 2 4)
					swap(a, 'a');
				if (2 4)
					push(a, b, 'a');
				reverse_rotate(a, 'a');
			}
		}
		else if (1 4 or 1 5 or 4 5 or 2 5)
		{
			if (1 4)
				reverse_rotate(a, 'a');
			push(a, b, 'a');
			rotate(a, 'a');
			if (1 4 or 1 5)
				rotate(a, 'a');
			push(a, b, 'a');
			if (4 5)
				rotate(a, 'a');
			if (2 5)
				swap(a, 'a');
		}
		else if (3 4 or 4 3)
		{
			reverse_rotate(a, 'a');
			if (4 3)
				swap(b , 'b');
			push(a, b, 'a');
			push(a, b, 'a');
			reverse_rotate(a, 'a');
			reverse_rotate(a, 'a');
		}
		else if (4 1 or 4 2 or 3 5)
		{
			push(a, b, 'a');
			if (4 2)
				swap(a, 'a');
			if (4 1 OR 4 2)
			{
				reverse_rotate(a, 'a');
				push(a, b, 'a');
			}
			rotate(a, 'a');
			rotate(a, 'a');
			if (3 5)
			{
				push(a, b, 'a');
				swap(a, 'a');
				reverse_rotate(a, 'a');
			}
		}
	}*/
}
