#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "SinglyLinkedList.h"

#define MAX_SIZE_OF_STRING		25
#define NB_OF_PUBLIC_FUNCTIONS	14

typedef void (*tpfRunFunctionTests)(void);

typedef struct TestManager
{
	char name[MAX_SIZE_OF_STRING];
	tpfRunFunctionTests pfRunFunctionTests;
}TestManager;

TestManager* initialize(void);
bool vidRunCreateSinglyLinkedList(void);

int main(int argc, char *argv[])
{
	char user_input[MAX_SIZE_OF_STRING];
	bool bEndOfTest = false;
	TestManager* tm = initialize();
	char *input = malloc(sizeof(char) * MAX_SIZE_OF_STRING);
	
	fprintf(stdout, "This is the test interface for the SingleLinkedList library.\n");
	fprintf(stdout, "Please enter an function to be tested.\n");
	fprintf(stdout, "List of public functions:\n");
	fprintf(stdout, "1. SinglyLinkedListNode* createSinglyLinkedList(int data)\n");
	fprintf(stdout, "2. unsigned int getLinkedListSize(SinglyLinkedListNode* head)\n");
	fprintf(stdout, "3. SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* head, int data)\n");
	fprintf(stdout, "4. SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data)\n");
	fprintf(stdout, "5. SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position)\n");
	fprintf(stdout, "6. SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position)\n");
	fprintf(stdout, "7. SinglyLinkedListNode* reverse(SinglyLinkedListNode* head)\n");
	fprintf(stdout, "8. bool compareLinkedLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)\n");
	fprintf(stdout, "9. SinglyLinkedListNode* mergeLinkedLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)\n");
	fprintf(stdout, "10. int getNode(SinglyLinkedListNode* head, int positionFromTail)\n");
	fprintf(stdout, "11. SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head)\n");
	fprintf(stdout, "12. bool bHasListCycle(SinglyLinkedListNode* head)\n");
	fprintf(stdout, "13. int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)\n");
	fprintf(stdout, "14. void reversePrint(SinglyLinkedListNode* head)\n");

	fprintf(stdout, "The printLinkedList function is not proposed to be tested as it will be used in every tests\n");

	while(bEndOfTest == false)
	{
		fprintf(stdout, "Type the name of the function to be tested.\n");
		fprintf(stdout, "Type 'quit' to leave the test.\n");
		fgets(user_input, 25, stdin);		
		strncpy(input, user_input, strlen(user_input) - 1);
		fprintf(stderr, "[%s]", input);
		if(strcmp(input, "quit") == 0)
		{
			bEndOfTest = true;
			fprintf(stdout, "End the test.\n");
		}
		else
		{

			
			for(unsigned int i = 0 ; i < NB_OF_PUBLIC_FUNCTIONS ; i++)
			{
				if(strcmp(input, tm[i].name) == 0)
				{
					if(tm[i].pfRunFunctionTests != NULL)
						tm[i].pfRunFunctionTests();
					else
						fprintf(stderr, "Function pointer to %s function is null\n", tm[i].name);
				}
			}			
		}
	}
	
	return 0;
}

TestManager* initialize(void)
{
	TestManager *tm = malloc(sizeof(TestManager) * NB_OF_PUBLIC_FUNCTIONS);
	
	strcpy(tm[0].name, "createSinglyLinkedList");
	tm[0].pfRunFunctionTests = (tpfRunFunctionTests)vidRunCreateSinglyLinkedList();
	
	// strcpy(tm[1].name, "getLinkedListSize");
	// tm[1].pfRunFunctionTests = (tpfRunFunctionTests)getLinkedListSize;
	
	// strcpy(tm[2].name, "insertNodeAtHead");
	// tm[2].pfRunFunctionTests = (tpfRunFunctionTests)insertNodeAtHead;
	
	// strcpy(tm[3].name, "insertNodeAtTail");
	// tm[3].pfRunFunctionTests = (tpfRunFunctionTests)insertNodeAtTail;
	
	// strcpy(tm[4].name, "insertNodeAtPosition");
	// tm[4].pfRunFunctionTests = (tpfRunFunctionTests)insertNodeAtPosition;
	
	// strcpy(tm[5].name, "deleteNode");
	// tm[5].pfRunFunctionTests = (tpfRunFunctionTests)deleteNode;
	
	// strcpy(tm[6].name, "reverse");
	// tm[6].pfRunFunctionTests = (tpfRunFunctionTests)reverse;
	
	// strcpy(tm[7].name, "compareLinkedLists");
	// tm[7].pfRunFunctionTests = (tpfRunFunctionTests)compareLinkedLists;
	
	// strcpy(tm[8].name, "mergeLinkedLists");
	// tm[8].pfRunFunctionTests = (tpfRunFunctionTests)mergeLinkedLists;
	
	// strcpy(tm[9].name, "getNode");
	// tm[9].pfRunFunctionTests = (tpfRunFunctionTests)getNode;
	
	// strcpy(tm[10].name, "removeDuplicates");
	// tm[10].pfRunFunctionTests = (tpfRunFunctionTests)removeDuplicates;
	
	// strcpy(tm[11].name, "bHasListCycle");
	// tm[11].pfRunFunctionTests = (tpfRunFunctionTests)bHasListCycle;
	
	// strcpy(tm[12].name, "findMergeNode");
	// tm[12].pfRunFunctionTests = (tpfRunFunctionTests)findMergeNode;
	
	// strcpy(tm[13].name, "printLinkedList");
	// tm[13].pfRunFunctionTests = (tpfRunFunctionTests)printLinkedList;
	
	// strcpy(tm[14].name, "reversePrint");
	// tm[14].pfRunFunctionTests = (tpfRunFunctionTests)reversePrint;
	
	return tm;
}

bool vidRunCreateSinglyLinkedList(void)
{
	printf("Hello world!\n");
	return 1;
}