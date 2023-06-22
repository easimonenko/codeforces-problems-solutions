// TODO: incomplete solution.

#include "stdio.h"

int min(int a, int b) {
  return a < b ? a : b;
}

int main(int argc, char* argv[]) {
  int t;
  scanf("%d", &t);
  for (int k = 0; k < t; k++) {
    int x;
    scanf("%d", &x);
    if (x == 1) {
      puts("2");
    } else {
      int ans = x / 3;
      if (x % 3 != 0) {
        ans += 1;
      }
      printf("%d\n", ans);
    }
  }
  
  return 0;
}
