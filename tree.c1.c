#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Fixed typo: structNode -> struct Node
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) { // Fixed: Changed '=' to '!='
        inorder(root->left);
        printf("%d ", root->data); // Added space for better formatting
        inorder(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Added space for better formatting
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data); // Fixed: removed extra quote after %d
    }
}

// Main function
int main() {
    // Build the binary tree
    struct Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6); // Fixed typo: rigt -> right
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7); // Fixed typo: riht -> right

    // Print traversals
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root); // Fixed typo: preorer -> preorder
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root); // Fixed typo: postordr -> postorder
    printf("\n");

    return 0;
}

