/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculations3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:45:13 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/25 17:29:48 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_index(t_stack **stack)
{
	t_stack	*temp;
	int		index;
	int		min;

	temp = *stack;
	index = 0;
	min = get_min(*stack);
	while (temp->content != min)
	{
		temp = temp->next;
		index++;
	}
	return (index);
}

/**
 * Rotates the stack 'a' until the element with the minimum value is at the top.
 * 
 * @param a The stack to rotate.
 */
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
