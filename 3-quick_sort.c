#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * lomuto_partition - Partitions the array for the Quick Sort algorithm
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 * Return: The index of the pivot.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	i = low - 1;
	pivot = array[high];

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	i++;
	swap(&array[i], &array[high]);

	print_array(array, size);

	return (i);
}

/**
 * quick_sort_recursive - Recursively sorts the array using Quick Sort
 * @array: The array to be sorted.
 * @low: The starting index of the array.
 * @high: The ending index of the array.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int low = 0;
	int high = size - 1;

	quick_sort_recursive(array, low, high, size);
}
