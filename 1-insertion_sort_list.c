#include "sort.h"



void insertion_sort_list(listint_t **list)
{
	size_t i, j;
	listint_t *now = malloc(sizeof(listint_t));

	if (now == NULL)
		return;

	if (!list)
		return;

	while (list)
		list = list->next;
	{
		if (list->n < list->prev->n)
		{
			now = list->prev;
			list->prev = list;
			list = now;

			print_list(list);
		}
	}
	free(now);
}
