#ifndef SORT_H
#define SORT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

/* Task 0 */
void bubble_sort(int *array, size_t size);
/* Task 1 */
void insertion_sort_list(listint_t **list);
/* Task 2 */
void swap(int *xp, int *yp);
void selection_sort(int *array, size_t size);
/* Task 3 */
void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size);
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);

/* ADVANCED */
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void counting_sort(int *array, size_t size);

void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *array, size_t left, size_t right);
void merge(int *array, int *left_array, int *right_array,
		size_t left_size, size_t right_size);

static void sift_down(int *array, size_t start, size_t end, size_t size);
void heap_sort(int *array, size_t size);

#endif /* SORT_H */
