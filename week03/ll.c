#include <stdio.h>
#include <stdlib.h>

typedef struct  node node;

struct node {
  int data;
  struct node *next;
};


int main (){

  node * head = NULL;
  node * t = NULL;

  for (int i=0; i<10; i++){

    t = head;
    node *p = (node *) malloc (sizeof(node));
    p->data = i+10;
    p->next = NULL;

    if (t==NULL){
			head = p;
    }
    else{
			while (t->next!=NULL){
				t = t->next;
			}

      t->next = p;
    }
  }  


  printf ("values in my linked list are:\n");
  t = head;
  while (t!=NULL){
		printf("%d\n", t->data);
		t = t->next;
  }

  return 0;
}
