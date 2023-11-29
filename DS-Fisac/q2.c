#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

// Stack data structure to store opening tags
char stack[MAX_LENGTH];
int top = -1;

// Function to push an element onto the stack
void push(char element) {
    if (top >= MAX_LENGTH - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = element;
}

// Function to pop an element from the stack
void pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return;
    }
    top--;
}

int main() {
    char input[MAX_LENGTH];
    int count = 0;
    bool inTag = false;

    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '#'; i++) {
        if (input[i] == '<') {
            inTag = true;
            i++; // Skip '<'
            if (input[i] == '/') {
                // Closing tag
                i++;
                while (input[i] != '>' && input[i] != '\0') {
                    i++;
                }
                inTag = false;
                if (top >= 0 && strncmp(stack + top, input + i - top, top + 1) == 0) {
                    pop();
                } else {
                    count++;
                }
            } else {
                // Opening tag
                while (input[i] != '>' && input[i] != '\0') {
                    push(input[i]);
                    i++;
                }
            }
        } else if (inTag && input[i] == '>') {
            inTag = false;
        }
    }

    // Check for remaining unmatched tags
    count += top + 1;

    printf("Count of missing or invalid tags: %d\n", count);

    return 0;
}
