/******************************************
*Student name: Omer Dekel
*Student ID: 
*Course Exercise Group: 01
*Exercise name: Exercise 6
******************************************/

#include "gadt.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct GADT_S {
	ELM val;
	struct GADT_S * next;
    ELM(*create_elm)();
    void(*cpy_elm)(ELM, ELM);
    int(*cmp_elm)(ELM, ELM);
    void(*free_elm)(ELM);
    void(*print_elm)(ELM);
    ELM(*add_elm_to_elm)(ELM, ELM);
} GADT_T;

/****************************************************
		* function name: SLCreate
		* input: ELM head_val,
			  ELM(*create_elm)(),
			  void(*cpy_elm)(ELM, ELM),
			  int(*cmp_elm)(ELM, ELM),
			  void(*free_elm)(ELM),
			  void(*print_elm)(ELM),
			  ELM(*add_elm_to_elm)(ELM, ELM))
		* output: ELM (pointer to the head)
		* operation function: the function creates a new node of the list
		by allocating a memory to the struct and puts there the value
		.we got, and the functions accordingly, the next pointer is initialized
		with NULL.
		* *********************************************/

HEAD SLCreate(ELM head_val,
			  ELM(*create_elm)(),
			  void(*cpy_elm)(ELM, ELM),
			  int(*cmp_elm)(ELM, ELM),
			  void(*free_elm)(ELM),
			  void(*print_elm)(ELM),
			  ELM(*add_elm_to_elm)(ELM, ELM))
{
	GADT_T *head = (GADT_T *)malloc(sizeof(struct GADT_S));
	//upon failure
	if (NULL == head)
		return NULL;
	else
	{
		head->val = create_elm();
		//copies the value from the user to the new node
		cpy_elm(head->val, head_val);
		head->next = NULL;
		head->create_elm = create_elm;
		head->cpy_elm = cpy_elm;
		head->cmp_elm = cmp_elm;
		head->free_elm = free_elm;
		head->print_elm = print_elm;
		head->add_elm_to_elm = add_elm_to_elm;
	}
	return head;
}

/****************************************************
		* function name: SLAddListElement
		* input: HEAD* head, ELM node
		* output:returns OUT_OF_MEM in case of failure to allocate memory,
		  SUCSESS in case we add a new node
		* operation function: the function appends the string pointed
		to by str1 to the end of the string pointed to by str2.
		* *********************************************/

Result SLAddListElement(HEAD* head, ELM node)
{
    //creating a new node
	GADT_T *new_node = (GADT_T *)SLCreate(node, ((GADT_T *)(*head))->create_elm,
						((GADT_T *)(*head))->cpy_elm,
						((GADT_T *)(*head))->cmp_elm,
						((GADT_T *)(*head))->free_elm,
						((GADT_T *)(*head))->print_elm,
						((GADT_T *)(*head))->add_elm_to_elm);
    int found = 0;
    int cmp;
	if (new_node==NULL)
		return OUT_OF_MEM;
    //checks if the value in the head is bigger the value in the node
	cmp = ((GADT_T *)(*head))->cmp_elm( ((GADT_T *)(*head))->val, node);
	if (cmp == 1)
	{
	    //replace between the head and the node
		new_node->next = ((GADT_T *)(*head));
		*head = (void *)new_node;
	}
	//if the value in node head is less then the current node
	else
	{
		GADT_T *cur_node = (GADT_T *)(*head);
		//running to the end of the list
		while (cur_node->next != NULL && !found)
		{
			cmp = cur_node->cmp_elm( cur_node->next->val, node);
			//if the next current node is less then the value we got
			if (cmp < 0)
			    //continue to the next node
				cur_node = cur_node->next;
            //the first node with bigger value was found
			else
				found = 1;
		}
		if (found)
			new_node->next = cur_node->next;
		cur_node->next = new_node;
	}
	return SUCEESS;
}

/****************************************************
		* function name: SLRemoveElement
		* input: HEAD* head, ELM node
		* output:returns SUCSESS if the node was removed
		else FAILURE
		* operation function: the function looking for the value in the parameter node
		in the list and free the node with that value.
		* *********************************************/

Result SLRemoveElement(HEAD* head, ELM node)
{
	GADT_T *cur_node = ((GADT_T *)(*head));
	GADT_T *d_node = NULL;
    int found = 0;
    //if the head is the node we want to delete
	if (cur_node->cmp_elm(node, cur_node->val) == 0)
	{
	    //head points to the next node
		*head = cur_node->next;
		d_node = cur_node;
	}
	else
	{
	    //else continue to search
		while (cur_node->next != NULL && !found)
		{
		    //if the node we want to delete equal to the one in the next node
			if (cur_node->cmp_elm(node, cur_node->next->val) == 0)
				found = 1;
			else
				cur_node = cur_node->next;
		}
		if (found)
		{
			d_node = cur_node->next;
			//the next pointer of the cur node is skipping to the next one
			cur_node->next = cur_node->next->next;
		}
	}
	if (d_node != NULL)
	{
		d_node->free_elm(d_node->val);
		free(d_node);
		return SUCEESS;
	}
	else
		return FAILURE;
}

/****************************************************
		* function name: SLFindElement
		* input: HEAD head, ELM node
		* output:ELM (pointer to the val in the node we found,
        NULL if it wasn't found)
		* operation function: the function looking for the value
        in the parameter node in the list by running all over
        the list until it's found.
		* *********************************************/

ELM SLFindElement(HEAD head, ELM node)
{
	GADT_T *cur_node = (GADT_T *)head;
	int found = 0;
	while (cur_node != NULL && !found)
	{
	    //checks if the cur node is the node we search
		if (cur_node->cmp_elm(node, cur_node->val) == 0)
			found = 1;
		else
            //continue to the next node
			cur_node = cur_node->next;
	}
	if (found)
		return cur_node->val;
	else
		return NULL;
}

/****************************************************
		* function name: SLDestroy
		* input: HEAD head
		* output:void
		* operation function: running all over the list and free
		every malloc of the value in the node, and then the whole node.
		* *********************************************/

void SLDestroy(HEAD head)
{
	GADT_T *cur_node = (GADT_T *)head;
	while (cur_node != NULL)
	{
		head = cur_node;
		cur_node = cur_node->next;
		//freeing the malloc of the value in the node
		((GADT_T *)head)->free_elm(((GADT_T *)head)->val);
		//freeing the whole node
		free(head);
	}
}

/****************************************************
		* function name: SLAddToElement
		* input: HEAD* head, ELM toEl, ELM addEl
		* output:void
		* operation function:checks if toEl is in the list, then if toEl is in
		the only node in the list we adding addEl to it,
		else we delete the node that points on toEl, then sends the node
        that points on the adding of the two elements to the list
		* *********************************************/

void SLAddToElement(HEAD* head, ELM toEl, ELM addEl)
{
    //if toEl is in the list
    if(SLFindElement(*head,toEl)!=NULL)
    {
        //if the length of the list is 1
        if (((GADT_T *)(*head))->next == NULL)
            ((GADT_T *)(*head))->add_elm_to_elm(((GADT_T *)(*head))->val, addEl);
        else
        {
            //removing the node before the adding action
            SLRemoveElement(head, toEl);
            ((GADT_T *)(*head))->add_elm_to_elm(toEl, addEl);
            //adding the node after the adding element to element
            SLAddListElement(head, toEl);
        }
    }
}

/****************************************************
		* function name: SLPrint
		* input: HEAD head
		* output:void
		* operation function:  the function go all over the list, then prints
		 every value in the node.
		* *********************************************/

void SLPrint(HEAD head)
{
    int i;
	GADT_T *cur_node = (GADT_T *)head;
	int tabNum = 0;
	//go all over the list
	while (cur_node != NULL)
	{
	    //printing tab
		for ( i = 0; i < tabNum; i++)
			printf("\t");
		cur_node->print_elm(cur_node->val);
		cur_node = cur_node->next;
		tabNum++;
	}
}

/****************************************************
		* function name: SLLength
		* input: HEAD head
		* output:the length of the list
		* operation function:  the function go all over the list,
		then counts every node in the list.
		* *********************************************/

int SLLength(HEAD head)
{
	int count = 0;
	GADT_T *cur_node = (GADT_T *)head;
	//go all over the list
	while (cur_node != NULL)
	{
		cur_node = cur_node->next;
		count++;
	}
	return count;
}
