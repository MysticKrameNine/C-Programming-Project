//main.c
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
// cette fonction vous permettra de parcourir et afficher la liste
/*static void print_list(const List *list)
{
 ListElmt *element;
 int *data,
 i;
 fprintf(stdout, "List size is %d\n", sizeListe(list));
 i = 0;
 element = headListe(list);
 while (1)
 {
 data = dataElement(element);
 fprintf(stdout, "list[%03d]=%03d\n", i, *data);
 i++;
 if (isTailListe(element))
 break;
 else
 element = nextElement(element);
 }
 return;
}*/
int main(int argc, char **argv){
  List list;
  ListElmt *element;
  int *data, i,*data2;
  initListe(&list, free);// Je passe en paramètre un pointeur sur la fonction free. Pourquoi?
  printf("size de la liste initial=%d\n",sizeListe(&list));
 /*fprintf(stdout, "Size of the list : ");
 printf("%d\n", sizeListe(&list));*/
 //inserer les elements dans la liste tout en affichant la taille apres chaque insertion
  data=malloc(sizeof(int));
  *data =10;
  insNextListe(&list,NULL,data);
  printf("size de la liste apres ajout de data=%d\n",sizeListe(&list));
  data2=malloc(sizeof(int));
  *data2 =15;
  insNextListe(&list,NULL,data2);
  printf("size de la liste apres ajout de data2=%d\n",sizeListe(&list));
  int *data3;
  data3=malloc(sizeof(int));
  *data3=13;
  insNextListe(&list,NULL,data3);
  printf("size de la liste apres ajout de data3=%d\n",sizeListe(&list));
  /*void *d=(list.head)->data;
  int *p = (int *) d;
  printf("%d\n",*p);*/
//*headListe(const list);
//*tailListe(const list);
  headListe(&list);
  tailListe(&list);
  //inserer un nouvel element
  int *data4;
  data4=malloc(sizeof(int));
  *data4=86;
  insNextListe(&list,NULL,data4);
  printf("size de la liste apres ajout de data4=%d\n",sizeListe(&list));
  //afficher le head et le tail de la liste
  element=headListe(&list);
  printf("le head de la liste contient la valeur:%d\n",*(int*)(dataElement(headListe(&list))));
  element=tailListe(&list);
  printf("le tail de la liste contient la valeur:%d\n",*(int*)(dataElement(tailListe(&list))));
  //verifier si notre element est head ou tail de la liste
  element=tailListe(&list);
  printf("si l'element est le tail de la liste=1,sinon=0 alors c'est:%d\n", isTailListe(&list, headListe(&list)));
  element=headListe(&list);
  printf("si l'element est le head de la liste=1,sinon=0 alors c'est:%d\n", isHeadListe(&list, element));
//afficher la data de notre element
  data =dataElement(element);
  printf("le data de l'element est :%d\n",*data);
// afficher l'element qui suit notre element
  int *datanext;
  datanext=dataElement(nextElement(headListe(&list)));
  printf("l'element next est:%d\n",*datanext);
//isTailListe(const ListElmt *elt);
//isHeadListe(const List *list, const ListElmt *elt);
//*dataElement(const elt);
//*nextElement(const ListElmt *elt);
  
delNextListe(&list,element,(void**)&data);
printf("size de la liste apres suppression d'un element est:=%d\n", sizeListe(&list));
destroyListe(&list);
 return 0;
} 
