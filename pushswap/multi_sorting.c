/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:01:11 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/10 15:17:16 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sswap(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, '\0');
	swap(stack_b, '\0');
	ft_printf("ss\n");
}

void	rrotate(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, '\0');
	rotate(stack_b, '\0');
	ft_printf("rr\n");
}

void	rreverse_rrotate(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, '\0');
	reverse_rotate(stack_b, '\0');
	ft_printf("rrr\n");
}
