/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:33:16 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/18 18:42:41 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int TEST_ASSERT_EQUAL(int expected, int actual)
{
	if (expected == actual)
	{
		printf("\t\033[32m[OK]\033[0m\n\n");
		return 1;
	}

	else
	{
		printf("\t\033[31m[KO]\033[0m\n");
		ft_printf("Expected: %d\n", expected);
		ft_printf("Actual: %d\n", actual);
		return 0;
	}
}

static void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int *arr, int *expected, int start, int end, bool test)
{
	t_stack *a = NULL;
	t_stack *b = NULL;

	if (start == end)
	{
		for (int i = 0; i <= end; i++)
		{
			ft_printf("%d", arr[i]);
			ft_add_next(&a, arr[i]);
		}
		ft_printf("\n");
		sort(&a, &b);
		if (test)
		{
			for (int i = 0; i <= end; i++)
			{
				if (TEST_ASSERT_EQUAL(expected[i], a->content))
					a = a->next;
				ft_free_stack(&a);
				return;
			}
		}
		printf("\n");
		ft_free_stack(&a);
	}
	else
	{
		for (int i = start; i <= end; i++)
		{
			swap(&arr[start], &arr[i]);
			permute(arr, expected, start + 1, end, test);
			swap(&arr[start], &arr[i]); // backtrack
		}
	}
}
// Generates all possible permutations of an array of three numbers and sorts each one of them using the custom sorting algorithm
// And checks if the sorted stack matches the expected array [1, 2, 3]
void sort_three_numbers()
{

	int arr[] = {1, 2, 3};
	int expected[] = {1, 2, 3};

	permute(arr, expected, 0, 2, true);
}

// Generates all possible permutations of an array of four numbers and sorts each one of them using the custom sorting algorithm
// And checks if the sorted stack matches the expected array [1, 2, 3, 4]
void sort_four_numbers()
{

	int arr[] = {1, 2, 3, 4};
	int expected[] = {1, 2, 3, 4};

	permute(arr, expected, 0, 3, true);
}

// Generates all possible permutations of an array of five numbers and sorts each one of them using the custom sorting algorithm
// And checks if the sorted stack matches the expected array [1, 2, 3, 4, 5]
void sort_five_numbers()
{

	int arr[] = {1, 2, 3, 4, 5};
	int expected[] = {1, 2, 3, 4, 5};

	permute(arr, expected, 0, 4, true);
}