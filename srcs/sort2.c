/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:01:27 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/19 13:27:58 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool four_index(t_stack **a, t_stack **b, int index) // Index is the position of the minimum value in stack 'a'
{
	if (index == 0)
		push_stack(a, b, 'b'); // Push the minimum value to stack 'b'
	if (index == 1)
	{
		rotate_stack(a, 'a');	   // Rotate the stack
		if (check_sort_list(*a))   // Check if the stack is sorted
			return (EXIT_SUCCESS); // If it is, return
		push_stack(a, b, 'b');	   // Push the minimum value to stack 'b'
	}
	if (index == 2)
	{
		rotate_stack(a, 'a');	   // Rotate the stack
		rotate_stack(a, 'a');	   // Rotate the stack
		if (check_sort_list(*a))   // Check if the stack is sorted
			return (EXIT_SUCCESS); // If it is, return
		push_stack(a, b, 'b');	   // Push the minimum value to stack 'b'
	}
	if (index == 3)
	{
		reverse_stack(a, 'a');	   // Reverse the stack
		if (check_sort_list(*a))   // Check if the stack is sorted
			return (EXIT_SUCCESS); // If it is, return
		push_stack(a, b, 'b');	   // Push the minimum value to stack 'b'
	}
	return (EXIT_FAILURE); // If the stack is not sorted, return
}

bool five_index(t_stack **a, t_stack **b, int index) // Index is the position of the minimum value in stack 'a'
{
	if (index <= 2)
		four_index(a, b, index); // If the minimum value is in the first half of the stack, use the four_index function
	if (index == 3)
	{
		reverse_stack(a, 'a');	   // Reverse the stack
		reverse_stack(a, 'a');	   // Reverse the stack
		if (check_sort_list(*a))   // Check if the stack is sorted
			return (EXIT_SUCCESS); // If it is, return
		push_stack(a, b, 'b');	   // Push the minimum value to stack 'b'
	}
	if (index == 4)
	{
		reverse_stack(a, 'a');	   // Reverse the stack
		if (check_sort_list(*a))   // Check if the stack is sorted
			return (EXIT_SUCCESS); // If it is, return
		push_stack(a, b, 'b');	   // Push the minimum value to stack 'b'
	}
	return (EXIT_FAILURE); // If the stack is not sorted, return
}

/* void sort_more(t_stack **a, t_stack **b)
{
	t_info inf_a;	 // Create a struct to store information about stack 'a'
	t_info nbr2sort; // Create a struct to store information about the numbers to sort
	t_info target;	 // Create a struct to store information about the target numbers

	if (check_sort_list(*a))	// Check if the stack is sorted
		return;					// If it is, return
	push_stack(a, b, 'b');		// Push the first element of stack 'a' to stack 'b'
	push_stack(a, b, 'b');		// Push the second element of stack 'a' to stack 'b'
	inf_a.size = stack_len(*a); // Get the length of stack 'a'
	while (inf_a.size > 3)
	{
		nbr2sort = get_nbr2sort(*a); // Get the numbers to sort
	}
} */