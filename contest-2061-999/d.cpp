// Incomplete.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t != 0) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(m);
    for (int k = 0; k < m; k++) {
      cin >> b[k];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (n == m) {
      bool ans = true;
      for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
          ans = false;
          break;
        }
      }
      cout << (ans ? "Yes" : "No") << endl;
    } else {
      cout << "N/A" << endl;
    }

    t--;
  }

  return 0;
}
