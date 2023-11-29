#include <stdio.h>

#define MAX_TERMS 100

// Structure to represent a tuple (row, column, value)
struct SparseMatrixElement {
    int row;
    int col;
    int value;
};

// Function to print the sparse matrix
void printSparseMatrix(struct SparseMatrixElement matrix[], int numTerms) {
    printf("Sparse Matrix:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < numTerms; i++) {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

// Function to find the fast transpose of a sparse matrix
void fastTranspose(struct SparseMatrixElement matrix[], int numTerms, struct SparseMatrixElement transpose[]) {
    int rowTerms[MAX_TERMS], startingPos[MAX_TERMS];

    // Initialize counts of terms in each column
    for (int i = 0; i < MAX_TERMS; i++) {
        rowTerms[i] = 0;
    }

    // Count the number of terms in each column
    for (int i = 0; i < numTerms; i++) {
        int col = matrix[i].col;
        rowTerms[col]++;
    }

    // Compute the starting position of each column in the transpose matrix
    startingPos[0] = 0;
    for (int i = 1; i < MAX_TERMS; i++) {
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    // Fill in the transpose matrix
    for (int i = 0; i < numTerms; i++) {
        int col = matrix[i].col;
        int pos = startingPos[col];

        // Copy the values from the original matrix to the transpose matrix
        transpose[pos].row = matrix[i].col;
        transpose[pos].col = matrix[i].row;
        transpose[pos].value = matrix[i].value;

        startingPos[col]++; // Move to the next position in the transpose matrix
    }
}

int main() {
    int numTerms;
    struct SparseMatrixElement matrix[MAX_TERMS];
    struct SparseMatrixElement transpose[MAX_TERMS];

    // Input the number of non-zero elements
    printf("Enter the number of non-zero elements in the matrix: ");
    scanf("%d", &numTerms);

    // Input the elements of the sparse matrix
    printf("Enter the elements in the format (row, column, value):\n");
    for (int i = 0; i < numTerms; i++) {
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }

    // Find the fast transpose of the sparse matrix
    fastTranspose(matrix, numTerms, transpose);

    // Print the original and transposed matrices
    printSparseMatrix(matrix, numTerms);
    printf("\nTransposed Matrix:\n");
    printSparseMatrix(transpose, numTerms);

    return 0;
}

