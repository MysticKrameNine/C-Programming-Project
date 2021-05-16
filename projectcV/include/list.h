#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
typedef struct ListElmt_
{
 void *data;//data est de type (void *)
 struct ListElmt_ *next;
} ListElmt;
typedef struct List_
{
 int size;
 void (*destroy)(void *data);
 ListElmt *head;
 ListElmt *tail;
} List;
void initListe (List *list, void (*destroy)(void *data));
//#define sizeListe(list) ((list)->size) 
// une macro//…
int sizeListe( List * list);
int insNextListe(List *list, ListElmt *elt, const void *data); 
ListElmt *headListe(const List *list);
ListElmt *tailListe(const List *list);
int isTailListe(const List *list,const ListElmt *elt);
int isHeadListe(const List *list, const ListElmt *eltt);
void *dataElement(const ListElmt *elt);
ListElmt *nextElement(const ListElmt *elt);
int delNextListe(List *list, ListElmt *elt, void **data);
void destroyListe (List *list);
#endif
