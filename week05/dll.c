#include <stdio.h>
#include <stdlib.h>

#define OFFSET 32

typedef struct  node node;

struct node {
  int data;
  struct node *next;
  struct node *prev;
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


// delete first node whose data==val
void list_delete (struct node **hp, int val){

  if (hp==NULL){perror("NULL ptr passed\n"); exit(-1);}

  struct node *p = *hp;
	if (p==NULL) return;

  /*
	while (p->data!=val && p->next!=NULL){
		p = p->next;
	}
	*/
	while (p!=NULL && p->data!=val)
		p = p->next;

  if (p==NULL) return;

  if (*hp == p){	// first node
		*hp = p->next;
		(*hp)->prev=NULL;
		p->next=NULL;
	}
	else if (p->next==NULL){	// last node
		p->prev->next = p->next;
		p->prev = NULL;
	}
	else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		p->next = p->prev = NULL;
	}

	free (p);
}
   
void list_insert_at_tail (struct node **hp, int val){

  if (hp==NULL){perror("NULL ptr passed\n"); exit(-1);}

  node * t = *hp;

	node *p = (node *) malloc (sizeof(node));
  if (p==NULL){perror("Memory error\n"); exit(-1);}

	p->data = val;
	p->next = NULL;
	p->prev = NULL;

	if (t==NULL){
		*hp = p;
	}
	else{
		while (t->next!=NULL){
			t = t->next;
		}

		t->next = p;
		t->next->prev = t;	//p->prev = t;
	}
}


int main (){

  node * head = NULL;

	for (int i=0; i<10; i++)
		list_insert_at_tail (&head, i+OFFSET);

  list_print (head);

  list_delete (&head, 37);

  list_print (head);

  list_delete (&head, OFFSET);

  list_print (head);

  list_delete (&head, OFFSET+9);

  list_print (head);

  return 0;
}
