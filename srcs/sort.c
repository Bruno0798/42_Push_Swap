/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:37:56 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/17 18:16:52 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void sort_two(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
	{
		// If the top element is greater than the second element
		swap_stack(a, 'a'); // Swap the top two elements
	}
}

void sort_three(t_stack **a)
{
	int min = get_min(*a); // Find the minimum value in stack 'a'
	int max = get_max(*a); // Find the maximum value in stack 'a'

	// Check if the list is already sorted
	// If it is, do nothing
	if (check_sort_list(*a))
		return;

	// If the top element is not the max and the second element is the min
	// Swap the top two elements
	if ((*a)->content != max && (*a)->next->content == min) // 2 1 3
		swap_stack(a, 'a');

	// If the top element is the max and the second element is not the min
	// Swap the top two elements and reverse the stack
	else if ((*a)->content == max && (*a)->next->content != min) // 3 2 1
	{
		swap_stack(a, 'a');
		reverse_stack(a, 'a');
	}
	// If the top element is the max and the second element is the min
	// Reverse the stack
	else if ((*a)->content == max && (*a)->next->content == min) // 3 1 2
		rotate_stack(a, 'a');

	// If the top element is the min and the second element is the max
	// Swap the top two elements
	else if ((*a)->content == min && (*a)->next->content == max) // 1 3 2
	{
		swap_stack(a, 'a');
		rotate_stack(a, 'a');
	}

	// If the top element is not the min and the second element is not the max
	// Swap the top two elements and reverse the stack
	else
		reverse_stack(a, 'a');
}

void sort_four(t_stack **a, t_stack **b)
{
	int min = get_min(*a); // Find the minimum value in stack 'a'

	// Rotate stack 'a' until the top element is equal to 'min'
	while ((*a)->content != min)
		rotate_stack(a, 'a');

	push_stack(a, b, 'b'); // Push the top element of stack 'a' to stack 'b'
	sort_three(a);		   // Sort the remaining three elements in stack 'a'
	push_stack(b, a, 'a'); // Push the top element of stack 'b' back to stack 'a'
}

void sort_five(t_stack **a, t_stack **b)
{
	int min = get_min(*a); // Find the minimum value in stack 'a'

	while ((*a)->content != min) // Rotate stack 'a' until the top element is equal to the minimum value
		rotate_stack(a, 'a');

	push_stack(a, b, 'b'); // Push the top element of stack 'a' to stack 'b'
	sort_four(a, b);	   // Sort the remaining four elements in stack 'a'
	push_stack(b, a, 'a'); // Push the top element of stack 'b' back to stack 'a'
}

void sort(t_stack **a, t_stack **b)
{
	int len = stack_len(*a); // Get the length of stack 'a'

	// If len is equal to 2, sort the stack with two elements
	if (len == 2)
		sort_two(a); // Sort the stack with two elements

	// If len is equal to 3, sort the stack with three elements
	else if (len == 3)
		sort_three(a); // Sort the stack with three elements

	// If len is equal to 4, sort the stack with four elements
	else if (len == 4)
		sort_four(a, b); // Sort the stack with four elements

	// If len is equal to 5, sort the stack with five elements
	else if (len == 5)
		sort_five(a, b); // Sort the stack with five elements

	/* 	else
			sort_more(a, b); */
}
