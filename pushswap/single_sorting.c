/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:55:12 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/20 05:46:52 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
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
	
	// il y a un leak quand on ajoute cette partie qui est censé changer prev à 
	// NULL du nombre que j'envoie dans stack 1 et mettre le prev du premier de stack 2 à
	// NULL, le deuxiéme de stack 1 qui etait premier doit mtn avoir prev sur le
	// nouveau premier, je soupconne que le leak vient de là quand stack 1 n'a pas
	// de deuxiéme
	
	/*(*stack_1)->prev = NULL;
	(*stack_1)-> pos = 0;
	if (temp)
		temp->prev = *stack_1;
	temp = *stack_1;
	while (temp->next)
	{
		temp->next->pos = temp->pos + 1;
		temp = temp->next;
	}
	temp = *stack_2;
	temp->prev = NULL;
	temp->pos = 0;
	while (temp->next)
	{
		temp->next->pos = temp->pos + 1;
		temp = temp->next;
	}*/
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}

void	rotate(t_list **stack, char c)
{
	t_list	*temp;

	t_list *last;
	last = ft_lstlast(*stack);
	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
	
		//old code that should be replaced by the new one if everything is right
		///////temp = *stack;
		///////*stack = ft_lstlast(*stack);
		///////(*stack)->next = temp;
		//////*stack = temp->next;
		//////temp->next = NULL;
	
	t_list	*current = *stack;
	int		pos = 0;
	while (current)
	{
		current->pos = pos++;
		current = current->next;
	}
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	reverse_rotate(t_list **stack, char c)
{
	//int		i;
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	t_list *tmp = NULL;
	while (temp->next)
	{
		tmp = temp;
		temp = temp->next;
	}
	if (tmp != NULL)
	{
		tmp->next = NULL;
		temp->next = *stack;
		(*stack)->prev = temp;
		temp->prev = NULL;
		*stack = temp;
	}
	
		//old code that should be replaced or changed
		//// i = 0;
		//// temp = *stack;
		//// while ((*stack)->next)
		//// {
		////	*stack = (*stack)->next;
		//// 	++i;
		//// }
		//// (*stack)->next = temp;
		//// while (i > 1)
		//// {
		//// 	temp = temp->next;
		//// 	--i;
		//// }
		//// temp->next = NULL;

	t_list	*current = *stack;
	int		pos = 0;
	while (current)
	{
		current->pos = pos++;
		current = current->next;
	}
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}
