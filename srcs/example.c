/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:55:00 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/18 10:59:04 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int *arr, int start, int end)
{
	if (start == end)
	{
		for (int i = 0; i <= end; i++)
		{
			printf("%d", arr[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = start; i <= end; i++)
		{
			swap(&arr[start], &arr[i]);
			permute(arr, start + 1, end);
			swap(&arr[start], &arr[i]); // backtrack
		}
	}
}

int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter the elements: ");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	printf("Permutations:\n");
	permute(arr, 0, n - 1);

	return 0;
}
