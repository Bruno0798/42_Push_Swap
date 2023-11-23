/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:10:54 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/23 14:18:08 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	create_stack(t_stack **stack, int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!(new))
		error();
	new->content = content;
	new->next = *stack;
	*stack = new;
}

void	ft_add_next(t_stack **stack, int content)
{
	t_stack	*new;
	t_stack	*temp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!(new))
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
