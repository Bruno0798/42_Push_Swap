/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:24:49 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/25 15:53:07 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	a_top(t_stack **a, t_info nbr2sort)
{
	while ((*a)->content != nbr2sort.data)
	{
		if (nbr2sort.movements > nbr2sort.size / 2)
			reverse_stack(a, 'a');
		else
			rotate_stack(a, 'a');
	}
}

void	b_top(t_stack **b, t_info target)
{
	while ((*b)->content != target.data)
	{
		if (target.movements > target.size / 2)
			reverse_stack(b, 'b');
		else
			rotate_stack(b, 'b');
	}
}

void	ab_top(t_stack **a, t_stack **b, t_info nbr2sort, t_info target)
{
	while ((*a)->content != nbr2sort.data && (*b)->content != target.data)
	{
		if (nbr2sort.movements > nbr2sort.size / 2 && target.movements > target.size / 2)
			reverse_both(a, b);
		else if (nbr2sort.movements < nbr2sort.size / 2 && target.movements > target.size / 2)
			rotate_stack(a, 'a');
		else if (target.movements < target.size / 2 && nbr2sort.movements > nbr2sort.size / 2)
			rotate_stack(b, 'b');
		else
			rotate_both(a, b);
	}
}
