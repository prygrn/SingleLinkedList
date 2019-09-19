/*
 ============================================================================
 Name        : SingleLinkedList.c
 Author      : xxx
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
 
#include "SinglyLinkedList.h"

SinglyLinkedListNode* createSinglyLinkedList(int data)
{
	SinglyLinkedListNode *head = malloc(sizeof(SinglyLinkedListNode));

	if(head != NULL)
	{
		head->data = data;
		head->next = NULL;
	}
	else
	{
		fprintf(stderr, "Not enough memory to create a new list.\n");
		exit(EXIT_FAILURE);
	}
	return head;
}

unsigned int getLinkedListSize(SinglyLinkedListNode* head)
{
	unsigned int size = 0;
	SinglyLinkedListNode* current = head;
	
	while(current != NULL)
	{
		size++;
		current = current->next;
	}
	
	return size;
}

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* head, int data)
{
    SinglyLinkedListNode *node = malloc(sizeof(SinglyLinkedListNode));

    if(head != NULL)
    {
		node->data = data;
        node->next = head;
        head = node;
    }
    else
    {
        head = node;
        head->next = NULL;
        head->data = data;
    }

    return head;
}

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data)
{
    SinglyLinkedListNode *node = malloc(sizeof(SinglyLinkedListNode));
    
    if(head != NULL)
    {
        SinglyLinkedListNode *previous = head;
        while(previous->next != NULL)
        {
            previous = previous->next;
        }
        previous->next = node;
    }
    else
    {
        head = node;
    }

    node->next = NULL;
    node->data = data;
    
    return head;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position)
{
    SinglyLinkedListNode *node = malloc(sizeof(SinglyLinkedListNode));
    int pos = 0;

    if(head != NULL)
    {
        if(position != 0)
        {
            SinglyLinkedListNode *current = head;
            while(current->next != NULL)
            {
                if(pos == (position - 1))
                {
                    break;
                }
                pos++;
                current = current->next;
            }
            node->next = current->next;
            node->data = data;
            current->next = node;
        }
        else
        {
            node->next = head;
            node->data = data;
            head = node;
        }
    }
    else
    {
        head = node;
        head->data = data;
        head->next = NULL;
    }

    return head;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position)
{
    int pos = 0;
    SinglyLinkedListNode *node = NULL;
    SinglyLinkedListNode *previous = head;

    if(position != 0)
    {
        while(previous != NULL)
        {
            if(pos == (position - 1))
            {
                break;
            }
            pos++;
            previous = previous->next;
        }
        node = previous->next;
        previous->next = node->next;
        free(node);
    }
    else
    {
        node = head;
        head = head->next;
        free(node);
    }
    
    return head;
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode *current = head;
    SinglyLinkedListNode *previous = NULL;
    SinglyLinkedListNode *next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;

    return head;
}

bool compareLinkedLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    bool bAreEqual = false;
    
    SinglyLinkedListNode *current1 = head1;
    SinglyLinkedListNode *current2 = head2;

    while(current1 != NULL)
    {
        if(current2 != NULL)
        {
            if(current1->data == current2->data)
            {
                current1 = current1->next;
                current2 = current2->next;
            }
            else
            {
                return(false);
            }
        }
        else
        {
            return(false);
        }
    }
    bAreEqual = true;

    return bAreEqual;
}

SinglyLinkedListNode* mergeLinkedLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    SinglyLinkedListNode *current1 = head1;
    SinglyLinkedListNode *current2 = head2;

    if((head1 == NULL) && (head2 == NULL))
        return NULL;
    if(head1 == NULL)
         return head2;
    if(head2 == NULL)
        return head1;

    if(head1->data < head2->data)
    {
        head1->next = mergeLinkedLists(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = mergeLinkedLists(head1, head2->next);
        return head2;
    }
}

int getNode(SinglyLinkedListNode* head, int positionFromTail)
{
    int index = 0;
    int size = 0;
    SinglyLinkedListNode *current = head;

    while(current != NULL)
    {
        size++;
        current = current->next;
    }

    current = head;
    while(current != NULL)
    {
        index++;
        if(index == (size - positionFromTail))
        {
            return current->data;
        }
        current = current->next;
    }

    return current->data;
}

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode *current = head;
    SinglyLinkedListNode *next = head->next;

    if(head != NULL)
    {
        while(next != NULL)
        {
            if(current->data == next->data)
            {
                next = next->next;
                current->next = next;
            }
            else
            {
                current = current->next;
                next = next->next;
            }
        }
    }

    return head;
}

bool bHasListCycle(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode *slow = head;
    SinglyLinkedListNode *fast = head;

    // Traverse the list with the 'current' node
    while((slow != NULL) && (fast != NULL) && (fast->next != NULL))
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return true;
        }
    }

    return false;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    SinglyLinkedListNode *current1 = head1;
    SinglyLinkedListNode *current2 = head2;

    while(current1 != NULL)
    {
        current2 = head2;
        while(current2 != NULL)
        {
            if(current1 == current2)
            {
                return current1->data;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    return current1->data;
}

void printLinkedList(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode *current = head;

	if(current != NULL)
	{
		fprintf(stdout, "[%d", current->data);
		while(current != NULL)
		{
			printf("%d\n", current->data);
			current = current->next;
		}
		fprintf(stdout, "]\n");
	}
	else
	{
		fprintf(stdout, "[]\n");
	}
}

void reversePrint(SinglyLinkedListNode* head)
{
   unsigned int size = 0;
   unsigned int index = 0;
   SinglyLinkedListNode *current = head;
   int *reverse = NULL;
   
   while(current != NULL)
   {
       size++;
       current = current->next;
   }

    reverse = malloc(sizeof(int) * size);
    current = head;

    while(current != NULL)
    {
        index++;
        reverse[size - index] = current->data;
        current = current->next;
    }

    for(unsigned int i = 0 ; i < size ; i++)
    {
        printf("%d\n", reverse[i]);
    }
	
	free(reverse);
}

/*
SinglyLinkedListNode* sortLinkedList(SinglyLinkedListNode* head)
bool destroyList(SinglyLinkedListNode* head)
SinglyLinkedListNode* updateNode(SinglyLinkedListNode* head, SinglyLinkedListNode* node)
*/