#include <iostream>

using namespace std;

int main() {
  int n, t;
  cin >> n >> t;

  int answer = 0;
  int diff = 10e5;
  for (int i = 1; i <= n; i++) {
    int s, d;
    cin >> s >> d;

    int new_diff;

    int dd = t - s;
    if (dd < 0) {
      new_diff = -dd;
    } else {
      int ddd = (t - s) % d;
      if (ddd == 0) {
        new_diff = 0;
      } else {
        new_diff = d - ddd;
      }
    }

    int next_diff = min(diff, new_diff);
    if (next_diff < diff) {
      diff = next_diff;
      answer = i;
    }
  }

  cout << answer << endl;

  return 0;
}
