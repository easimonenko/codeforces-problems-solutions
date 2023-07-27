#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    if (c[0] == c[n - 1]) {
      int counter = 1;
      for (int i = 1; i < n; i++) {
        if (c[i] == c[0]) {
          counter++;
        }
      }
      cout << (counter >= k ? "YES" : "NO") << endl;
    } else {
      int c_first = 0, c_first_idx = -1;
      for (int i = 0; i < n; i++) {
        if (c[i] == c[0]) {
          c_first++;
          c_first_idx = i;
          if (c_first == k) {
            break;
          }
        }
      }
      int c_last = 0, c_last_idx = n;
      for (int i = n - 1; i >= 0; i--) {
        if (c[i] == c[n - 1]) {
          c_last++;
          c_last_idx = i;
          if (c_last == k) {
            break;
          }
        }
      }
      cout << ((c_first >= k) && (c_last >= k) && (c_first_idx < c_last_idx) ? "YES" : "NO")
           << endl;
    }
  }
  return 0;
}
