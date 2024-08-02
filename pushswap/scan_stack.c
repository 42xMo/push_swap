/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:33:03 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/02 15:37:23 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	scan_top(t_list **a, int *pos_first, int i, int j)
{
	t_list	*temp;
	int		found;

	found = 0;
	temp = *a;
	while (temp)
	{
		if ((temp->index >= i && temp->index <= j) && !found)
		{
			*pos_first = temp->pos;
			found = 1;
		}
		temp = temp->next;
	}
}

void	scan_bot(t_list **a, int *pos_second, int i, int j)
{
	t_list	*temp;
	int		found;

	found = 0;
	temp = ft_lstlast(*a);
	while (temp)
	{
		if ((temp->index >= i && temp->index <= j) && !found)
		{
			*pos_second = temp->pos;
			found = 1;
		}
		temp = temp->prev;
	}
}

void	scan_for_biggest(t_list **a, int *pos_biggest, int i)
{
	t_list	*temp;
	int		found;

	found = 0;
	temp = *a;
	while (temp)
	{
		if ((temp->index == i) && !found)
		{
			*pos_biggest = temp->pos;
			found = 1;
		}
		temp = temp->next;
	}
}

int	chunk_still_exists(t_list **a, int i, int j)
{
	t_list	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->index >= i && temp->index <= j)
			return (1);
		temp = temp->next;
	}
	return (0);
}
