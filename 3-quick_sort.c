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
