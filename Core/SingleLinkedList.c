/*
 ============================================================================
 Name        : LinkedList.c
 Author      : xxx
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>

#include "LinkedList.h"

extern List* create(int data)
{
	List *list = malloc(sizeof(List));
	Element *first = malloc(sizeof(Element));

	if((list != NULL) && (first != NULL))
	{
		list->first = first;
		list->size = 1;
		first->data = data;
		first->next = NULL;
	}
	else
	{
		exit(EXIT_FAILURE);
	}
	return list;
}

extern boolean append(List *list, int data)
{
	boolean isAppened = false;
	Element *new = NULL;

	if(list != NULL)
	{
		new = malloc(sizeof(Element));
		if(new != NULL)
		{
			new->data = data;
			new->next = list->first;
			list->first = new;
			list->size++;
			isAppened = true;
		}
		else
		{
			fprintf(stderr, "Not enough memory to allocate space for a new node.\n");
		}
	}
	else
	{
		fprintf(stderr, "List pointer sent as argument of the append function is NULL.\n");
	}

	return isAppened;
}

extern boolean appendAt(List *list, int data, unsigned int index)
{
	boolean isAppened = false;
	Element *new = NULL;
	Element *previous = NULL;

	if(list != NULL)
	{
		if(index <= list->size)
		{
			if(index == 0)
			{
				append(list, data);
			}
			else
			{
				new = malloc(sizeof(Element));
				previous = get(list, index - 1);
				if((previous != NULL) || (new != NULL))
				{
					new->data = data;
					new->next = previous->next;
					previous->next = new;
					list->size++;
					isAppened = true;
				}
				else
				{
					fprintf(stderr, "Not enough memory to allocate space for a new node.\n");
				}
			}
		}
		else
		{
			fprintf(stderr, "Index greater than the size of the input list.\n");
		}
	}
	else
	{
		fprintf(stderr, "List pointer sent as argument of the appendAt function is NULL.\n");
	}
	return isAppened;
}

extern boolean delete(List *list)
{
	boolean bIsDeleted = false;
	Element *node = NULL;
	if(list != NULL)
	{
		if(list->first != NULL)
		{
			node = list->first;
			list->first = node->next;
			list->size--;
			free(node);
			bIsDeleted = true;
		}
		else
		{
			fprintf(stderr, "List is empty.\n");
		}
	}
	else
	{
		fprintf(stderr, "List pointer sent as argument of the delete function is NULL.\n");
	}

	return bIsDeleted;
}

extern boolean deleteAt(List *list, unsigned int index)
{
	boolean bIsDeleteAt = false;
	Element *previous = NULL;
	Element *node = NULL;

	if(list != NULL)
	{
		if(index < list->size)
		{
			if(index == 0)
			{
				delete(list);
			}
			else
			{
				previous = get(list, index - 1);
				if(previous != NULL)
				{
					node = previous->next;
					if(node != NULL)
					{
						previous->next = node->next;
						free(node);
						list->size--;
						bIsDeleteAt = true;
					}
					else
					{
						fprintf(stderr, "Unable to retrieve the node corresponding to the index %d\n", index);
					}
				}
				else
				{
					fprintf(stderr, "Unable to retrieve the previous node.\n");
				}
			}
		}
		else
		{
			fprintf(stderr, "Index greater than the size of the input list.\n");
		}
	}
	else
	{
		fprintf(stderr, "List pointer sent as argument of the deleteAt function is NULL.\n");
	}

	return bIsDeleteAt;
}

extern boolean update(List *list, unsigned int index, int new_data)
{
	boolean bIsDestroyd = false;
	Element *node = NULL;

	if(list != NULL)
	{
		if(index < list->size)
		{
			node = get(list, index);
			if(node != NULL)
			{
				node->data = new_data;
				bIsDestroyd = true;
			}
			else
			{
				fprintf(stderr, "Unable to retrieve the node corresponding to the index.\n");
			}
		}
		else
		{
			fprintf(stderr, "Index greater than the size of the input list.\n");
		}
	}
	else
	{
		fprintf(stderr, "List pointer sent as argument of the update function is NULL.\n");
	}

	return bIsDestroyd;
}

extern void print(List *list)
{
	Element *current = NULL;

	if(list != NULL)
	{
		current = malloc(sizeof(Element));
		if(list->first != NULL)
		{
			current = list->first;
			fprintf(stdout, "[%d", current->data);
			while(current->next != NULL)
			{
				current = current->next;
				fprintf(stdout, "-%d", current->data);
			}
			fprintf(stdout, "]\n");
		}
		else
		{
			fprintf(stdout, "[]\n");
		}
	}
	else
	{

	}
}

extern int printAt(List *list, unsigned int index)
{
	int data = 0;
	Element *node = get(list, index);
	if(node != NULL)
	{
		data = node->data;
	}
	else
	{
		fprintf(stderr, "Index is out of bound.\n");
	}
	return data;
}

extern Element* get(List *list, unsigned int index)
{
	unsigned int current_index = 0;
	Element *current = NULL;

	if(list != NULL)
	{
		if(index < list->size)
		{
			current = malloc(sizeof(Element));
			if(list->first != NULL)
			{
				current = list->first;
				while(current != NULL)
				{
					if(current_index == index)
					{
						/* End the while loop as we founded the node corresponding to the index. */
						break;
					}
					else
					{
						current = current->next;
						current_index++;
					}
				}
			}
			else
			{
				fprintf(stderr, "List is empty.\n");
			}
		}
		else
		{
			fprintf(stderr, "Index is out of bound.\n");
		}
	}
	else
	{
		fprintf(stderr, "List pointer sent as argument of the get function is NULL.\n");
	}

	return current;
}

extern unsigned int size(List *list)
{
	unsigned int list_size = 0;

	if(list != NULL)
	{
		list_size = list->size;
	}
	else
	{
		list_size = 0;
	}

	return list_size;
}

extern boolean destroy(List *list)
{
	boolean bIsDeleted = false;

	if(list != NULL)
	{
		while(list->first != NULL)
		{
			delete(list);
		}
		free(list);
		bIsDeleted = true;
	}
	else
	{
		fprintf(stderr, "List pointer sent as argument of the destroy function is NULL.\n");
	}

	return bIsDeleted;
}
