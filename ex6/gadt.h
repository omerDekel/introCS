/******************************************
*Student name: Omer Dekel
*Course Exercise Group: 01
*Exercise name: Exercise 6
******************************************/

#ifndef GADT_H_INCLUDED
#define GADT_H_INCLUDED

#include <stdio.h>

//typedef declaration
typedef void* ELM;
typedef void* HEAD;
typedef enum { SUCEESS, OUT_OF_MEM, BAD_ARGS, FAILURE } Result;

HEAD SLCreate(ELM head_val,
			  ELM(*create_elm)(),
			  void(*cpy_elm)(ELM, ELM),
			  int(*cmp_elm)(ELM, ELM),
			  void(*free_elm)(ELM),
			  void(*print_elm)(ELM),
			  ELM(*add_elm_to_elm)(ELM, ELM));

void SLDestroy(HEAD head);

Result SLAddListElement(HEAD* head, ELM node);

Result SLRemoveElement(HEAD* head, ELM node);

ELM SLFindElement(HEAD head, ELM node);

void SLAddToElement(HEAD* head, ELM toEl, ELM addEl);

void SLPrint(HEAD head);

int SLLength(HEAD head);


#endif // GADT_H_INCLUDED
