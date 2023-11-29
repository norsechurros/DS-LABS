#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;

Node* createNode(int coef, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* initializeHeader() {
    Node* header = createNode(0, 0);
    header->next = header;
    header->prev = header;
    return header;
}

void insertTerm(Node* header, int coef, int exp) {
    Node* newNode = createNode(coef, exp);
    Node* current = header->next;

    while (current != header && current->exp > exp) {
        current = current->next;
    }

    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
}

void displayPolynomial(Node* header) {
    Node* current = header->next;
    if (current == header) {
        printf("0\n");
        return;
    }
    int isFirstTerm = 1;
    while (current != header) {
        if (current->coef > 0) {
            if (!isFirstTerm) {
                printf(" + ");
            }
            printf("%d*x^%d", current->coef, current->exp);
            isFirstTerm = 0;
        }
        current = current->next;
    }
    printf("\n");
}

Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* resultHeader = initializeHeader();
    Node* current1 = poly1->next;

    while (current1 != poly1) {
        Node* current2 = poly2->next;
        while (current2 != poly2) {
            int coef = current1->coef * current2->coef;
            int exp = current1->exp + current2->exp;
            insertTerm(resultHeader, coef, exp);
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    return resultHeader;
}

int main() {
    Node* poly1Header = initializeHeader();
    Node* poly2Header = initializeHeader();

    // Insert terms into poly1 and poly2
    insertTerm(poly1Header, 3, 2);
    insertTerm(poly1Header, 2, 1);
    insertTerm(poly1Header, 5, 0);

    insertTerm(poly2Header, 4, 3);
    insertTerm(poly2Header, 1, 1);

    printf("Polynomial 1: ");
    displayPolynomial(poly1Header);
    printf("Polynomial 2: ");
    displayPolynomial(poly2Header);

    Node* resultHeader = multiplyPolynomials(poly1Header, poly2Header);
    printf("Result of multiplication: ");
    displayPolynomial(resultHeader);

    // Free the memory
    Node* current = resultHeader->next;
    while (current != resultHeader) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(resultHeader);

    return 0;
}
