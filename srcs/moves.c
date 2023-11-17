/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:23:44 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/12 22:21:18 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_stack(t_stack **stack, char list)
{
	int temp;

	if (!*stack || !(*stack)->next)
		return;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	if (list == 'a')
		ft_printf("sa\n");
	else if (list == 'b')
		ft_printf("sb\n");
}

void swap_both(t_stack **a, t_stack **b)
{
	swap_stack(a, ' ');
	swap_stack(b, ' ');
	ft_printf("ss\n");
}

void push_stack(t_stack **from, t_stack **to, char list)
{
	t_stack *temp;

	if (!*from && !*to)
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
void rotate_stack(t_stack **stack, char list)
{
	t_stack *temp;
	t_stack *last;

	if (!*stack || !(*stack)->next)
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

void rotate_both(t_stack **a, t_stack **b)
{
	rotate_stack(a, ' ');
	rotate_stack(b, ' ');
	ft_printf("rr\n");
}
