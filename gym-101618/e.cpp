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
  reverse(a.begin(), a.end());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, a[i] + i);
  }

  cout << ans << endl;

  return 0;
}
