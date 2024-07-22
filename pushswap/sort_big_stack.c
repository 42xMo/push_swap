/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:17:46 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/20 05:55:05 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_big_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == ft_lstsize(*b) + 999)
		return ;
	/*if (ft_lstsize(*a) <= 100)
		sort_100(a, b);
	else
		sort_500(a, b);*/
}

/*void	sort_100(t_list **a, t_list **b)
{
	t_list	*temp;
	int		i;
	int		found;
	long	hold_first;
	long	hold_second;
	int		rotate_first;
	int		rotate_second;
	int		number_moves_first;
	int		number_moves_second;
	int		pos_first;
	int		pos_second;

	temp = *a;
	found = 0;
	pos_first = 0;
	pos_second = 0;
	hold_first = 0;
	hold_second = 0;
	while (temp)
	{
		if ((temp->index >= 0 && temp->index <= 19) && !found)
		{
			hold_first = temp->index;
			pos_first = temp->pos;
			found = 1;
		}
		temp = temp->next;
	}
	temp = temp->prev;
	found = 0;
	while (temp)
	{
		if ((temp->index >= 0 && temp->index <= 19) && !found)
		{
			hold_second = temp->index;
			pos_second = temp->pos;
			found = 1;
		}
		temp = temp->prev;
	}
	rotate_first = 0;
	if (pos_first <= (lstsize(*a) / 2))
		number_moves_first = pos_first;
	else if (pos_first > (lstsize(*a) / 2))
	{
		number_moves_first = (lstsize(*a)) - pos_first;
		rotate_first = 1;
	}
	rotate_second = 0;
	if (pos_second <= (lstsize(*a) / 2))
		number_moves_second = pos_second;
	else if (pos_second > (lstsize(*a) / 2))
	{
		number_moves_second = (lstsize(*a)) - pos_second;
		rotate_second = 1;
	}
	if (number_moves_first <= number_moves_second)
	{
		i = -1;
		if (!(rotate_first))
		{
			while (++i < number_moves_first)
				rotate(a, 'a');
		}
		else
		{
			while (++i < number_moves_first)
				reverse_rotate(a, 'a');
		}
	}
	else if (number_moves_first > number_moves_second)
	{
		i = -1;
		if (!(rotate_second))
		{
			while (++i < number_moves_second)
				rotate(a, 'a');
		}
		else
		{
			while (++i < number_moves_second)
				reverse_rotate(a, 'a');
		}
	}
	//STEP 4
	
	
}*/

//void	sort_500(t_list **a, t_list **b)
//{
//}
