#pragma once
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
	int* _stack;
	long empty: 1;
	long _size: 31;
} Stack;

Stack* initStack()
{
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->_stack = NULL;
	s->_size = 0;
	s->empty = 1;
	return s;
}

void freeStack(Stack *s)
{
	if(s->_size==0)
		free(s->_stack);
	s->_size = 0;
	s->empty = 1;
	free(s);
}

int topStack(Stack* s)
{
	return s->_stack[0];
}	

void pushStack(Stack* s, int val)
{
	int* tmp = (int*)malloc(sizeof(int)*s->_size);
	memcpy(tmp, s->_stack, sizeof(int)*s->_size);
	free(s->_stack);
	s->_stack = (int*)malloc(sizeof(int)*(s->_size+1));
	s->_size++;
	memcpy(s->_stack+1, tmp, sizeof(int)*(s->_size-1));
	free(tmp);
	s->_stack[0] = val;
	s->empty = 0;

}

void popStack(Stack* s)
{
	s->_size--;
	if(s->_size != 0)
	{
		int* tmp = (int*)malloc(sizeof(int)*s->_size);
		memcpy(tmp, s->_stack+1, sizeof(int)*s->_size);
		free(s->_stack);
		s->_stack = (int*)malloc(sizeof(int)*s->_size);
		memcpy(s->_stack, tmp, sizeof(int)*s->_size);
		free(tmp);
	}else{
		s->empty = 0;
		free(s->_stack);
	}
}

