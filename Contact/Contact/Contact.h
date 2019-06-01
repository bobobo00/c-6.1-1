#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <errno.h>

#define NAME_SIZE 32
#define TELE_SIZE 12
#define ADDRESS_SIZE 256
#define DEFAULT 1

typedef struct Person{
	char name[NAME_SIZE];
	char sex;
	unsigned char age;
	char tele[NAME_SIZE];
	char  address[ADDRESS_SIZE];
}person,*person_p,**person_pp;

typedef struct Contact{
	int cap;
	int size;
	person contact[0];
}contact,*contact_ct;


int InitList(contact **ct);
void AddList(contact_ct ct);
void DeletList(contact_ct ct);
void CheckList(contact_ct ct);
void AlterList(contact_ct ct);
void ShowList(contact_ct ct);
void ClearList(contact_ct ct);
void SortList(contact_ct ct);
void DesList(contact_ct ct);
void Menue();

#endif