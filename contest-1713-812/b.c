// TODO: incomplete solution.

#include <stdio.h>

int main(int argc, char* argv[]) {
  int t;
  scanf("%d", &t);
  for (int k = 0; k < t; k++) {
    int n;
    scanf("%d", &n);
    if (n == 1) {
      puts("YES");
    } else {
      int a[n];
      for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
      }
      int is_lower = 0;
      int x = 1;
      for (; x < n; x += 1) {
        if (a[x - 1] > a[x]) {
          is_lower = 1;
          break;
        }
      }
      if (x == n && is_lower == 0) {
        puts("YES");
      } else {
        int is_upper = 0;
        x += 1;
        for (; x < n; x += 1) {
          if (a[x - 1] < a[x]) {
            is_upper = 1;
            break;
          }
        }
        if (is_upper == 0) {
          puts("YES");
        } else {
          puts("NO");
        }
      }
    }
  }
  
  return 0;
}
