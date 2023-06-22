// TODO: incomplete solution.

#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) {
  return x < y ? x : y;
}

int max(int x, int y) {
  return x < y ? y : x;
}

int minxs(int a[], int n) {
  int res = a[0];
  for (int i = 1; i < n; i++) {
    res = min(res, a[i]);
  }

  return res;
}

int maxxs(int a[], int n) {
  int res = a[0];
  for (int i = 1; i < n; i++) {
    res = max(res, a[i]);
  }

  return res;
}

void swap(int* x, int* y) {
  int t = *x;
  *x = *y;
  *y = t;
}

int main(int argc, char* argv[]) {
  int t;
  scanf("%d", &t);
  for (int k = 0; k < t; k++) {
    int n;
    scanf("%d", &n);
    int xs[n], ys[n];
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      xs[i] = x; ys[i] = y;
    }
    int x_min = minxs(xs, n); printf("%d\n", x_min);
    int x_max = maxxs(xs, n); printf("%d\n", x_max);
    int y_min = minxs(ys, n); printf("%d\n", y_min);
    int y_max = maxxs(ys, n); printf("%d\n", y_max);
    int a[4] = {x_min, y_min, x_max, y_max};
    if (a[1] < a[0]) {
      swap(&a[0], &a[1]);
    }
    if (a[3] < a[2]) {
      swap(&a[2], &a[3]);
    }
    if (a[2] < a[1]) {
      swap(&a[1], &a[2]);
    }
    printf("%d\n", 2 * a[0] + 2 * a[1] + 2* a[2] + a[3]);
  }
  
  return 0;
}
