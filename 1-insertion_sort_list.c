#include "sort.h"



void insertion_sort_list(listint_t **list)
{
	listint_t *now = *list->next;
	listint_t *before = now->previous;

	if (list == NULL)
		return;

	while (now != NULL)
	{
		if (before->previous != NULL)
			before->previous->next = now:
		if (now->next != NULL)
			now->next->previous = before
		{
			now = list->prev;
			list->prev = list;
			list = now;

			print_list(list);
		}

		now->next;
	}
}
