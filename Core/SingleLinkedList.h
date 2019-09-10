/*
 * LinkedList.h
 *
 *  Created on: 24 août 2019
 *      Author: xxx
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "../Config/Configurations.h"
#include "../common.h"

typedef struct Element
{
	int data;
	struct Element *next;
}Element;

typedef struct List
{
	unsigned int size;
	Element *first;
}List;

extern List* create(int data);
extern boolean append(List *list, int data);
extern boolean appendAt(List *list, int data, unsigned int index);
extern boolean delete(List *list);
extern boolean deleteAt(List *list, unsigned int index);
extern boolean update(List *list, unsigned int index, int new_data);
extern void print(List *list);
extern int printAt(List *list, unsigned int index);
extern Element* get(List *list, unsigned int index);
extern unsigned int size(List *list);
extern boolean destroy(List *list);

#endif /* LINKEDLIST_H_ */
