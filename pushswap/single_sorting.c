/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:55:12 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/22 10:39:03 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printf_instruction(char c, char x)
{
	if (c == 'a' && x == 's')
		ft_printf("sa\n");
	else if (c == 'b' && x == 's')
		ft_printf("sb\n");	
	else if (c == 'a' && x == 'p')
		ft_printf("pa\n");
	else if (c == 'b' && x == 'p')
		ft_printf("pb\n");
	else if (c == 'a' && x == 'r')
		ft_printf("ra\n");
	else if (c == 'b' && x == 'r')
		ft_printf("rb\n");
	else if (c == 'a' && x == 'v')
		ft_printf("rra\n");
	else if (c == 'b' && x == 'v')
		ft_printf("rrb\n");
}

void	swap(t_list **stack, char c)
{
	t_list	*temp;

	if (!stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	if (temp->next != NULL)
		temp->next->prev = NULL;
	(*stack)->next = temp;
	(*stack)->prev = NULL;
	temp->prev = *stack;
	(*stack)->pos = 0;
	temp->pos = 1;
	printf_instruction(c, 's');
}

void	push(t_list **stack_1, t_list **stack_2, char c)
{
	t_list	*temp;

	if (!stack_2)
		return ;
	temp = *stack_1;
	*stack_1 = *stack_2;
	*stack_2 = (*stack_2)->next;
	(*stack_1)->next = temp;
	if (temp)
		temp->prev = *stack_1;
	temp = *stack_1;
	set_positions(&temp);
	temp = *stack_2;
	if (temp)
	{
		temp->prev = NULL;
		temp->pos = 0;
		set_positions(&temp);
	}
	printf_instruction(c, 'p');
}

void	rotate(t_list **stack, char c)
{
	t_list	*temp;
	t_list *last;
	int		pos;

	last = ft_lstlast(*stack);
	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	pos = 0;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
	temp = *stack;
	while (temp)
	{
		temp->pos = pos++;
		temp = temp->next;
	}
	printf_instruction(c, 'r');
}

void	reverse_rotate(t_list **stack, char c)
{
	t_list	*temp;
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	tmp = NULL;
	while (temp->next)
	{
		tmp = temp;
		temp = temp->next;
	}
	if (tmp)
	{
		tmp->next = NULL;
		temp->next = *stack;
		(*stack)->prev = temp;
		temp->prev = NULL;
		*stack = temp;
	}
	temp = *stack;
	set_positions_2(&temp);
	printf_instruction(c, 'v');
}
