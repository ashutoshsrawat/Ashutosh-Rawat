#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* root;

node* newNode(int number) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = number;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* createNode(node* root, int number) {
    if(root==NULL) {
        root = newNode(number);
        return root;
    }
    else if(number>root->data) {
        root->right = createNode(root->right, number);
    }
    else {
        root->left = createNode(root->left, number);
    }
}

void getNode(int number) {
    root = createNode(root, number);
}

void PrintPreorder(node* root) {
    if(root==NULL) return;
    else {
        printf("%d  ", root->data);
        if(root->left!=NULL) {
            PrintPreorder(root->left);
        }
        if(root->right!=NULL) {
            PrintPreorder(root->right);
        }
    }
}

int main() {
    root = NULL;
    getNode(40);
    getNode(30);
    getNode(20);
    getNode(10);
    getNode(25);
    getNode(35);
    getNode(50);
    getNode(45);
    getNode(60);
    getNode(70);
    getNode(55);
    PrintPreorder(root);
    return 0;
}