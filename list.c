#include <stdio.h>
#include <stdlib.h>
#include "list.h"
//Ryan Davis 
//linked list implementation
list_t *list_alloc() 
{
    list_t *elements;
    elements = malloc(sizeof(list_t));
	elements->head = NULL;
    return elements;
}

void list_print(list_t *elements) 
{
    //this function basically just prints out the list contents
    node_t *currentNode = elements->head;
    node_t *nextN = NULL;
    while (currentNode->next != NULL)
    {
        printf("%d -> ", currentNode->value);
        nextN = currentNode->next;
        currentNode = nextN;
    }
	printf("%d", currentNode->value);
	printf("\n");
}
//returns the length of the list
int list_length(list_t *elements) { 
    node_t *currentN = elements->head;
    int length = 0;
    while (currentN != NULL)
    {
        length ++;
        currentN = currentN->next;
    }
    return length; 
}
//adds the given node to the back of the list input
void list_add_to_back(list_t *elements, elem value) {
    node_t *newNode = malloc(sizeof(node_t));
    newNode->value = value;
    newNode->next = NULL;
    node_t *currentN = elements->head;
    while (currentN->next != NULL)
    {
        
        currentN = currentN->next;
    }
    
    currentN->next = newNode;
}
void list_add_to_front(list_t *elements, elem value) 
{
    node_t *newNode = malloc(sizeof(node_t));
    newNode->value = value;//assigning value to node
    newNode->next = elements->head;//new node points to head
	elements->head = newNode;//head = new node 
}
void list_add_at_index(list_t *elements, elem value, int index) {
    int count = 1;
    node_t *newNode= malloc(sizeof(node_t));
    newNode->value = value;
    newNode->next = NULL;
    node_t * currentN = elements->head;
    node_t* nextN = NULL;
    while (currentN != NULL && count < (index))
    {
        count++;
        nextN = currentN->next;
        currentN = nextN;
    }
    nextN = currentN->next;
    currentN->next = newNode;
    newNode->next = nextN;
}

elem list_remove_from_back(list_t *l) { 
    //remove a list element from the back
    node_t *prevN = l->head;
	node_t *currentN = prevN->next;
    while (currentN->next != NULL)
    {
		prevN = currentN;
        currentN = currentN->next;
    }
	prevN->next = NULL;
    elem value = currentN->value;
    free(currentN);
    return value; 
}
//remove the element  from the front of the list
elem list_remove_from_front(list_t *elements) 
{ 
    node_t *currentNode = elements->head;
    elements->head = currentNode->next;
    elem value = currentNode->value;
    free(currentNode);
    return value;
}
elem list_remove_at_index(list_t *l, int index) 
{ 
    int count = 0;
    node_t *prevN = l->head;
	node_t *currentN = prevN->next;
    while (currentN->next != NULL && count < (index - 1))
    {
        count++;
		prevN = currentN;
        currentN = currentN->next;
    }
    node_t *temp = currentN;
    prevN->next = currentN->next;
    elem value = temp->value;
    free(temp);
    return value;
}
/* Checks to see if the given element exists in the list. */
bool list_is_in(list_t *l, elem value) 
{
	bool exist;
    node_t *currentN = l->head;
    while (currentN->next != NULL && !exist)
    {
		if (currentN->value == value){
			exist = true;
		}
        currentN = currentN->next;
    }
    return exist; 
}

//gets the list element at the specific index
elem list_get_elem_at(list_t *l, int index) 
{
	int counter = 0;
	elem value = 0;
	node_t *currentN = l->head;
    while (currentN->next != NULL && counter < (index))
    {
		counter++;
        currentN = currentN->next;
    }
	if (currentN != NULL){
		value = currentN->value;
	}
	return value; 
}

void list_free(list_t *l) {
    if (l == NULL)
    {
        return;
    }
    node_t *currentN = l->head;
    node_t *nextN = NULL;
    while (currentN != NULL)
    {
        nextN = currentN->next;
        free(currentN);
        currentN = nextN;
    }
    l->head = NULL;
    free(l);
}

/* Returns the index at which the given element appears. */
int list_get_index_of(list_t *l, elem value) {
	int counter = 0;
	node_t *currentN = l->head;
    while (currentN->next != NULL)
    {
		if (currentN->value == value){
			return counter;
		} else {
			counter++;
			currentN = currentN->next;
		}
    }
	return counter; 
}