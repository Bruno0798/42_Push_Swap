/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:23:44 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/19 21:10:26 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_stack(t_stack **stack, char list) // Swap the top two elements of a stack
{
	int temp;

	if (!*stack || !(*stack)->next) // If the stack is empty or has only one element, do nothing
		return;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	if (list == 'a')
		ft_printf("sa\n");
	else if (list == 'b')
		ft_printf("sb\n");
}

void swap_both(t_stack **a, t_stack **b) // Swap the top two elements of both stacks
{
	swap_stack(a, ' ');
	swap_stack(b, ' ');
	ft_printf("ss\n");
}

void push_stack(t_stack **from, t_stack **to, char list) // Take the first element at the top of 'from' and put it at the top of 'to'
{
	t_stack *temp;

	if (!*from && !to) // If both stacks are empty, do nothing
		return;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	if (list == 'a')
		ft_printf("pa\n");
	else if (list == 'b')
		ft_printf("pb\n");
}
void rotate_stack(t_stack **stack, char list) // Shift up all elements of a stack by 1
{
	t_stack *temp;
	t_stack *last;

	if (!*stack || !(*stack)->next) // If the stack is empty or has only one element, do nothing
		return;
	temp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (list == 'a')
		ft_printf("ra\n");
	else if (list == 'b')
		ft_printf("rb\n");
}

void rotate_both(t_stack **a, t_stack **b) // Shift up all elements of both stacks by 1
{
	rotate_stack(a, ' ');
	rotate_stack(b, ' ');
	ft_printf("rr\n");
}
