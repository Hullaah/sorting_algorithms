#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly-linked list to be sorted
 * Return: void (does not have a return value. It sorts in-place)
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *prev_ptr, *next_ptr;

	if (!list || (!*list) || !(*list)->next)
		return;
	for (ptr = *list; ptr->next; ptr = ptr->next)
	{
		next_ptr = ptr->next;
		prev_ptr = ptr->prev;
		/*
		* continue moving the node backwards while still
		* smaller than the other nodes
		*/
		while (next_ptr->n < ptr->n)
		{
			if (!prev_ptr)
			{
				ptr->next = next_ptr->next;
				next_ptr->next = ptr;
				ptr->prev = next_ptr;
				next_ptr->prev = prev_ptr;
				if (ptr->next)
					ptr->next->prev = ptr;
				*list = next_ptr;
				print_list(*list);
				break;
			}
			prev_ptr->next = next_ptr;
			ptr->next = next_ptr->next;
			next_ptr->next = ptr;
			ptr->prev = next_ptr;
			next_ptr->prev = prev_ptr;
			if (ptr->next)
				ptr->next->prev = ptr;
			next_ptr = ptr->prev;
			ptr = prev_ptr;
			prev_ptr = prev_ptr->prev;
			print_list(*list);
		}
	}
}
