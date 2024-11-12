#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createnode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode-> data=value;
    newNode->next=NULL;
    return newNode;
}
struct Node* createlinkedlist(){
    struct Node* head = NULL;
    return head;
}
void insertatstart(struct Node** head,int value){
    struct Node* newnode=createnode(value);
    newnode->next=*head;
    *head=newnode;
}
void insertatend(struct Node** head,int value){
    struct Node* newnode = createnode(value);
    if(*head==NULL){
        *head=newnode;
    }
    else{
        struct Node* temp = *head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void insertatposition(struct Node** head,int pos,int value){
    struct Node* newnode=createnode(value);
    if(pos==1){
        newnode->next=*head;
        *head=newnode;
    }
    else{
        struct Node* temp = *head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
        if (temp == NULL) {
        printf("Position is greater than the length of the list.\n");
        return;
    }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void display(struct Node* head){
    if(head==NULL){
        printf("linked list empty\n");
    }
    else{
        struct Node* temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    struct Node* head = createlinkedlist();
    insertatstart(&head,3);
    insertatstart(&head,2);
    insertatstart(&head,1);
    display(head);
    insertatend(&head,5);
    insertatposition(&head,4,4);
    display(head);
    return 0;
}
