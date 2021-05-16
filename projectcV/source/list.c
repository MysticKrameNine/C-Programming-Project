#include"list.h"
#include <stdio.h>

//initialiser la liste list
void initListe (List *list, void (*destroy)(void *data)){
  list->head = NULL; 
  list->tail = NULL; 
  list->size = 0;
  list->destroy = destroy;
}
int sizeListe( List * list){
//renvoie le nombre d'element de la liste
  return list->size;
}
int insNextListe(List *list, ListElmt *elt, const void *data){
  //declarer une variable de type ListElmt
  //allouer de la memoire a la variable
  // inserer l'element dans la liste:
  //(a) affecter data au champs data de l'element
  //(b) si elt est NULL: inserer en-tete de liste
  //(c) sinon inserer apres elt 
  //(b.1) si taillelist = NULL : tailelist = newelement
  //      sinon newelementNext = listHead
  //      listHead <- l'adresse de newelement
  ListElmt *newElement;
  //allocation memoire a newElement
  newElement = malloc(sizeof(ListElmt));
  //inserer un element dans la liste
  //(a) affecter data au champs data de l'element
  newElement->data=(void*)data;
  //elt est NULL: inserer en-tete de liste
  if (elt == NULL){
    //on teste si la taille = 0
    if(sizeListe(list) == 0){
      list->tail = newElement;
    }
    newElement->next=list->head;
    list->head= newElement;
  }
  else{
//insertion apres elt
    if(elt->next==NULL){
      list->tail=newElement;
    }
    newElement->next=elt->next;
    elt->next=newElement;
 }
 //mettre a jour la taille de la liste
 list->size++;
 return 0;
}
ListElmt *headListe(const List *list){
  return list->head;
}
ListElmt *tailListe(const List *list){
  return list->tail;
}
int isTailListe(const List *list ,const ListElmt *elt){ 
  if( elt == list -> tail ){
    return 1;
  }
  else{
    return 0;
  }
}
int isHeadListe(const List *list, const ListElmt *elt){ 
  if( elt == list -> head ){
    return 1;
  }
  else{
    return 0;
  }
}
void *dataElement(const ListElmt*elt){
  return elt->data;
}
ListElmt *nextElement(const ListElmt *elt){
  return elt->next;
}

int delNextListe(List *list, ListElmt *elt, void **data) {
    ListElmt  *old_element;
    // tester si la liste est vide
    if (sizeListe(list) == 0){
       return -1;
}
    // supprimer un element de la liste
    if (elt == NULL) {
       // supprimer un element du debut de la liste(car elt=NULL)
      *data = list->head->data;
      old_element = list->head;
      list->head = list->head->next;
      if (sizeListe(list) == 1)
	       list->tail = NULL;
    } else { 
     
      //supprimer un element du milieu de la liste
      *data = elt->next->data;
      old_element = elt->next;
      elt->next = elt->next->next;
     //le cas ou elt est a la fin de la liste
      if (elt->next == NULL)
	       list->tail = elt;
    }
    free(old_element);
    // mettre a jour la taille de la liste
    list->size--;
    return 0;
}
void destroyListe (List *list){
  void *data;
  //si la liste est vide alors on fait rien
  if (sizeListe(list)==0){
    return;
  }
  else{
    while(sizeListe(list)>0){
      // on fait appel a delNextListe e pour supprimer un à un les éléments de la liste
      if(delNextListe(list, NULL, (void **)&data) ==0 && list->destroy !=NULL){
        list->destroy(data);
      }
    }

  }
}

