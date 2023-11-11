/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:57:51 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/11 01:37:33 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void create_stack(t_stack **stack, int content)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		error();
	new->content = content;
	new->next = *stack;
	*stack = new;
}