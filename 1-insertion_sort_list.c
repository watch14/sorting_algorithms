#include "sort.h"



void insertion_sort_list(listint_t **list)
{
	listint_t *now = (*list)->next;
	listint_t *before = now->previous;

	if (list == NULL || (*list)->next == NULL || *list == NULL)
		return;

	while (now != NULL)
	{
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
