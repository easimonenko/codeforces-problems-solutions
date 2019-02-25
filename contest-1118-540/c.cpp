#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n * n);
  for (int i = 0; i < n * n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  bool ans = true;
  vector<vector<int> > pm(n, vector<int>(n));
  if (n % 2 == 0) {
    int k = 0;
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < n / 2; j++) {
        if (a[k * 4] == a[k * 4 + 1]
          && a[k * 4 + 1] == a[k * 4 + 2]
          && a[k * 4 + 2] == a[k * 4 + 3]) {
          pm[i][j] = pm[i][n - 1 - j] = a[k * 4];
          pm[n - 1 - i][j] = pm[n - 1 - i][n - 1 - j] = a[k * 4];
          k++;
        } else {
          ans = false;
          break;
        }
      }
      if (!ans) {
        break;
      }
    }
  } else {
    // TODO
  }

  if (ans) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << pm[i][0];
      for (int j = 1; j < n; j++) {
        cout << ' ' << pm[i][j];
      }
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
