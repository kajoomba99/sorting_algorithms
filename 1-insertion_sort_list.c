#include "sort.h"
/**
 * insertion_sort_list - insertion_sort_list
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur = NULL;

	if (list == NULL || *list == NULL)
		return;

	cur = (*list)->next;

	while (cur != NULL)
	{
		while (cur->prev != NULL && cur->n < cur->prev->n)
		{
			cur->prev->next = cur->next;
			if (cur->next != NULL)
				cur->next->prev = cur->prev;
			cur->next = cur->prev;
			cur->prev = cur->prev->prev;
			cur->next->prev = cur;
			if (!cur->prev)
				*list = cur;
			else
				cur->prev->next = cur;
			print_list(*list);
		}
		cur = cur->next;
	}
}
