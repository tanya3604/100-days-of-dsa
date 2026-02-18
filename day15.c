#include <stdio.h>

int main() {
    int m, n;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int i, j;
    int sum = 0;

    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate primary diagonal sum
    for(i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of primary diagonal = %d", sum);

    return 0;
}
