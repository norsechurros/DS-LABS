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
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertTerm(Node* header, int coef, int exp) {
    Node* newNode = createNode(coef, exp);
    if (header->next == NULL) {
        header->next = newNode;
        newNode->prev = header;
        newNode->next = header;
        header->prev = newNode;
        return;
    }

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
            printf("%dx^%d", current->coef, current->exp);
            isFirstTerm = 0;
        }
        current = current->next;
    }
    printf("\n");
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* resultHeader = createNode(0, 0);
    Node* current1 = poly1->next;
    Node* current2 = poly2->next;

    while (current1 != poly1 && current2 != poly2) {
        if (current1->exp == current2->exp) {
            int coef = current1->coef + current2->coef;
            insertTerm(resultHeader, coef, current1->exp);
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->exp > current2->exp) {
            insertTerm(resultHeader, current1->coef, current1->exp);
            current1 = current1->next;
        } else {
            insertTerm(resultHeader, current2->coef, current2->exp);
            current2 = current2->next;
        }
    }

    while (current1 != poly1) {
        insertTerm(resultHeader, current1->coef, current1->exp);
        current1 = current1->next;
    }

    while (current2 != poly2) {
        insertTerm(resultHeader, current2->coef, current2->exp);
        current2 = current2->next;
    }

    return resultHeader;
}

int main() {
    Node* poly1Header = createNode(0, 0);
    Node* poly2Header = createNode(0, 0);

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

    Node* resultHeader = addPolynomials(poly1Header, poly2Header);
    printf("Result of addition: ");
    displayPolynomial(resultHeader);

    return 0;
}
