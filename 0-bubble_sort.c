#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 *
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
 * bubble_sort - Sorts an array of integers in ascending order using the
 *               Bubble Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	if (!array || size < 2)
	{
		print_array(array, size);
		return;
	}

	for (i = 0 ; i < size ; i++)
	{
		swapped = false;
		for (j = 0 ; j < size - 1 ; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
				print_array(array, size);
			}
		}
		if (!swapped)
			return;
	}
}
