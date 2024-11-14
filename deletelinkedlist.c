#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createnode(int val){
    struct Node* newnode=(struct Node*) malloc (sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}
struct Node* createll(){
    struct Node* head=NULL;
    return head;
}
void insertatstart(struct Node** head,int data){
    struct Node* node1=createnode(data);
    node1->next=*head;
    *head=node1;
}
void insertatend(struct Node** head,int data){
    struct Node* node1=createnode(data);
    if(*head==NULL){
        *head=node1;
    }
    else{
        struct Node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=node1;
    }
}
void display(struct Node** head){
    struct Node* temp=*head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void deletefirst(struct Node** head){
    struct Node* temp=*head;
    *head=temp->next;
    temp->next=NULL;
    free(temp);
}
void deletelast(struct Node** head){
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL; 
    free(temp);
}
void deletebyval(struct Node** head,int val){
    struct Node* temp = *head;
    if(temp!=NULL && temp->data==val){
        *head=temp->next;
        free(temp);
    }
    struct Node* prev=NULL;
    while(temp!=NULL && temp->data!=val){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("element not found\n");
    }
    prev->next=temp->next;
    free(temp);
}
int main(){
    struct Node* head=createll();
    insertatstart(&head,5);
    insertatstart(&head,4);
    insertatstart(&head,3);
    insertatstart(&head,2);
    insertatstart(&head,1);
    display(&head);
    deletefirst(&head);
    display(&head);
    deletelast(&head);
    display(&head);
    deletebyval(&head,3);
    display(&head);
    return 0;
}
