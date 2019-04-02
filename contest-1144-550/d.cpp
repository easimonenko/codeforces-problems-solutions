#include <iostream>
#include <vector>

using namespace std;

int sign(int x) { return x == 0 ? 0 : (x > 0 ? 1 : -1); }

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> s(2e5 + 1, 0);
  int max_count_elem;
  scanf("%d", &max_count_elem);
  int counter = 1;
  s[max_count_elem]++;
  int max_count_elem_idx = 0;
  for (int i = 1; i < n; i++) {
    scanf("%d", &a[i]);
    s[a[i]]++;
    if (s[a[i]] > counter) {
      max_count_elem = a[i];
      counter = s[a[i]];
      max_count_elem_idx = i;
    }
  }

  if (n - counter > 0) {
    cout << n - counter << endl;
    for (int i = max_count_elem_idx; i < n - 1; i++) {
      switch (sign(a[i + 1] - a[i])) {
      case 1:
        printf("%d %d %d\n", 2, i + 2, i + 1);
        break;
      case -1:
        printf("%d %d %d\n", 1, i + 2, i + 1);
        break;
      }
      a[i + 1] = a[i];
    }
    for (int i = max_count_elem_idx - 1; i >= 0; i--) {
      switch (sign(a[i] - a[i + 1])) {
      case 1:
        printf("%d %d %d\n", 2, i + 1, i + 1 + 1);
        break;
      case -1:
        printf("%d %d %d\n", 1, i + 1, i + 1 + 1);
        break;
      }
      a[i] = a[i + 1];
    }
  } else {
    cout << '0' << endl;
  }

  return 0;
}
