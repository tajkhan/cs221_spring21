#include <stdio.h>
#include <stdlib.h>

typedef struct  node node;

struct node {
  struct node *next;
  int data;
};


void ll_print (node *hp){
  printf ("ll: ");
  while (hp!=NULL){
		printf("%d, ", hp->data);
		hp = hp->next;
  }
  printf ("\n");
}

void ll_remove (node *hp, int val){
  //printf("%p %p\n", hp, hp->next);
	node *t = hp;
  if (t==NULL)
		return;

  if (t->data==val){  // first element
		hp = hp->next;
		//t->next=NULL;
		free (t);
		return;
  }
  else {
		while (t->next != NULL && t->next->data!=val)
			t = t->next;

    if (t->next==NULL) // val not found.
			return;
	  else{		// val found
			node *premove = t->next; // store pointer to node-to-be-removed
			t->next = t->next->next; // rearrange ll to skip the node-to-be-removed
      free (premove);	// remove node-to-be-removed
		}
  }
}

void ll_insert_at_head (node *hp, int val){
  node  *p = (node *)malloc (sizeof(node));
  if (p==NULL){fprintf(stderr, "error allocating memory\n"); exit (-1);}

  p->data = val;
  p->next = NULL;

  if (hp==NULL){
		hp = p;
  }
  else {
		p->next = hp;
		hp = p;
  }
}

void ll_insert_at_tail (node *hp, int val){
  node  *p = (node *)malloc (sizeof(node));
  if (p==NULL){fprintf(stderr, "error allocating memory\n"); exit (-1);}

  p->data = val;
  p->next = NULL;

  if (hp==NULL){
		hp = p;
  }
  else {
    node *t = hp;
    while (t->next!=NULL)
			t = t->next;

		t->next = p;
  }
}

void ll_insert_after (node *hp, int guard, int val){
  // inserts after the node whose data==guard
  // if there's no such node, does nothing
  node  *p = (node *)malloc (sizeof(node));
  if (p==NULL){fprintf(stderr, "error allocating memory\n"); exit (-1);}

  p->data = val;
  p->next = NULL;

  if (hp==NULL){
		return; //empty list; no node has val==guard
  }
  else {
    node *t = hp;
    while (t->next!=NULL && t->next->data!=guard)
			t = t->next;

    if (t->next==NULL) // guard not found
			return;
		else { // guard found; insert after guard
			p->next = t->next->next;
			t->next->next = p;
		}
  }
}

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


  ll_print(head);
  ll_remove(head, 16);
  ll_print(head);
  ll_remove(head, 18);
  ll_print(head);
  ll_insert_after (head, 17, 23);
  ll_print(head);
  ll_remove(head, 10);
  ll_print(head);
  ll_remove(head, 19);
  ll_print(head);

  return 0;
}
