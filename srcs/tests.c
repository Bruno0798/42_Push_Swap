/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:33:16 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/17 15:55:28 by bsousa-d         ###   ########.fr       */
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

//************************* 5 NUMBERS *************************//

static void TEST_ASSERT_EQUAL(int expected, int actual)
{
	if (expected == actual)
		printf("\033[32m[OK]\033[0m\n");
	else
		printf("\033[31m[KO]\033[0m\n");
}

// Sorts a stack of five elements in ascending order
void sort_five_asc_order_test()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	ft_add_next(&a, 5);
	ft_add_next(&a, 2);
	ft_add_next(&a, 3);
	ft_add_next(&a, 4);
	ft_add_next(&a, 1);

	sort_five(&a, &b);
	ft_printf(" 5 2 3 4 1\n");

	assert(a->content == 1);
	assert(a->next->content == 2);
	assert(a->next->next->content == 3);
	assert(a->next->next->next->content == 4);
	assert(a->next->next->next->next->content == 5);
}

// If the minimum value is at the top of the stack, pushes it to stack b and sorts the remaining four elements in stack a
void sort_five_min_at_top_test()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	ft_add_next(&a, 1);
	ft_add_next(&a, 5);
	ft_add_next(&a, 2);
	ft_add_next(&a, 3);
	ft_add_next(&a, 4);

	sort_five(&a, &b);
	ft_printf(" 1 5 2 3 4\n");

	assert(a->content == 1);
	assert(a->next->content == 2);
	assert(a->next->next->content == 3);
	assert(a->next->next->next->content == 4);
	assert(a->next->next->next->next->content == 5);
}

// If the maximum value is at the top of the stack, rotates the stack until the minimum value is at the top, pushes it to stack b and sorts the remaining four elements in stack a
void sort_five_max_at_top_test()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	ft_add_next(&a, 4);
	ft_add_next(&a, 3);
	ft_add_next(&a, 2);
	ft_add_next(&a, 5);
	ft_add_next(&a, 1);

	sort_five(&a, &b);
	ft_printf(" 4 3 2 5 1\n");

	assert(a->content == 1);
	assert(a->next->content == 2);
	assert(a->next->next->content == 3);
	assert(a->next->next->next->content == 4);
	assert(a->next->next->next->next->content == 5);
}
// sorts a stack of five elements in ascending order
void test_sort_five_ascending_order()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	int arr[] = {4, 2, 5, 1, 3};
	int expected[] = {1, 2, 3, 4, 5};
	int i;

	for (i = 0; i < 5; i++)
	{
		ft_add_next(&a, arr[i]);
	}

	sort_five(&a, &b);

	for (i = 0; i < 5; i++)
	{
		TEST_ASSERT_EQUAL(expected[i], a->content);
		a = a->next;
	}
}

// correctly identifies the minimum value in the stack
void test_sort_five_minimum_value()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	int arr[] = {4, 2, 5, 1, 3};
	int expected[] = {1, 2, 3, 4, 5};
	int i;

	for (int i = 0; i < 5; i++)
	{
		ft_add_next(&a, arr[i]);
	}

	sort_five(&a, &b);

	for (i = 0; i < 5; i++)
	{
		TEST_ASSERT_EQUAL(expected[i], a->content);
		a = a->next;
	}
}

// rotates the stack until the minimum value is at the top
void test_sort_five_rotate_until_minimum()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	int arr[] = {4, 2, 5, 1, 3};
	int expected[] = {1, 2, 3, 4, 5};
	int i;

	for (int i = 0; i < 5; i++)
	{
		ft_add_next(&a, arr[i]);
	}

	sort_five(&a, &b);

	for (i = 0; i < 5; i++)
	{
		TEST_ASSERT_EQUAL(expected[i], a->content);
		a = a->next;
	}
}

// correctly handles a stack that is already sorted
void test_sort_five_already_sorted()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	int arr[] = {1, 2, 3, 4, 5};
	int expected[] = {1, 2, 3, 4, 5};
	int i;

	for (int i = 0; i < 5; i++)
	{
		ft_add_next(&a, arr[i]);
	}

	sort_five(&a, &b);

	for (i = 0; i < 5; i++)
	{
		TEST_ASSERT_EQUAL(expected[i], a->content);
		a = a->next;
	}
}

// pushes the minimum value to stack b
void test_sort_five_push_minimum_to_b()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	int arr[] = {4, 2, 5, 1, 3};
	int expected[] = {1, 2, 3, 4, 5};
	int i;

	for (int i = 0; i < 5; i++)
	{
		ft_add_next(&a, arr[i]);
	}

	sort_five(&a, &b);

	for (i = 0; i < 5; i++)
	{
		TEST_ASSERT_EQUAL(expected[i], a->content);
		a = a->next;
	}
}