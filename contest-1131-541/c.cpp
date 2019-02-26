#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  vector<int> b(n);
  for (int i = 0; i <= n / 2; i++) {
    b[n - 1 - i] = a[n - 1 - 2 * i];
  }
  for (int i = 0; i < n / 2; i++) {
    b[i] = a[n - 2 - 2 * i];
  }

  cout << b[0];
  for (int i = 1; i < n; i++) {
    cout << ' ' << b[i];
  }
  cout << endl;

  return 0;
}
