#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion Sort algorithm.
 *
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		key = current->prev;
		temp = current->next;

		while (key != NULL && key->n > current->n)
		{
			if (key->prev)
				key->prev->next = current;
			else
				*list = current;
			if (current->next)
				current->next->prev = key;

			key->next = current->next;
			current->prev = key->prev;
			key->prev = current;
			current->next = key;

			print_list(*list);
			key = current->prev;
		}
		current = temp;
	}
}
