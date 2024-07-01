/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:55:12 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/01 13:26:09 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*temp;
	
	if (!stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*temp;
	
	if (!stack_2)
		return ;
	temp = *stack_1;
	*stack_1 = *stack_2;
	*stack_2 = (*stack_2)->next;
	(*stack_1)->next = temp;
}

void	rotate(t_list **stack)
{
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = temp;
	*stack = temp->next;
	temp->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	int		i;
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	temp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		++i;
	}
	(*stack)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		--i;
	}
	temp->next = NULL;
}
