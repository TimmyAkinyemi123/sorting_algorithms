#include "sort.h"

void swap_nodes(listint_t *node_a, listint_t *node_b, listint_t **list);

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 * ascending orderusing the Cocktail shaker sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next, list);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;

		swapped = 0;
		current = current->prev;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current, list);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @node_a: First node to be swapped.
 * @node_b: Second node to be swapped.
 * @list: A pointer to the pointer to the head of the list.
 */
void swap_nodes(listint_t *node_a, listint_t *node_b, listint_t **list)
{
	listint_t *temp;

	if (node_a->prev != NULL)
		node_a->prev->next = node_b;
	else
		*list = node_b;

	if (node_b->next != NULL)
		node_b->next->prev = node_a;

	temp = node_b->next;
	node_b->next = node_a;
	node_a->prev = node_b;
	node_a->next = temp;
	node_b->prev = NULL;
}
