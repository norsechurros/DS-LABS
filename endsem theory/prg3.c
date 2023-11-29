#include <stdio.h>
#include <stdlib.h>

// Structure to represent each element of the sparse matrix
struct Element {
    int row;
    int column;
    int value;
};

int main() {
    int rows, columns, nonZeroElements;

    // Read the number of rows, columns, and non-zero elements
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &nonZeroElements);

    // Allocate memory for the array of structures
    struct Element* sparseMatrix = (struct Element*)malloc(nonZeroElements * sizeof(struct Element));

    // Read the non-zero elements of the sparse matrix
    printf("Enter the non-zero elements:\n");
    for (int i = 0; i < nonZeroElements; i++) {
        printf("Enter the row, column, and value of element %d: ", i + 1);
        scanf("%d %d %d", &sparseMatrix[i].row, &sparseMatrix[i].column, &sparseMatrix[i].value);
    }

    // Print the original sparse matrix
    printf("\nOriginal Sparse Matrix:\n");
    for (int i = 0; i < nonZeroElements; i++) {
        printf("%d %d %d\n", sparseMatrix[i].row, sparseMatrix[i].column, sparseMatrix[i].value);
    }

    // Create the transpose of the sparse matrix
    struct Element* transposeMatrix = (struct Element*)malloc(nonZeroElements * sizeof(struct Element));
    for (int i = 0; i < nonZeroElements; i++) {
        transposeMatrix[i].row = sparseMatrix[i].column;
        transposeMatrix[i].column = sparseMatrix[i].row;
        transposeMatrix[i].value = sparseMatrix[i].value;
    }

    // Print the transpose of the sparse matrix
    printf("\nTranspose of Sparse Matrix:\n");
    for (int i = 0; i < nonZeroElements; i++) {
        printf("%d %d %d\n", transposeMatrix[i].row, transposeMatrix[i].column, transposeMatrix[i].value);
    }

    // Free the allocated memory
    free(sparseMatrix);
    free(transposeMatrix);

    return 0;
}
fast(struct spa a[],struct spa b[])
{
    int i=0,j,k=1,t=0; int r_terms[20],start_pos[20];

      b[0].row=a[0].col; b[0].col=a[0].row; b[0].val=a[0].val;

       for(i=0; i<a[0].col; i++)
         {r_terms[i]=0;}

         for(i=1; i<=a[0].val; i++)
         {r_terms[a[i].col]++;}

         start_pos[0]=1;

         for(i=1; i<a[0].col; i++)
         {start_pos[i]=r_terms[i-1]+start_pos[i-1];}
         
        for(j=1; j<=a[0].val; j++)
        {  k=start_pos[a[j].col]++;

               b[k].row=a[j].col; b[k].col=a[j].row; b[k].val=a[j].val;
          }
}