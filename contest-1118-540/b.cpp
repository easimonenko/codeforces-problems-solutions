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

  vector<int> sf(n + 4, 0);
  for (int i = 0; i < n; i++) {
    sf[i + 2] = sf[i] + a[i];
  }

  vector<int> sb(n + 4, 0);
  for (int i = n - 1; i >= 0; i--) {
    sb[i + 2] = sb[i + 4] + a[i];
  }

  int ans = 0;
  for (int i = 2; i < n + 2; i++) {
    if (sf[i - 1] + sb[i + 2] == sf[i - 2] + sb[i + 1]) {
      ans += 1;
    }
  }
  cout << ans << endl;

  return 0;
}
