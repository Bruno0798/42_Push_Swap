/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:25:36 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/23 12:36:18 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_info	a_nbr2move(t_stack *a, t_stack *b, t_info info_a)
{
	t_stack	*temp_a;
	t_info	nbr2move;
	int		moves;
	int		cheaper_nbr;

	cheaper_nbr = 0;
	temp_a = a;
	info_a.movements = 0;
	while (temp_a != NULL)
	{
		if (temp_a->content > get_max(b) || temp_a->content < get_min(b))
			moves = out_min_max(b, info_a);
		else if (temp_a->content < get_max(b) && temp_a->content > get_min(b))
			moves = in_min_max(b, temp_a->content, info_a);
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
	t_stack	*temp_b;
	t_info	target;

	temp_b = b;
	if (data_a > get_max(b) || data_a < get_min(b))
	{
		target.data = get_max(b);
		target.movements = get_index(b, target.data);
		return (target);
	}
	else
		target.data = get_min(b);
	while (temp_b != NULL)
	{
		if (data_a > temp_b->content)
		{
			if (target.data < temp_b->content)
				target.data = temp_b->content;
		}
		temp_b = temp_b->next;
	}
	target.movements = get_index(b, target.data);
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
		if (info_a.movements >= info_a.size / 2
			&& info_b.movements >= info_b.size / 2)
			nbr_m = calc(info_b.size - info_b.movements, info_a.size
					- info_a.movements);
		else if (info_a.movements > info_a.size / 2
			&& info_b.movements < info_b.size / 2)
			nbr_m = (info_a.size - info_a.movements) + info_b.movements;
		else if (info_b.movements > info_b.size / 2
			&& info_a.movements < info_a.size / 2)
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
