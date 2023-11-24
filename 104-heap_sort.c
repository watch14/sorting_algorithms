#include "sort.h"

/**
 * heapify - Repair the heap whose root element is at index 'start'
 * @array: Array to heapify
 * @size: Size of the array
 * @start: Index to start heapifying from
 * @end: Max index of the heap
 */
void heapify(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child, swap, left, right;

	while (2 * root + 1 <= end)
	{
		left = 2 * root + 1;
		right = left + 1;
		swap = root;

		if (array[swap] < array[left])
			swap = left;

		if (right <= end && array[swap] < array[right])
			swap = right;

		if (swap != root)
		{
			int temp = array[root];

			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heap_sort - Heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t start;

	if (!array || size < 2)
		return;

	/* Build the heap (rearrange array) */
	for (start = (size - 2) / 2; start >= 0; start--)
		heapify(array, size, (size_t)start, size - 1);

	/* One by one extract elements from the heap */
	for (start = size - 1; start > 0; start--)
	{
		/* Move current root to end */
		int temp = array[0];

		array[0] = array[start];
		array[start] = temp;
		print_array(array, size);

		/* call max heapify on the reduced heap */
		heapify(array, size, 0, (size_t)start - 1);
	}
}
