#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct stack stack;

struct stack {
	int a[N];
	int top;
};

void push (struct stack* ss, int val){
	if (ss==NULL){fprintf(stderr, "NULL ptr passed"); exit(-1);}

	if (ss->top==N){
		fprintf(stderr, "can't push %d. stack in FULL\n", val);
	}
	else {
		ss->a[ss->top] = val;
		ss->top++;
	}
}

int pop (struct stack *ss){
	if (ss==NULL){fprintf(stderr, "NULL ptr passed"); exit(-1);}

	if (ss->top==0){
		fprintf(stderr, "can't pop. stack is EMPTY\n");
	}
	else {
		ss->top = ss->top-1;
		return ss->a[ss->top];
	}
}

int main (){

	stack s;
	s.top = 0;

	for(int i=0; i<N+1; i++)
		push(&s, i+N);

	for(int i=0; i<N; i++)
		printf("%d\n", pop(&s));
	pop(&s);
	//printf("%d\n", pop(&s));

	return 0;
}
