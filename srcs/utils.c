/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:57:51 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/12 16:11:22 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void create_stack(t_stack **stack, int content)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		error();
	new->content = content;
	new->next = *stack;
	*stack = new;
}

void ft_add_next(t_stack **stack, int content)
{
	t_stack *new;
	t_stack *temp;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		error();
	new->content = content;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void ft_free_stack(t_stack **stack)
{
	t_stack *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void error(void)
{
	ft_printf("Error\n");
	exit(0);
}

int get_min(t_stack *stack)
{
	int min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}
