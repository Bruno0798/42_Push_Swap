/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:34:39 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/17 22:05:12 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void reverse_stack(t_stack **stack, char list) // Shift down all elements of a stack by 1
{
	t_stack *temp;
	t_stack *last;

	if (!*stack || !(*stack)->next) // If the stack is empty or has only one element, do nothing
		return;
	temp = *stack;
	while (temp->next)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	temp->next = *stack;
	*stack = temp;
	if (list == 'a')
		ft_printf("rra\n");
	else if (list == 'b')
		ft_printf("rrb\n");
}

void reverse_both(t_stack **a, t_stack **b) // Shift down all elements of both stacks by 1
{
	reverse_stack(a, ' ');
	reverse_stack(b, ' ');
	ft_printf("rrr\n");
}

void free_list(t_stack **stack) // Free the stack
{
	t_stack *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
