#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, int left, int right);
void lomuto_sort(int *array, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, int left, int right)
{
	int *pivot = array[right], below = left - 1;

	// pivot = array + right;
	for (int j = left; j <= right - 1; j++)
	{
		if (array[j] <= pivot)
		{
			below++;
			swap_ints(array[below], array[j]);
		}
	}
	swap_ints(array[below + 1], array[right]);

	return (below + 1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, int left, int right)
{
	int part;

	if (left < right)
	{
		part = lomuto_partition(array, left, right);
		lomuto_sort(array, left, part - 1);
		lomuto_sort(array, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1);
}