#include <iostream>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  int n, m;
  cin >> n >> m;

  int d = gcd(n, m);
#ifdef DEBUG
  cout << d << endl;
#endif
  if (n != gcd(n, m)) {
    cout << "-1" << endl;
  } else {
    int c = m / n;
    int ans = 0;
    while (c != 1) {
      if (c % 2 == 0) {
        ans++;
        c >>= 1;
      } else if (c % 3 == 0) {
        ans++;
        c /= 3;
      } else {
        cout << "-1" << endl;
        return 0;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
