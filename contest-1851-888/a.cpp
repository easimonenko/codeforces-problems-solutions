#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, m, k, H;
    cin >> n >> m >> k >> H;
    /*if (m == 1) {
      cout << "0" << endl;
      continue;
      }*/
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int h;
      cin >> h;
      int d = abs(H - h);
      if (d == 0) {
        continue;
      }
      if ((d % k == 0) && ((d / k) <= (m - 1))) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
