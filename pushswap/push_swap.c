/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:28:45 by mabdessm          #+#    #+#             */
/*   Updated: 2024/06/29 15:58:54 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
				ft_lstadd_front(&a, ft_lstnew(ft_atoi(argv[i])));
			ft_printf("%d\n%d\n", ft_lstsize(a), ft_lstsize(b));
		}
		else
			ft_printf("Error\n");
	}
}
