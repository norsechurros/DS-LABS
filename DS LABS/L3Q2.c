#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure of a stack node
struct sNode {
    char data;
    struct sNode* next;
};

// Function to push an item to stack
void push(struct sNode** top_ref, char new_data);

// Function to pop an item from stack
char pop(struct sNode** top_ref);

// Returns 1 if character1 and character2 are matching left
// and right Brackets
bool isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return true;
    else if (character1 == '{' && character2 == '}')
        return true;
    else if (character1 == '[' && character2 == ']')
        return true;
    else
        return false;
}

// Return true if expression has balanced Brackets
bool areBracketsBalanced(char exp[]) {
    int i = 0;

    // Declare an empty character stack
    struct sNode* stack = NULL;

    // Traverse the given expression to check matching
    // brackets
    while (exp[i]) {
        // If the exp[i] is a starting bracket then push
        // it
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(&stack, exp[i]);

        // If exp[i] is an ending bracket then pop from
        // stack and check if the popped bracket is a
        // matching pair
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            // If we see an ending bracket without a pair
            // then return false
            if (stack == NULL)
                return false;

            // Pop the top element from stack, if it is not
            // a pair bracket of character then there is a
            // mismatch.
            // This happens for expressions like {(})
            else if (!isMatchingPair(pop(&stack), exp[i]))
                return false;
        }
        i++;
    }

    // If there is something left in expression then there
    // is a starting bracket without a closing
    // bracket
    return (stack == NULL);
}

// Function to push an item to stack
void push(struct sNode** top_ref, char new_data) {
    // allocate node
    struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));

    if (new_node == NULL) {
        printf("Stack overflow\n");
        exit(0);
    }

    // put in the data
    new_node->data = new_data;

    // link the old list of the new node
    new_node->next = (*top_ref);

    // move the head to point to the new node
    (*top_ref) = new_node;
}

// Function to pop an item from stack
char pop(struct sNode** top_ref) {
    char res;
    struct sNode* top;

    // If stack is empty then error
    if (*top_ref == NULL) {
        printf("Stack overflow\n");
        exit(0);
    } else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

int main5() {
    char exp[100];
    printf("Enter an expression: ");
    fgets(exp, sizeof(exp), stdin);

    if (areBracketsBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
