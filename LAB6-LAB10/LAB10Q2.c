
#include <stdio.h>
#include <stdlib.h>
//binary tree recursive
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

int main() {
    Node* root = NULL;
    int n, data;

    printf("Enter the number of elements in the binary tree: ");
    scanf("%d", &n);

    printf("Enter the elements of the binary tree:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("In-order traversal of the binary tree: ");
    printInOrder(root);
    printf("\n");

    return 0;
}
