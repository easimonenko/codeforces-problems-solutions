#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int q;
  cin >> q;
  while (q > 0) {
    int n;
    cin >> n;
    vector<int> c(n + 1, 0);
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      c[t]++;
    }
    sort(begin(c), end(c));
    int answer = c[n];
    int p = c[n];
    for (int i = n - 1; i >= 0; i--) {
      int v = c[i] == p ? max(c[i] - 1, 0) : (c[i] < p ? c[i] : max(p - 1, 0));

      answer += v;
      p = v;
    }
    cout << answer << endl;
    q--;
  }
  return 0;
}
