#include "sort.h"

/**
 * insertion_sort_list - Perform insertion sort on a doubly linked list
 * @list: Double pointer to the head of the list
 *
 * Description: This function sorts a doubly linked list in ascending order
 * using the insertion sort algorithm. It takes a double pointer to the head
 * of the list and rearranges the nodes in place.
 *
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			/* Create a temporary node to hold the current node */
			listint_t *temp = current;

			/* Adjust adjacent links to the current node */
			if (temp->next)
				temp->next->prev = current->prev;
			temp->prev->next = current->next;

			/* Move the current node to the previous position */
			current = current->prev;

			/* Adjust the temporary node to point to the previous current node */
			temp->next = current;
			temp->prev = temp->prev->prev;

			/* Point the previous current node back to the temporary node */
			current->prev = temp;

			/* Adjust the previous node's next link to point to the temporary node */
			if (temp->prev)
				temp->prev->next = temp;

			/* Update the head node if the temporary node is now the head */
			if (temp->prev == NULL)
				(*list) = temp;

			/* Print the list after each swap */
			print_list(*list);

			/* Move back in the list */
			current = current->prev;
		}

		current = current->next;
	}
}
