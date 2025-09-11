#include <stdio.h>

int matrixSize;


void convertToSparse(int matrix[][matrixSize], int sparseMatrix[][3], int *nonZeroCount) {
    *nonZeroCount = 0;
    
    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixSize; col++) {
            if (matrix[row][col] != 0) {
                (*nonZeroCount)++;
            }
        }
    }

    sparseMatrix[0][0] = matrixSize;          
    sparseMatrix[0][1] = matrixSize;          
    sparseMatrix[0][2] = *nonZeroCount;      

    int index = 1;
    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixSize; col++) {
            if (matrix[row][col] != 0) {
                sparseMatrix[index][0] = row;
                sparseMatrix[index][1] = col;
                sparseMatrix[index][2] = matrix[row][col];
                index++;
            }
        }
    }
}

int addSparseMatrices(int sparseA[][3], int sparseB[][3], int result[][3], int sizeA, int sizeB) {
    int i = 1, j = 1, k = 1;

    result[0][0] = sparseA[0][0];
    result[0][1] = sparseA[0][1];

    while (i <= sizeA && j <= sizeB) {
        if (sparseA[i][0] < sparseB[j][0] || 
            (sparseA[i][0] == sparseB[j][0] && sparseA[i][1] < sparseB[j][1])) {
            result[k][0] = sparseA[i][0];
            result[k][1] = sparseA[i][1];
            result[k][2] = sparseA[i][2];
            i++;
        }
        else if (sparseA[i][0] > sparseB[j][0] || 
                 (sparseA[i][0] == sparseB[j][0] && sparseA[i][1] > sparseB[j][1])) {
            result[k][0] = sparseB[j][0];
            result[k][1] = sparseB[j][1];
            result[k][2] = sparseB[j][2];
            j++;
        }
        else {  
            result[k][0] = sparseA[i][0];
            result[k][1] = sparseA[i][1];
            result[k][2] = sparseA[i][2] + sparseB[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i <= sizeA) {
        result[k][0] = sparseA[i][0];
        result[k][1] = sparseA[i][1];
        result[k][2] = sparseA[i][2];
        i++;
        k++;
    }

    while (j <= sizeB) {
        result[k][0] = sparseB[j][0];
        result[k][1] = sparseB[j][1];
        result[k][2] = sparseB[j][2];
        j++;
        k++;
    }

    result[0][2] = k - 1;  
    return k - 1;
}

void transposeSparse(int sparse[][3], int transposed[][3], int size) {
    transposed[0][0] = sparse[0][1]; 
    transposed[0][1] = sparse[0][0];  
    transposed[0][2] = sparse[0][2]; 

    int k = 1;
    for (int col = 0; col < sparse[0][1]; col++) {
        for (int i = 1; i <= size; i++) {
            if (sparse[i][1] == col) {
                transposed[k][0] = sparse[i][1];
                transposed[k][1] = sparse[i][0];
                transposed[k][2] = sparse[i][2];
                k++;
            }
        }
    }
}

void printSparse(int sparse[][3], int size) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= size; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
    printf("\n");
}

void readMatrix(int matrix[][matrixSize]) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    printf("Enter the size of the matrices: ");
    scanf("%d", &matrixSize);

    int matrixA[matrixSize][matrixSize];
    int matrixB[matrixSize][matrixSize];

    printf("Enter elements of matrix A:\n");
    readMatrix(matrixA);

    printf("Enter elements of matrix B:\n");
    readMatrix(matrixB);

    int sparseA[matrixSize * matrixSize + 1][3];
    int sparseB[matrixSize * matrixSize + 1][3];
    int sumSparse[matrixSize * matrixSize + 1][3];
    int transposedSum[matrixSize * matrixSize + 1][3];

    int nonZeroA, nonZeroB;

    convertToSparse(matrixA, sparseA, &nonZeroA);
    convertToSparse(matrixB, sparseB, &nonZeroB);

    printf("\nSparse representation of matrix A:\n");
    printSparse(sparseA, nonZeroA);

    printf("Sparse representation of matrix B:\n");
    printSparse(sparseB, nonZeroB);

    int nonZeroSum = addSparseMatrices(sparseA, sparseB, sumSparse, nonZeroA, nonZeroB);

    printf("Sum of sparse matrices:\n");
    printSparse(sumSparse, nonZeroSum);

    transposeSparse(sumSparse, transposedSum, nonZeroSum);

    printf("Transpose of the sum:\n");
    printSparse(transposedSum, nonZeroSum);

    return 0;
}

