/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:28:45 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/18 18:18:21 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// for testing
void	show_stacks(t_list *stack_a, t_list *stack_b)
{
	ft_printf("stack_a :\n");
	while (stack_a)
	{
		ft_printf("|\t%i\t|\n _______________\n", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\ta\t\n");
	ft_printf("stack_b :\n");
	while (stack_b)
	{
		ft_printf("|\t%i\t|\n _______________\n", stack_b->content);
		stack_b = stack_b->next;
	}
	ft_printf("\tb\t\n");
}

void	ft_sort(t_list **a, t_list **b)
{
	index_stack(a);
	show_stacks(*a, *b);
	if (ft_lstsize(*a) <= 5)
		sort_small_stack(a, b);
	else
		sort_big_stack(a, b);
	show_stacks(*a, *b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a;
	t_list	*b;
	t_list	*prev;

	if (argc > 1)
	{
		if (no_error(argv, argc) && no_duplicates(argv, argc))
		{
			i = 1;
			a = ft_lstnew(ft_atoi(argv[1]), NULL, i);
			b = NULL;
			prev = a;
			while (++i < argc)
			{
				//ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i]), prev, i));
				ft_lstadd_back(&prev, ft_lstnew(ft_atoi(argv[i]), prev, i));
				//prev = a;
				prev = prev->next;
			}
			if (!(a_is_sorted(a)))
				ft_sort(&a, &b);
			free_stack(&a);
		}
		else
			ft_printf("Error\n");
	}
}
