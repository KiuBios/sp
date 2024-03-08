#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Matrix {
    int rows, cols;
    double *data;
};

// Function to create a matrix
struct Matrix CreateMatrix(int rows, int cols) {
    struct Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (double *)malloc(rows * cols * sizeof(double));
    return matrix;
}

// Function to print a matrix
void PrintMatrix(struct Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            printf("%.2f ", matrix.data[i * matrix.cols + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to transpose a matrix
struct Matrix Transpose(struct Matrix matrix) {
    struct Matrix result = CreateMatrix(matrix.cols, matrix.rows);
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            result.data[j * result.cols + i] = matrix.data[i * matrix.cols + j];
        }
    }
    return result;
}

// Function to add two matrices
struct Matrix Add(struct Matrix a, struct Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: Matrices dimensions mismatch.\n");
        exit(1);
    }
    struct Matrix result = CreateMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i * result.cols + j] = a.data[i * a.cols + j] + b.data[i * b.cols + j];
        }
    }
    return result;
}

// Function to multiply two matrices
struct Matrix Multiply(struct Matrix a, struct Matrix b) {
    if (a.cols != b.rows) {
        printf("Error: Matrices dimensions mismatch for multiplication.\n");
        exit(1);
    }
    struct Matrix result = CreateMatrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            for (int k = 0; k < a.cols; k++) {
                result.data[i * result.cols + j] += a.data[i * a.cols + k] * b.data[k * b.cols + j];
            }
        }
    }
    return result;
}

// Function to fill matrix with random values
void FillRandom(struct Matrix matrix) {
    for (int i = 0; i < matrix.rows * matrix.cols; i++) {
        matrix.data[i] = rand() % 10; // Generates random numbers between 0 and 9
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Create and initialize matrices
    struct Matrix A = CreateMatrix(3, 3);
    struct Matrix B = CreateMatrix(3, 3);

    // Fill matrices with random values
    FillRandom(A);
    FillRandom(B);

    // Print matrices
    printf("Matrix A:\n");
    PrintMatrix(A);

    printf("Matrix B:\n");
    PrintMatrix(B);

    // Transpose matrix A
    printf("Transpose of Matrix A:\n");
    struct Matrix transposed_A = Transpose(A);
    PrintMatrix(transposed_A);

    // Add matrices A and B
    printf("Addition of Matrices A and B:\n");
    struct Matrix addition_result = Add(A, B);
    PrintMatrix(addition_result);

    // Multiply matrices A and B
    printf("Multiplication of Matrices A and B:\n");
    struct Matrix multiplication_result = Multiply(A, B);
    PrintMatrix(multiplication_result);

    // Free allocated memory
    free(A.data);
    free(B.data);
    free(transposed_A.data);
    free(addition_result.data);
    free(multiplication_result.data);

    return 0;
}
