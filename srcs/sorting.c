/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:32:14 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/23 15:05:11 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	int	len;

	if (check_sort_list(*a))
		exit(1);
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

void	sort_two(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
		swap_stack(a, 'a');
}

void	sort_three(t_stack **a)
{
	int	min;
	int	max;

	min = get_min(*a);
	max = get_max(*a);
	if (check_sort_list(*a))
		return ;
	if ((*a)->content != max && (*a)->next->content == min)
		swap_stack(a, 'a');
	else if ((*a)->content == max && (*a)->next->content != min)
	{
		swap_stack(a, 'a');
		reverse_stack(a, 'a');
	}
	else if ((*a)->content == max && (*a)->next->content == min)
		rotate_stack(a, 'a');
	else if ((*a)->content == min && (*a)->next->content == max)
	{
		swap_stack(a, 'a');
		rotate_stack(a, 'a');
	}
	else
		reverse_stack(a, 'a');
}

void	sort_four(t_stack **a, t_stack **b)
{
	if (check_sort_list(*a))
		return ;
	four_index(a, b, get_min_index(a));
	sort_three(a);
	push_stack(a, b, 'b');
}

void	sort_five(t_stack **a, t_stack **b)
{
	if (check_sort_list(*a))
		return ;
	five_index(a, b, get_min_index(a));

	if (check_sort_list(*a))
		return ;
	four_index(a, b, get_min_index(a));
	sort_three(a);
	push_stack(b, a, 'a');
	push_stack(b, a, 'a');
}