/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:33:16 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/12 22:35:24 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void assert(int test)
{
	if (test)
		printf("\033[32m[OK]\033[0m\n");
	else
		printf("\033[31m[KO]\033[0m\n");
}

// Sorts a stack of three elements in ascending order when the elements are not already sorted
void test_sort_three_not_sorted()
{
	t_stack *a = NULL;
	ft_add_next(&a, 3);
	ft_add_next(&a, 2);
	ft_add_next(&a, 1);

	sort_three(&a);
	ft_printf(" 3 2 1\n");

	assert(a->content == 1);
	assert(a->next->content == 2);
	assert(a->next->next->content == 3);
}

// Sorts a stack of three elements in ascending order when the elements are already sorted in ascending order
void test_sort_three_sorted_ascending()
{
	t_stack *a = NULL;
	ft_add_next(&a, 1);
	ft_add_next(&a, 2);
	ft_add_next(&a, 3);

	sort_three(&a);
	ft_printf(" 1 2 3\n");

	assert(a->content == 1);
	assert(a->next->content == 2);
	assert(a->next->next->content == 3);
}

// Sorts a stack of three elements in ascending order when the elements are sorted in descending order
void test_sort_three_sorted_descending()
{
	t_stack *a = NULL;
	ft_add_next(&a, 3);
	ft_add_next(&a, 2);
	ft_add_next(&a, 1);

	sort_three(&a);
	ft_printf(" 3 2 1\n");

	assert(a->content == 1);
	assert(a->next->content == 2);
	assert(a->next->next->content == 3);
}

// Sorts a stack of three elements in ascending order when the stack is NULL
void test_sort_three_null_stack()
{
	t_stack *a = NULL;

	sort_three(&a);

	assert(a == NULL);
}

// Sorts a stack of three elements in ascending order when the first element is the minimum and the second element is the maximum
void test_sort_three_min_max()
{
	t_stack *a = NULL;
	ft_add_next(&a, 1);
	ft_add_next(&a, 3);
	ft_add_next(&a, 2);

	sort_three(&a);
	ft_printf(" 2 3 1\n");

	assert(a->content == 1);
	assert(a->next->content == 2);
	assert(a->next->next->content == 3);
}

// Sorts a stack of three elements in ascending order when the first element is the minimum and the second element is not the maximum
void test_sort_three_min_not_max()
{
	t_stack *a = NULL;
	ft_add_next(&a, 1);
	ft_add_next(&a, 2);
	ft_add_next(&a, 3);

	sort_three(&a);
	ft_printf(" 2 1 3\n");

	assert(a->content == 1);
	assert(a->next->content == 2);
	assert(a->next->next->content == 3);
}

//************************* 4 NUMBERS *************************//
// Sorts a stack of four elements in ascending order
void sort_four_asc_order_test()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	ft_add_next(&a, 4);
	ft_add_next(&a, 2);
	ft_add_next(&a, 3);
	ft_add_next(&a, 1);

	sort_four(&a, &b);
	ft_printf(" 4 2 3 1\n");

	assert(a->content == 1);
	assert(a->next->content == 2);
	assert(a->next->next->content == 3);
	assert(a->next->next->next->content == 4);
}
// If the minimum value is at the top of the stack, pushes it to stack b and sorts the remaining three elements in stack a
void sort_four_min_at_top_test()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	ft_add_next(&a, 1);
	ft_add_next(&a, 4);
	ft_add_next(&a, 2);
	ft_add_next(&a, 3);

	sort_four(&a, &b);
	ft_printf(" 1 4 2 3\n");

	assert(a->content == 1);
	assert(a->next->content == 2);
	assert(a->next->next->content == 3);
	assert(a->next->next->next->content == 4);
}

// If the maximum value is at the top of the stack, rotates the stack until the minimum value is at the top, pushes it to stack b and sorts the remaining three elements in stack a
void sort_four_max_at_top_test()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	ft_add_next(&a, 3);
	ft_add_next(&a, 2);
	ft_add_next(&a, 4);
	ft_add_next(&a, 1);

	sort_four(&a, &b);
	ft_printf(" 3 2 4 1\n");

	assert(a->content == 1);
	assert(a->next->content == 2);
	assert(a->next->next->content == 3);
	assert(a->next->next->next->content == 4);
}

// Stack a is NULL
void sort_four_null_stack_a_test()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	sort_four(&a, &b);
	assert(a == NULL);
	assert(b == NULL);
}

// Stack a has less than four elements
void sort_four_less_than_four_elements_test()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	ft_add_next(&a, 3);
	ft_add_next(&a, 2);
	sort_four(&a, &b);
	assert(a->content == 2);
	assert(a->next->content == 3);
	assert(b == NULL);
}
