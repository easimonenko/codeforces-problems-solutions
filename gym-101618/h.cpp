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

  int ans = n;

  for (int i = 0; i < n; i++) {
    ans = min(a[i] + (n - i - 1), ans);
  }

  cout << ans << endl;

  return 0;
}
