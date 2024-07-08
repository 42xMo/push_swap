/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:52:30 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/08 17:04:48 by mabdessm         ###   ########.fr       */
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

void	sort_small_stack(t_list **a, t_list **b)
{
	//just for unused parameter error for now
	if (ft_lstsize(*b) == 1335759)
		return ;
	if (ft_lstsize(*a) == 2)
	{
		swap(a);
		ft_printf("sa\n");
	}
	// else if (ft_lstsize(a) == 3)
	// else if (ft_lstsize(a) == 4)
	// else if (ft_lstsize(a) == 5)
}

// void	sort_big_stack(t_list **a, t_list **b)
// {}
