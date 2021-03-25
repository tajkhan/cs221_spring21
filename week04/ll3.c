#include <stdio.h>
#include <stdlib.h>

typedef struct  node node;

struct node {
  int data;
  struct node *next;
};

void list_print (struct node *hp){
  printf ("list = ");
  struct node *t  = hp;
  while (t!=NULL){
		printf("%d, ", t->data);
		t = t->next;
  }
	printf("\n");
}


void list_delete (struct node **hp, int val){
  struct node *p = *hp;
  struct node *prev = NULL;

  if (p->data == val){
    *hp = p->next;
    free (p);
  }
  else {
		while (p->next!=NULL){
			if (p->data == val)
				break;

      prev = p;
			p = p->next;
    }

    prev->next = p->next;
    p->next =NULL;
    free (p);
  }
}
   
void list_insert_at_tail (struct node **hp){
  node * t = NULL;

  for (int i=0; i<10; i++){

    t = *hp;

    node *p = (node *) malloc (sizeof(node));
    p->data = i+10;
    p->next = NULL;

    if (t==NULL){
			*hp = p;
    }
    else{
			while (t->next!=NULL){
				t = t->next;
			}

      t->next = p;
    }
  }  
}


int main (){

  node * head = NULL;

  list_insert_at_tail (&head);

  list_print (head);

  list_delete (&head, 15);

  list_print (head);

  return 0;
}
