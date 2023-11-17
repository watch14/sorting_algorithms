#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list.
 *
 * @list: Pointer to a pointer to the head of the linked list.
 *
 * Description: The function sorts the doubly linked list in place by swapping
 * nodes, and prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *now = (*list)->next;

	if (list == NULL || (*list)->next == NULL || *list == NULL)
		return;

	while (now != NULL)
	{
		listint_t *before = now->previous;

		while (before != NULL && before->n > now->n)
		{
			if (before->previous != NULL)
				before->previous->next = now;
			if (now->next != NULL)
				now->next->previous = before;

			before->next = now->next;
			now->previous = before->previous;

			if (now->previous == NULL)
				*list = now;
			print(*list);
		}
		now = now->next;
	}
}
