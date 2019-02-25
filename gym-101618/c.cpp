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

  int ans = -1;

  for (int i = 0; i < n; i++) {
    if (ans == -1 && a[i] == 2) {
      ans = i;
    } else {
      if (a[i] != a[i - 1] + 1) {
        ans = -1;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
