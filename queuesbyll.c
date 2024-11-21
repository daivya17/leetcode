#include <stdio.h>
#include <stdlib.h>
typedef struct p_node {
    int data;
    struct p_node* next;
} p_node;
p_node* init(int data) {
    p_node *n = (p_node*)malloc(sizeof(p_node));
    if (n == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    n->data = data;
    n->next = NULL;
    return n;
}
p_node* enquee(p_node **last, int data, p_node **head) {
    if (*head == NULL) {
        *head = init(data); 
        *last = *head;
        return *head;
    }
    p_node *l = *last;
    l->next = init(data);  
    *last = l->next;       
    return l->next;
}
int dequee(p_node **head) {
    if (*head == NULL) {
        printf("Queue is empty, nothing to dequeue.\n");
        return -1;  
    }
    p_node *h = *head;
    int r = h->data;  
    *head = h->next;  
    free(h);          
    return r;
}
void print_list(p_node *head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    p_node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    p_node *head = NULL;
    p_node *last = NULL;
    int choice, data;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue a node\n");
        printf("2. Dequeue a node\n");
        printf("3. Print the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                last = enquee(&last, data, &head);
                break;
            case 2:
                data = dequee(&head);
                if (data != -1) {
                    printf("Dequeued: %d\n", data);
                }
                break;
            case 3:
                print_list(head);
                break;
            case 4:
                while (head != NULL) {
                    dequee(&head);
                }
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
