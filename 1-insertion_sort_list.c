#include "sort.h"

void swap_nodes(listint_t **head, listint_t **left, listint_t *right);
void insertion_sort_list(listint_t **list);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion Sort algorithm.
 *
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *temp;
	const listint_t *list_ptr = (const listint_t *)*list;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		key = current->prev;
		temp = current->next;

		while (key != NULL && key->n > current->n)
		{
			swap_nodes(list, &key, current);
			print_list(list_ptr);
		}
		current = temp;
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @head: A pointer to the head of the list.
 * @left: A pointer to the left node to be swapped.
 * @right: A pointer to the right node to be swapped.
 */
void swap_nodes(listint_t **head, listint_t **left, listint_t *right)
{
	(*left)->next = right->next;

	if (right->next != NULL)
		right->next->prev = *left;

	right->prev = (*left)->prev;
	right->next = *left;

	if ((*left)->prev)
		(*left)->prev->next = right;
	else
		*head = right;
	(*left)->prev = right;
	*left = right->prev;
}
