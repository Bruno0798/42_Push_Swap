/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:25:36 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/25 17:10:58 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Finds the number in stack A that requires the fewest movements to be sorted.
 * 
 * @param a         The stack A.
 * @param b         The stack B.
 * @param info_a    The information about stack A.
 * @return          The information about the number to move and the number of movements.
 */
t_info a_nbr2move(t_stack *a, t_stack *b, t_info info_a)
{
	t_stack *temp_a = a;
	t_info nbr2move;
	int moves;
	int cheaper_nbr = 0;

	info_a.movements = 0;

	// Iterate through stack A to find the number requiring the fewest movements
	while (temp_a != NULL)
	{
		if (temp_a->content > get_max(b) || temp_a->content < get_min(b)) // If the number is out of range
			moves = out_min_max(b, info_a);
		else if (temp_a->content < get_max(b) && temp_a->content > get_min(b)) // If the number is in range
			moves = in_min_max(b, temp_a->content, info_a);

		// Update the number of movements and the number to move if it is cheaper
		if (cheaper_nbr > moves || info_a.movements == 0)
		{
			cheaper_nbr = moves;
			nbr2move.movements = info_a.movements;
			nbr2move.data = temp_a->content;
		}

		info_a.movements++;
		temp_a = temp_a->next;
	}

	return (nbr2move);
}

t_info	b_target(t_stack *b, int data_a)
{
	t_stack	*temp_b = b;
	t_info	target;

	if (data_a > get_max(b) || data_a < get_min(b)) 		// If the number is out of range
	{
		target.data = get_max(b); 							// Set the target to the maximum value in stack B
		target.movements = get_index(b, target.data); 		// Set the number of movements to the index of the maximum value in stack B
		return (target);
	}
	else
		target.data = get_min(b); 							// Set the target to the minimum value in stack B
	while (temp_b != NULL)
	{
		if (data_a > temp_b->content) 						// If the number is greater than the current value in stack B
		{
			if (target.data < temp_b->content) 				// If the current value is greater than the target
				target.data = temp_b->content; 				// Set the target to the current value
		}
		temp_b = temp_b->next;
	}
	target.movements = get_index(b, target.data); 			// Set the number of movements to the index of the target value in stack B
	return (target);
}

int	calc(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	mv_calcs(t_info info_a, t_info info_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (info_a.movements > 0 && info_b.movements > 0)
	{
		if (info_a.movements >= info_a.size / 2 && info_b.movements >= info_b.size / 2)
			nbr_m = calc(info_b.size - info_b.movements, info_a.size - info_a.movements);
		else if (info_a.movements > info_a.size / 2 && info_b.movements < info_b.size / 2)
			nbr_m = (info_a.size - info_a.movements) + info_b.movements;
		else if (info_b.movements > info_b.size / 2 && info_a.movements < info_a.size / 2)
			nbr_m = (info_b.size - info_b.movements) + info_a.movements;
		else
			nbr_m = calc(info_b.movements, info_a.movements);
	}
	else
		nbr_m = mv_calcs2(info_a, info_b);
	return (++nbr_m);
}

int	mv_calcs2(t_info info_a, t_info info_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (info_a.movements >= info_a.size / 2)
		nbr_m = info_a.size - info_a.movements;
	else if (info_b.movements >= info_b.size / 2)
		nbr_m = info_b.size - info_b.movements;
	else
		nbr_m = calc(info_b.movements, info_a.movements);
	return (nbr_m);
}
