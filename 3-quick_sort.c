#include "sort.h"


/**
 * swap - Swaps the values of two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap(int *x, int *y)
{
	size_t temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - Partitions the array for the Quick Sort algorithm.
 * @array: The array to be partitioned.
 * @start: The starting index of the partition.
 * @end: The ending index of the partition.
 * @size: The size of the array.
 * Return: The index of the pivot.
 */
int partition(int *array, int start, int end, size_t size)
{
	int i, j, pivot;

	i = start - 1;
	pivot = array[end];

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	i++;
	swap(&array[i], &array[end]);

	print_array(array, size);

	return (i);
}

/**
 * quick_sort_recursive - Recursively sorts the array using Quick Sort.
 * @array: The array to be sorted.
 * @start: The starting index of the array.
 * @end: The ending index of the array.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int start, int end, size_t size)
{
	if (array == NULL || size < 2)
		return;

	if (start < end)
	{
		int pivot = partition(array, start, end, size);

		quick_sort_recursive(array, start, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, end, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;

	quick_sort_recursive(array, start, end, size);
}
