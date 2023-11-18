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

/**
 * quick_sort - Sorts an array in ascending order using Quick Sort
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void quick_sort(int *array, size_t size)
{
	size_t i, j;
	int flag;

	if (array == NULL || size < 2)
		return;

	for (i = 0 ; i < size  ; i++)
	{
		flag = 0;

		for (j = size - 1 ; j > i ; j--)
		{

			if (array[i] > array[j])
			{
				swap(&array[i], &array[j]);
				flag = 1;
			}
		}
		if (flag == 1)
			print_array(array, size);
	}
}
