/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:17:46 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/02 16:08:59 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_100(t_list **a, t_list **b)
{
	int	start;
	int	end;

	start = 0;
	end = (ft_lstsize(*a) / 6) - 1;
	find_optimal_push(a, b, start, end);
	sort_back(a, b);
}

void	sort_500(t_list **a, t_list **b)
{
	int	start;
	int	end;

	start = 0;
	end = (ft_lstsize(*a) / 13) - 1;
	find_optimal_push(a, b, start, end);
	sort_back(a, b);
}

void	sort_big_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 100)
		sort_100(a, b);
	else
		sort_500(a, b);
}
