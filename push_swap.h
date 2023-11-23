/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:04:33 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/21 23:10:01 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/includes/libft.h"

typedef struct s_stack
{
	long content;         // The content of the stack
	struct s_stack *next; // Pointer to the next element of the stack
}			t_stack;

typedef struct info
{
	int		movements;
	int		size;
	long	data;
}			t_info;

// *************************** STACK MANIPULATION *************************** //

void		swap_stack(t_stack **stack, char list);
/**
 * This function swaps the top two elements of the stack.
 *
 * @param stack - a pointer to a t_stack structure
 * @param list - a character representing the stack
 *
 * @return None
 */

void		swap_both(t_stack **a, t_stack **b);
/**
 * This function swaps the top two elements of both stacks.
 *
 * @param a - a pointer to a t_stack structure
 * @param b - a pointer to a t_stack structure
 *
 * @return None
 */

void		push_stack(t_stack **from, t_stack **to, char list);
/**
 * This function takes the first element at the top of 'from' and puts it at the
 * top of 'to'.
 *
 * @param from - a pointer to a t_stack structure
 * @param to - a pointer to a t_stack structure
 * @param list - a character representing the stack
 *
 * @return None
 */

void		rotate_stack(t_stack **stack, char list);
/**
 * This function shifts up all elements of the stack by 1.
 *
 * @param stack - a pointer to a t_stack structure
 * @param list - a character representing the stack
 *
 * @return None
 */

void		rotate_both(t_stack **a, t_stack **b);
/**
 * This function shifts up all elements of both stacks by 1.
 *
 * @param a - a pointer to a t_stack structure
 * @param b - a pointer to a t_stack structure
 *
 * @return None
 */

void		reverse_stack(t_stack **stack, char list);
/**
 * This function shifts down all elements of the stack by 1.
 *
 * @param stack - a pointer to a t_stack structure
 * @param list - a character representing the stack
 *
 * @return None
 */

void		reverse_both(t_stack **a, t_stack **b);
/**
 * This function shifts down all elements of both stacks by 1.
 *
 * @param a - a pointer to a t_stack structure
 * @param b - a pointer to a t_stack structure
 *
 * @return None
 */

// *************************** STACK INFORMATION *************************** //

int			get_min(t_stack *stack);
/**
 * Returns the minimum value in the stack.
 *
 * @param stack A pointer to the first element of the stack.
 * @return The minimum value in the stack.
 */

int			get_max(t_stack *stack);
/**
 * Returns the maximum value in the stack.
 *
 * @param stack A pointer to the first element of the stack.
 * @return The maximum value in the stack.
 */

int			stack_len(t_stack *stack);
/**
 * Returns the length of the stack.
 *
 * @param stack A pointer to the first element of the stack.
 * @return The length of the stack.
 */

// **************************** INPUT VALIDATION **************************** //

void		ft_check_args(int argc, char **argv, t_stack *stack);
/**
 * This function ensures that there are at least two arguments,
 * and that all the arguments are valid numbers without any duplicates.
 *
 * @param argc - an integer representing the number of command line arguments
 * @param argv - an array of strings representing the command line arguments
 * @param stack - a pointer to a t_stack structure
 *
 * @return None
 */

int			ft_dup_check(char **argv);
/**
 * This function checks if there are duplicates.
 *
 * @param argv - an array of strings representing the command line arguments
 * @return 1 if there are no duplicates, 0 otherwise
 */

int			ft_isnum(char **num);
/**
 * This function checks if the arguments are numbers.
 *
 * @param num - an array of strings representing the command line arguments
 * @return 1 if the arguments are numbers, 0 otherwise
 */

// *************************** SORTING FUNCTIONS *************************** //

void		sort(t_stack **a, t_stack **b);
/**
 * This function sorts the stack.
 *
 * @param a - a pointer to a t_stack structure
 * @param b - a pointer to a t_stack structure
 *
 * @return None
 */

void		sort_two(t_stack **a);
/**
 * This function sorts two numbers.
 *
 * @param a - a pointer to a t_stack structure
 * @return None
 */

void		sort_three(t_stack **a);
/**
 * This function sorts three numbers.
 *
 * @param a - a pointer to a t_stack structure
 * @return None
 */

void		sort_four(t_stack **a, t_stack **b);
/**
 * This function sorts four numbers.
 *
 * @param a - a pointer to a t_stack structure
 * @param b - a pointer to a t_stack structure
 * @return None
 */

void		sort_five(t_stack **a, t_stack **b);
/**
 * This function sorts five numbers.
 *
 * @param a - a pointer to a t_stack structure
 * @param b - a pointer to a t_stack structure
 * @return None
 */

void		sort_more(t_stack **a, t_stack **b);
/**
 * This function sorts the list a with more than 5 numbers.
 *
 * @param a - Pointer to the first stack
 * @param b - Pointer to the second stack
 * @return None
 */

void		sort_out_min_max(t_stack **a, t_stack **b, int size);
/**
 * This function sorts the list a with more than 100 numbers.
 *
 * @param a - Pointer to the first stack
 * @param b - Pointer to the second stack
 * @param size - The size of the stack
 * @return None
 */

void		sort_in_min_max(t_stack **a, t_stack **b, int size);
/**
 * This function sorts the list a with more than 100 numbers.
 *
 * @param a - Pointer to the first stack
 * @param b - Pointer to the second stack
 * @param size - The size of the stack
 * @return None
 */

void		sort_numbers(t_stack **a, t_stack **b, t_info nbr2sort,
				t_info target);
/**
 * This function sorts the list a with more than 100 numbers.
 *
 * @param a - Pointer to the first stack
 * @param b - Pointer to the second stack
 * @param nbr2sort - Structure with information about the number to move
 * @param target - Structure with information about the number to move
 * @return None
 */

void		put_all_a(t_stack **a, t_stack **b);
/**
 * This function sorts the list a with more than 100 numbers.
 *
 * @param a - Pointer to the first stack
 * @param b - Pointer to the second stack
 * @return None
 */

void		ab_top(t_stack **a, t_stack **b, t_info nbr2sort, t_info target);
/**

	* Moves the top elements of stacks `a` and `b` to their respective target positions.
 * Uses the `rotate_stack`, `reverse_stack`,
	and `rotate_both` functions to perform the necessary rotations.
 *
 * @param a - A pointer to the stack `a`
 * @param b - A pointer to the stack `b`
 * @param nbr2sort
	- A structure containing information about the element to be moved from stack `a`
 * @param target
	- A structure containing information about the target position in stack `b`
 */

void		b_top(t_stack **b, t_info target);
/**
 * Moves the top element of stack `b` to the desired target position.
 *
 * @param b - A pointer to the stack `b`.
 * @param target - The target position to move the top element of stack `b`.
 *
 * @return None.
 */

void		a_top(t_stack **a, t_info nbr2sort);
/**

	* Moves the top element of stack `a` to the desired position specified by `nbr2sort.data`.
 *
 * @param a - A pointer to the stack `a` (passed by reference).
 * @param nbr2sort
	- A structure that holds the desired position (`nbr2sort.data`) and the number of movements required to reach that position (`nbr2sort.movements`).
 *
 * @return None.
 */

// ************************* MOVEMENT CALCULATIONS ************************* //

t_info		a_nbr2move(t_stack *a, t_stack *b, t_info info_a);
/**
 * This function finds the cheapest number to move from stack 'a' to stack 'b'.
 *
 * @param a - Pointer to the first stack
 * @param b - Pointer to the second stack
 * @param info_a - Structure with information about the number to move

	* @return The number of movements needed to move the number to the top of stack 'a'
 */

t_info		b_target(t_stack *b, int data_a);
/**
	* This function returns the number of movements needed to move the number to the top of stack 'b'.
 *
 * @param b - Pointer to the second stack
 * @param data_a - The number to move

	* @return The number of movements needed to move the number to the top of stack 'b'
 */

int			calc(int a, int b);
/**

	* This function calculates the number of movements needed to move the number to the top of stack 'b'.
 *
 * @param a - The number of movements to move the number to the top of stack 'a'
 * @param b - The number of movements to move the number to the top of stack 'b'

	* @return The number of movements needed to move the number to the top of stack 'b'
 */
int			mv_calcs2(t_info info_a, t_info info_b);
/**

	* Calculates the number of movements needed to reach a target position in a stack.
 *
 * @param info_a - a structure containing information about stack A,
	including the number of movements and the size of the stack.
 * @param info_b - a structure containing information about stack B,
	including the number of movements and the size of the stack.
 * @return nbr_m
	- the number of movements needed to reach the target position in the stack.
 */

int			mv_calcs(t_info info_a, t_info info_b);
/**

	* This function calculates the number of movements needed to move the number to the top of stack 'b'.
 *
 * @param info_a - Structure with information about the number to move
 * @param info_b - Structure with information about the number to move

	* @return The number of movements needed to move the number to the top of stack 'b'
 */

int			get_index(t_stack *stack, int target);
/**
 * This function returns the index of the target value in the stack.
 *
 * @param stack - Pointer to the stack
 * @param target - The target value
 * @return The index of the target value in the stack
 */

int			out_min_max(t_stack *b, t_info info_a);
/**

	* This function returns the number of movements needed to move the number to the top of stack 'b'.
 *
 * @param b - Pointer to the second stack
 * @param info_a - Structure with information about the number to move

	* @return The number of movements needed to move the number to the top of stack 'b'
 */

int			check_sort_list(t_stack *stack);
/**
 * This function checks if the stack is sorted.
 *
 * @param stack - a pointer to a t_stack structure
 *
 * @return 1 if the stack is sorted, 0 otherwise
 */

bool		four_index(t_stack **a, t_stack **b, int index);
/**
 * Performs different operations on stack 'a' based on the value of the index.
 * Pushes elements from stack 'a' to stack 'b' in certain cases.
 * Returns EXIT_SUCCESS if stack 'a' is sorted after the operations,
	and EXIT_FAILURE otherwise.
 *
 * @param a - Pointer to the first stack
 * @param b - Pointer to the second stack
 * @param index - Integer representing the index value
 * @return EXIT_SUCCESS if stack 'a' is sorted after the operations,
	EXIT_FAILURE otherwise
 */

bool		five_index(t_stack **a, t_stack **b, int index);
/**
 * Performs different operations on stack 'a' based on the value of the index.
 * Pushes elements from stack 'a' to stack 'b' in certain cases.
 * Returns EXIT_SUCCESS if stack 'a' is sorted after the operations,
	and EXIT_FAILURE otherwise.
 *
 * @param a - Pointer to the first stack
 * @param b - Pointer to the second stack
 * @param index - Integer representing the index value
 * @return EXIT_SUCCESS if stack 'a' is sorted after the operations,
	EXIT_FAILURE otherwise
 */

int			get_min_index(t_stack **stack);
/**
 * This function returns the index of the minimum value in stack 'a'.
 *
 * @param stack - Pointer to the first stack
 * @return The index of the minimum value in stack 'a'
 */

void		rotating_a(t_stack **a);
/**
 * This function rotates the stack 'a' to the top.
 *
 * @param a - a pointer to a t_stack structure
 * @return None
 */

t_info		b_target(t_stack *b, int data_a);
/**

	* This function returns the number of movements needed to move the number to the top of stack 'b'.
 *
 * @param b - Pointer to the second stack
 * @param data_a - The number to move

	* @return The number of movements needed to move the number to the top of stack 'b'
 */

int			in_min_max(t_stack *b, int data_a, t_info info_a);
/**

	* This function returns the number of movements needed to move the number to the top of stack 'b'.
 *
 * @param b - Pointer to the second stack
 * @param data_a - The number to move
 * @param info_a - Structure with information about the number to move

	* @return The number of movements needed to move the number to the top of stack 'b'
 */

// ************************** AUXILIARY FUNCTIONS ************************** //
void		print_stack(t_stack *stack);
/**
 * This function prints the content of a stack.
 *
 * @param stack - a pointer to a t_stack structure
 *
 * @return None
 */

void		error(void);
/**
 * This function prints "Error" and exits the program.
 *
 * @return None
 */

// **************************** STACK MANAGEMENT **************************** //
void		ft_free_stack(t_stack **stack);
/**
 * This function frees the memory allocated for a stack.
 *
 * @param stack - a pointer to a t_stack structure
 *
 * @return None
 */

void		create_stack(t_stack **stack, int content);
/**
 * This function creates a stack.
 *
 * @param stack - a pointer to a t_stack structure
 * @param content - an integer representing the content of the stack
 *
 * @return None
 */

void		ft_add_next(t_stack **stack, int content);
/**
 * This function adds a new node to the stack.
 *
 * @param stack - a pointer to a t_stack structure
 * @param content - an integer representing the content of the stack
 *
 * @return None
 */
#endif
