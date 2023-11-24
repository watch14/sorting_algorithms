#ifndef DECK_H
#define DECK_H

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * enum kind_e - Suit of a card
 * @SPADE: Spade suit
 * @HEART: Heart suit
 * @CLUB: Club suit
 * @DIAMOND: Diamond suit
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 * @value: Value of the card (Ace to King)
 * @kind: Suit of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Node of a deck of cards
 * @card: Pointer to the card
 * @prev: Pointer to the previous node in the deck
 * @next: Pointer to the next node in the deck
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void print_deck(const deck_node_t *deck);
void sort_deck(deck_node_t **deck);

void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2);

#endif /* DECK_H */
