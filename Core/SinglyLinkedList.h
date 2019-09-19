#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct SinglyLinkedListNode
{
	int data;
	struct SinglyLinkedListNode *next;
}SinglyLinkedListNode;

SinglyLinkedListNode* createSinglyLinkedList(int data);
unsigned int getLinkedListSize(SinglyLinkedListNode* head);
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* head, int data);
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data);
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position);
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position);
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head);
bool compareLinkedLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
SinglyLinkedListNode* mergeLinkedLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
int getNode(SinglyLinkedListNode* head, int positionFromTail);
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head);
bool bHasListCycle(SinglyLinkedListNode* head);
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
void printLinkedList(SinglyLinkedListNode* head);
void reversePrint(SinglyLinkedListNode* head);

/* To be created: 
- SinglyLinkedListNode* sortLinkedList(SinglyLinkedListNode* head);
void printLinkedList(SinglyLinkedListSinglyLinkedListNode* head);
void reversePrint(SinglyLinkedListNode* head);

/* To be created: 
- SinglyLinkedListNode*	sortLinkedList(SinglyLinkedListNode* head);
- bool destroyList(SinglyLinkedListNode* head);
- SinglyLinkedListNode* updateNode(SinglyLinkedListNode* head, SinglyLinkedListNode* node);
*/

#endif /* SINGLYLINKEDLIST_H_ */
