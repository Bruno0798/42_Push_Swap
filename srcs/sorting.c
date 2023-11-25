/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:32:14 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/25 15:36:44 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort(t_stack **a, t_stack **b)
{
	int len;

	if (check_sort_list(*a))
		return;
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
	int	min = get_min(*a);
	int	max = get_max(*a);

	if (check_sort_list(*a))
		return ;
	if ((*a)->content != max && (*a)->next->content == min) // 2 1 3
		swap_stack(a, 'a');
	else if ((*a)->content == max && (*a)->next->content != min) // 3 2 1
	{
		swap_stack(a, 'a');
		reverse_stack(a, 'a');
	}
	else if ((*a)->content == max && (*a)->next->content == min) // 3 1 2
		rotate_stack(a, 'a');
	else if ((*a)->content == min && (*a)->next->content == max) // 1 3 2
	{
		swap_stack(a, 'a');
		rotate_stack(a, 'a');
	}
	else // 2 3 1
		reverse_stack(a, 'a');
}

void	sort_four(t_stack **a, t_stack **b)
{
	if(!four_index(a, b, get_min_index(a))) 
		return ;
	sort_three(a);
	push_stack(b, a, 'a'); 
}

void	sort_five(t_stack **a, t_stack **b)
{
	five_index(a, b, get_min_index(a));
	if (check_sort_list(*a))
		return ;
	if(four_index(a, b, get_min_index(a)))
	{
	sort_three(a);
	push_stack(b, a, 'a');
	push_stack(b, a, 'a');
	} else
	push_stack(b, a ,'a');
}
