/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:57:51 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/17 22:07:10 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void create_stack(t_stack **stack, int content) // Create a new stack
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		error();
	new->content = content;
	new->next = *stack;
	*stack = new;
}

void ft_add_next(t_stack **stack, int content) // Add a new element to the end of the stack
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

void ft_free_stack(t_stack **stack) // Free the stack
{
	t_stack *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void error(void) // Print "Error" and exit the program
{
	ft_printf("Error\n");
	exit(0);
}

int get_min(t_stack *stack) // Get the minimum value of the stack
{
	int min = stack->content; // Set the minimum value to the first element of the stack

	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}
