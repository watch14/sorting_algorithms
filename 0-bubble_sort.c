#include "sort.h"

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

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
