/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:28:45 by mabdessm          #+#    #+#             */
/*   Updated: 2024/06/29 11:33:12 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	no_error(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		if (ft_atoi(argv[i]) < 0)
			++j;
		if (!argv[i][j])
			return (0);
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int	no_duplicates(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (no_error(argv, argc) && no_duplicates(argv, argc))
		{
			ft_printf("No_Error\n");
		}
		else
			ft_printf("Error\n");
	}
}
