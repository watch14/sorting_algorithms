#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the doubly linked list.
 * @node: Node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	if (node->prev != NULL)
		node->prev->next = node->next;
	else
		*list = node->next;

	if (node->next != NULL)
		node->next->prev = node->prev;

	node->next = node->next->next;
	node->prev = node->next->prev;
	node->next->prev = node;
	if (node->prev != NULL)
		node->prev->next = node;
}

/**
 * cocktail_forward - Traverses the list forward and performs swaps.
 * @list: Pointer to the head of the doubly linked list.
 * @swapped: Pointer to the swapped flag.
 */
void cocktail_forward(listint_t **list, int *swapped)
{
	listint_t *current;

	for (current = *list; current->next != NULL; current = current->next)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current);
			*swapped = 1;
			print_list(*list);
		}
	}
}

/**
 * cocktail_backward - Traverses the list backward and performs swaps.
 * @current: Pointer to the current node.
 * @swapped: Pointer to the swapped flag.
 * @list: Pointer to the head of the doubly linked list.
 */
void cocktail_backward(listint_t **list, listint_t *current, int *swapped)
{
	for (; current->prev != NULL; current = current->prev)
	{
		if (current->n < current->prev->n)
		{
			swap_nodes(list, current);
			*swapped = 1;
			print_list(*list);
		}
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                      using Cocktail shaker sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;
		cocktail_forward(list, &swapped);

		if (swapped == 0)
			break;

		swapped = 0;
		for (current = *list; current->prev != NULL; current = current->prev)
		{
			cocktail_backward(list, current, &swapped);
		}

	} while (swapped);
}
