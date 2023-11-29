#include <stdio.h>

void inputMatrix(int mat[][100], int rows, int cols) {
    printf("Enter the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[][100], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int matA[][100], int matB[][100], int matResult[][100], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            matResult[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                matResult[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

void addMatrices(int matA[][100], int matB[][100], int matResult[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matResult[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

int isMagicSquare(int mat[][100], int n) {
    int sumRow, sumCol, sumDiagonal1 = 0, sumDiagonal2 = 0;

    for (int i = 0; i < n; i++) {
        sumDiagonal1 += mat[i][i];
        sumDiagonal2 += mat[i][n - i - 1];
    }

    if (sumDiagonal1 != sumDiagonal2) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        sumRow = 0;
        sumCol = 0;

        for (int j = 0; j < n; j++) {
            sumRow += mat[i][j];
            sumCol += mat[j][i];
        }

        if (sumRow != sumDiagonal1 || sumCol != sumDiagonal1) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int matA[100][100], matB[100][100], matResult[100][100];
    int rowsA, colsA, rowsB, colsB;

    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    inputMatrix(matA, rowsA, colsA);

    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    inputMatrix(matB, rowsB, colsB);

    if (colsA != rowsB) {
        printf("Matrix multiplication is not possible.\n");
    } else {
        multiplyMatrices(matA, matB, matResult, rowsA, colsA, colsB);
        printf("Result of matrix multiplication:\n");
        displayMatrix(matResult, rowsA, colsB);
    }

    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrix addition is not possible.\n");
    } else {
        addMatrices(matA, matB, matResult, rowsA, colsA);
        printf("Result of matrix addition:\n");
        displayMatrix(matResult, rowsA, colsA);
    }

    if (rowsA == colsA && isMagicSquare(matA, rowsA)) {
        printf("Matrix A is a magic square.\n");
    } else {
        printf("Matrix A is not a magic square.\n");
    }

    return 0;
}
