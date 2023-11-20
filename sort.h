#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* TASK 0 */
void bubble_sort(int *array, size_t size);

/* TASK 1 */
void insertion_sort_list(listint_t **list);

/* TASK 2 */
void selection_sort(int *array, size_t size);

/* TASK 3 */
void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void swap(int *x, int *y);

/* ADVANCED */

/* TASK 100 */
void shell_sort(int *array, size_t size);

/* TASK 101 */
void swap_nodes(listint_t **list, listint_t *node);
void cocktail_forward(listint_t **list, int *swapped);
void cocktail_backward(listint_t **list, listint_t *current, int *swapped);
void cocktail_sort_list(listint_t **list);

#endif /* SORT_H */
