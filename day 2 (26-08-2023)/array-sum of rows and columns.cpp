#include <stdio.h>
int main() {
  int rows, columns, i, j, sum_row, sum_column;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &columns);
  int matrix[rows][columns];
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      printf("Enter the element at [%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }
  for (i = 0; i < rows; i++) {
    sum_row = 0;
    for (j = 0; j < columns; j++) {
      sum_row += matrix[i][j];
    }
    printf("The sum of row %d is %d\n", i, sum_row);
  }
  for (j = 0; j < columns; j++) {
    sum_column = 0;
    for (i = 0; i < rows; i++) {
      sum_column += matrix[i][j];
    }
    printf("The sum of column %d is %d\n", j, sum_column);
  }
}

