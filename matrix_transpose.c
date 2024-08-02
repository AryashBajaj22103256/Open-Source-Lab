#include <stdio.h>

#define MAX 100

int main() {
    int row, col;
    printf("Enter the dimnsions of matrix - ");
    scanf("%d %d", &row, &col);
    int mat[MAX][MAX];
    int transpose[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transpose[j][i] = mat[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf(" %d", transpose[i][j]);
        }
        printf("\n");
    }
}