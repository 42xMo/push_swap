/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:50:54 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/02 17:54:27 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../printf/ft_printf.h"

int		ft_strlen_argv(char **str);
int		no_error(char **argv, int argc);
int		no_duplicates(char **argv, int argc);
void	printf_instruction(char c, char x);
void	set_positions(t_list **stack);
void	set_positions_2(t_list **stack);
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
void	scan_top(t_list **a, int *pos_first, int i, int j);
void	scan_bot(t_list **a, int *pos_second, int i, int j);
int		number_of_moves(t_list **a, int pos, int *rotate_x);
void	rotate_optimally(t_list **a, int rotate_x, int number_moves);
int		chunk_still_exists(t_list **a, int i, int j);
int		bigger_than_b(int i, t_list **b);
void	compare_moves_and_push(t_list **a, t_list **b, int pos_st, int pos_sec);
void	find_optimal_push(t_list **a, t_list **b, int start, int end);
void	scan_for_biggest(t_list **a, int *pos_biggest, int i);
void	rotate_optimally_back(t_list **a, int rotate_x, int number_moves);
void	push_biggest(t_list **a, t_list **b, int pos_biggest);
void	sort_back(t_list **a, t_list **b);
void	sort_100(t_list **a, t_list **b);
void	sort_500(t_list **a, t_list **b);
void	sort_big_stack(t_list **a, t_list **b);
void	ft_sort(t_list **a, t_list **b);
void	free_if_split(int argc, char **argv);
void	push_swap(int argc, char **argv);

#endif