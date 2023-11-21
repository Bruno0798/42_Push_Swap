/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:08:15 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/20 21:32:39 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotating_a(t_stack **a)
{
	int size;
	int position;

	position = get_index(*a, get_min(*a));
	size = stack_len(*a);
	while ((*a)->content != get_min(*a))
	{
		if (position > size / 2)
			reverse_stack(a, 'a');
		else
			rotate_stack(a, 'a');
	}
}

void a_top(t_stack **a, t_info nbr2sort)
{
	while ((*a)->content != nbr2sort.data)
	{
		if (nbr2sort.movements > nbr2sort.size / 2)
			reverse_stack(a, 'a');
		else
			rotate_stack(a, 'a');
	}
}

void b_top(t_stack **b, t_info target)
{
	while ((*b)->content != target.data)
	{
		if (target.movements > target.size / 2)
			reverse_stack(b, 'b');
		else
			rotate_stack(b, 'b');
	}
}

void ab_top(t_stack **a, t_stack **b, t_info nbr2sort, t_info target)
{
	while ((*a)->content != nbr2sort.data && (*b)->content != target.data)
	{
		if (nbr2sort.movements > nbr2sort.size / 2 && target.movements > target.size / 2)
			reverse_both(a, b);
		else if (nbr2sort.movements < nbr2sort.size / 2 && target.movements > target.size / 2)
			rotate_stack(a, 'a');
		else if (target.movements < target.size / 2 && nbr2sort.movements > nbr2sort.size / 2)
			rotate_stack(b, 'b');
		else
			rotate_both(a, b);
	}
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

void sort_out_min_max(t_stack **a, t_stack **b, int size)
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

void sort_in_min_max(t_stack **a, t_stack **b, int size)
{
	t_stack *temp_a;
	int position;
	int target;

	target = get_max(*a);
	temp_a = *a;
	while (temp_a != NULL)
	{
		if (target > temp_a->content && temp_a->content > (*b)->content)
			target = temp_a->content;
		temp_a = temp_a->next;
	}
	position = get_index(*a, target);
	while ((*a)->content != target)
	{
		if (position > size / 2)
			reverse_stack(a, 'a');
		else
			rotate_stack(a, 'a');
	}
	push_stack(b, a, 'a');
}

void put_all_a(t_stack **a, t_stack **b)
{
	int size;

	while (*b != NULL)
	{
		size = stack_len(*b);
		if ((*b)->content > get_max(*a) || (*b)->content < get_min(*a))
			sort_out_min_max(a, b, size);
		else if ((*b)->content < get_max(*a) && (*b)->content > get_min(*a))
			sort_in_min_max(a, b, size);
	}
}

t_info b_target(t_stack *b, int data_a) // Finds the number to move from stack 'a' to stack 'b'
{
	t_stack *temp_b = b;
	t_info target;

	if (data_a > get_max(b) || data_a < get_min(b)) // If the number is greater than the maximum or less than the minimum, move it to the top of the stack
	{
		target.data = get_max(b);
		target.movements = get_index(b, target.data);
		return (target);
	}
	else // If the number is between the maximum and the minimum, move it to the top of the stack
		target.data = get_min(b);
	while (temp_b != NULL)
	{
		if (data_a > temp_b->content) // If the number is greater than the current number in the stack, move it to the top of the stack
		{
			if (target.data < temp_b->content) // If the current number is greater than the previous number, update the target
				target.data = temp_b->content;
		}
		temp_b = temp_b->next;
	}
	target.movements = get_index(b, target.data); // Get the number of movements to move the number to the top of the stack
	return target;
}

int calc(int a, int b) // Calculates the cheapest number of movements
{
	if (a > b)
		return (a);
	return (b);
}

int mv_calcs2(t_info info_a, t_info info_b) // Calculates the cheapest number of movements
{
	int nbr_m = 0;

	if (info_a.movements >= info_a.size / 2)
		nbr_m = info_a.size - info_a.movements;
	else if (info_b.movements >= info_b.size / 2)
		nbr_m = info_b.size - info_b.movements;
	else
		nbr_m = calc(info_b.movements, info_a.movements);
	return (nbr_m);
}

int mv_calcs(t_info info_a, t_info info_b) // Calculates the cheapest number of movements
{
	int nbr_m = 0;

	if (info_a.movements > 0 && info_b.movements > 0) // If both numbers are greater than 0, calculate the cheapest number of movements
	{
		if (info_a.movements >= info_a.size / 2 && info_b.movements >= info_b.size / 2) // If both numbers are greater than half of the stack, calculate the cheapest number of movements
			nbr_m = calc(info_b.size - info_b.movements, info_a.size - info_a.movements);
		else if (info_a.movements > info_a.size / 2 && info_b.movements < info_b.size / 2) // If one number is greater than half of the stack and the other is less than half of the stack, calculate the cheapest number of movements
			nbr_m = (info_a.size - info_a.movements) + info_b.movements;
		else if (info_b.movements > info_b.size / 2 && info_a.movements < info_a.size / 2) // If one number is greater than half of the stack and the other is less than half of the stack, calculate the cheapest number of movements
			nbr_m = (info_b.size - info_b.movements) + info_a.movements;
		else
			nbr_m = calc(info_b.movements, info_a.movements);
	}
	else
		nbr_m = mv_calcs2(info_a, info_b); // If one number is 0, calculate the cheapest number of movements
	return (++nbr_m);
}

int get_index(t_stack *stack, int target) // Get the number of movements to move the number to the top of the stack
{
	int index = 0;

	while (stack->content != target)
	{
		stack = stack->next;
		index++;
	}
	return index;
}
int out_min_max(t_stack *b, t_info info_a)
{
	t_info info_b;
	int target;

	target = get_max(b);
	info_b.size = stack_len(b);
	info_b.movements = get_index(b, target);
	return (mv_calcs(info_a, info_b));
}

int in_min_max(t_stack *b, int data_a, t_info info_a)
{
	t_stack *temp_b;
	t_info info_b;
	int target;

	temp_b = b;
	target = get_min(b);
	info_b.size = stack_len(b);
	while (temp_b != NULL)
	{
		if (data_a > temp_b->content)
		{
			if (target < temp_b->content)
				target = temp_b->content;
		}
		temp_b = temp_b->next;
	}
	info_b.movements = get_index(b, target);
	return (mv_calcs(info_a, info_b));
}

t_info a_nbr2move(t_stack *a, t_stack *b, t_info info_a) // Find the number to move from stack 'a' to stack 'b'
{
	t_stack *temp_a; // Temporary stack 'a'
	t_info nbr2move; // Number to move from stack 'a' to stack 'b'
	int moves;		 // Number of movements to move the number to the top of the stack
	int cheaper_nbr; // Cheapest number of movements

	cheaper_nbr = 0;
	temp_a = a;
	info_a.movements = 0;
	while (temp_a != NULL)
	{
		if (temp_a->content > get_max(b) || temp_a->content < get_min(b))
			moves = out_min_max(b, info_a);
		else if (temp_a->content < get_max(b) && temp_a->content > get_min(b))
			moves = in_min_max(b, temp_a->content, info_a);
		if (cheaper_nbr > moves || info_a.movements == 0)
		{
			cheaper_nbr = moves;
			nbr2move.movements = info_a.movements;
			nbr2move.data = temp_a->content;
		}
		info_a.movements++;
		temp_a = temp_a->next;
	}
	return (nbr2move);
}

void sort_more(t_stack **a, t_stack **b) // Sort more than 5 numbers
{
	t_info info_a;	 // Information about stack 'a'
	t_info nbr2sort; // Number to move from stack 'a' to stack 'b'
	t_info target;	 // Number to move from stack 'b' to stack 'a'

	if (check_sort_list(*a))
		return;
	push_stack(a, b, 'b');		 // Move the first number from stack 'a' to stack 'b'
	push_stack(a, b, 'b');		 // Move the second number from stack 'a' to stack 'b'
	info_a.size = stack_len(*a); // Get the size of stack 'a'
	while (info_a.size > 3)		 // While the size of stack 'a' is greater than 3
	{
		nbr2sort = a_nbr2move(*a, *b, info_a); // Find the number to move from stack 'a' to stack 'b'
		nbr2sort.size = stack_len(*a);		   // Get the size of stack 'a'
		target = b_target(*b, nbr2sort.data);  // Find the number to move from stack 'b' to stack 'a'
		target.size = stack_len(*b);		   // Get the size of stack 'b'
		sort_numbers(a, b, nbr2sort, target);  // Move the numbers to the top of the stacks
		info_a.size = stack_len(*a);		   // Get the size of stack 'a'
	}
	sort_three(a);
	put_all_a(a, b);
	rotating_a(a);
}
