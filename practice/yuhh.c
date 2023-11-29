#include <stdio.h>

struct sparse {
    int rows;
    int cols;
    int value;
} matrix[10], trans[10];

void print(struct sparse matrix[], int numterms) {
    printf("Sparse Matrix:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < numterms; i++) {
        printf("%d\t%d\t%d\n", matrix[i].rows, matrix[i].cols, matrix[i].value);
    }
}

void fastTrans(struct sparse matrix[], int numterms, struct sparse trans[]) {
    int rowterms[10], startingpos[10];

    for (int i = 0; i < 10; i++) {
        rowterms[i] = 0;
        startingpos[i] = 0; // Initialize startingpos
    }

    for (int i = 0; i < numterms; i++) {
        int cols = matrix[i].cols;
        rowterms[cols]++;
    }

    for (int i = 1; i < 10; i++) {
        startingpos[i] = startingpos[i - 1] + rowterms[i - 1];
    }

    for (int i = 0; i < numterms; i++) {
        int cols = matrix[i].cols;
        int pos = startingpos[cols];

        trans[pos].rows = matrix[i].cols;
        trans[pos].cols = matrix[i].rows;
        trans[pos].value = matrix[i].value;

        startingpos[cols]++;
    }
}

int main() {
    int numterms;

    // Input the number of non-zero elements
    printf("Enter the number of non-zero elements in the matrix: ");
    scanf("%d", &numterms);

    // Input the elements of the sparse matrix
    printf("Enter the elements in the format (row, column, value):\n");
    for (int i = 0; i < numterms; i++) {
        scanf("%d %d %d", &matrix[i].rows, &matrix[i].cols, &matrix[i].value);
    }

    // Find the fast transpose of the sparse matrix
    fastTrans(matrix, numterms, trans);

    // Print the original and transposed matrices
    print(matrix, numterms);
    printf("\nTransposed Matrix:\n");
    print(trans, numterms);

    return 0;
}
