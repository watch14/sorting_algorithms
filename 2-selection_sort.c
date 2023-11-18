#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 *
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap(int *x, int *y)
{
	size_t temp = *x;
	*x = *y;
	*y = temp;
}

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
