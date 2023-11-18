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
	size_t i, j;
	int flag, temp;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		temp = i;
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[temp] > array[j])
			{
				temp = j;
				flag = 1;
			}
		}
		swap(&array[i], &array[temp]);
		if (flag != 0)
			print_array(array, size);
	}
}
