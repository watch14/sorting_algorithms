#include "sort.h"

/**
 * quick_sort - Sorts an array of integers using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
<<<<<<< HEAD
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
=======
	int temp = *x;
	*x = *y;
	*y = temp;
>>>>>>> parent of 3063224... updated
}

/**
 * quick_sort_recursive - Recursive helper function for Quick sort
 * @array: The array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		ssize_t pivot = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * @size: The size of the array
 *
 * Return: The pivot index
 */
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
