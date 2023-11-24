#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using the LSD Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int max = getMax(array, size);

	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
		print_array(array, size);
	}
}

/**
 * getMax - Finds the maximum number in an array.
 * @array: The array to find the maximum number from.
 * @size: The size of the array.
 * Return: The maximum number.
 */
int getMax(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countingSort - Performs counting sort for a given digit.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The current digit being considered.
 */
void countingSort(int *array, size_t size, int exp)
{
	const int base = 10;
	int *output = malloc(sizeof(int) * size);
	int count[base] = {0};

	if (output == NULL)
		exit(EXIT_FAILURE);

	for (size_t i = 0; i < size; i++)
		count[(array[i] / exp) % base]++;

	for (int i = 1; i < base; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % base] - 1] = array[i];
		count[(array[i] / exp) % base]--;
	}

	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}
