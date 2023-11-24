#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_recursive(array, size, 1);
}

/**
 * bitonic_recursive - Recursive helper function for bitonic_sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_recursive(int *array, size_t size, int dir)
{
	if (size > 1)
	{
		size_t mid = size / 2;

		printf("Merging [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
		print_array(array, size);

		bitonic_recursive(array, mid, 1);
		bitonic_recursive(array + mid, mid, 0);

		bitonic_merge(array, size, dir);

		printf("Result [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
		print_array(array, size);
	}
}

/**
 * bitonic_merge - Merges two subarrays in a bitonic manner.
 * @array: The array containing the subarrays to be merged.
 * @size: The size of the array.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	if (size > 1)
	{
		size_t mid = size / 2;
		size_t i;

		bitonic_compare(array, size, dir);

		bitonic_merge(array, mid, dir);
		bitonic_merge(array + mid, mid, dir);
	}
}

/**
 * bitonic_compare - Compares and swaps elements in a bitonic manner.
 * @array: The array containing the elements to be compared.
 * @size: The size of the array.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_compare(int *array, size_t size, int dir)
{
	size_t i, j;
	int temp;

	for (i = 0; i < size / 2; i++)
	{
		j = i + size / 2;

		if ((array[i] > array[j] && dir) || (array[i] < array[j] && !dir))
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			printf("Result [2/%lu] (%s):\n", size, dir ? "UP" : "DOWN");
			print_array(array, size);
		}
	}
}
