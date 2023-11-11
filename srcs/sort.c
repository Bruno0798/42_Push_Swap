/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:37:56 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/10 22:43:18 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_stack **a, t_stack **b)
{
	int len;

	len = stack_len(*a);
	if (len == 2)
		sort_two(a);
	else if (len == 3)
		sort_three(a);
	else if (len == 4)
		sort_four(a, b);
	else if (len == 5)
		sort_five(a, b);
	else
		sort_more(a, b);
}

void sort_two(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
		swap_stack(a, 'a');
}

void sort_three(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
	{
		if ((*a)->content > (*a)->next->next->content)
		{
			if ((*a)->next->content > (*a)->next->next->content)
			{
				swap_stack(a, 'a');
				reverse_stack(a, 'a');
			}
			else
				reverse_stack(a, 'a');
		}
		else
			swap_stack(a, 'a');
	}
	else if ((*a)->content > (*a)->next->next->content)
	{
		if ((*a)->next->content > (*a)->next->next->content)
			swap_stack(a, 'a');
		else
			reverse_stack(a, 'a');
	}
}

void sort_four(t_stack **a, t_stack **b)
{
	int min;
	int max;

	min = get_min(*a);
	max = get_max(*a);
	while ((*a)->content != min && (*a)->content != max)
		rotate_stack(a, 'a');
	if ((*a)->content == min)
		push_stack(a, b, 'b');
	sort_three(a);
	push_stack(b, a, 'a');
}

void sort_five(t_stack **a, t_stack **b)
{
	int min;
	int max;

	min = get_min(*a);
	max = get_max(*a);
	while ((*a)->content != min && (*a)->content != max)
		rotate_stack(a, 'a');
	if ((*a)->content == min)
		push_stack(a, b, 'b');
	sort_four(a, b);
	push_stack(b, a, 'a');
}
