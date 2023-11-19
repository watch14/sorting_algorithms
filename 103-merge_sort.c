#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, 0, size - 1);
}

/**
 * merge_sort_recursive - Recursive helper function for Merge Sort
 * @array: The array to be sorted
 * @left: The left index of the sub-array
 * @right: The right index of the sub-array
 */
void merge_sort_recursive(int *array, size_t left, size_t right)
{
	if (left < right)
	{
		size_t middle = left + (right - left) / 2;

		printf("Merging...\n[left]: ");
		print_array(array + left, middle - left + 1);
		printf("[right]: ");
		print_array(array + middle + 1, right - middle);

		merge_sort_recursive(array, left, middle);
		merge_sort_recursive(array, middle + 1, right);

		int *left_array = malloc((middle - left + 1) * sizeof(int));
		int *right_array = malloc((right - middle) * sizeof(int));

		if (left_array == NULL || right_array == NULL)
		{
			free(left_array);
			free(right_array);
			return;
		}

		for (size_t i = 0; i < (middle - left + 1); i++)
			left_array[i] = array[left + i];

		for (size_t j = 0; j < (right - middle); j++)
			right_array[j] = array[middle + 1 + j];

		merge(array, left_array, right_array, middle - left + 1, right - middle);

		printf("[Done]: ");
		print_array(array + left, right - left + 1);

		free(left_array);
		free(right_array);
	}
}

/**
 * merge - Merges two sub-arrays in ascending order
 * @array: The array containing the sub-arrays to be merged
 * @left_array: The left sub-array
 * @right_array: The right sub-array
 * @left_size: Size of the left sub-array
 * @right_size: Size of the right sub-array
 */
void merge(int *array, int *left_array, int *right_array,
		size_t left_size, size_t right_size)
{
	size_t i, j, k;

	i = j = k = 0;

	while (i < left_size && j < right_size)
	{
		if (left_array[i] <= right_array[j])
		{
			array[k] = left_array[i];
			i++;
		}
		else
		{
			array[k] = right_array[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		array[k] = left_array[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right_array[j];
		j++;
		k++;
	}
}
