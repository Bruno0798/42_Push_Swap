/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:33:16 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/20 18:47:40 by bsousa-d         ###   ########.fr       */
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
		exit(1);
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

// Generates all possible permutations of an array of six numbers and sorts each one of them using the custom sorting algorithm
// And checks if the sorted stack matches the expected array [1, 2, 3, 4, 5, 6]
void sort_six_numbers()
{

	int arr[] = {1, 2, 3, 4, 5, 6};
	int expected[] = {1, 2, 3, 4, 5, 6};

	permute(arr, expected, 0, 5, true);
}

// Generates all possible permutations of an array of seven numbers and sorts each one of them using the custom sorting algorithm
// And checks if the sorted stack matches the expected array [1, 2, 3, 4, 5, 6, 7]
void sort_seven_numbers()
{

	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int expected[] = {1, 2, 3, 4, 5, 6, 7};

	permute(arr, expected, 0, 6, true);
}

void sort_hundred_and_fifty()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
				 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
				 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
				 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
				 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
				 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
				 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
				 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
				 91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
				 101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
				 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
				 121, 122, 123, 124, 125, 126, 127, 128, 129, 130,
				 131, 132, 133, 134, 135, 136, 137, 138, 139, 140,
				 141, 142, 143, 144, 145, 146, 147, 148, 149, 150};
	int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
					  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
					  21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
					  31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
					  41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
					  51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
					  61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
					  71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
					  81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
					  91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
					  101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
					  111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
					  121, 122, 123, 124, 125, 126, 127, 128, 129, 130,
					  131, 132, 133, 134, 135, 136, 137, 138, 139, 140,
					  141, 142, 143, 144, 145, 146, 147, 148, 149, 150};

	permute(arr, expected, 0, 6, true);
}