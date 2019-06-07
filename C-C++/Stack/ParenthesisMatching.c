#include <stdio.h>
#define MAX_STACK 100

typedef enum {false, true} bool;
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

bool IsParantBalanced(char*exp, int len){
    Stack stack;
    InitStack(&stack);
    for (int i=0; i<len;i++){
        if(exp[i]=='(')
           Push(&stack, exp[i]);
        else if (exp[i]==')'){
            if (IsEmpty(&stack))
               return false;
            else
                Pop(&stack);
        }
    }
    if (IsEmpty(&stack))
       return true;
    else
       return false;
}