#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool parity_compare(int x, int y) {
  return ((x % 2 == 0) && (y % 2 == 0))
    || ((x % 2 != 0) && (y % 2 != 0));
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    size_t n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    bool ans = true;
    for (size_t i = 0; i < n; i++) {
      if (!parity_compare(a[i], sorted_a[i])) {
        ans = false;
        break;
      }
    }
    cout << (ans ? "YES": "NO") << endl;
  }
  return 0;
}
