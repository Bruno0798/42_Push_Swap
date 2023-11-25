/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:04:33 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/25 17:36:43 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/includes/libft.h"

/**
 * @brief Structure representing a stack node.
 * 
 * This structure is used to store the content of a stack node and a pointer to the next node.
 */
typedef struct s_stack
{
	long			content;	/**< The content of the stack node. */
	struct s_stack	*next;		/**< Pointer to the next stack node. */
}					t_stack;

/**
 * @brief Structure representing additional information.
 * 
 * This structure is used to store additional information related to the stack.
 */
typedef struct info
{
	int				movements;	/**< The number of movements made. */
	int				size;		/**< The size of the stack. */
	long			data;		/**< Additional data. */
}					t_info;

// *************************** STACK MANIPULATION *************************** //

void	swap_stack(t_stack **stack, char list);
/**
 * This function swaps the top two elements of the stack.
 *
 * @param stack - a pointer to a t_stack structure.
 * @param list - a character representing the stack.
 */

void	swap_both(t_stack **a, t_stack **b);
/**
 * This function swaps the top two elements of both stacks.
 *
 * @param a - a pointer to a t_stack structure.
 * @param b - a pointer to a t_stack structure.
 */

void	push_stack(t_stack **from, t_stack **to, char list);
/**
 * This function takes the first element at the top of 'from' and puts it at the top of 'to'.
 *
 * @param from - a pointer to a t_stack structure.
 * @param to - a pointer to a t_stack structure.
 * @param list - a character representing the stack.
 */

void	rotate_stack(t_stack **stack, char list);
/**
 * This function shifts up all elements of the stack by 1.
 * The first element becomes the last one.
 *
 * @param stack - a pointer to a t_stack structure.
 * @param list - a character representing the stack.
 */

void	rotate_both(t_stack **a, t_stack **b);
/**
 * This function shifts up all elements of both stacks by 1.
 *
 * @param a - a pointer to a t_stack structure.
 * @param b - a pointer to a t_stack structure.
 */

void	reverse_stack(t_stack **stack, char list);
/**
 * This function shifts down all elements of the stack by 1.
 * The last element becomes the first one.
 *
 * @param stack - a pointer to a t_stack structure.
 * @param list - a character representing the stack.
 */

void	reverse_both(t_stack **a, t_stack **b);
/**
 * This function shifts down all elements of both stacks by 1.
 *
 * @param a - a pointer to a t_stack structure.
 * @param b - a pointer to a t_stack structure.
 */

// *************************** STACK INFORMATION *************************** //

int		get_min(t_stack *stack);
/**
 * Finds the minimum value in the stack.
 *
 * @param stack A pointer to the first element of the stack.
 * 
 * @return The minimum value in the stack.
 */

int		get_max(t_stack *stack);
/**
 * Finds the maximum value in the stack.
 *
 * @param stack A pointer to the first element of the stack.
 * 
 * @return The maximum value in the stack.
 */

int		stack_len(t_stack *stack);
/**
 * Returns the length of the stack.
 *
 * @param stack A pointer to the first element of the stack.
 * 
 * @return The length of the stack.
 */

int		check_sort_list(t_stack *stack);
/**
 * This function checks if the stack is sorted.
 *
 * @param stack - a pointer to a t_stack structure.
 *
 * @return 1 if the stack is sorted, 0 otherwise.
 */

// **************************** INPUT VALIDATION **************************** //

void	ft_check_args(int argc, char **argv, t_stack *stack);
/**
 * @brief Validates the command line arguments and checks for errors.
 * 
 * @param argc The number of command line arguments.
 * @param argv An array of strings containing the command line arguments.
 * @param stack A pointer to the stack structure.
 */

int		ft_dup_check(char **argv);
/**
 * This function checks if there are duplicates.
 *
 * @param argv - an array of strings representing the command line arguments.
 * 
 * @return 1 if there are no duplicates, 0 otherwise.
 */

int		ft_isnum(char **num);
/**
 * This function checks if the arguments are numbers.
 *
 * @param num - an array of strings representing the command line arguments.
 * 
 * @return 1 if the arguments are numbers, 0 otherwise.
 */

int		ft_max_min_int_number(char **argv);
/**
 * This function checks if the arguments are numbers.
 *
 * @param argv - an array of strings representing the command line arguments.
 * 
 * @return 1 if the arguments are numbers, 0 otherwise.
 */

// *************************** SORTING FUNCTIONS *************************** //

void	sort(t_stack **a, t_stack **b);
/**
 * @brief Sorts the given stack using various sorting algorithms based on the stack length.
 * 
 * @param a Pointer to the first stack.
 * @param b Pointer to the second stack.
 */

void	sort_two(t_stack **a);
/**
 * Sorts a stack of two elements in ascending order.
 *
 * @param a The stack to be sorted.
 */

void	sort_three(t_stack **a);
/**
 * Sorts a stack of three elements in ascending order.
 *
 * @param a - a pointer to a t_stack structure.
 */

void	sort_four(t_stack **a, t_stack **b);
/**
 * Sorts a stack of four elements in ascending order.
 *
 * @param a - a pointer to a t_stack structure.
 * @param b - a pointer to a t_stack structure.
 */

void	sort_five(t_stack **a, t_stack **b);
/**
 * Sorts a stack of five elements in ascending order.
 *
 * @param a - a pointer to a t_stack structure.
 * @param b - a pointer to a t_stack structure.
 */

void	sort_more(t_stack **a, t_stack **b);
/**
 * Sorts a stack of more than five elements in ascending order.
 *
 * @param a - Pointer to the first stack.
 * @param b - Pointer to the second stack.
 */

void	push_min_b(t_stack **a, t_stack **b, int size);
/**
 * Pushes the minimum value from stack A to stack B.
 * 
 * @param a     Pointer to the stack A.
 * @param b     Pointer to the stack B.
 * @param size  The size of the stack A.
 */

void	push_max_b(t_stack **a, t_stack **b, int size);
/**
 * Pushes the maximum value from stack A to stack B.
 * 
 * @param a     Pointer to the top of stack A.
 * @param b     Pointer to the top of stack B.
 * @param size  The size of stack A.
 */

void	sort_numbers(t_stack **a, t_stack **b, t_info nbr2sort, t_info target);
/**
 * Sorts the numbers in the stacks 'a' and 'b' based on the given parameters.
 * 
 * @param a         Pointer to the stack 'a'.
 * @param b         Pointer to the stack 'b'.
 * @param nbr2sort  Information about the number to be sorted.
 * @param target    Information about the target number.
 */

void	put_all_a(t_stack **a, t_stack **b);
/**
 * @brief Puts all elements from stack B to stack A based on their values.
 * 
 * This function iterates through stack B and checks the value of each element.
 * If the element is greater than the maximum value in stack A or less than the minimum value in stack A,
 * it is pushed to stack A using the push_min_b() function.
 * If the element is between the maximum and minimum values in stack A,
 * it is pushed to stack A using the push_max_b() function.
 * 
 * @param a Pointer to the stack A.
 * @param b Pointer to the stack B.
 */

void	ab_top(t_stack **a, t_stack **b, t_info nbr2sort, t_info target);
/**
 * This function continuously moves the top elements of stacks 'a' and 'b' until the desired values,
 * specified by 'nbr2sort' and 'target', are at the top of their respective stacks.
 * 
 * @param a Pointer to the stack 'a'.
 * @param b Pointer to the stack 'b'.
 * @param nbr2sort Information about the value to be sorted in stack 'a'.
 * @param target Information about the target value in stack 'b'.
 */

void	b_top(t_stack **b, t_info target);
/**
 * Moves the top element of stack 'b' to the correct position.
 * 
 * @param b         Pointer to the stack 'b'.
 * @param target    Information about the target number.
 */

void	a_top(t_stack **a, t_info nbr2sort);
/**
 * Moves the top element of stack 'a' to the correct position.
 * 
 * @param a         Pointer to the stack 'a'.
 * @param nbr2sort  Information about the number to be sorted.
 */

// ************************* MOVEMENT CALCULATIONS ************************* //

t_info	a_nbr2move(t_stack *a, t_stack *b, t_info info_a);
/**
 * Finds the number in stack A that requires the fewest movements to be sorted.
 * 
 * @param a         The stack A.
 * @param b         The stack B.
 * @param info_a    The information about stack A.
 * 
 * @return          The information about the number to move and the number of movements.
 */

t_info	b_target(t_stack *b, int data_a);
/**
 * Finds the target element in stack B based on the given data from stack A.
 *
 * @param b The stack B.
 * @param data_a The data from stack A.
 * 
 * @return The target element in stack B and the number of movements required to reach it.
 */

int		calc(int a, int b);
/**
 * Returns the larger of two integers.
 *
 * @param a: The first integer.
 * @param b: The second integer.
 *
 * @return: The larger of the two integers.
 */

int		mv_calcs(t_info info_a, t_info info_b);
/**
 * Calculates the number of movements required to sort the data in two stacks.
 *
 * @param info_a: A structure containing information about the first stack, including the number of movements and the size of the stack.
 * @param info_b: A structure containing information about the second stack, including the number of movements and the size of the stack.
 *
 * @return: The number of movements required to sort the data in the stacks.
 */

int		mv_calcs2(t_info info_a, t_info info_b);
/**
 * Calculates the number of movements needed to reach a target position in a stack.
 *
 * @param info_a: A structure containing information about the first stack, including the number of movements and the size of the stack.
 * @param info_b: A structure containing information about the second stack, including the number of movements and the size of the stack.
 *
 * @return: The number of movements needed to reach the target position in the stack.
 */

int		get_index(t_stack *stack, int target);
/**
 * Returns the index of the first occurrence of the target value in the stack.
 *
 * @param stack The stack to search in.
 * @param target The value to search for.
 * 
 * @return The index of the target value in the stack, or -1 if not found.
 */

int		out_min_max(t_stack *b, t_info info_a);
/**
 * Calculates the number of movements required to move the maximum element of stack B to stack A.
 * 
 * @param b The stack B.
 * @param info_a Information about stack A.
 * 
 * @return The number of movements required.
 */

int		in_min_max(t_stack *b, int data_a, t_info info_a);
/**
 * Calculates the minimum and maximum values in stack B and determines the target value.
 * 
 * @param b The stack B.
 * @param data_a The data value from stack A.
 * @param info_a The information about stack A.
 * 
 * @return The result of the movement calculations.
 */

bool	four_index(t_stack **a, t_stack **b, int index);
/**
 * Moves the elements in the stack based on the given index.
 * 
 * @param a The first stack.
 * @param b The second stack.
 * @param index The index indicating the position of the minimum value in the stack.
 * 
 * @return Returns EXIT_SUCCESS if the stack is sorted after the move, otherwise returns EXIT_FAILURE.
 */

bool	five_index(t_stack **a, t_stack **b, int index);
/**
 * Moves the elements in the stack to achieve a specific arrangement when the lenght of the stack is 5.
 * 
 * @param a The first stack.
 * @param b The second stack.
 * @param index The index indicating the position of the minimum value in the stack.
 * 
 * @return Returns EXIT_SUCCESS if the stack is sorted after the moves, otherwise returns EXIT_FAILURE.
 */

int		get_min_index(t_stack **stack);
/**
 * This function returns the index of the minimum value in stack 'a'.
 *
 * @param stack - Pointer to the first stack.
 * 
 * @return The index of the minimum value in stack 'a'.
 */

void	rotating_a(t_stack **a);
/**
 * Rotates the stack 'a' until the element with the minimum value is at the top.
 * 
 * @param a The stack to rotate.
 */

// ************************** AUXILIARY FUNCTIONS ************************** //
void	print_stack(t_stack *stack);
/**
 * This function prints the content of a stack.
 *
 * @param stack - a pointer to a t_stack structure.
 */

void	error(void);
/**
 * This function prints "Error" and exits the program.
 */

// **************************** STACK MANAGEMENT **************************** //
void	ft_free_stack(t_stack **stack);
/**
 * This function frees the memory allocated for a stack.
 *
 * @param stack - a pointer to a t_stack structure.
 */

void	create_stack(t_stack **stack, int content);
/**
 * This function creates a stack.
 *
 * @param stack - a pointer to a t_stack structure.
 * @param content - an integer representing the content of the stack.
 */

void	ft_add_next(t_stack **stack, int content);
/**
 * This function adds a new node to the stack.
 *
 * @param stack - a pointer to a t_stack structure.
 * @param content - an integer representing the content of the stack.
 */

#endif
