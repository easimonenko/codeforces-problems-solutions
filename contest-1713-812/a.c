// TODO: incomplete solution.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  int t;
  scanf("%d", &t);
  for (int k = 0; k < t; k++) {
    int n;
    scanf("%d", &n);
    int x_min, x_max, y_min, y_max;
    scanf("%d %d", &x_min, &y_min);
    x_max = x_min;
    y_max = y_min;
    for (int i = 1; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      if (x < x_min) {
        x_min = x;
      }
      if (x > x_max) {
        x_max = x;
      }
      if (y < y_min) {
        y_min = y;
      }
      if (y > y_max) {
        y_max = y;
      }
    }
    printf("%d\n", 2 * abs(x_min) + 2 * abs(x_max) + 2 * abs(y_min) + 2 * abs(y_max));
  }
  
  return 0;
}
