#include <stdio.h>
int main() {
  str *s = "некоторая строка";
  char *c = 's';
  int *matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  printf("Matrix created using an array:\n");
  /* ...dawdawdawdaw 
    dadadadadawdawdawda*/
  for (int i = 0; i < 3; i++) {
    // второй однострочный комментарий
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]); // тут некоторый комментарий ****
    }
    // Снова не"который комментарий"
  }

  /* ...dawdawdawdaw ********/
