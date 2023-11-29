#include <stdio.h>
#include <stdlib.h>
//binary first as well
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

void inOrderIterative(Node* root) {
    if (root == NULL) return;

    Node* current = root;
    Node* stack[100];
    int top = -1;

    while (1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        if (top == -1) break;

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}

void postOrderIterative(Node* root) {
    if (root == NULL) return;

    Node* current = root;
    Node* stack1[100];
    Node* stack2[100];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = current;

    while (top1 != -1) {
        current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left) stack1[++top1] = current->left;
        if (current->right) stack1[++top1] = current->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

void preOrderIterative(Node* root) {
    if (root == NULL) return;

    Node* current = root;
    Node* stack[100];
    int top = -1;

    stack[++top] = current;

    while (top != -1) {
        current = stack[top--];
        printf("%d ", current->data);

        if (current->right) stack[++top] = current->right;
        if (current->left) stack[++top] = current->left;
    }
}

Node* findParent(Node* root, int key) {
    if (root == NULL) return NULL;

    Node* parent = NULL;
    Node* current = root;

    while (current != NULL && current->data != key) {
        parent = current;
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL)
        return NULL;
    else
        return parent;
}

int findDepth(Node* root) {
    if (root == NULL) return 0;

    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

void printAncestors(Node* root, int key) {
    if (root == NULL) return;

    Node* current = root;

    while (current != NULL && current->data != key) {
        printf("%d ", current->data);
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL)
        printf("Element not found.\n");
}

int countLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;

    int leftLeaves = countLeafNodes(root->left);
    int rightLeaves = countLeafNodes(root->right);

    return leftLeaves + rightLeaves;
}

int main() {
    Node* root = NULL;
    int numNodes;
    int data;

    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &numNodes);

    printf("Enter the elements of the binary tree:\n");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &data);
        if (root == NULL) {
            root = createNode(data);
        } else {
            Node* current = root;
            while (1) {
                if (data < current->data) {
                    if (current->left == NULL) {
                        current->left = createNode(data);
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == NULL) {
                        current->right = createNode(data);
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    printf("In-order traversal: ");
    inOrderIterative(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderIterative(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrderIterative(root);
    printf("\n");

    int element;
    printf("Enter an element to find its parent: ");
    scanf("%d", &element);
    Node* parent = findParent(root, element);
    if (parent != NULL)
        printf("Parent of %d is %d\n", element, parent->data);
    else
        printf("%d is the root element.\n", element);

    printf("Depth of the tree: %d\n", findDepth(root));

    printf("Enter an element to find its ancestors: ");
    scanf("%d", &element);
    printf("Ancestors of %d: ", element);
    printAncestors(root, element);
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}
