# C-Stack

# Accessor Methods
|Method|Usage|
|:-:|:-|
|directAccess|s->_stack[index] where s is the Stack object and index is the element to retrieve.|
|topStack(Stack *s)|topStack(s) where s is the Stack object. Returns the item on the top of the stack.|
|size variable|s->_size where s is the Stack object. Returns the number of elements in the stack. The maximum size is 2147483648 elements, or 2^31 elements. It's unlikely you'll ever actually use anywhere near that many elements, however.|
|empty variable|s->empty where s is the Stack object. Returns a 1 or a 0. 1 if it is empty, 0 if not. Is only 1 bit, so no other information should be stored in it.|

# Modifier Methods
|Method|Usage|
|:-:|:-|
|pushStack(Stack *s, void* val)| pushStack(s, num) where s is the Stack object and num is the value to input. Adds value to top of stack, updating both empty and _size variables.|
|popStack(Stack *s)|popStack(s) where s is the Stack object. Removes the element last added. Updates _size and empty accordingly.|

# Initializing a Stack
The method `Stack* initStack()` creates a new, empty stack object. It should be used with `void freeStack(Stack *s)` in order to prevent memory leaks. The initialized stack is empty and its stack pointer is set to NULL.
