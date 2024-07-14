/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:50:54 by mabdessm          #+#    #+#             */
/*   Updated: 2024/07/14 11:27:31 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../printf/ft_printf.h"

int		no_error(char **argv, int argc);
int		no_duplicates(char **argv, int argc);
void	swap(t_list **stack, char c);
void	push(t_list **stack_1, t_list **stack_2, char c);
void	rotate(t_list **stack, char c);
void	reverse_rotate(t_list **stack, char c);
void	sswap(t_list **stack_a, t_list **stack_b);
void	rrotate(t_list **stack_a, t_list **stack_b);
void	rreverse_rrotate(t_list **stack_a, t_list **stack_b);
int		a_is_sorted(t_list *a);
int		ft_min(t_list *a);
int		ft_max(t_list *a);
t_list	*next_min(t_list **stack);
void	index_stack(t_list **stack);
void	free_stack(t_list **stack);
void	sort_three(t_list **a);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
void	sort_five_2(t_list **a, t_list **b);
void	sort_small_stack(t_list **a, t_list **b);
void	sort_big_stack(t_list **a, t_list **b);
void	ft_sort(t_list **a, t_list **b);

#endif