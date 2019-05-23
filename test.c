#include <stdio.h>
#include "Stack.h"

void printStack(Stack os)
{
	Stack s = os;
	printf("Stack Contents: (Higher Position In Stack Means Closer To Top)\n");
	while(s._size > 0)
	{
		printf("Stack Position %d: %d\n", s._size, topStack(&s));
		popStack(&s);
	}
}

int main()
{
	Stack* s = initStack();
	pushStack(s, 10);
	pushStack(s, 30);
	pushStack(s, 20);
	pushStack(s, 5);
	pushStack(s, 1);
	printf("Top: %d\n", topStack(s));
	printf("Stack:\n");
	printStack(*s);

	freeStack(s);
}
