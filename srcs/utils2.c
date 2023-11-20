/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:10:17 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/20 10:07:46 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int get_max(t_stack *stack) // Find the maximum value in stack 'a'
{
	int max = stack->content;

	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int stack_len(t_stack *stack) // Find the length of the stack
{
	int len = 0;

	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void print_stack(t_stack *stack) // Print the stack
{
	while (stack)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
}

int check_sort_list(t_stack *stack) // Check if the stack is sorted
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int get_min_index(t_stack **stack) // Find the minimum value in stack 'a'
{
	t_stack *temp = *stack;
	int index = 0;
	int min = get_min(*stack);

	while (temp->content != min)
	{
		temp = temp->next;
		index++;
	}
	return (index);
}
