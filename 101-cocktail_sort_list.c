#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b);

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
				swap_nodes(list, current, current->next);
				if (current->prev == NULL)
					*list = current;
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;

		swapped = 0;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				if (current->next == NULL)
					current = current->prev;
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
 * @list: A pointer to the pointer to the head of the list.
 * @node_a: First node to be swapped.
 * @node_b: Second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
	if (node_a->prev != NULL)
		node_a->prev->next = node_b;
	else
		*list = node_b;

	if (node_b->next != NULL)
		node_b->next->prev = node_a;

	node_a->next = node_b->next;
	node_b->prev = node_a->prev;
	node_a->prev = node_b;
	node_b->next = node_a;
}
