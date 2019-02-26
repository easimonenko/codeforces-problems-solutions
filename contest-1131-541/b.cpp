#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long ans = 1;
  int a_prev = 0, b_prev = 0;
  for (int i = 0; i < n; i++) {
    int a_curr, b_curr;
    cin >> a_curr >> b_curr;
    if (a_curr == a_prev && b_curr == b_prev) {
      continue;
    }
    int l = max(a_prev, b_prev);
    int r = min(a_curr, b_curr);
    if (r >= l) {
      ans = ans + r - l + 1;
    if (a_prev == b_prev) {
      ans--;
    }
    }

    a_prev = a_curr;
    b_prev = b_curr;
  }
  cout << ans << endl;

  return 0;
}
