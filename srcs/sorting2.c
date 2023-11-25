/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:33:43 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/25 16:45:32 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_more(t_stack **a, t_stack **b)
{
	t_info	info_a;
	t_info	nbr2sort;
	t_info	target;

	if (check_sort_list(*a))
		return ;
	push_stack(a, b, 'b');
	push_stack(a, b, 'b');
	info_a.size = stack_len(*a);
	while (info_a.size > 3)
	{
		nbr2sort = a_nbr2move(*a, *b, info_a);
		nbr2sort.size = stack_len(*a);
		target = b_target(*b, nbr2sort.data);
		target.size = stack_len(*b);
		sort_numbers(a, b, nbr2sort, target);
		info_a.size = stack_len(*a);
	}
	sort_three(a);
	put_all_a(a, b);
	rotating_a(a);
}

void push_min_b(t_stack **a, t_stack **b, int size)
{
	int position;

	position = get_index(*a, get_min(*a));
	while ((*a)->content != get_min(*a))
	{
		if (position > size / 2)
			reverse_stack(a, 'a');
		else
			rotate_stack(a, 'a');
	}
	push_stack(b, a, 'a');
}

void push_max_b(t_stack **a, t_stack **b, int size)
{
	// Find the maximum value in stack A
	int target = get_max(*a);
	
	// Iterate through stack A to find a value greater than the top of stack B
	t_stack *temp_a = *a;
	while (temp_a != NULL)
	{
		if (target > temp_a->content && temp_a->content > (*b)->content) // If the value is greater than the top of stack B
			target = temp_a->content;
		temp_a = temp_a->next;
	}
	
	// Get the position of the target value in stack A
	int position = get_index(*a, target);
	
	// Move the target value to the top of stack A
	while ((*a)->content != target)
	{
		if (position > size / 2) // If the target value is in the second half of stack A
			reverse_stack(a, 'a');
		else
			rotate_stack(a, 'a');
	}
	
	// Push the target value from stack A to stack B
	push_stack(b, a, 'a');
}

void sort_numbers(t_stack **a, t_stack **b, t_info nbr2sort, t_info target)
{
	ab_top(a, b, nbr2sort, target); 
	if ((*a)->content == nbr2sort.data && (*b)->content != target.data)
		b_top(b, target);
	else if ((*b)->content == target.data && (*a)->content != nbr2sort.data)
		a_top(a, nbr2sort);
	push_stack(a, b, 'b');
}

void put_all_a(t_stack **a, t_stack **b)
{
	int size;

	while (*b != NULL)
	{
		size = stack_len(*b);
		if ((*b)->content > get_max(*a) || (*b)->content < get_min(*a))
			push_min_b(a, b, size);
		else if ((*b)->content < get_max(*a) && (*b)->content > get_min(*a))
			push_max_b(a, b, size);
	}
}
