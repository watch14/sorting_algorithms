#include "deck.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @deck: Pointer to the head of the doubly linked list
 * @node1: Pointer to the first node to be swapped
 * @node2: Pointer to the second node to be swapped
 */
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*deck = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: Pointer to the head of the doubly linked list representing the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *next;
	int sorted, cmp;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	do {
		sorted = 1;
		current = *deck;

		while (current->next != NULL)
		{
			next = current->next;
			cmp = strcmp(current->card->value, next->card->value);

			if (cmp > 0 || (cmp == 0 && current->card->kind > next->card->kind))
			{
				swap_nodes(deck, current, next);
				sorted = 0;
				print_deck(*deck);
			}
			else
			{
				current = current->next;
			}
		}
	} while (!sorted);
}
