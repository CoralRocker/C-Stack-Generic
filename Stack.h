#pragma once
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
	void** _stack;
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

void* topStack(Stack* s)
{
	return s->_stack[0];
}	

void pushStack(Stack* s, void* val)
{
	void** tmp = (void**)malloc(sizeof(void*)*s->_size);
	memcpy(tmp, s->_stack, sizeof(void*)*s->_size);
	free(s->_stack);
	s->_stack = (void**)malloc(sizeof(void*)*(s->_size+1));
	s->_size++;
	memcpy(s->_stack+1, tmp, sizeof(void*)*(s->_size-1));
	free(tmp);
	s->_stack[0] = val;
	s->empty = 0;

}

void popStack(Stack* s)
{
	s->_size--;
	if(s->_size != 0)
	{
		void** tmp = (void**)malloc(sizeof(void*)*s->_size);
		memcpy(tmp, s->_stack+1, sizeof(void*)*s->_size);
		free(s->_stack);
		s->_stack = (void**)malloc(sizeof(void*)*s->_size);
		memcpy(s->_stack, tmp, sizeof(void*)*s->_size);
		free(tmp);
	}else{
		s->empty = 0;
		free(s->_stack);
	}
}

