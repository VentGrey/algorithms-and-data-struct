#include <stdio.h>
#include <stdbool.h>

#define MAX_STACK 100


typedef int Data;

typedef struct{
    Data items[MAX_STACK];
    int top;
} Stack;

void InitStack(Stack *pstack){
    pstack ->top=-1;
}
bool IsFull(Stack*pstack){
    return pstack->top ==MAX_STACK -1;
}

bool IsEmpty(Stack *pstack){
    return pstack -> top ==-1;
}

Data Peek (Stack *pstack){
    if (IsEmpty(pstack))
        exit(1)
    return pstack->items[pstack->top];
}

void Push(Stack*pstack, Data item){
    if (IsFull(pstack))
        exit(1);
    pstack->items[++(pstack->top)]=item;
}
void Pop(Stack*pstack){
    it(IsEmpty(pstack))
       exit(1);
    --(pstack->top);
}

void ReversePrint(char*s, int len){
    Stack stack;
    char ch;

    InitStack(&stack);
    for(int i=0;i<len;i++)
        Push(&stack, s[i]);
    while (!IsEmpty(&stack)){
        ch=Peek(&stack);
        printf("%c", ch);
        Pop(&stack);
    }
}
