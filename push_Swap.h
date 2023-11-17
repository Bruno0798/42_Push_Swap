/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:04:33 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/12 21:59:14 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/includes/libft.h"

typedef struct s_stack
{
	long content;
	struct s_stack *next;
} t_stack;

void ft_check_args(int argc, char **argv, t_stack *stack);

void free_list(t_stack **stack);
void print_stack(t_stack *stack);
void create_stack(t_stack **stack, int content);
void ft_add_next(t_stack **stack, int content);
void sort(t_stack **a, t_stack **b);
int check_sort_list(t_stack *stack);
void swap_stack(t_stack **stack, char list);
void swap_both(t_stack **a, t_stack **b);
void push_stack(t_stack **from, t_stack **to, char list);
void rotate_stack(t_stack **stack, char list);
void rotate_both(t_stack **a, t_stack **b);
void reverse_stack(t_stack **stack, char list);
void reverse_both(t_stack **a, t_stack **b);
void ft_free_stack(t_stack **stack);
int get_min(t_stack *stack);
int get_max(t_stack *stack);
int stack_len(t_stack *stack);
void error(void);

// TESTS
// 3 NUMBERS
void sort_three(t_stack **a);
void test_sort_three_not_sorted();
void test_sort_three_sorted_ascending();
void test_sort_three_sorted_descending();
void test_sort_three_null_stack();
void test_sort_three_min_max();
void test_sort_three_min_not_max();
// 4 NUMBERS
void sort_four(t_stack **a, t_stack **b);
void sort_four_asc_order_test();
void sort_four_min_at_top_test();
void sort_four_max_at_top_test();
void sort_four_min_max_test();

#endif