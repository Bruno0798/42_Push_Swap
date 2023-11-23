/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:33:16 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/23 18:36:23 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	TEST_ASSERT_EQUAL(int expected, int actual)
{
	if (expected == actual)
	{
		printf("\t\033[32m[OK]\033[0m\n\n");
		return (1);
	}
	else
	{
		printf("\t\033[31m[KO]\033[0m\n");
		ft_printf("Expected: %d\n", expected);
		ft_printf("Actual: %d\n", actual);
		exit(1);
		return (0);
	}
}

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	permute(int *arr, int *expected, int start, int end, bool test)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*current;

	a = NULL;
	b = NULL;
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
			current = a;
			for (int i = 0; i <= end; i++)
			{
				if (TEST_ASSERT_EQUAL(expected[i], current->content))
				{
					current = current->next;
				}
				else
				{
					// Test failed,handle accordingly(print an error message, return,etc.)
					ft_free_stack(&a);
					return ;
				}
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
void	sort_three_numbers(void)
{
	int	arr[] = {1, 2, 3};
	int	expected[] = {1, 2, 3};

	permute(arr, expected, 0, 2, true);
}

// Generates all possible permutations of an array of four numbers and sorts each one of them using the custom sorting algorithm
// And checks if the sorted stack matches the expected array [1, 2, 3, 4]
void	sort_four_numbers(void)
{
	int	arr[] = {1, 2, 3, 4};
	int	expected[] = {1, 2, 3, 4};

	permute(arr, expected, 0, 3, true);
}

// Generates all possible permutations of an array of five numbers and sorts each one of them using the custom sorting algorithm
// And checks if the sorted stack matches the expected array [1, 2, 3, 4, 5]
void	sort_five_numbers(void)
{
	int	arr[] = {1, 2, 3, 4, 5};
	int	expected[] = {1, 2, 3, 4, 5};

	permute(arr, expected, 0, 4, true);
}

// Generates all possible permutations of an array of six numbers and sorts each one of them using the custom sorting algorithm
// And checks if the sorted stack matches the expected array [1, 2, 3, 4, 5, 6]
void	sort_six_numbers(void)
{
	int	arr[] = {1, 2, 3, 4, 5, 6};
	int	expected[] = {1, 2, 3, 4, 5, 6};

	permute(arr, expected, 0, 5, true);
}

// Generates all possible permutations of an array of seven numbers and sorts each one of them using the custom sorting algorithm
// And checks if the sorted stack matches the expected array [1, 2, 3, 4, 5, 6]
void	sort_seven_numbers(void)
{
	int	arr[] = {1, 2, 3, 4, 5, 6, 7};
	int	expected[] = {1, 2, 3, 4, 5, 6, 7};

	permute(arr, expected, 0, 6, true);
}

void	sort_hundred_and_fifty(int number)
{
	int *arr;
	int *expected;

	// Allocate memory for arr and expected
	arr = malloc(sizeof(int) * number);
	expected = malloc(sizeof(int) * number);

	// Check if memory allocation was successful
	if (arr == NULL || expected == NULL)
	{
		printf("Memory allocation failed\n");
		return ;
	}

	// Initialize arr and expected
	for (int i = 0; i < number; i++)
	{
		arr[i] = i + 1;
		expected[i] = i + 1;
	}

	// Call permute with the correct parameters
	permute(arr, expected, 0, number - 1, true);

	// Free allocated memory
	free(arr);
	free(expected);
}