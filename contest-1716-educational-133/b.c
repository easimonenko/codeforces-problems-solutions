// TODO: incomplete solution.

#include "stdio.h"

void print_int_array(int a[], int n) {
  printf("%d", a[0]);
  for (int i = 1; i < n; i++) {
    printf(" %d", a[i]);
  }
  printf("\n");
}

void swap_elems_in_int_array(int a[], int l, int r) {
  int t = a[l];
  a[l] = a[r];
  a[r] = t;
}

int main(int argc, char* argv[]) {
  int t;
  scanf("%d", &t);
  for (int k = 0; k < t; k++) {
    int n;
    scanf("%d", &n);
    int p[n];
    for (int j = 1; j <= n; j++) {
      p[j - 1] = j;
    }
    printf("%d\n", n);
    print_int_array(p, n);
    for (int r = n - 2; r >= 0; r--) {
      swap_elems_in_int_array(p, r, r + 1);
      print_int_array(p, n);
    }
  }
  
  return 0;
}
