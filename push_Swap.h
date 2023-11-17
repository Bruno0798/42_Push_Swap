/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:04:33 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/17 22:15:49 by bsousa-d         ###   ########.fr       */
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
/**
 * This function ensures that there are at least two arguments, and that all the arguments are valid numbers without any duplicates.
 *
 * @param argc - an integer representing the number of command line arguments
 * @param argv - an array of strings representing the command line arguments
 * @param stack - a pointer to a t_stack structure
 *
 * @return None
 */

void ft_free_stack(t_stack **stack);
/**
 * This function frees the memory allocated for a stack.
 *
 * @param stack - a pointer to a t_stack structure
 *
 * @return None
 */

void print_stack(t_stack *stack);
/**
 * This function prints the content of a stack.
 *
 * @param stack - a pointer to a t_stack structure
 *
 * @return None
 */

void create_stack(t_stack **stack, int content);
/**
 * This function creates a stack.
 *
 * @param stack - a pointer to a t_stack structure
 * @param content - an integer representing the content of the stack
 *
 * @return None
 */

void ft_add_next(t_stack **stack, int content);
/**
 * This function adds a new node to the stack.
 *
 * @param stack - a pointer to a t_stack structure
 * @param content - an integer representing the content of the stack
 *
 * @return None
 */

void sort(t_stack **a, t_stack **b);
/**
 * This function sorts the stack.
 *
 * @param a - a pointer to a t_stack structure
 * @param b - a pointer to a t_stack structure
 *
 * @return None
 */
int check_sort_list(t_stack *stack);
void swap_stack(t_stack **stack, char list);
void swap_both(t_stack **a, t_stack **b);
void push_stack(t_stack **from, t_stack **to, char list);
void rotate_stack(t_stack **stack, char list);
void rotate_both(t_stack **a, t_stack **b);
void reverse_stack(t_stack **stack, char list);
void reverse_both(t_stack **a, t_stack **b);
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
// 5 NUMBERS
void sort_five(t_stack **a, t_stack **b);
void sort_five_asc_order_test();
void sort_five_min_at_top_test();
void sort_five_max_at_top_test();

#endif