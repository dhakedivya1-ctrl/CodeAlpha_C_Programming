#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX],
                 int result[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX],
                      int result[MAX][MAX],
                      int r1, int c1, int c2) {
    int i, j, k;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX],
                     int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            transpose[j][i] = matrix[i][j];
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX], trans[MAX][MAX];
    int r1, c1, r2, c2;

    printf("===== Matrix Operations =====\n");

    printf("\nEnter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    if (r1 > MAX || c1 > MAX || r1 <= 0 || c1 <= 0) {
        printf("Invalid matrix size.\n");
        return 0;
    }

    printf("Enter elements of Matrix A:\n");
    inputMatrix(a, r1, c1);

    printf("\nEnter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    if (r2 > MAX || c2 > MAX || r2 <= 0 || c2 <= 0) {
        printf("Invalid matrix size.\n");
        return 0;
    }

    printf("Enter elements of Matrix B:\n");
    inputMatrix(b, r2, c2);

    printf("\nMatrix A:\n");
    displayMatrix(a, r1, c1);

    printf("\nMatrix B:\n");
    displayMatrix(b, r2, c2);

    if (r1 == r2 && c1 == c2) {
        addMatrices(a, b, result, r1, c1);
        printf("\nMatrix Addition (A + B):\n");
        displayMatrix(result, r1, c1);
    } else {
        printf("\nMatrix Addition not possible: sizes are different.\n");
    }

    if (c1 == r2) {
        multiplyMatrices(a, b, result, r1, c1, c2);
        printf("\nMatrix Multiplication (A x B):\n");
        displayMatrix(result, r1, c2);
    } else {
        printf("\nMatrix Multiplication not possible: columns of A must equal rows of B.\n");
    }

    transposeMatrix(a, trans, r1, c1);
    printf("\nTranspose of Matrix A:\n");
    displayMatrix(trans, c1, r1);

    return 0;
}
