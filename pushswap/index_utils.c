/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:27:11 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/26 21:45:13 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

t_list	*next_min(t_list **stack)
{
	int		x;
	t_list	*temp;
	t_list	*min;

	x = 1;
	temp = *stack;
	min = NULL;
	while (temp)
	{
		if ((temp->index == -1) && (x || temp->content < min->content))
		{
			min = temp;
			x *= 0;
		}
		temp = temp->next;
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = next_min(stack);
	while (temp)
	{
		temp->index = i;
		temp = next_min(stack);
		++i;
	}
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->content = 0;
		free(*stack);
		*stack = tmp;
	}
}
