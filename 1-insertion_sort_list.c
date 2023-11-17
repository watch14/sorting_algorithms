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
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *now = (*list)->next;

	while (now != NULL)
	{
		listint_t *before = now->prev;

		while (before != NULL && before->n > now->n)
		{
			if (before->prev != NULL)
				before->prev->next = now;
			if (now->next != NULL)
				now->next->prev = before;

			before->next = now->next;
			now->prev = before->prev;

			before->prev = now;
			now->next = before;

			if (now->prev == NULL)
				*list = now;

			print_list(*list);

			before = now->prev;
		}

		now = now->next;
	}
}
