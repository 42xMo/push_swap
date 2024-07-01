/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:28:45 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/01 13:33:51 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//for testing
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

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a;
	t_list	*b;

	if (argc > 1)
	{
		if (no_error(argv, argc) && no_duplicates(argv, argc))
		{
			a = ft_lstnew(ft_atoi(argv[1]));
			b = NULL;
			i = 1;
			while (++i < argc)
				ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
			/*TESTING*/
			ft_printf(" ================\n");
			ft_printf("a : %d\nb : %d\n", ft_lstsize(a), ft_lstsize(b));
			show_stacks(a, b);
			ft_printf(" ================\n");
			swap(&a);
			ft_printf("swap(a)\n");
			ft_printf("a : %d\nb : %d\n", ft_lstsize(a), ft_lstsize(b));
			show_stacks(a, b);
			ft_printf(" ================\n");
			push(&b, &a);
			ft_printf("push(b, a)\n");
			ft_printf("a : %d\nb : %d\n", ft_lstsize(a), ft_lstsize(b));
			show_stacks(a, b);
			ft_printf(" ================\n");
			rotate(&a);
			ft_printf("rotate(a)\n");
			ft_printf("a : %d\nb : %d\n", ft_lstsize(a), ft_lstsize(b));
			show_stacks(a, b);
			ft_printf(" ================\n");
			reverse_rotate(&a);
			ft_printf("reverse_rotate(a)\n");
			ft_printf("a : %d\nb : %d\n", ft_lstsize(a), ft_lstsize(b));
			show_stacks(a, b);
			ft_printf(" ================\n");
			push(&b, &a);
			push(&b, &a);
			ft_printf("push(b, a)\npush(b, a)\n");
			ft_printf("a : %d\nb : %d\n", ft_lstsize(a), ft_lstsize(b));
			show_stacks(a, b);
			ft_printf(" ================\n");
			sswap(&a, &b);
			ft_printf("sswap(a, b)\n");
			ft_printf("a : %d\nb : %d\n", ft_lstsize(a), ft_lstsize(b));
			show_stacks(a, b);
			ft_printf(" ================\n");
			rrotate(&a, &b);
			ft_printf("rrotate(a, b)\n");
			ft_printf("a : %d\nb : %d\n", ft_lstsize(a), ft_lstsize(b));
			show_stacks(a, b);
			ft_printf(" ================\n");
			rreverse_rrotate(&a, &b);
			ft_printf("rreverse_rrotate(a, b)\n");
			ft_printf("a : %d\nb : %d\n", ft_lstsize(a), ft_lstsize(b));
			show_stacks(a, b);
			ft_printf(" ================\n");
			/*TESTING*/
			/*Test Example   ./push_swap 92 61 12 -57 84 -12   */
		}
		else
			ft_printf("Error\n");
	}
}
