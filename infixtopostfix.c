#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define max 100
char stack[max];
int top=-1;
void push(char x){
    if(top==max-1){
        printf("overflow stack full");
    }
    else{
        top++;
        stack[top]=x;
    }
}
char pop(){
    if(top==-1){
        printf("underflow stack empty");
    }
    else{
        return stack[top--];
    }
}
int preference(char x){
    if(x=='+'||x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    else if(x=='^'){
        return 3;
    }
    else{
        return 0;
    }
}
int isop(char x){
    return (x=='+'||x=='-' || x=='*' || x=='/' || x=='^');
}
void infixtopostfix(char *infix){
    char *ptr=infix;
    char postfix[max];
    int i=0;
    while(*ptr!='\0'){
        if(isalnum(*ptr)){
            postfix[i++]=*ptr;
        }
        else if(*ptr=='('){
            push(*ptr);
        }
        else if(*ptr==')'){
            while(stack[top]!='('){
                postfix[i++]=pop();
            }
            pop();
        }
        else if(isop(*ptr)){
            while(top!=-1 && preference(stack[top])>=preference(*ptr)){
                postfix[i++]=pop();
            }
            push(*ptr);
        }
        ptr++;
    }
    while(top!=-1){
        postfix[i++]=pop();
    }
    printf("postfix:%s",postfix);
}
int main(){
    char infix[max];
    printf("enter infix:");
    scanf("%s",infix);
    infixtopostfix(infix);
    return 0;
}
