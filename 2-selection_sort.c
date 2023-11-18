#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 * @xp: Pointer to the first integer.
 * @yp: Pointer to the second integer.
 *
 * Return: void
 */

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i+1; j < size; j++)
			if (array[j] < array[min])
				min = j;

		if(min != i)
			swap(&array[min], &array[i]);
		print_array(array, size);
	}
}
