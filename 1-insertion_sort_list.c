#include "sort.h"

void swap_nodes(listint_t **head, listint_t *left, listint_t *right);
void insertion_sort_list(listint_t **list);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion Sort algorithm.
 *
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key;
	int value;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		key = current;
		value = key->n;
		while (key->prev != NULL && key->prev->n > value)
		{
			swap_nodes(list, key, key->prev);
			print_list(*list);
			key = key->prev;
		}
		current = key->next;
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @head: A pointer to the head of the list.
 * @left: A pointer to the left node to be swapped.
 * @right: A pointer to the right node to be swapped.
 */
void swap_nodes(listint_t **head, listint_t *left, listint_t *right)
{
	listint_t *left_prev = left->prev;
	listint_t *right_next = right->next;

	if (left_prev)
		left_prev->next = right;
	else
		*head = right;

	right->prev = left_prev;
	right->next = left;
	left->prev = right;
	left->next = right_next;

	if (right_next)
		right_next->prev = left;
}
