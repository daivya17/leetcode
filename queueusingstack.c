#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Stack {
    int *arr;
    int capacity;
    int top;
} Stack;
typedef struct {
    Stack *stack1;
    Stack *stack2;
} MyQueue;
Stack* createstack(int capacity){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->arr = (int *)malloc(capacity * sizeof(int));
    return stack;
}
bool isEmpty(Stack *stack) {
   return stack->top==-1;
}
void push(Stack *stack, int item){
    stack->arr[++stack->top]=item;
}
int pop(Stack *stack){
    return stack->arr[stack->top--];
}
int top(Stack *stack){
    return stack->arr[stack->top];
}
MyQueue* myQueueCreate() {
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->stack1=createstack(100);
    queue->stack2=createstack(100);
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    push(obj->stack1,x);
}

int myQueuePop(MyQueue* obj) {
    if(isEmpty(obj->stack2)){
        while(!isEmpty(obj->stack1)){
            push(obj->stack2,pop(obj->stack1));
        }
    }
    return pop(obj->stack2);
}

int myQueuePeek(MyQueue* obj) {
    if(isEmpty(obj->stack2)){
        while(!isEmpty(obj->stack1)){
            push(obj->stack2,pop(obj->stack1));
        }
    }
    return top(obj->stack2);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->stack1) && isEmpty(obj->stack2);
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1->arr);
    free(obj->stack1);
    free(obj->stack2->arr);
    free(obj->stack2);
    free(obj);
}
