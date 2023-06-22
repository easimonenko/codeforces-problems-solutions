// TODO: incomplete solution.

#include <iostream>

using namespace std;

int main() {
  int a1, a2, k1, k2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;

  int b1 = min(a1, n / k1);
  int b2 = min(a2, (n - b1 * k1) / k2);
  int c1 = min(a2, n / k2);
  int c2 = min(a1, (n - c1 * k2) / k1);
  int max_ans = max(b1 + b2, c1 + c2);
  int d1 = min(a1 / k1, n / k1);
  int d2 = min(a2 / k2, (n - d1 * k1) / k2);
  int e1 = min(a2 / k2, n / k2);
  int e2 = min(a1 / k1, (n - e1 * k2) / k1);
  int min_ans = min(d1 + d2, e1 + e2);
  cout << min_ans << " " << max_ans << endl;
  return 0;
}
