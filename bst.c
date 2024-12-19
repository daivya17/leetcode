#include<stdio.h>
#include<stdlib.h>
typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
}node;
node* create(){
    node* newnode = (node*)malloc(sizeof(node));
    printf("enter data:");
    scanf("%d",&newnode->data);
    newnode->left = newnode->right = NULL;
    return newnode;
}
void insert(node* root,node* newnode){
    if(newnode->data < root->data){
        if(root->left!=NULL){
            insert(root->left,newnode);
        }
        else{
            root->left = newnode;
        }
    }
    if(newnode->data > root->data){
        if(root->right!=NULL){
            insert(root->right,newnode);
        }
        else{
            root->right = newnode;
        }
    }
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void preorder(node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main() {
    char ch;
    node *root = NULL, *temp;
    
    do {
        temp = create();
        if (root == NULL)
            root = temp;
        else
            insert(root, temp);
        
        printf("\nDo you want to enter more(y/n)? ");
        getchar();  // To consume the newline character from previous input
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
