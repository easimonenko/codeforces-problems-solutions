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

  int ans = 0;

  auto from = a.begin() + 1;
  for (int i = 0; i < n; i++) {
    auto it = upper_bound(from, a.end(), a[i]);
    if (it != a.end()) {
      ans++;
      from = it + 1;
    }
    else {
      break;
    }
  }
  
  cout << ans << endl;

  return 0;
}
