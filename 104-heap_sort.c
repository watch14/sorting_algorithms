#include "sort.h"

/**
 * sift_down - Perform the sift-down operation in heap sort
 * @array: The array to be sorted
 * @start: The index to start the sift-down operation
 * @end: The end index of the heap
 * @size: The size of the array
 */
static void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child;
	size_t swap;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap != root)
		{
			int temp = array[root];

			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
		{
			return;
		}
	}
}

/**
 * heap_sort - Sort an array of integers using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	for (int start = (size - 2) / 2; start >= 0; start--)
		sift_down(array, start, size - 1, size);

	for (int end = size - 1; end > 0; end--)
	{
		int temp = array[0];

		array[0] = array[end];
		array[end] = temp;
		print_array(array, size);
		sift_down(array, 0, end - 1, size);
	}
}
