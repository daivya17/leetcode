#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createnode(int val){
    struct Node* newnode=(struct Node*) malloc (sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}
struct Node* createll(){
    struct Node* head = NULL;
    return head;
}
void insertatstart(struct Node** head,int val){
    struct Node* newnode = createnode(val);
    newnode->next = *head;
    *head = newnode;
}
void display(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int len(struct Node* head){
    int count = 0;
    struct Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}
void sort(struct Node** head){
    int n = len(*head);
    for(int i=0;i<n;i++){
        struct Node* temp = *head;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->data > temp->next->data){
                int x = temp->data;
                temp->data = temp->next->data;
                temp->next->data = x;
            }
            temp = temp->next;
        }
    }
}
void rev(struct Node** head){
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* forward = NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    *head = prev;
}
void concat(struct Node** head1, struct Node** head2){
    struct Node* temp = *head1;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = *head2;
}
int main(){
    struct Node* head1 = createll();
    insertatstart(&head1,3);
    insertatstart(&head1,2);
    insertatstart(&head1,4);
    insertatstart(&head1,5);
    insertatstart(&head1,1);
    display(head1);
    rev(&head1);
    display(head1);
    sort(&head1);
    display(head1);
    struct Node* head2 = createll();
    insertatstart(&head2,10);
    insertatstart(&head2,9);
    insertatstart(&head2,8);
    insertatstart(&head2,7);
    insertatstart(&head2,6);
    display(head2);
    concat(&head1,&head2);
    display(head1);
    return 0;
}
