#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct stack stack;
typedef struct node node;

struct node {
	int data;
	node *next;
};

struct stack {
	node *top;
};

void push (struct stack* ss, int val){

	if (ss==NULL){fprintf(stderr, "NULL ptr passed\n"); exit(-1);}

	node *p = (node *) malloc (sizeof(node));
	if (p==NULL){fprintf(stderr, "Memory error\n"); exit(-1);}
	p->data = val;
	p->next = NULL;

	p->next = ss->top;
	ss->top = p;
}

int pop (struct stack *ss){
	if (ss==NULL){fprintf(stderr, "NULL ptr passed"); exit(-1);}

	if (ss->top==NULL){
		fprintf(stderr, "can't pop. stack is EMPTY\n");
	}
	else {
		node *p = ss->top;
		ss->top = ss->top->next;
	
    int val = p->data;
		p->next = NULL;
		free (p);
		return val;
	}
}

int main (){

	stack s;
	s.top = NULL;

	pop(&s);

	for(int i=0; i<N+1; i++)
		push(&s, i+N);

	for(int i=0; i<N+1; i++)
		printf("%d\n", pop(&s));
	//printf("%d\n", pop(&s));

	return 0;
}
