#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

/**
 * compare_cards - Compare two cards for sorting
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 *
 * Return: Negative value if a < b, positive value if a > b, 0 if a = b
 */
int compare_cards(const void *a, const void *b) {
    const card_t *card_a = (*(const deck_node_t **)a)->card;
    const card_t *card_b = (*(const deck_node_t **)b)->card;

    if (card_a->kind < card_b->kind)
        return -1;
    else if (card_a->kind > card_b->kind)
        return 1;
    else
        return strcmp(card_a->value, card_b->value);
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t count = 0, i = 0;
    deck_node_t *current = *deck;
    deck_node_t **deck_array;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    deck_array = (deck_node_t **)malloc(count * sizeof(deck_node_t *));
    if (deck_array == NULL)        
        return;

    current = *deck;    
    while (current != NULL)
    {
        deck_array[i] = current;
        current = current->next;
        i++;
    }
    qsort(deck_array, count, sizeof(deck_node_t *), compare_cards);

    *deck = deck_array[0];
    for (i = 0; i < count - 1; i++)
    {
        deck_array[i]->next = deck_array[i + 1];
        deck_array[i + 1]->prev = deck_array[i];
    }
    deck_array[count - 1]->next = NULL;
    free(deck_array);
}