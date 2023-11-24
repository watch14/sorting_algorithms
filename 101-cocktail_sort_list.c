#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Cocktail Shaker sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current);
				swapped = 1;
				print_list(*list);
			}
		}

		if (swapped == 0)
			break;

		swapped = 0;
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev);
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 * @node: Pointer to the node to be swapped with its next node
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	if (node == NULL || node->next == NULL)
		return;

	if (node->prev != NULL)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->next->prev = node->prev;
	node->prev = node->next;
	node->next = node->next->next;

	if (node->next != NULL)
		node->next->prev = node;

	node->prev->next = node;
}
