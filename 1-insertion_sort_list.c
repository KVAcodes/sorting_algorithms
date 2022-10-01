#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *		      order using the Insertion sort algorithm.
 * @list: address of the pointer to the first node in the list.
 *
 * Return: Nothing(void).
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *next, *back;

	if (!(*list) || !(*list)->next)
		return;

	curr = (*list)->next;
	next = curr->next;

	while (curr)
	{
		back = curr->prev;
		while (back && back->n > curr->n)
		{
			back->next = curr->next;
			if (curr->next)
				curr->next->prev = back;
			curr->prev = back->prev;
			if (curr->prev)
				curr->prev->next = curr;
			else
				*list = curr;
			curr->next = back;
			back->prev = curr;
			print_list(*list);
			back = curr->prev;
		}
		curr = next;
		if (next)
			next = next->next;
	}
}
