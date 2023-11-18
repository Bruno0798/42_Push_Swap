/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:04:33 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/18 19:12:58 by bsousa-d         ###   ########.fr       */
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
/**
 * This function checks if the stack is sorted.
 *
 * @param stack - a pointer to a t_stack structure
 *
 * @return 1 if the stack is sorted, 0 otherwise
 */

void swap_stack(t_stack **stack, char list);
/**
 * This function swaps the top two elements of the stack.
 *
 * @param stack - a pointer to a t_stack structure
 * @param list - a character representing the stack
 *
 * @return None
 */

void swap_both(t_stack **a, t_stack **b);
/**
 * This function swaps the top two elements of both stacks.
 *
 * @param a - a pointer to a t_stack structure
 * @param b - a pointer to a t_stack structure
 *
 * @return None
 */

void push_stack(t_stack **from, t_stack **to, char list);
/**
 * This function takes the first element at the top of 'from' and puts it at the top of 'to'.
 *
 * @param from - a pointer to a t_stack structure
 * @param to - a pointer to a t_stack structure
 * @param list - a character representing the stack
 *
 * @return None
 */

void rotate_stack(t_stack **stack, char list);
/**
 * This function shifts up all elements of the stack by 1.
 *
 * @param stack - a pointer to a t_stack structure
 * @param list - a character representing the stack
 *
 * @return None
 */

void rotate_both(t_stack **a, t_stack **b);
/**
 * This function shifts up all elements of both stacks by 1.
 *
 * @param a - a pointer to a t_stack structure
 * @param b - a pointer to a t_stack structure
 *
 * @return None
 */

void reverse_stack(t_stack **stack, char list);
/**
 * This function shifts down all elements of the stack by 1.
 *
 * @param stack - a pointer to a t_stack structure
 * @param list - a character representing the stack
 *
 * @return None
 */

void reverse_both(t_stack **a, t_stack **b);
/**
 * This function shifts down all elements of both stacks by 1.
 *
 * @param a - a pointer to a t_stack structure
 * @param b - a pointer to a t_stack structure
 *
 * @return None
 */

int get_min(t_stack *stack);
/**
 * Returns the minimum value in the stack.
 *
 * @param stack A pointer to the first element of the stack.
 * @return The minimum value in the stack.
 */

int get_max(t_stack *stack);
/**
 * Returns the maximum value in the stack.
 *
 * @param stack A pointer to the first element of the stack.
 * @return The maximum value in the stack.
 */

int stack_len(t_stack *stack);
/**
 * Returns the length of the stack.
 *
 * @param stack A pointer to the first element of the stack.
 * @return The length of the stack.
 */

void error(void);
/**
 * This function prints "Error" and exits the program.
 *
 * @return None
 */

bool four_index(t_stack **a, t_stack **b, int index);
/**
 * Performs different operations on stack 'a' based on the value of the index.
 * Pushes elements from stack 'a' to stack 'b' in certain cases.
 * Returns EXIT_SUCCESS if stack 'a' is sorted after the operations, and EXIT_FAILURE otherwise.
 *
 * @param a - Pointer to the first stack
 * @param b - Pointer to the second stack
 * @param index - Integer representing the index value
 * @return EXIT_SUCCESS if stack 'a' is sorted after the operations, EXIT_FAILURE otherwise
 */

bool five_index(t_stack **a, t_stack **b, int index);

int get_min_index(t_stack **stack);
// ?? **************** TESTES **************** ?? //

// todo **************** 3 NUMBERS **************** todo //
void sort_three(t_stack **a);
void sort_four(t_stack **a, t_stack **b);
void sort_five(t_stack **a, t_stack **b);
void sort_three_numbers();
void sort_four_numbers();
void sort_five_numbers();

#endif